# Triple_modular_redundancy

The function of the C files:

- `pipe.c` - The pipe expects the references to either three pipes or three
  sources. The pipe will store the last valid value (default 0). Each cycle the pipe will read the three
  inputs and only if two or more are the same update the stored valid value. The pipe will store the
  last valid value in a 2D array.
- `source.c` - The source accepts an array of numbers and will return one number
  at each cycle and then move to the next number.
- `sink.c` - The sink expects the reference to either three pipes or sources. Each
  cycle the sink will read the three inputs and only if two or more are the same, store the output inside
  an output array, otherwise repeat the last valid value.
- `main.c` - run the chain with pipe, source and sink

# Procedure to run script

- Download the Zip file or clone the github repository
- Use gcc compiler
````
gcc -std=c99 main.c source.c pipe.c sink.c -o TMR.out
 ./TMR.out

````

- Run the cmake command

  Note: CMake 3.20 or higher is required
  
- ````
  cmake . 
  ````
