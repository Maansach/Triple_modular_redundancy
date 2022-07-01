#include <stdio.h>
#include "source.h"
#include "pipe.h"
#include "sink.h"
#include "define.h"

int pipe_value[PIPE_LEVEL][PIPE_SIZE];
int source_value[SOURCE_SIZE];

int main() {

// Case 1
//    int array[][total_numbers] = {{1,  2,  3,  4,  5,  6,  7,  8,  9,  10},
//                                  {11, 12, 13, 14, 15, 16, 17, 18, 19, 110},
//                                  {21, 22, 23, 24, 25, 26, 27, 28, 29, 210}
//    };

// Case 2
//    int array[][total_numbers] = {{1,  2,  3,  4,  5,  6,  7,  8,  9,  10},
//                                  {1,  2,  3,  4,  5,  6,  7,  8,  9,  10},
//                                  {21, 22, 23, 24, 25, 26, 27, 28, 29, 210}
//    };

// Case 3
    int array[][total_numbers] = {{1,  2,  3,  4,  5,  6,  7,  8,  9,  10},
                                  {1,  2,  3,  44, 55, 66, 7,  8,  9,  10},
                                  {21, 22, 23, 24, 25, 26, 27, 28, 29, 210}
    };

    // Initialize the value of pipes to zero

    for (int pl = 0; pl < PIPE_LEVEL; pl++) {
        for (int ps = 0; ps < PIPE_SIZE; ps++) {
            pipe_value[pl][ps] = 0;
            //printf("\nThe value of pipe number %d of pipe level %d is %d", ps, pl, pipe_value[pl][ps]);
        }
    }

    for (int i = 0; i < total_numbers; i++) {
        for (int pl = 0; pl < PIPE_LEVEL; pl++) {
            for (int ps = 0; ps < PIPE_SIZE; ps++) {
                if (pl == 0) {
                    printf("\n");
                    for (int sn = 0; sn < SOURCE_SIZE; sn++) {
                        printf("\nThe value %d of source array is %d", sn,
                               generate_value_for_number_array(array[sn], i));
                        source_value[sn] = generate_value_for_number_array(array[sn], i);
                    }
                    verify_inputs(ps, pl, 1);
                } else {
                    printf("\n");
                    for (int rp = 0; rp < PIPE_SIZE; rp++) {
                        printf("\nThe value %d of pipe level %d is %d", rp, pl - 1, pipe_value[pl - 1][rp]);
                    }
                    verify_inputs(ps, pl, 0);
                }
            }
        }

        // Sink
        if (PIPE_LEVEL == 0) {
            sink_value_inputs(1, i);
        } else {
            sink_value_inputs(0, i);
        }

    }

    return (0);
}