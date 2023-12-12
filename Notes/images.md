# Images

## Format

### XPM

XPM (X PixMap) is an image file format used by the X Window System, created in 1989. It is primarily intended for creating icon pixmaps and supports transparent pixels. XPM files are plain text files in the XPM2 format or of a C programming language syntax, which can be included in a C program file.

The XPM file format uses C syntax in order for these to be integrated in C and C++ programs. It consists of the following six different sections.

- `<Values>`
- `<Colors>`
- `<Pixels>`
- `<Extensions>`

The sections are actually an array of strings as follow.

```c
/* XPM */
static char *<variable_name>[] = {
  <Values>
  <Colors>
  <Pixels>
  <Extensions>
};
```

`<Values>` - This section is a string that contains four or six integers that are in base 10 and correspond to the:

- pixmap width and height
- number of Colors
- number of characters per pixel
- optional hotspot coordinates and XPMEXT tag

`<Colors>` - This section contains as many strings as there are colors. Each string is as follows:

- `<chars> {<key> <color>}+`

`<Pixels>` - This section is composed of strings and `*<chars_per_pixel>` characters. Every `<chars_per_pixel>` length string should be one of the previously defined groups in the section.

`<Extension>` - The extension section must be labeled, if it is not empty, in the section. It may consist of several subsections which may be of the following two types:

- one stand alone string composed as follows: XPMEXT
- or a block composed by several strings:XPMEXT

Examples:

```c
/* XPM */
static char * blarg_xpm[] = {
"16 7 2 1",
"* c #000000",
". c #ffffff",
"**..*...........",
"*.*.*...........",
"**..*..**.**..**",
"*.*.*.*.*.*..*.*",
"**..*..**.*...**",
"...............*",
".............**."
};
```

![xmp image demo](https://upload.wikimedia.org/wikipedia/commons/4/43/Blarg.xpm.png)

#### Integration in Code

XPM2 format is a plain text format, while the XPM3 format is a C programming language syntax.

With MinilibX - Use XPM3 inside a plain text to.

#### Version

XPM2 - Plain text

```xpm2
! XPM2
48 4 2 1
a c #FFFFFF
b c #000000
abaabaababaaabaabababaabaabaababaabaaababaabaaab
abaabaababaaabaabababaabaabaababaabaaababaabaaab
abaabaababaaabaabababaabaabaababaabaaababaabaaab
abaabaababaaabaabababaabaabaababaabaaababaabaaab
```

XPM3 - Inside C files

```c
/* XPM */
static char * XFACE[] = {
"48 4 2 1",
"a c #ffffff",
"b c #000000",
"abaabaababaaabaabababaabaabaababaabaaababaabaaab",
"abaabaababaaabaabababaabaabaababaabaaababaabaaab",
"abaabaababaaabaabababaabaabaababaabaaababaabaaab",
"abaabaababaaabaabababaabaabaababaabaaababaabaaab"
};
```
