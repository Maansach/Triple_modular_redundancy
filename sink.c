//
// Created by maana on 7/1/2022.
//

#include "define.h"
#include <stdio.h>

int sink_value[total_numbers];

void sink_value_inputs(int is_source, int index) {

    int flag = 0;
    if (is_source == 1) {
        for (int i = 0; i < SOURCE_SIZE - 1; i++) {
            if (source_value[i] == source_value[i + 1]) {
                sink_value[index] = source_value[i];
                printf("\nThe value of index %d of sink is %d", index, sink_value[index]);
                flag = 1;
            }
        }
    } else {
        for (int i = 0; i < PIPE_SIZE - 1; i++) {
            if (pipe_value[PIPE_SIZE - 1][i] == pipe_value[PIPE_SIZE - 1][i + 1]) {
                sink_value[index] = pipe_value[PIPE_SIZE - 1][i];
                printf("\nThe value of index %d of sink is %d", index, sink_value[index]);
                flag = 1;
            }
        }
    }

    if (flag == 0) {
        if (index > 0) {
            sink_value[index] = sink_value[index - 1];
        }
        printf("\nThe value of index %d of sink is %d", index, sink_value[index]);
    }

}