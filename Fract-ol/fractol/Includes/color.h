/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:37:53 by rcutte            #+#    #+#             */
/*   Updated: 2023/12/17 22:51:55 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

/**
 * * Color palette
 * [*] = last color and also color of the fractal set.
 * last because fractal set is out of the iterations range.
*/

// Gradient green to cyan
# define PALETTE_1_NAME "Green to Cyan"
# define PALETTE_1_ARRAY "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLM*"
# define PALETTE_1 "\"0 c #00FFFF\",\n\
\"1 c #00EEFF\",\n\
\"2 c #00DDFF\",\n\
\"3 c #00CCFF\",\n\
\"4 c #00BBFF\",\n\
\"5 c #00AAFF\",\n\
\"6 c #0099FF\",\n\
\"7 c #0088FF\",\n\
\"8 c #0077FF\",\n\
\"9 c #0066FF\",\n\
\"a c #0055FF\",\n\
\"b c #0044FF\",\n\
\"c c #0033FF\",\n\
\"d c #0022FF\",\n\
\"e c #0011FF\",\n\
\"f c #0000FF\",\n\
\"g c #FF00FF\",\n\
\"h c #EE00FF\",\n\
\"i c #DD00FF\",\n\
\"j c #CC00FF\",\n\
\"k c #BB00FF\",\n\
\"l c #AA00FF\",\n\
\"m c #9900FF\",\n\
\"n c #8800FF\",\n\
\"o c #7700FF\",\n\
\"p c #6600FF\",\n\
\"q c #5500FF\",\n\
\"r c #4400FF\",\n\
\"s c #3300FF\",\n\
\"t c #2200FF\",\n\
\"u c #1100FF\",\n\
\"v c #00FF00\",\n\
\"w c #00EE00\",\n\
\"x c #00DD00\",\n\
\"y c #00CC00\",\n\
\"z c #00BB00\",\n\
\"A c #00AA00\",\n\
\"B c #009900\",\n\
\"C c #008800\",\n\
\"D c #007700\",\n\
\"E c #006600\",\n\
\"F c #005500\",\n\
\"G c #004400\",\n\
\"H c #003300\",\n\
\"I c #002200\",\n\
\"J c #001100\",\n\
\"K c #FFFFFF\",\n\
\"L c #FFFFEE\",\n\
\"M c #FFFFDD\",\n\
\"* c #FFFFFF\",\n"

// Gradient rainbow
// Display  Green to Red in fractal set
# define PALETTE_2_NAME "Rainbow"
# define PALETTE_2_ARRAY "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLM*"
# define PALETTE_2 "\"0 c #FF0000\",\n\
\"1 c #FF1100\",\n\
\"2 c #FF2200\",\n\
\"3 c #FF3300\",\n\
\"4 c #FF4400\",\n\
\"5 c #FF5500\",\n\
\"6 c #FF6600\",\n\
\"7 c #FF7700\",\n\
\"8 c #FF8800\",\n\
\"9 c #FF9900\",\n\
\"a c #FFAA00\",\n\
\"b c #FFBB00\",\n\
\"c c #FFCC00\",\n\
\"d c #FFDD00\",\n\
\"e c #FFEE00\",\n\
\"f c #FFFF00\",\n\
\"g c #EEFF00\",\n\
\"h c #DDFF00\",\n\
\"i c #CCFF00\",\n\
\"j c #BBFF00\",\n\
\"k c #AAFF00\",\n\
\"l c #99FF00\",\n\
\"m c #88FF00\",\n\
\"n c #77FF00\",\n\
\"o c #66FF00\",\n\
\"p c #55FF00\",\n\
\"q c #44FF00\",\n\
\"r c #33FF00\",\n\
\"s c #22FF00\",\n\
\"t c #11FF00\",\n\
\"u c #00FF00\",\n\
\"v c #00FF11\",\n\
\"w c #00FF22\",\n\
\"x c #00FF33\",\n\
\"y c #00FF44\",\n\
\"z c #00FF55\",\n\
\"A c #00FF66\",\n\
\"B c #00FF77\",\n\
\"C c #00FF88\",\n\
\"D c #00FF99\",\n\
\"E c #00FFAA\",\n\
\"F c #00FFBB\",\n\
\"G c #00FFCC\",\n\
\"H c #00FFDD\",\n\
\"I c #00FFEE\",\n\
\"J c #00FFFF\",\n\
\"K c #00EEFF\",\n\
\"L c #00DDFF\",\n\
\"M c #00CCFF\",\n\
\"* c #FFFFFF\",\n"

