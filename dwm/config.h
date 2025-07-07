/* See LICENSE file for copyright and license details. */
#ifndef NULL
    #define NULL (void*)(0)
#endif

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 5;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 5;       /* vert inner gap between windows */
static const unsigned int gappoh    = 5;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 5;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int vertpad            = 5;        /* vertical padding of bar */
static const int sidepad            = 5;        /* horizontal padding of bar */
static const char *fonts[]          = { "caskaydia cove nfm:size=12" };
static const char dmenufont[]       = "caskaydia cove nfm:size=12";

static int show_all_tags            = 0;        /* show all tags, or only tags which windows open*/

/* Defaults */
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";

/* Catppuccin-Mocha */
static const char col_mauve[]       = "#cba6f7";

/* Everforest */
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

/* Gruvbox-Material */
static const char col_status3[]     = "#504945";
static const char col_purple[]      = "#d3869b";
static const char col_aqua[]        = "#89b482";
static const char col_red[]         = "#ea6962";
static const char col_blue[]        = "#7daea3";
static const char col_green[]       = "#a9b665";
static const char col_orange[]      = "#e78a4e";
static const char col_yellow[]      = "#d8a657";

static const char col_bg0[]         = "#1d2021";
static const char col_bg1[]         = "#282828";
static const char col_bg2[]         = "#282828";
static const char col_bg3[]         = "#3c3836";
static const char col_bg4[]         = "#3c3836";
static const char col_bg5[]         = "#504945";
static const char col_fg[]          = "#d4be98";

static const char *colors[][3]      = {
    /* fg            bg          border */
    { col_blue,     col_bg0,    col_blue },  /* Tag 1 */
    { col_purple,   col_bg0,    col_purple },/* Tag 2 */
    { col_aqua,     col_bg0,    col_aqua },  /* Tag 3 */
    { col_red,      col_bg0,    col_red },  // Tag 4
    { col_green ,   col_bg0,    col_green },  // Tag 5
    { col_orange,   col_bg0,    col_orange },  // Tag 6
    { col_yellow,   col_bg0,    col_yellow },  // Tag 7
    { col_blue,     col_bg0,    col_red },  // Tag 8
    { col_purple,   col_bg0,    col_yellow },  // Tag 9
    { col_fg,       col_bg0,    col_bg0 },  // SchemeNorm
    { col_aqua,     col_bg0,    col_aqua },  // SchemeSel
};

// #include "/home/magic/.cache/wal/colors-wal-dwm.h"

static const unsigned int SchemeNorm = LENGTH(colors) - 2;
static const unsigned int SchemeSel = LENGTH(colors) - 1;

static const unsigned int baralpha = 0xb2; // 70% | 0xd0 defualt
static const unsigned int borderalpha = OPAQUE;

static const unsigned int alphas[][3]      = {
    // fg        bg        border
    { OPAQUE,   baralpha, borderalpha }, // Tag 1
    { OPAQUE,   baralpha, borderalpha }, // Tag 2
    { OPAQUE,   baralpha, borderalpha }, // Tag 3
    { OPAQUE,   baralpha, borderalpha }, // Tag 4
    { OPAQUE,   baralpha, borderalpha }, // Tag 5
    { OPAQUE,   baralpha, borderalpha }, // Tag 6
    { OPAQUE,   baralpha, borderalpha }, // Tag 7
    { OPAQUE,   baralpha, borderalpha }, // Tag 8
    { OPAQUE,   baralpha, borderalpha }, // Tag 9
    { OPAQUE,   baralpha, borderalpha }, // SchemeNorm
    { OPAQUE,   baralpha, borderalpha }, // SchemeSel
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
    */
    /* class      instance    title       tags mask     isfloating   monitor */
    { "Blueman",        NULL,       NULL,       0,            1,           -1 },
    { "Thunar",         NULL,       NULL,       0,            1,           -1 },
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
#define ALT Mod1Mask // Alt Key
#define WIN Mod4Mask // Window's key
#define MODKEY WIN
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] =                 { "dmenu_run", "-c", "-R", "-m", dmenumon, "-fn", dmenufont, "-l", "15", "-p", "Application Runner:", NULL };

static const char *termcmd[]  =                 { "st", NULL };

static const char* firefoxcmd[] =               { "firefox", NULL};

static const char* volmutecmd[] =               { "/home/magic/suckless/scripts/volume.sh", "mute", NULL };
static const char* volupcmd[] =                 { "/home/magic/suckless/scripts/volume.sh", "up", NULL };
static const char* voldowncmd[] =               { "/home/magic/suckless/scripts/volume.sh", "down", NULL };

static const char* brightupcmd[] =              { "/home/magic/suckless/scripts/brightness.sh", "up", NULL};
static const char* brightdowncmd[] =              { "/home/magic/suckless/scripts/brightness.sh", "down", NULL};

static const char* nextcmd[] =                  { "playerctl", "next", NULL };
static const char* prevcmd[] =                  { "playerctl", "previous", NULL };
static const char* toggleplaycmd[] =            { "playerctl", "play-pause", NULL };

static const char* bluetoothcmd[] =             { "blueman-manager", NULL };

static const char* boomercmd[] =                { "boomer", NULL };

