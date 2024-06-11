/* See LICENSE file for copyright and license details. */
#ifndef NULL
    #define NULL (void*)(0)
#endif

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "caskaydia cove nfm:size=12" };
static const char dmenufont[]       = "caskaydia cove nfm:size=12";

// Defaults
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";

// catppuccin-mocha
static const char col_mauve[]       = "#cba6f7";

// everforest
static const char col_purple[]      = "#D699B6";
static const char col_status3[]     = "#E67E80";
static const char col_aqua[]        = "#83C092";

static const char col_bg0[]         = "#272e33";
static const char col_bg1[]         = "#2e383c";
static const char col_bg2[]         = "#374145";
static const char col_bg3[]         = "#414b50";
static const char col_bg4[]         = "#495156";
static const char col_bg5[]         = "#4f5b58";
static const char col_fg[]          = "#d3c6aa";

static const char *colors[][3]      = {
    /*               fg         bg         border   */
    [SchemeNorm] = { col_fg, col_bg0, col_bg1 },
    [SchemeSel]  = { col_bg5, col_aqua,  col_aqua  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
    */
    /* class      instance    title       tags mask     isfloating   monitor */
    { "Blueman-Manager", NULL,       NULL,       0,            1,           -1 },
    { "Gimp",            NULL,       NULL,       0,            1,           -1 },
    { "Firefox",         NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact        = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster        = 1;    /* number of clients in master area */
static const int resizehints    = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[]=",      tile },    /* first entry is default */
    { "><>",      NULL },    /* no layout function means floating behavior */
    { "[M]",      monocle },
};

#include <X11/XF86keysym.h>
#include <X11/keysym.h>

/* key definitions */
#define MODKEY Mod4Mask // Window's key
#define TAGKEYS(KEY,TAG) \
{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] =       { "dmenu_run", "-i", "-m", dmenumon, "-fn", dmenufont, "-nb", col_bg0, "-nf", col_fg, "-sb", col_aqua, "-sf", col_bg5, NULL };
static const char *termcmd[]  =       { "kitty", NULL };
static const char* wdtermcmd[] =      { "wdterm", NULL };

static const char* powermenucmd[] =   { "/home/magic/suckless/dmenu/scripts/power.sh", NULL};
static const char* firefoxcmd[] =     { "firefox", NULL};

static const char* volmutecmd[] =     { "pactl", "set-sink-mute",   "@DEFAULT_SINK@", "toggle", NULL };
static const char* volupcmd[] =       { "pactl", "set-sink-volume", "@DEFAULT_SINK@", "+5%",    NULL };
static const char* voldowncmd[] =     { "pactl", "set-sink-volume", "@DEFAULT_SINK@", "-5%",    NULL };

static const char* brightupcmd[] =    { "light", "-A", "5", NULL };
static const char* brightdowncmd[] =  { "light", "-U", "5", NULL };

static const char* nextcmd[] =        { "playerctl", "next", NULL };
static const char* prevcmd[] =        { "playerctl", "previous", NULL };
static const char* toggleplaycmd[] =  { "playerctl", "play-pause", NULL };

static const char* screenshotcmd[] =  { "scrot", "-z", "-F", "/home/magic/Pictures/Screenshots/%b-%d-%H:%M.png", NULL };

static const char* bluetoothcmd[] =   { "blueman-manager", NULL };

static const char* boomercmd[] =      { "boomer", NULL };

static const Key keys[] = {
    /* modifier                     key                       function        argument */
    { 0,                            XK_Print,                 spawn,          { .v = screenshotcmd} },
    { MODKEY,                       XK_Print,                 spawn,          { .v = boomercmd} },
    { 0,                            XF86XK_AudioMute,         spawn,          {.v = volmutecmd} },
    { 0,                            XF86XK_AudioLowerVolume,  spawn,          {.v = voldowncmd} },
    { 0,                            XF86XK_AudioRaiseVolume,  spawn,          {.v = volupcmd} },
    { 0,                            XF86XK_MonBrightnessDown, spawn,          {.v = brightdowncmd} },
    { 0,                            XF86XK_MonBrightnessUp,   spawn,          {.v = brightupcmd} },
    { MODKEY,                       XK_bracketleft,           spawn,          {.v = prevcmd } },
    { MODKEY,                       XK_bracketright,          spawn,          {.v = nextcmd } },
    { MODKEY,                       XK_Left,                  spawn,          {.v = prevcmd } },
    { MODKEY,                       XK_Right,                 spawn,          {.v = nextcmd } },
    { MODKEY,                       XK_space,                 spawn,          {.v = toggleplaycmd} },
    { MODKEY,                       XK_d,                     spawn,          {.v = dmenucmd } },
    { MODKEY,                       XK_Return,                spawn,          {.v = termcmd } },
    { MODKEY|ShiftMask,             XK_Return,                spawn,          {.v = wdtermcmd } },
    { MODKEY,                       XK_p,                     spawn,          {.v = powermenucmd } },
    { MODKEY|ShiftMask,             XK_f,                     spawn,          {.v = firefoxcmd } },
    { MODKEY|ShiftMask,             XK_b,                     spawn,          {.v = bluetoothcmd } },
    { MODKEY,                       XK_b,                     togglebar,      {0} },
    { MODKEY,                       XK_j,                     focusstack,     {.i = +1 } },
    { MODKEY,                       XK_k,                     focusstack,     {.i = -1 } },
    { MODKEY|ShiftMask,             XK_j,                     movestack,      {.i = +1} },
    { MODKEY|ShiftMask,             XK_k,                     movestack,      {.i = -1} },
    { MODKEY|ShiftMask,             XK_i,                     incnmaster,     {.i = +1 } },
    { MODKEY|ShiftMask,             XK_d,                     incnmaster,     {.i = -1 } },
    { MODKEY,                       XK_h,                     setmfact,       {.f = -0.05} },
    { MODKEY,                       XK_l,                     setmfact,       {.f = +0.05} },
    { MODKEY|ShiftMask,             XK_Return,                zoom,           {0} },
    { MODKEY,                       XK_Tab,                   view,           {0} },
    { MODKEY|ShiftMask,             XK_q,                     killclient,     {0} },
    { MODKEY,                       XK_t,                     setlayout,      {.v = &layouts[0]} },
    { MODKEY,                       XK_f,                     setlayout,      {.v = &layouts[1]} },
    { MODKEY,                       XK_m,                     setlayout,      {.v = &layouts[2]} },
    { MODKEY|ControlMask,           XK_space,                 setlayout,      {0} },
    { MODKEY|ShiftMask,             XK_space,                 togglefloating, {0} },
    { MODKEY,                       XK_0,                     view,           {.ui = ~0 } },
    { MODKEY|ShiftMask,             XK_0,                     tag,            {.ui = ~0 } },
    { MODKEY,                       XK_comma,                 focusmon,       {.i = -1 } },
    { MODKEY,                       XK_period,                focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,             XK_comma,                 tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask,             XK_period,                tagmon,         {.i = +1 } },
    { MODKEY|Mod1Mask,              XK_h,                     incrgaps,       {.i = +1 } },
    { MODKEY|Mod1Mask,              XK_l,                     incrgaps,       {.i = -1 } },
    { MODKEY|Mod1Mask|ShiftMask,    XK_h,                     incrogaps,      {.i = +1 } },
    { MODKEY|Mod1Mask|ShiftMask,    XK_l,                     incrogaps,      {.i = -1 } },
    { MODKEY|Mod1Mask|ControlMask,  XK_h,                     incrigaps,      {.i = +1 } },
    { MODKEY|Mod1Mask|ControlMask,  XK_l,                     incrigaps,      {.i = -1 } },
    { MODKEY|Mod1Mask,              XK_0,                     togglegaps,     {0} },
    { MODKEY|Mod1Mask|ShiftMask,    XK_0,                     defaultgaps,    {0} },
    { MODKEY,                       XK_y,                     incrihgaps,     {.i = +1 } },
    { MODKEY,                       XK_o,                     incrihgaps,     {.i = -1 } },
    { MODKEY|ControlMask,           XK_y,                     incrivgaps,     {.i = +1 } },
    { MODKEY|ControlMask,           XK_o,                     incrivgaps,     {.i = -1 } },
    { MODKEY|Mod1Mask,              XK_y,                     incrohgaps,     {.i = +1 } },
    { MODKEY|Mod1Mask,              XK_o,                     incrohgaps,     {.i = -1 } },
    { MODKEY|ShiftMask,             XK_y,                     incrovgaps,     {.i = +1 } },
    { MODKEY|ShiftMask,             XK_o,                     incrovgaps,     {.i = -1 } },
    TAGKEYS(                        XK_1,                                     0)
    TAGKEYS(                        XK_2,                                     1)
    TAGKEYS(                        XK_3,                                     2)
    TAGKEYS(                        XK_4,                                     3)
    TAGKEYS(                        XK_5,                                     4)
    TAGKEYS(                        XK_6,                                     5)
    TAGKEYS(                        XK_7,                                     6)
    TAGKEYS(                        XK_8,                                     7)
    TAGKEYS(                        XK_9,                                     8)
    { MODKEY|ControlMask,           XK_q,                     quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
    { ClkWinTitle,          0,              Button2,        zoom,           {0} },
    { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

// Commands to be run when starting dwm
static char* commands[] = {
    "xset s 300",
    "xss-lock -- slock",
    "slstatus",
    "feh --bg-fill /home/magic/Pictures/a1.png",
    "picom -b",
};