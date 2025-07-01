/*
*
* tunakat (copyright)
*
*/

#include <stdio.h>
#include "keyhandler.h"

int main(int argc, char **argv) {

    if(argc < 3) {
        printf("Not enough arguments :(\n");
        printf("Correct Usage: ./gyro message key\n");
        return -1;
    }

    init(argv[1], argv[2]);
    encrypt();

    return 0;
}