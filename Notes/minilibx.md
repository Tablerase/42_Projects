# MiniLibX

Manuel, dispo dans le terminal: `man 3 mlx`

📑 Documentation: [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx.html)

## Installation local (for homework)

Setup env: `sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev`

Compile and Install:

- Clone: `git clone https://github.com/42Paris/minilibx-linux minilibx_linux`
- Compile and Install:

  ```code
  cd minilibx_linux
  make
  sudo cp libmlx.a /usr/local/lib
  sudo cp mlx.h /usr/local/include
  ```

- Install Manual: `sudo cp man/man3/mlx*.3 /usr/local/man/man3`

## Compilation/Linking

LINKING MinilibX on BSD/Linux and X-Window To use MiniLibX functions, you’ll need to link your software with several libraries, including the MiniLibX library itself.

To do this, simply add the following arguments at linking time:

- Linux:
  - .

## Hooks and Events

📚 [Official Documentation X System](https://www.x.org/releases/X11R7.6/doc/xproto/x11protocol.html)

### Hook

- Mouse code:
  
  ![mouse code](https://harm-smits.github.io/42docs/libs/minilibx/res/mouse-schema.png)
- Key code: Use lib X11/keysim
  - To use just call: `XC_keyname` in your code
  - Here a list of all keycode:  🔗[Doc](https://www.oreilly.com/library/view/xlib-reference-manual/9780937175262/16_appendix-h.html)
- Event code: Use lib X11/X
  - To use just call: `X_event` in your code

  ```c
  // Keyboard keys library / X11 events
  # include <X11/keysym.h>
  # include <X11/X.h>
  ```

![Mlx loop](https://firebasestorage.googleapis.com/v0/b/aurelienbrabant-com.appspot.com/o/blog%2Fevents-with-the-minilibx%2Fmlx-loop-flowchart.webp?alt=media&token=cdd0424a-a8c7-4527-8782-f67c4419bbff)

The `mlx_loop` function is called to start the event loop. This function will keep the program running until the window is closed.

### Event

MiniLibX used event from X11 library. 🔗[X11 Doc](https://tronche.com/gui/x/xlib/events/)

- X button on window: The `DestroyNotify` event is triggered when the window is closed.

- Mouse event:
  - `MotionNotify` event is triggered when the mouse cursor moves within the specified window.
    - `PointerMotionMask`, is a mask that specifies which events the hook should be triggered for. In this case, `PointerMotionMask` indicates that the hook should be triggered for mouse motion events.

      <details>
      <summary> 🖱️ Exemple print mouse position with MinilibX</summary>

      ```c
      #include "../mlx/mlx.h"
      #include "../libft/Includes/libft.h"
      #include <X11/X.h>

      typedef struct s_fractol
      {
        void *mlx;
        void *win;
        int  mouse_x;
        int  mouse_y;
      } t_fractol;

      int ft_test(int mouse_x, int mouse_y, t_fractol *fractol)
      {
        mlx_mouse_get_pos(fractol->mlx, fractol->win, &mouse_x, \
          &mouse_y);
        fractol->mouse_x = mouse_x;
        fractol->mouse_y = mouse_y;
        static int i = 0;
        i++;
        ft_printf("test %i | mouse x: %i mouse y: %i\n", i, \
          fractol->mouse_x, fractol->mouse_y);
        return (0);
      }

      int ft_exit(t_fractol *fractol)
      {
        mlx_destroy_window(fractol->mlx, fractol->win);
        mlx_destroy_display(fractol->mlx);
        free(fractol->mlx);
        exit(0);
        return (0);
      }

      int main()
      {
        t_fractol fractol;

        fractol.mlx = mlx_init();
        if (!fractol.mlx)
        {
          mlx_destroy_display(fractol.mlx);
          free(fractol.mlx);
          return(1);
        }
        fractol.win = mlx_new_window(fractol.mlx, 500, 500, "test");
        mlx_hook(fractol.win, MotionNotify, PointerMotionMask, ft_test, &fractol);
        mlx_hook(fractol.win, DestroyNotify, NoEventMask, ft_exit, &fractol);

        mlx_loop(fractol.mlx);
        ft_exit(&fractol);
        return (0);
      }
      ```

      </details>

## Images

Image are used by the MiniLibX to render graphics to the screen. Images can be created from scratch, or loaded from XPM or PNG files.

### Image data

Image allows to draw on the window. It more efficient to draw on an image and then put the image on the window because it will reduce the number of calls to the X server. (also the mlx_pixel_put function is slow, so it's better to use images to draw on the window.)

Images are stored in a 2D array of pixels. Each pixel is a 32-bit integer, with the following format:
- Bits 0-7: Blue channel
- Bits 8-15: Green channel
- Bits 16-23: Red channel
- Bits 24-31: Alpha channel

#### Init image

```c
void *mlx_new_image(void *mlx_ptr, int width, int height);
```

Example:

```c
void *mlx;
void *img;

mlx = mlx_init();
img = mlx_new_image(mlx, 500, 500);
```

#### Get image data

Before you can read or write pixels in an image, you need to get the address of the image data.
When you have the address of the image data, you can read and write pixels in the image.

```c
int *mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
```

- `img_ptr` is the image instance.
- `bits_per_pixel` is a pointer to where the bits per pixel ought to be written.
  - The bits per pixel is the number of bits used to represent a single pixel.
- `size_line` is a pointer to where the size line ought to be written.
  - The size line is the number of bytes in a row of the image data.
- `endian` is a pointer to where the endian ought to be written.
  - The endian is the byte order of the image data. It can be either 0 or 1.

Example:

```c
int *img_data;
int bits_per_pixel;
int size_line;
int endian;

img_data = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
```

#### Put pixel

Now that we have the address. The bytes are not aligned, this means that the `line_length` or `size-line` differs from the actual window width. We therefore should ALWAYS calculate the memory offset using the line length set by `mlx_get_data_addr`.

```c
int offset = (y * size_line) + (x * (bits_per_pixel / 8));
```

Now we can put a pixel at the position (x, y) in the image.

```c
int *img_data;
int bits_per_pixel;
int size_line;
int endian;
int offset;

img_data = mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);
offset = (y * size_line) + (x * (bits_per_pixel / 8));
*(int *)(img_data + offset) = color; // This is the same as img_data[offset] = color
```

The bits needed to edit each pixel are stored in the `img_data` array. The `offset` is calculated using the `size_line` and `x` and `y` coordinates. The `color` is then written to the `img_data` array at the `offset` position.

Example:

```c
typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

void	pixel_put(t_img *img, int x, int y, int color)
{
	int		offset;

	offset = (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)(img->addr + offset) = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
```

0x00FF0000 is the hex representation of ARGB(0,255,0,0). This will draw a red pixel at the position (5, 5) in the window.

Note that this will cause an issue. Because an image is represented in real time in a window, changing the same image will cause a bunch of screen-tearing when writing to it. You should therefore **create two or more images to hold your frames temporarily**. You can then write to a temporary image, so that you don’t have to write to the currently presented image.

#### Put image to window

```c
void mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
```

- `mlx_ptr` is the mlx instance.
- `win_ptr` is the window instance.
- `img_ptr` is the image instance.
- `x` is the x-coordinate of the top-left corner of the image.
- `y` is the y-coordinate of the top-left corner of the image.


### From XPM and PNG

XMP and PNG(png: leaks) can be used to render images into windows.

Reading images from xmp char** :

```c
/*
** Converts xpm data to a new image instance.
**
** @param void *mlx_ptr the mlx instance;
** @param char **xpm_data the xpm data in a 2 dimensional char array;
** @param int  *width  a pointer to where the width ought to be written;
** @param int  *height a pointer to where the height ought to be written;
** @return void*   the image instance, and NULL in case of error.
*/
void *mlx_xpm_to_image(void *mlx_ptr, char **xpm_data, int *width, int *height);
```

Reading images from xmp file :

```c
#include <mlx.h>

int main(void)
{
 void *mlx;
 void *img;
 char *relative_path = "./test.xpm";
 int  img_width;
 int  img_height;

 mlx = mlx_init();
 img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
}
```

If you read a file your file must contains XPM3 Syntax to work.

```c
/* XPM */
static char * XFACE[] = {
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
