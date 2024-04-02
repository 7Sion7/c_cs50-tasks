#include <stdio.h>
#include "../cs50.h"

void marioMaker(void) {
    int num = get_int("Size: ");
    if (num <= 0) {
        printf("Too short try again\n");
        marioMaker();
    }

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num - 1 - i; j++) {
            printf(" ");
        }


        printf("\n");
    }
}

int main(void) {
    marioMaker();
}
