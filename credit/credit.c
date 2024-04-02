#include <stdio.h>
#include "../cs50.h"

void validate_credit_card(long long card_number);

int main(void){
    // Prompt user for credit card number
    long long card_number = get_long("Number: ");

    // Validate the credit card number
    validate_credit_card(card_number);

    return 0;
}

void validate_credit_card(long long card_number){
    int sum = 0;
    int length = 0;
    bool is_second = false;
    long long original_card_number = card_number;

    // Calculate the length of the credit card number
    while (card_number > 0){
        card_number /= 10;
        length++;
    }

    card_number = original_card_number; // Reset card_number to its original value

    // Iterate through the credit card number digits
    while (card_number > 0){
        int digit = card_number % 10;
        card_number /= 10;
        length++;

        if (is_second)
        {
            digit *= 2;
            sum += (digit / 10) + (digit % 10);
        }
        else
        {
            sum += digit;
        }

        is_second = !is_second;
    }

    if (sum % 10 == 0)
    {
        // Determine the type of card based on its starting digits and length
        if ((length == 15 && (original_card_number / 10000000000000 == 34 || original_card_number / 10000000000000 == 37)))
        {
            printf("AMEX\n");
        }
        else if ((length == 16 && (original_card_number / 1000000000000000 == 4)))
        {
            printf("VISA\n");
        }
        else if ((length == 16 && (original_card_number / 100000000000000 >= 51 && original_card_number / 100000000000000 <= 55)))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
