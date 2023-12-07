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
