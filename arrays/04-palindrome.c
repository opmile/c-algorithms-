#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

void toLowerCase(char *str, int len);

bool isPalindrome(char *str, int len);

int main() {
    char palindrome[] = "mutum";

    if (isPalindrome(palindrome, strlen(palindrome))) {
        printf("é palindromo\n");
    } else {
        printf("não é palindromo");
    }
    
    return 0;
}

void toLowerCase(char *str, int len) {
    for (int i = 0; i < len; i++) {
        *(str + i) = tolower(*(str + i));
    }
}

bool isPalindrome(char *str, int len) {
    toLowerCase(str, len);
    
    int left = 0;
    int right = len - 1;

    while (left < right) {
        if (*(str + left) != *(str + right)) { 
            return false;
        }
        
        left++;
        right--;
    }
    return true;
}
