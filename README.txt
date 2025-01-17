use "make" to make fractol

use "./fractol <max_iteration> <length> <height> <arg>" to run program (arg being m or j for now)

use mouse wheel to zoom in and out (zoom * 2)
use key m to switch to Mandelbrot
use key j to switch to Julia
use key w to increase max_iteration (+5)
use key s to decrease max_iteration (-5)
use key r to reset zoom, max_iteration and colours
use key b, g and t to change colours
use key esc to close window



 // TO DO \\
ft_printf
arrow to move the fractal
zoom that follows the pointer
code Julia
code extra fractal
clean up hook function


 / ! \ not to self / ! \
initialise at
red = 0
green = 0
blue = 0
will initialise a black window but the colours will be true and will change with the first colours change
(key b will be blue, g green and t red)