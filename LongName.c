#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 100

void longNames(int n);

int main() {
    int n;
    printf("Enter the amount of names you want: ");
    scanf("%d", &n);
    longNames(n);
    return 0;
}

void longNames(int n) {
    char name[MAX_NAME_LENGTH], longest[MAX_NAME_LENGTH] = "";
    int longest_length = 0;
    int ties = 0;
    for (int i = 1; i <= n; i++) {
        printf("Enter name #%d: ", i);
        scanf("%s", name);
        int length = strlen(name);
        if (length > longest_length) {
            strcpy(longest, name);
            longest_length = length;
            ties = 0;
        } else if (length == longest_length) {
            ties++;
        }
    }

    longest[0] = toupper(longest[0]);
    
    if (ties > 0) {
        printf("(There were %d ties for the longest names!)\n", ties+1);
    } else {
    printf("%s's name is longest\n", longest);
    }
}