// Gradient Purple, Yellow, Cyan
# define PALETTE_3_NAME "Purple, Yellow, Cyan"
# define PALETTE_3_ARRAY "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLM*"
# define PALETTE_3 "\"0 c #FF00FF\",\n\
\"1 c #FF11FF\",\n\
\"2 c #FF22FF\",\n\
\"3 c #FF33FF\",\n\
\"4 c #FF44FF\",\n\
\"5 c #FF55FF\",\n\
\"6 c #FF66FF\",\n\
\"7 c #FF77FF\",\n\
\"8 c #FF88FF\",\n\
\"9 c #FF99FF\",\n\
\"a c #FFAAFF\",\n\
\"b c #FFBBFF\",\n\
\"c c #FFCCFF\",\n\
\"d c #FFDDFF\",\n\
\"e c #FFEEFF\",\n\
\"f c #FFFFEE\",\n\
\"g c #FFFFDD\",\n\
\"h c #FFFFCC\",\n\
\"i c #FFFFBB\",\n\
\"j c #FFFFAA\",\n\
\"k c #FFFF99\",\n\
\"l c #FFFF88\",\n\
\"m c #FFFF77\",\n\
\"n c #FFFF66\",\n\
\"o c #FFFF55\",\n\
\"p c #FFFF44\",\n\
\"q c #FFFF33\",\n\
\"r c #FFFF22\",\n\
\"s c #FFFF11\",\n\
\"t c #FFFF00\",\n\
\"u c #FFEE00\",\n\
\"v c #FFDD00\",\n\
\"w c #FFCC00\",\n\
\"x c #FFBB00\",\n\
\"y c #FFAA00\",\n\
\"z c #FF9900\",\n\
\"A c #FF8800\",\n\
\"B c #FF7700\",\n\
\"C c #FF6600\",\n\
\"D c #FF5500\",\n\
\"E c #FF4400\",\n\
\"F c #FF3300\",\n\
\"G c #FF2200\",\n\
\"H c #FF1100\",\n\
\"I c #FF0000\",\n\
\"J c #EE0000\",\n\
\"K c #DD0000\",\n\
\"L c #CC0000\",\n\
\"M c #BB0000\",\n\
\"* c #FFFFFF\",\n"

// Color primary
# define C_BLACK 0x000000
# define C_WHITE 0xFFFFFF
# define C_RED 0xFF0000
# define C_GREEN 0x00FF00
# define C_BLUE 0x0000FF

// Color complement
# define C_YELLOW 0xFFFF00
# define C_PURPLE 0xFF00FF
# define C_CYAN 0x00FFFF
# define C_ORANGE 0xFFA500
# define C_PINK 0xFFC0CB
# define C_GREY 0x808080
# define C_BROWN 0xA52A2A
# define C_LIME 0x00FF00
# define C_MAROON 0x800000
# define C_NAVY 0x000080
# define C_OLIVE 0x808000
# define C_TEAL 0x008080

// ANSI Color
//Regular text
# define BLK "\e[0;30m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"

//Regular bold text
# define BBLK "\e[1;30m"
# define BRED "\e[1;31m"
# define BGRN "\e[1;32m"
# define BYEL "\e[1;33m"
# define BBLU "\e[1;34m"
# define BMAG "\e[1;35m"
# define BCYN "\e[1;36m"
# define BWHT "\e[1;37m"

//Regular underline text
# define UBLK "\e[4;30m"
# define URED "\e[4;31m"
# define UGRN "\e[4;32m"
# define UYEL "\e[4;33m"
# define UBLU "\e[4;34m"
# define UMAG "\e[4;35m"
# define UCYN "\e[4;36m"
# define UWHT "\e[4;37m"

//Regular background
# define BLKB "\e[40m"
# define REDB "\e[41m"
# define GRNB "\e[42m"
# define YELB "\e[43m"
# define BLUB "\e[44m"
# define MAGB "\e[45m"
# define CYNB "\e[46m"
# define WHTB "\e[47m"

//High intensty background 
# define BLKHB "\e[0;100m"
# define REDHB "\e[0;101m"
# define GRNHB "\e[0;102m"
# define YELHB "\e[0;103m"
# define BLUHB "\e[0;104m"
# define MAGHB "\e[0;105m"
# define CYNHB "\e[0;106m"
# define WHTHB "\e[0;107m"

//High intensty text
# define HBLK "\e[0;90m"
# define HRED "\e[0;91m"
# define HGRN "\e[0;92m"
# define HYEL "\e[0;93m"
# define HBLU "\e[0;94m"
# define HMAG "\e[0;95m"
# define HCYN "\e[0;96m"
# define HWHT "\e[0;97m"

//Bold high intensity text
# define BHBLK "\e[1;90m"
# define BHRED "\e[1;91m"
# define BHGRN "\e[1;92m"
# define BHYEL "\e[1;93m"
# define BHBLU "\e[1;94m"
# define BHMAG "\e[1;95m"
# define BHCYN "\e[1;96m"
# define BHWHT "\e[1;97m"

// ANSI Reset
# define RESET "\033[0m"

#endif