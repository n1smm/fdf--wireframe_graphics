### FDF
Wireframe graphics rendering program. The program reads a map file and renders a 3D wireframe of the map. The program uses the minilibx library to render the wireframe.

## prerequisites
1. cc
2. make
3. minilibx
4. X11
5. Xext
For Debian users do:
`sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev`

will probably not run in wayland.

## Installation
1. Clone the repository
2. Run `make` in the repository directory
3. run `make bonus` to compile the bonus version of the program

## Usage
`./fdf [map]` or `./fdf_bonus [map]`

## pictures
### 42
![alt text](/imgs/42.jpg)

### Mars
![alt text](/imgs/pylone.jpg)

### Earth
![alt text](/imgs/earth.jpg)



