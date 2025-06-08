/* user and group to drop privileges to */
static const char *user  = "magic";
static const char *group = "magic";

static const float textsize        =    16.0;
static const char* textfamily      =    "Caskaydia Cove NFM";
static const double textcolorred   =    212;
static const double textcolorgreen =    190;
static const double textcolorblue  =    152;

static const char* background_image = "/home/magic/Pictures/nemo-collage.png";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "#3c3836",     /* after initialization */
	[INPUT] =  "#89b482",   /* during input */
	[FAILED] = "#ea6962",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 0; // bool
