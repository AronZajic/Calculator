# Calculator
A C++ command line calculator that can use variables and functions
# Usage
## Basic Aritmetics:

.>2+2

.=4.000000

.>8*9

.=72.000000

.>3-2*2

.=-1.000000

.>(3-2)*2

.=2.000000

.>2^2

.=4.000000

.>3!

.=6

## Defining variables:

.>x=5

.>x

.=5

.>a=4*x

.>a

.=20.000000

.>x=6

.>x

.=6

.>a

.=24.000000 (definition of the variable “a” did not change but a variable that it references did)

.>a*x

.=144.000000

## Function definition and usage:

.>f:=x*x

.>f:(+5)

.=25.000000

.>5+f:(+5)

.=30.000000
