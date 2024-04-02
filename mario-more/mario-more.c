#include <stdio.h>
#include "../cs50.h"

void marioPyramid(int num) {
    for(int i = 0; i < num; i++) {
        for (int j = 0; j < num -1 - i; j++) {
            printf(" ");
        }
         for (int k = 0; k <= i; k++) {
            printf("#");
        }
        printf("  ");
         for (int k = 0; k <= i; k++) {
            printf("#");
        }
        printf("\n");
    }
}

int main(void) {
    int num;
    do {
        num = get_int("Height: ");
    }
    while(num <= 0 || num > 8);
    marioPyramid(num);
}

