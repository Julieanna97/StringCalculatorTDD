#include "StringCalculator.h"

CALCULATION_RESULT Add(const char *sz) {

    // Check if the string is empty
    if (sz == NULL || *sz == '\0') {
        return RESULT_EMPTY_STRING;
    }

    int sum = 0, valueCount = 0;
    char *token;

    // Use strtok to tokenize the input string based on comma
    char *sz_copy = strdup(sz); // Make a copy to modify
    token = strtok(sz_copy, ",");

    while (token != NULL) {
        // Convert the token to an integer
        int num = atoi(token);

        // Check if num is a valid number
        if (num == 0 && *token != '0')
        {
            free(sz_copy);
            return RESULT_INVALID_NUMBER;
        }

        // Ignore numbers less than 0 or greater than 1000
        if (num >= 0 && num <= 1000) {
            sum += num;
            valueCount++;
        }

        // Get the next token
        token = strtok(NULL, ",");
    }

    free(sz_copy); // Free the allocated memory

    CALCULATION_RESULT result;

    
    if (valueCount > 1)
    {
        result = RESULT_VALID;
    }
    else if (valueCount == 1)
    {
        result = RESULT_ONE_INPUT;
    }
    else
    {
        result = RESULT_EMPTY_STRING;

    }

    return result;
}