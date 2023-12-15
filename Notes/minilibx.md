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
