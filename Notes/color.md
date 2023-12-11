# Color

## A RGB

![argb display](https://upload.wikimedia.org/wikipedia/commons/0/0b/RGBA_comp.png)

In many systems when there are more than 8 bits per channel (such as 16 bits or floating-point), the channels are stored in RGBA order, even if 8-bit channels are stored in some other order.

ARGB values are typically expressed using 8 hexadecimal digits, with each pair of the hexadecimal digits representing the values of the Alpha, Red, Green and Blue channel, respectively.

![argb picture](https://upload.wikimedia.org/wikipedia/commons/0/0e/PixelSamples32bppRGBA.png)

On little-endian systems, this is equivalent to BGRA byte order. On big-endian systems, this is equivalent to ARGB byte order.

![rgba picture](https://upload.wikimedia.org/wikipedia/commons/d/d7/HexRGBAbits.png)

In OpenGL and Portable Network Graphics (PNG), the RGBA byte order is used, where the colors are stored in memory such that R is at the lowest address, G after it, B after that, and A last. On a little endian architecture this is equivalent to ABGR32.

## HSV

![HSV vs Other](https://www.researchgate.net/profile/Hamid-Jalab/publication/329019029/figure/fig1/AS:960478280957952@1606007275709/Color-representation-in-different-color-models-a-RGB-color-space-b-HSV-color-space-c.png)

a = RGB b = HSV, c = CIE, d = YUV


HSL (for hue, saturation, lightness) and **HSV** (for hue, saturation, value; also known as HSB, for hue, saturation, brightness) are alternative representations of the RGB color model, designed in the 1970s by computer graphics researchers.

<img src="https://upload.wikimedia.org/wikipedia/commons/0/00/HSV_color_solid_cone_chroma_gray.png" align="right" width="50%">

### Hue

Hue tells the angle to look at the cylindrical disk. The hue represents the color. The hue value ranges from o to 360 degrees.

| Angle | Color   |
|-------|---------|
| 0-60  | Red     |
| 60-120 | Yellow |
| 120-180 | Green  |
| 180-240 | Cyan   |
| 240-300 | Blue   |
| 300-360 | Magenta |

### Saturation

The saturation value tells us how much quantity of respective color must be added. A 100% saturation means that complete pure color is added, while a 0% saturation means no color is added, resulting in grayscale.

### Value

The value represents the brightness concerning the saturation of the color. the value 0 represents total black darkness, while the value 100 will mean a full brightness and depend on the saturation.

![HSV list](/Notes/Media/HSV.png)

### Convertion

To RGB:

Given an HSV color with hue H ∈ [0°, 360°], saturation S ∈ [0, 1], and value V ∈ [0, 1]
