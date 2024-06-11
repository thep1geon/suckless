/* user and group to drop privileges to */
static const char *user  = "magic";
static const char *group = "magic";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "#414b50",     /* after initialization */
	[INPUT] =  "#83c092",   /* during input */
	[FAILED] = "#e67e80",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 0; // bool
