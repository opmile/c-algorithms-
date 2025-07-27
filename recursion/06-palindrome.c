#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char *str, int start, int end) {
    if (start < end) {
        if (str[start] == str[end]) {
            return isPalindrome(str, start + 1, end - 1);
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    return 0;
}