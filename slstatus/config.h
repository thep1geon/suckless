/* See LICENSE file for copyright and license details. */

/* interval between updates (in ms) */
const unsigned int interval = 1000;

/* text to show if no value can be retrieved */
static const char unknown_str[] = "n/a";

/* maximum output string length */
#define MAXLEN 2048

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

#define COLOR(c) "^c" c  "^"

static const struct arg args[] = {
    /* function format              argument */
    { datetime,             "^c#ea6962^ %s",       "%a, %b %d - %I:%M%p" }, // Date and time
    { run_command,          "^c#89b482^ 󰝚 %s",      "~/suckless/scripts/status-playbackinfo.sh" }, // The currently playing media
    { run_command,          "^c#d3869b^ %s",       "~/suckless/scripts/status-battery.sh BAT0"      }, // Internal battery info
    { battery_remaining,    " %s",                   "BAT0"  },
    { battery_notify,       "",                     "BAT0"      }, // Internal battery notification
    { run_command,          " %s",                  "~/suckless/scripts/status-battery.sh BAT1"      }, // ^ for the external battery
    { battery_remaining,    " %s",                   "BAT1"  },
    { battery_notify,       "",                     "BAT1"      }, // ^
    { cpu_perc,             "^c#d8a657^ 󰻠 %s%%",    NULL        }, // CPU usage percent
    { ram_perc,             "^c#a9b665^  %s%%",    NULL        }, // RAM usage percent
    { disk_perc,            "^c#89b482^ 󰋊 %s%%",    "/"         }, // Total disk usage
    { vol_perc,             "^c#ea6962^  %s",      "Master"    }, // Volume of the current sink
    { uptime,               "^c#7daea3^ 󰁝 %s",      NULL        }, // Total uptime of the system
    { wifi_perc,            "^c#d3869b^ 󰖩 %s%%",    "wlp3s0"    }, // WiFi strength
    { run_command,          "^c#d8a657^ 󰚰 %s",      "~/suckless/scripts/status-updates.sh"    }, // Total number of updates for my packages
};

// static const struct arg args[] = {
//     /* function format              argument */
//     { datetime,             COLOR(col1)" %s",       "%a, %b %d - %I:%M%p" }, // Date and time
//     { run_command,          COLOR(col5)" 󰝚 %s",      "~/suckless/scripts/status-playbackinfo.sh" }, // The currently playing media
//     { run_command,          COLOR(col2)" %s",       "~/suckless/scripts/status-battery.sh BAT0"      }, // Internal battery info
//     { battery_remaining,    " %s",                   "BAT0"  },
//     { battery_notify,       "",                     "BAT0"      }, // Internal battery notification
//     { run_command,          " %s",                  "~/suckless/scripts/status-battery.sh BAT1"      }, // ^ for the external battery
//     { battery_remaining,    " %s",                   "BAT1"  },
//     { battery_notify,       "",                     "BAT1"      }, // ^
//     { cpu_perc,             COLOR(col3)" 󰻠 %s%%",    NULL        }, // CPU usage percent
//     { ram_perc,             COLOR(col7)"  %s%%",    NULL        }, // RAM usage percent
//     { disk_perc,            COLOR(col4)" 󰋊 %s%%",    "/"         }, // Total disk usage
//     { vol_perc,             COLOR(col6)"  %s",      "Master"    }, // Volume of the current sink
//     { uptime,               COLOR(col11)" 󰁝 %s",      NULL        }, // Total uptime of the system
//     { wifi_perc,            COLOR(col8)" 󰖩 %s%%",    "wlp3s0"    }, // WiFi strength
//     { run_command,          COLOR(col14)" 󰚰 %s",      "~/suckless/scripts/status-updates.sh"    }, // Total number of updates for my packages
// };
