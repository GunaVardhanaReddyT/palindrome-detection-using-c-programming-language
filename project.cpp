#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindromeNumber(long num) {
    long reversedNum = 0, originalNum = num;
    while (num != 0) {
        reversedNum = reversedNum * 10 + num % 10;
        num /= 10;
    }
    return reversedNum == originalNum;
}

int isPalindromeString(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            return 0;
        }
    }
    return 1;
}

void detectPalindrome() {
    int choice;
    printf("1. Check if a number is a palindrome\n");
    printf("2. Check if a string is a palindrome\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        long num;
        printf("Enter a number: ");
        scanf("%ld", &num);
        if (isPalindromeNumber(num)) {
            printf("%ld is a palindrome.\n", num);
        } else {
            printf("%ld is not a palindrome.\n", num);
        }
    } else if (choice == 2) {
        char str[100];
        printf("Enter a string: ");
        scanf("%s", str);
        if (isPalindromeString(str)) {
            printf("%s is a palindrome.\n", str);
        } else {
            printf("%s is not a palindrome.\n", str);
        }
    } else {
        printf("Invalid choice.\n");
    }
}

void generatePalindromesInRange() {
    long x, y;
    printf("Enter the range (x to y): ");
    scanf("%ld %ld", &x, &y);
    printf("Palindromes in the range %ld to %ld are:\n", x, y);
    for (long num = x; num <= y; num++) {
        if (num >= 10 && isPalindromeNumber(num)) {
            printf("%ld\n", num);
        }
    }
}

int main() {
    int option;
    do {
        printf("\nMenu:\n");
        printf("1. Detect Palindrome\n");
        printf("2. Generate Palindromes in a Range\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                detectPalindrome();
                break;
            case 2:
                generatePalindromesInRange();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 3);

    return 0;
}