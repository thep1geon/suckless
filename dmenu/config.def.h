/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
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
static const char col_purple[]      = "#D3869b";
static const char col_status3[]     = "#504945";
static const char col_aqua[]        = "#89b482";

static const char col_bg0[]         = "#1d2021";
static const char col_bg1[]         = "#282828";
static const char col_bg2[]         = "#282828";
static const char col_bg3[]         = "#3c3836";
static const char col_bg4[]         = "#3c3836";
static const char col_bg5[]         = "#504945";
static const char col_fg[]          = "#d4be98";
static const char *colors[][2]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_fg, col_bg1 },
	[SchemeSel]  = { col_bg5, col_aqua },
	[SchemeOut]  = { "#000000", "#00ffff" },
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";
