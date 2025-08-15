/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
static int fuzzy  = 1;                      /* -F  option; if 0, dmenu doesn't use fuzzy matching */
static int centered = 0;                    /* -c option; centers dmenu on screen */
static int left = 0;                        /* -L option; postions dmenu on the left side of the screen. Requires dmenu to be centered*/
static int right = 0;                        /* -R option; postions dmenu on the left side of the screen. Requires dmenu to be centered*/
static int gap = 8;                         /* The number of pixels from the side of the screen when either on the left or right */
static char passwordch = '*';               /* The character to be used in place of the text when password is enabled */
static int min_width = 50;                    /* minimum width when centered */
static const float menu_height_ratio = 4.0f;  /* This is the ratio used in the original calculation */
static const unsigned int alpha = 0xb2;     /* 70% Amount of opacity. 0xff is opaque             */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[]          = { "caskaydia cove nfm:size=12" };
static const char *prompt           = NULL;      /* -p  option; prompt to the left of input field */
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";

// Catppuccin-Mocha
static const char col_mauve[]       = "#cba6f7";

// everforest
static const char ef_col_purple[]   = "#D699B6";
static const char ef_col_status3[]  = "#E67E80";
static const char ef_col_aqua[]     = "#83C092";

static const char ef_col_bg0[]      = "#272e33";
static const char ef_col_bg1[]      = "#2e383c";
static const char ef_col_bg2[]      = "#374145";
static const char ef_col_bg3[]      = "#414b50";
static const char ef_col_bg4[]      = "#495156";
static const char ef_col_bg5[]      = "#4f5b58";
static const char ef_col_fg[]       = "#d3c6aa";

// Gruvbox Material
static const char gbm_status3[]     = "#504945";
static const char gbm_purple[]      = "#D3869b";
static const char gbm_aqua[]        = "#89b482";
static const char gbm_red[]         = "#ea6962";
static const char gbm_blue[]        = "#7daea3";
static const char gbm_green[]       = "#a9b665";
static const char gbm_orange[]      = "#e78a4e";
static const char gbm_yellow[]      = "#d8a657";
static const char gbm_bg0[]         = "#1d2021";
static const char gbm_bg1[]         = "#282828";
static const char gbm_bg2[]         = "#282828";
static const char gbm_bg3[]         = "#3c3836";
static const char gbm_bg4[]         = "#3c3836";
static const char gbm_bg5[]         = "#504945";
static const char gbm_fg[]          = "#d4be98";

// My ColorScheme
static const char mcs_black[]         = "#2f1e33"; // Color 0
static const char mcs_red[]           = "#ce808b"; // Color 1
static const char mcs_green[]         = "#80cea3"; // Color 2
static const char mcs_yellow[]        = "#cec580"; // Color 3
static const char mcs_blue[]          = "#809ace"; // Color 4
static const char mcs_magenta[]       = "#c080ce"; // Color 5
static const char mcs_cyan[]          = "#80cecd"; // Color 6
static const char mcs_white[]         = "#d7b1df"; // Color 7
static const char mcs_bold_black[]    = "#9c7da3"; // Color 8
static const char mcs_bold_red[]      = "#f48f9d"; // Color 9
static const char mcs_bold_green[]    = "#9ff5c0"; // Color 10
static const char mcs_bold_yellow[]   = "#f5eb9f"; // Color 11
static const char mcs_bold_blue[]     = "#9fb5f5"; // Color 12
static const char mcs_bold_magenta[]  = "#eb9ff5"; // Color 13
static const char mcs_bold_cyan[]     = "#9ff5f5"; // Color 14
static const char mcs_bold_white[]    = "#ffdcff"; // Color 15
static const char mcs_bg[]            = "#2f1e33";
static const char mcs_fg[]            = "#d7b1df";

static const char *colors[][2]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { mcs_fg, mcs_bg },
	[SchemeSel]  = { mcs_green, mcs_bg },
	[SchemeOut]  = { "#000000", "#00ffff" },
 	[SchemeSelHighlight] = { mcs_blue, mcs_bg },
 	[SchemeNormHighlight] = { mcs_blue, mcs_bg },
    [SchemeBorder] = { mcs_magenta, mcs_magenta },
    [SchemeInput] = { mcs_fg, mcs_bg },
    [SchemePrompt] = { mcs_bg, mcs_magenta },
};

// #include "/home/magic/.cache/wal/colors-wal-dmenu.h"

static const unsigned int alphas[SchemeLast][2] = {
	[SchemeNorm] = { OPAQUE, alpha },
	[SchemeSel] = { OPAQUE, alpha },
	[SchemeOut] = { OPAQUE, alpha },
	[SchemeSelHighlight] = { OPAQUE, alpha },
	[SchemeNormHighlight] = { OPAQUE, alpha },
	[SchemeBorder] = { OPAQUE, alpha },
	[SchemeInput] = { OPAQUE, alpha },
	[SchemePrompt] = { OPAQUE, alpha },
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 5;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

/* Size of the window border */
static unsigned int border_width = 2;

