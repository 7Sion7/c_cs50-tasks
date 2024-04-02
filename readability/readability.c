#include <stdio.h>
#include <ctype.h>
#include "../cs50.h"
#include <math.h>

void totalLettersAndWordsAndSentences(const char *str, int *letterCount, int *wordCount, int *sentenceCount) {
    int l = 0;
    int w = 1;          // wordCount initial value is one
    int s = 0;          //as we assume there is a word after the last space,
                       //also because if there is no space it means there is only one word
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            l++;
        }
        if (str[i] == ' ') {
            w++;
        }
        if (str[i] == '.' || str[i] == '!' || str[i] == '?') {
            s++;
        }
    }

    *letterCount = l;
    *wordCount = w;
    *sentenceCount = s;
}

float GetGradeLevel(string str) {
    int letterCount, wordCount, sentenceCount;
    totalLettersAndWordsAndSentences(str, &letterCount, &wordCount, &sentenceCount);
    printf("Letter Count: %d\nWord Count: %d\nSentence Count: %d\n", letterCount, wordCount, sentenceCount);

    double L = (double)letterCount / wordCount * 100;
    double S =  (double)sentenceCount / wordCount * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    return index;
}




int main(void) {
    string str = get_string("Text: ");
    int gradeLevel = (int) round(GetGradeLevel(str));

    if (gradeLevel < 0) {
        printf("Before Grade 1\n");
        return 0;
    } else if (gradeLevel > 16) {
         printf("Grade 16+\n");
         return 0;
    }


        printf("Grade %d\n", gradeLevel);
        return 0;

}

