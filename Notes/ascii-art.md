# Ascii Art

## Usefull websites

- 🔗 [Ascii Drawing](https://asciiflow.com/#/)

## Unicode

- 🔗 [List of Unicodes](https://symbl.cc/en/unicode/table/)

### Box Drawing

- :toolbox: [Unicode list for Bow Drawing](https://symbl.cc/en/unicode/blocks/box-drawing/)

| Character | Description |
| --------- | ----------- |
| `─`       | Horizontal  |
| `│`       | Vertical    |
| `┌`       | Top left corner |
| `┐`       | Top right corner |
| `└`       | Bottom left corner |
| `┘`       | Bottom right corner |
| `├`       | Left "T" |
| `┤`       | Right "T" |
| `┬`       | Top "T" |
| `┴`       | Bottom "T" |
| `┼`       | Cross |
| `╭`       | Top left curved corner |
| `╮`       | Top right curved corner |
| `╯`       | Bottom right curved corner |
| `╰`       | Bottom left curved corner |

## ANSI Escape Codes

The format is `\033[<attribute>;<foreground>;<background>m`.

The `<attribute>` can be `0` for reset, `1` for bold, `4` for underline, `7` for inverse, `8` for concealed, and `9` for strikethrough.

| Style         | Code     | Visual Representation |
| ------------- | -------- | --------------------- |
| Bold          | `1`      | <span style="font-weight: bold;">Bold</span> |
| Faint         | `2`      | <span style="opacity: 0.5;">Faint</span> |
| Italic        | `3`      | <span style="font-style: italic;">Italic</span> |
| Underlined    | `4`      | <span style="text-decoration: underline;">Underlined</span> |
| Inverse       | `7`      | <span style="background-color: black; color: white;">Inverse</span> |
| Strikethrough | `9`      | <span style="text-decoration: line-through;">Strikethrough</span> |

The `<foreground>` color codes are from `30` to `37` for standard colors, and `90` to `97` for bright colors.

| Color         | Standard Code | Bright Code | Visual Representation |
| ------------- | ------------- | ----------- | --------------------- |
| Black         | `30`          | `90`        | <span style="color: #000000;">Black</span> / <span style="color: #808080;">Bright Black</span> |
| Red           | `31`          | `91`        | <span style="color: #800000;">Red</span> / <span style="color: #ff0000;">Bright Red</span> |
| Green         | `32`          | `92`        | <span style="color: #008000;">Green</span> / <span style="color: #00ff00;">Bright Green</span> |
| Yellow        | `33`          | `93`        | <span style="color: #808000;">Yellow</span> / <span style="color: #ffff00;">Bright Yellow</span> |
| Blue          | `34`          | `94`        | <span style="color: #000080;">Blue</span> / <span style="color: #0000ff;">Bright Blue</span> |
| Magenta       | `35`          | `95`        | <span style="color: #800080;">Magenta</span> / <span style="color: #ff00ff;">Bright Magenta</span> |
| Cyan          | `36`          | `96`        | <span style="color: #008080;">Cyan</span> / <span style="color: #00ffff;">Bright Cyan</span> |
| White         | `37`          | `97`        | <span style="color: #c0c0c0;">White</span> / <span style="color: #ffffff;">Bright White</span> |

The `<background>` color codes are from `40` to `47` for standard colors, and `100` to `107` for bright colors.

| Color         | Standard Code | Bright Code | Visual Representation |
| ------------- | ------------- | ----------- | --------------------- |
| Black         | `40`          | `100`       | <span style="background-color: #000000; color: #ffffff;">Black</span> / <span style="background-color: #808080; color: #ffffff;">Bright Black</span> |
| Red           | `41`          | `101`       | <span style="background-color: #800000; color: #ffffff;">Red</span> / <span style="background-color: #ff0000; color: #ffffff;">Bright Red</span> |
| Green         | `42`          | `102`       | <span style="background-color: #008000; color: #ffffff;">Green</span> / <span style="background-color: #00ff00; color: #ffffff;">Bright Green</span> |
| Yellow        | `43`          | `103`       | <span style="background-color: #808000; color: #ffffff;">Yellow</span> / <span style="background-color: #ffff00; color: #ffffff;">Bright Yellow</span> |
| Blue          | `44`          | `104`       | <span style="background-color: #000080; color: #ffffff;">Blue</span> / <span style="background-color: #0000ff; color: #ffffff;">Bright Blue</span> |
| Magenta       | `45`          | `105`       | <span style="background-color: #800080; color: #ffffff;">Magenta</span> / <span style="background-color: #ff00ff; color: #ffffff;">Bright Magenta</span> |
| Cyan          | `46`          | `106`       | <span style="background-color: #008080; color: #ffffff;">Cyan</span> / <span style="background-color: #00ffff; color: #ffffff;">Bright Cyan</span> |
| White         | `47`          | `107`       | <span style="background-color: #c0c0c0; color: #ffffff;">White</span> / <span style="background-color: #ffffff; color: #000000;">Bright White</span> |

For example, to set the text color to bright purple (`95`) and the background to bright yellow (`103`), you can use the following code:

```makefile
PURPLE_B_YELLOW_BG = \033[1;95;103m
```

This will make the text bold and bright purple, and set the background to bright yellow. The `1` in the sequence `\033[1;95;103m` stands for bold, `95` stands for bright purple text color, and `103` stands for bright yellow background.

### 8 bit colors

Example:

```makefile
GREY = \033[38;5;240m
```

This will give you a grey color. The `38;5;240` is a 8-bit color code. **`38;5`** is the **prefix for 8-bit foreground color** and `240` is the color code for grey.