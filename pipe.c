//
// Created by maana on 7/1/2022.
//

#include "define.h"
#include <stdio.h>

void verify_inputs(int pipe_size, int pipe_level, int is_source) {

    if(is_source == 1){
        for (int i = 0; i < SOURCE_SIZE - 1; i++) {
            if (source_value[i] == source_value[i + 1]) {
                pipe_value[pipe_level][pipe_size] = source_value[i];
                printf("\nThe value of pipe number %d of pipe level %d is %d", pipe_size, pipe_level,
                       pipe_value[pipe_level][pipe_size]);
            }
        }
    }

    else{

        for (int i = 0; i < PIPE_SIZE - 1; i++) {
            if (pipe_value[pipe_level-1][i] == pipe_value[pipe_level-1][i + 1]) {
                pipe_value[pipe_level][pipe_size] = pipe_value[pipe_level-1][i];
                printf("\nThe value of pipe number %d of pipe level %d is %d", pipe_size, pipe_level,
                       pipe_value[pipe_level][pipe_size]);
            }
        }

    }

}