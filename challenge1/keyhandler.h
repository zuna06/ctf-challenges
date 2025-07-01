#pragma once
#include <stdlib.h>
#include <memory.h>

struct BlockSet {

    u_int8_t blockOne[4];
    u_int8_t blockTwo[4];
    u_int8_t blockThree[4];
    u_int8_t blockFour[4];

};

extern struct BlockSet ciphertext;
extern struct BlockSet key;

void init(char* userMessage, char* userKey) {
    memcpy(ciphertext.blockOne, userMessage, 16);
    memcpy(key.blockOne, userKey, 16);
}

#define DECRYPT "Test";

void mix() {
    for(int i = 0; i < 4; i++) {
        ciphertext.blockOne[i] ^= key.blockOne[i];
        ciphertext.blockTwo[i] ^= key.blockTwo[i];
        ciphertext.blockThree[i] ^= key.blockThree[i];
        ciphertext.blockFour[i] ^= key.blockFour[i];
    }
}

void shift(int shifts, u_int8_t *block) {
    u_int8_t temp[4];
    memcpy(temp, block, 4);

    for(int _ = 0; _ < 4; _++) {
        for(int i = 0; i < 4; i++) {
            block[i] = temp[(i + 1) % 4];
        }
    }

}
void rot() {
    shift(0, ciphertext.blockOne);
    shift(1, ciphertext.blockOne);
    shift(2, ciphertext.blockOne);
    shift(3, ciphertext.blockOne);
}

void encrypt() {

    

}