/* user and group to drop privileges to */
static const char *user  = "magic";
static const char *group = "magic";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "#3c3836",     /* after initialization */
	[INPUT] =  "#89b482",   /* during input */
	[FAILED] = "#ea6962",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 0; // bool
