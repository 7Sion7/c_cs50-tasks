#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>


void println(void);

#define ALPHABET_SIZE 26

struct KeyValue {
    char key;
    char value;
};

int checkForDuplicates(char *key);
int initialiseMap(char *input, struct KeyValue *map);
void encrypt(char *encrypted, struct KeyValue *map, char *plainText);

int main(int argc, char *argv[]) {

   if (argc != 2) {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    char *input = argv[1];
    int input_length = strlen(input);

    if (input_length < ALPHABET_SIZE) {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    if (checkForDuplicates(input) == 1) {
        return 1;
    }

    struct KeyValue map[ALPHABET_SIZE];

    if (initialiseMap(input, map) != 0) {
        printf("invalid input, only letters accepted");
        println();
        return 1;
    };
    char *plainText = get_string("plaintext: ");
    char encrypted[strlen(plainText)];
    encrypt(encrypted, map, plainText);
    printf("ciphertext: %s\n", encrypted);

    return 0;
}


int checkForDuplicates(char *key){
    for (int i = 0; i < strlen(key); i++) {
        for (int j = i+1; j < strlen(key); j++) {
            if (key[i] == key[j]) {
                  return 1;
            }
        }
    }

    return 0;
}



int initialiseMap(char *input, struct KeyValue *map) {
    for (char key = 'A'; key <= 'Z'; key++) {
        if (!isalpha(input[key - 'A'])) {
            return 1;
        }
        map[key - 'A'].key = key;
        map[key - 'A'].value = toupper(input[key - 'A']);
    }
    return 0;
}

void encrypt(char *encrypted, struct KeyValue *map, char *plainText) {
    for (int i = 0; i < strlen(plainText); i++) {
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            if (isalpha(plainText[i])) {
                char letter = plainText[i];
                if (map[j].key == toupper(plainText[i])) {
                    if (islower(letter)) {
                        encrypted[i] = tolower(map[j].value);
                        break;
                    } else {
                        encrypted[i] = map[j].value;
                        break;
                    }
                }

            } else {
                encrypted[i] = plainText[i];
            }
        }
    }
    encrypted[strlen(plainText)] = '\0';
}

void println(void) {
    printf("\n");
}
