#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "source.h"
#include "define.h"

void *print_message_function(void *ptr);

int main() {

    int array[][total_numbers]={ {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                               {11, 12, 13, 14, 15, 16, 17, 18, 19, 110},
                               {21, 22, 23, 24, 25, 26, 27, 28, 29, 210}
                             };

    for (int i = 0; i < total_numbers; i++) {
        for (int pl = 0; pl < PIPE_LEVEL; pl++) {
            for (int ps = 0; ps < PIPE_SIZE; ps++) {
                for (int sn = 0; sn < SOURCE_SIZE; sn++) {
                    if (pl == 0) {
                        printf("\nThe value %d of array 1 is %d", i, generate_value_for_number_array(array[sn], i));
                    }
                }
            }
        }
    }

    return (0);
}