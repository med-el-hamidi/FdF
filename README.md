# FdF
FdF (Fil de Fer) is a simple 3D wireframe viewer that renders height maps in isometric projection using MiniLibX (Linux).

# Requirements
MiniLibX library for Linux (mlx_linux)
Can be found in 42Paris's internal resources (OR from [Here](https://github.com/42Paris/minilibx-linux))

# Installation
1. Clone this repository
2. Otain & extract minilibx-linux then rename it into mlx_linux
3. Unzip maps.zip
4. Compile & Run
```sh
git clone https://github.com/med-el-hamidi/FdF.git
cd FdF
git clone https://github.com/42paris/minilibx-linux.git mlx_linux
unzip maps.zip
make
./fdf test_maps/42.fdf
```

# Controls
- ESC and X Button  -->  Quit program safely and Close window.

File Format
Example map:
```txt
0 0 0
0 10 0
0 0 0
```
- Each number = height.
- Rows must have equal columns.

Notes
- This implementation covers only the mandatory requirements
- Uses basic isometric projection

[![License](https://img.shields.io/badge/License-MIT-blue.svg)](https://github.com/med-el-hamidi/FdF/blob/main/LICENSE.md)
