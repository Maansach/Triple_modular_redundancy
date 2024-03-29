//
// Created by maana on 7/1/2022.
// The pipe.c expects the references to either three pipes or three sources. The pipe will store the last valid value (default 0). Each cycle the pipe
// will read the three inputs and only if two or more are the same update the stored valid value. The pipe will store the last valid value in a 2D array.
//

#include "define.h"
#include <stdio.h>

void verify_inputs(int pipe_size, int pipe_level, int is_source) {

    printf("\n\n");
    int error_flag = 0;
    if (is_source == 1) {
        for (int i = 0; i < SOURCE_SIZE - 1; i++) {
            if (source_value[i] == source_value[i + 1]) {
                pipe_value[pipe_level][pipe_size] = source_value[i];
                printf("\nThe value of pipe number %d of pipe level %d is %d", pipe_size, pipe_level,
                       pipe_value[pipe_level][pipe_size]);
                error_flag = 1;
            }
        }
    } else {

        for (int i = 0; i < PIPE_SIZE - 1; i++) {
            if (pipe_value[pipe_level - 1][i] == pipe_value[pipe_level - 1][i + 1]) {
                pipe_value[pipe_level][pipe_size] = pipe_value[pipe_level - 1][i];
                printf("\nThe value of pipe number %d of pipe level %d is %d", pipe_size, pipe_level,
                       pipe_value[pipe_level][pipe_size]);
                error_flag = 1;
            }
        }

    }

    if (error_flag == 0) {
        printf("\nThe value of pipe number %d of pipe level %d is %d", pipe_size, pipe_level,
               pipe_value[pipe_level][pipe_size]);
    }

}