static const char* sysmenucmd[] =               { "/home/magic/suckless/scripts/sys.sh", NULL};
static const char* whatsplayingcmd[] =          { "/home/magic/suckless/scripts/whatsplaying.sh", NULL};
static const char* batteryremainingcmd[] =      { "/home/magic/suckless/scripts/battery-remaining.sh", NULL};
static const char* screenshotcmd[] =            { "/home/magic/suckless/scripts/screenshot.sh", NULL };
static const char* displayswitchercmd[] =       { "/home/magic/suckless/scripts/displayswitcher.sh", NULL };
static const char* wifimenucmd[] =              { "/home/magic/suckless/scripts/wifimenu.sh", NULL };
static const char* definecmd[] =                { "/home/magic/suckless/scripts/define.sh", NULL };
static const char* wallpapercmd[] =             { "/home/magic/suckless/scripts/wallpaper.sh", NULL };
// static const char* timercmd[] =                 { "/home/magic/suckless/scripts/timer.sh", NULL };

// keymaps
static const Key keys[] = {
    /* modifier                     key                       function        argument */
    { MODKEY|ControlMask,           XK_s,                     spawn,          { .v = screenshotcmd} },
    { MODKEY,                       XK_Print,                 spawn,          { .v = boomercmd} },
    { 0,                            XF86XK_AudioMute,         spawn,          {.v = volmutecmd} },
    { 0,                            XF86XK_AudioLowerVolume,  spawn,          {.v = voldowncmd} },
    { 0,                            XF86XK_AudioRaiseVolume,  spawn,          {.v = volupcmd} },
    { 0,                            XF86XK_MonBrightnessDown, spawn,          {.v = brightdowncmd} },
    { 0,                            XF86XK_MonBrightnessUp,   spawn,          {.v = brightupcmd} },
    { MODKEY,                       XK_plus,                  spawn,          {.v = volupcmd } },
    { MODKEY,                       XK_minus,                 spawn,          {.v = voldowncmd } },
    { MODKEY,                       XK_bracketleft,           spawn,          {.v = prevcmd } },
    { MODKEY,                       XK_bracketright,          spawn,          {.v = nextcmd } },
    { MODKEY,                       XK_Up,                    spawn,          {.v = volupcmd } },
    { MODKEY,                       XK_Down,                  spawn,          {.v = voldowncmd } },
    { MODKEY,                       XK_Left,                  spawn,          {.v = prevcmd } },
    { MODKEY,                       XK_Right,                 spawn,          {.v = nextcmd } },
    { MODKEY,                       XK_space,                 spawn,          {.v = toggleplaycmd} },
    { MODKEY,                       XK_d,                     spawn,          {.v = dmenucmd } },
    { MODKEY,                       XK_Return,                spawn,          {.v = termcmd } },
    { MODKEY,                       XK_p,                     spawn,          {.v = sysmenucmd } },
    { MODKEY|ShiftMask,             XK_f,                     spawn,          {.v = firefoxcmd } },
    { MODKEY|ShiftMask,             XK_b,                     spawn,          {.v = bluetoothcmd } },
    { MODKEY,                       XK_s,                     spawn,          {.v = displayswitchercmd } },
    { MODKEY,                       XK_w,                     spawn,          {.v = whatsplayingcmd } },
    { MODKEY|ShiftMask,             XK_w,                     spawn,          {.v = wifimenucmd } },
    { MODKEY,                       XK_r,                     spawn,          {.v = batteryremainingcmd } },
    { MODKEY|ShiftMask,             XK_d,                     spawn,          {.v = definecmd } },
    { MODKEY|ControlMask,           XK_b,                     spawn,          {.v = wallpapercmd } },
    // { MODKEY|ShiftMask,             XK_t,                     spawn,          {.v = timercmd } },
    { MODKEY,                       XK_b,                     togglebar,      {0} },
    { MODKEY|ShiftMask,             XK_s,                     toggletags,     {0} },
    { MODKEY,                       XK_j,                     focusstack,     {.i = +1 } },
    { MODKEY,                       XK_k,                     focusstack,     {.i = -1 } },
    { MODKEY|ShiftMask,             XK_j,                     movestack,      {.i = +1} },
    { MODKEY|ShiftMask,             XK_k,                     movestack,      {.i = -1} },
    { MODKEY|ShiftMask|ALT,         XK_d,                     incnmaster,     {.i = -1 } }, /* I dont even use these to be honest */
    { MODKEY|ShiftMask|ALT,         XK_i,                     incnmaster,     {.i = +1 } }, /* ^ ^ ^ ^ */
    { MODKEY,                       XK_h,                     setmfact,       {.f = -0.05} },
    { MODKEY,                       XK_l,                     setmfact,       {.f = +0.05} },
    { MODKEY|ShiftMask|ALT,         XK_Return,                zoom,           {0} },
    { MODKEY,                       XK_Tab,                   view,           {0} },
    { MODKEY|ShiftMask,             XK_q,                     killclient,     {0} },
    { MODKEY,                       XK_t,                     setlayout,      {.v = &layouts[0]} },
    { MODKEY,                       XK_f,                     setlayout,      {.v = &layouts[1]} },
    { MODKEY|ShiftMask,             XK_m,                     setlayout,      {.v = &layouts[2]} },
    { MODKEY|ControlMask,           XK_space,                 setlayout,      {0} },
    { MODKEY|ShiftMask,             XK_space,                 togglefloating, {0} },
    { MODKEY,                       XK_0,                     view,           {.ui = ~0 } },
    { MODKEY|ShiftMask,             XK_0,                     tag,            {.ui = ~0 } },
    { MODKEY,                       XK_comma,                 focusmon,       {.i = -1 } },
    { MODKEY,                       XK_period,                focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,             XK_Tab,                   focusmon,       {.i = +1 } },
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

static const char* const commands[] = {
    "xset s 300",
    "vol",
    "xss-lock -- slock",
    "~/.fehbg", /* Set the last selected wallpaper */
    "picom -b",
    "pulseaudio --start",
    "light",
    "xrandr --output HDMI-2 --auto --rotate normal --left-of eDP-1",
    "killall slstatus",
    "slstatus",
};
