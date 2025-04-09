# FdF
FdF (Fil de Fer) is a simple 3D wireframe viewer that renders height maps in isometric projection using MiniLibX (Linux).

# Requirements
MiniLibX library for Linux (mlx_linux)
Can be found in 42Paris's internal resources (check your school's intranet or ask your peers for the download link)

# Installation
1. Clone this repository
2. Otain mlx_linux from 42Paris resources OR from [![Here](https://github.com/42Paris/minilibx-linux)
3. Compile & Run
```sh
make && ./fdf test_maps/42.fdf
```

# Controls
  Key  Action
  ---- -------
- ESC  Quit program
- X    Button	Close window

File Format
Example map:
```txt
0 0 0
0 10 0
0 0 0
```
Each number = height.
Rows must have equal columns.

Notes
- This implementation covers only the mandatory requirements
- Uses basic isometric projection

[![License](https://img.shields.io/badge/License-MIT-blue.svg)](https://github.com/med-el-hamidi/FdF/blob/main/LICENSE.md)
