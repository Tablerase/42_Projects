# Color

## A RGB

![argb display](https://upload.wikimedia.org/wikipedia/commons/0/0b/RGBA_comp.png)



In many systems when there are more than 8 bits per channel (such as 16 bits or floating-point), the channels are stored in RGBA order, even if 8-bit channels are stored in some other order.

ARGB values are typically expressed using 8 hexadecimal digits, with each pair of the hexadecimal digits representing the values of the Alpha, Red, Green and Blue channel, respectively.

![argb picture](https://upload.wikimedia.org/wikipedia/commons/0/0e/PixelSamples32bppRGBA.png)

On little-endian systems, this is equivalent to BGRA byte order. On big-endian systems, this is equivalent to ARGB byte order.

![rgba picture](https://upload.wikimedia.org/wikipedia/commons/d/d7/HexRGBAbits.png)

In OpenGL and Portable Network Graphics (PNG), the RGBA byte order is used, where the colors are stored in memory such that R is at the lowest address, G after it, B after that, and A last. On a little endian architecture this is equivalent to ABGR32.