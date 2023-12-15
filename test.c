#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Add(const char *sz) {
    // Check if the string is empty
    if (sz == NULL || *sz == '\0') {
        return 0;
    }

    int sum = 0;
    char *token, *rest;

    // Use strtok to tokenize the input string based on comma
    char *sz_copy = strdup(sz); // Make a copy to modify
    token = strtok(sz_copy, ",");

    while (token != NULL) {
        // Convert the token to an integer
        int num = atoi(token);

        // Ignore numbers less than 0 or greater than 1000
        if (num >= 0 && num <= 1000) {
            sum += num;
        }

        // Get the next token
        token = strtok(NULL, ",");
    }

    free(sz_copy); // Free the allocated memory
    return sum;
}

int main() {
    // Example usage
    const char input1[] = "1,2,3,4,5";
    const char input2[] = "100,200,300";
    const char input3[] = "-1,0,1001,500";

    printf("Sum 1: %d\n", Add(input1));
    printf("Sum 2: %d\n", Add(input2));
    printf("Sum 3: %d\n", Add(input3));

    return 0;
}
