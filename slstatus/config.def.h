/* See LICENSE file for copyright and license details. */

/* interval between updates (in ms) */
const unsigned int interval = 1000;

/* text to show if no value can be retrieved */
static const char unknown_str[] = "n/a";

/* maximum command output length */
#define CMDLEN 128

/* battery levels to notify - add any levels you want to receive notification for (in percent) */
const int notifiable_levels[] = {
    25,
    20,
    10,
    5,
};

/*
 * function            description                     argument (example)
 *
 * battery_perc        battery percentage              battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_notify      linux battery notifications     battery name (BAT0)
 *                                                     OpenBSD/FreeBSD not supported
 * battery_remaining   battery remaining HH:MM         battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_state       battery charging state          battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * cat                 read arbitrary file             path
 * cpu_freq            cpu frequency in MHz            NULL
 * cpu_perc            cpu usage in percent            NULL
 * datetime            date and time                   format string (%F %T)
 * disk_free           free disk space in GB           mountpoint path (/)
 * disk_perc           disk usage in percent           mountpoint path (/)
 * disk_total          total disk space in GB          mountpoint path (/)
 * disk_used           used disk space in GB           mountpoint path (/)
 * entropy             available entropy               NULL
 * gid                 GID of current user             NULL
 * hostname            hostname                        NULL
 * ipv4                IPv4 address                    interface name (eth0)
 * ipv6                IPv6 address                    interface name (eth0)
 * kernel_release      `uname -r`                      NULL
 * keyboard_indicators caps/num lock indicators        format string (c?n?)
 *                                                     see keyboard_indicators.c
 * keymap              layout (variant) of current     NULL
 *                     keymap
 * load_avg            load average                    NULL
 * netspeed_rx         receive network speed           interface name (wlan0)
 * netspeed_tx         transfer network speed          interface name (wlan0)
 * num_files           number of files in a directory  path
 *                                                     (/home/foo/Inbox/cur)
 * ram_free            free memory in GB               NULL
 * ram_perc            memory usage in percent         NULL
 * ram_total           total memory size in GB         NULL
 * ram_used            used memory in GB               NULL
 * run_command         custom shell command            command (echo foo)
 * swap_free           free swap in GB                 NULL
 * swap_perc           swap usage in percent           NULL
 * swap_total          total swap size in GB           NULL
 * swap_used           used swap in GB                 NULL
 * temp                temperature in degree celsius   sensor file
 *                                                     (/sys/class/thermal/...)
 *                                                     NULL on OpenBSD
 *                                                     thermal zone on FreeBSD
 *                                                     (tz0, tz1, etc.)
 * uid                 UID of current user             NULL
 * uptime              system uptime                   NULL
 * username            username of current user        NULL
 * vol_perc            OSS/ALSA volume in percent      mixer file (/dev/mixer)
 *                                                     NULL on OpenBSD/FreeBSD
 * wifi_essid          WiFi ESSID                      interface name (wlan0)
 * wifi_perc           WiFi signal in percent          interface name (wlan0)
 */

/*
 * purple   #D3869b
 * aqua     #89b482
 * red      #ea6962
 * blue     #7daea3
 * green    #a9b665
 * orange   #e78a4e
 * yellow   #d8a657
 * fg       #d4be98
*/

// #include "/home/magic/.cache/wal/colors-wal-slstatus.h"

#define COLOR(c) "^c" c "^"

static const char playbackinfocmd[] = "~/suckless/scripts/status-playbackinfo.sh";
static const char bat0infocmd[] = "~/suckless/scripts/status-battery.sh BAT0";
static const char bat1infocmd[] = "~/suckless/scripts/status-battery.sh BAT1";
static const char updatescmd[] = "~/suckless/scripts/status-updates.sh";

#define BLACK           "#2f1e33" // Color 0
#define RED             "#ce80ac" // Color 1
#define GREEN           "#80cea3" // Color 2
#define YELLOW          "#cec580" // Color 3
#define BLUE            "#809ace" // Color 4
#define MAGENTA         "#c080ce" // Color 5
#define CYAN            "#80cecd" // Color 6
#define WHITE           "#d7b1df" // Color 7
#define BOLD_BLACK      "#9c7da3" // Color 8
#define BOLD_RED        "#f59fca" // Color 9
#define BOLD_GREEN      "#9ff5c0" // Color 10
#define BOLD_YELLOW     "#f5eb9f" // Color 11
#define BOLD_BLUE       "#9fb5f5" // Color 12
#define BOLD_MAGENTA    "#eb9ff5" // Color 13
#define BOLD_CYAN       "#9ff5f5" // Color 14
#define BOLD_WHITE      "#ffdcff" // Color 15
#define BG              "#2f1e33"
#define FG              "#d7b1df"

static const struct arg args[] = {
    /* function             format                  argument               turn signal*/
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { rain,                 COLOR(CYAN)"%s",   NULL, 1,   -1 },
    { datetime,             COLOR(BOLD_RED)"  %s",       "%a, %b %d - %I:%M%p", 1,   -1 }, // Date and time
    { run_command,          COLOR(CYAN)" 󰝚 %s",      playbackinfocmd,       1,   -1 }, // The currently playing media
    { run_command,          COLOR(BOLD_MAGENTA)" %s",        bat0infocmd,           1,   -1 }, // Internal battery info
    { battery_remaining,    " %s",                  "BAT0",                1,   -1 },
    { battery_notify,       "",                     "BAT0",                1,   -1 }, // Internal battery notification
    { run_command,          " %s",                  bat1infocmd,           1,   -1 }, // ^ for the external battery
    { battery_remaining,    " %s",                  "BAT1",                1,   -1 },
    { battery_notify,       "",                     "BAT1",                1,   -1 }, // ^
    { cpu_perc,             COLOR(YELLOW)" 󰻠 %s%%",    NULL,                  1,   -1 }, // CPU usage percent
    { ram_perc,             COLOR(GREEN)"  %s%%",    NULL,                  1,   -1 }, // RAM usage percent
    { disk_perc,            COLOR(CYAN)" 󰋊 %s%%",    "/",                   1,   -1 }, // Total disk usage
    { vol_perc,             COLOR(BOLD_RED)"  %s",      "Master",              1,   -1 }, // Volume of the current sink
    { uptime,               COLOR(BOLD_BLUE)" 󰁝 %s",      NULL,                  1,   -1 }, // Total uptime of the system
    { wifi_perc,            COLOR(BOLD_MAGENTA)" 󰖩 %s%%",    "wlp3s0",              1,   -1 }, // WiFi strength
    { run_command,          COLOR(YELLOW)" 󰚰 %s",      updatescmd,            1,   -1 }, // Total number of updates for my packages
};

// #define MAXLEN CMDLEN * LEN(args)
