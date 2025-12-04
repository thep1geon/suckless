/* See LICENSE file for copyright and license details. */
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <X11/Xlib.h>

#include "arg.h"
#include "slstatus.h"
#include "util.h"

struct arg {
	const char *(*func)(const char *);
	const char *fmt;
	const char *args;
	unsigned int turn;
	int signal;
};

char buf[1024];
static int sflag = 0;
static volatile sig_atomic_t done, upsigno;
static Display *dpy;

#include "config.h"
#define MAXLEN CMDLEN * LEN(args)

static char statuses[LEN(args)][CMDLEN] = {0};

static void
difftimespec(struct timespec *res, struct timespec *a, struct timespec *b)
{
	res->tv_sec = a->tv_sec - b->tv_sec - (a->tv_nsec < b->tv_nsec);
	res->tv_nsec = a->tv_nsec - b->tv_nsec +
	               (a->tv_nsec < b->tv_nsec) * 1E9;
}

static void
usage(void)
{
	die("usage: %s [-v] [-s] [-1]", argv0);
}

static void
printstatus(unsigned int iter)
{
	size_t i;
	char status[MAXLEN];
	const char *res;

	for (i = 0; i < LEN(args); i++) {
		if (!((!iter && !upsigno) || upsigno == SIGUSR1 ||
			(!upsigno && args[i].turn > 0 && !(iter % args[i].turn)) ||
			(args[i].signal >= 0 && upsigno - SIGRTMIN == args[i].signal)))
			continue;

		if (!(res = args[i].func(args[i].args)))
			res = unknown_str;

		if (esnprintf(statuses[i], sizeof(statuses[i]), args[i].fmt, res) < 0)
			break;
	}

	status[0] = '\0';
	for (i = 0; i < LEN(args); i++)
		strcat(status, statuses[i]);
	status[strlen(status)] = '\0';

	if (sflag) {
		puts(status);
		fflush(stdout);
		if (ferror(stdout))
			die("puts:");
	} else {
		if (XStoreName(dpy, DefaultRootWindow(dpy), status) < 0)
			die("XStoreName: Allocation failed");
		XFlush(dpy);
	}
}


static void
sighandler(const int signo)
{
	if ((signo <= SIGRTMAX && signo >= SIGRTMIN) || signo == SIGUSR1)
		upsigno = signo;
	else
		done = 1;
}

int
main(int argc, char *argv[])
{
	struct sigaction act;
	struct timespec start, current, diff, intspec, wait;
	unsigned int iter = 0;
	int i, ret = 0;

	ARGBEGIN {
	case 'v':
		die("slstatus-"VERSION);
        break;
	case '1':
		done = 1;
		/* FALLTHROUGH */
	case 's':
		sflag = 1;
		break;
	default:
		usage();
	} ARGEND

	if (argc)
		usage();

    srand(time(0));

	memset(&act, 0, sizeof(act));
	act.sa_handler = sighandler;
	sigaction(SIGINT,  &act, NULL);
	sigaction(SIGTERM, &act, NULL);
	sigaction(SIGUSR1, &act, NULL);
	for (i = SIGRTMIN; i <= SIGRTMAX; i++)
		sigaction(i, &act, NULL);

	if (!sflag && !(dpy = XOpenDisplay(NULL)))
		die("XOpenDisplay: Failed to open display");

	do {
		if (clock_gettime(CLOCK_MONOTONIC, &start) < 0)
			die("clock_gettime:");

		printstatus(iter++);

		if (!done) {
			if (clock_gettime(CLOCK_MONOTONIC, &current) < 0)
				die("clock_gettime:");
			difftimespec(&diff, &current, &start);

			intspec.tv_sec = interval / 1000;
			intspec.tv_nsec = (interval % 1000) * 1E6;
			difftimespec(&wait, &intspec, &diff);

			while(wait.tv_sec >= 0 &&
			      (ret = nanosleep(&wait, &wait)) < 0 &&
			      errno == EINTR && !done) {
				printstatus(0);
				errno = upsigno = 0;
			}
			if (ret < 0 && errno != EINTR)
				die("nanosleep:");
		}
	} while (!done);

	if (!sflag) {
		XStoreName(dpy, DefaultRootWindow(dpy), NULL);
		if (XCloseDisplay(dpy) < 0)
			die("XCloseDisplay: Failed to close display");
	}

	return 0;
}
