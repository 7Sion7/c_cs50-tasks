#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

#define MAP_SIZE 26

struct KeyValue {
    char key;
    int value;
};

const struct KeyValue alphabetMap[MAP_SIZE] = {
    {'A', 1}, {'B', 3}, {'C', 3}, {'D', 2}, {'E', 1}, {'F', 4}, {'G', 2}, {'H', 4}, {'I', 1}, {'J', 8},
    {'K', 5}, {'L', 1}, {'M', 3}, {'N', 1}, {'O', 1}, {'P', 3}, {'Q', 10}, {'R', 1}, {'S', 1}, {'T', 1},
    {'U', 1}, {'V', 4}, {'W', 4}, {'X', 8}, {'Y', 4}, {'Z', 10}
};

int score(const char *str) {
    int score = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            score += alphabetMap[toupper(str[i]) - 'A'].value;
        }
    }
    return score;
}

int main(void) {
    string str1 = get_string("Player 1: ");
    string str2 = get_string("Player 2: ");

    int score1 = score(str1);
    int score2 = score(str2);

    if (score1 != score2) {
        if (score1 > score2) {
            printf("Player 1 wins!\n");
        } else {
            printf("Player 2 wins!\n");
        }
    } else {
        printf("Tie!\n");
    }
    return 0;
}

