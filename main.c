#include "StringCalculator.h"

int main() {
    
    /*
    // Example usage
    const char input1[] = "1,2";
    const char input2[] = "100,200,300";
    const char input3[] = "-1,0,1001,500";

    printf("Sum 1: %d\n", Add(input1));
    printf("Sum 2: %d\n", Add(input2));
    printf("Sum 3: %d\n", Add(input3));

    */
   while(1)
   {
    // Get user input
    char input[100]; // Assuming a maximum input length of 100 characters

    printf("Enter a string of numbers seperatedby commas: ");
    fgets(input, sizeof(input), stdin);

    if (strncmp(input, "exit", 4) == 0 || (strncmp(input, "Exit", 4) == 0))
    {
        printf("Exiting the program. Goodbye!\n");
        return 0;
    }

    // Remove the newline character from the input
    input[strcspn(input, "\n")] = '\0';

    // Call the Add function with user input
    int result = Add(input);

    switch (result)
    {
        case RESULT_EMPTY_STRING:
            printf("Error: Empty string\n");
            break;
        case RESULT_VALID:
            // Display the result
            printf("Sum %d\n", result);
            break;
        case RESULT_ONE_INPUT:
            printf("%d\n", result);
            break;
        case RESULT_INVALID_NUMBER:
            printf("Error: Invalid Number.\n");
            break;
        default:
            printf("Unknown result\n");
            break;
    }
   }
   
   
   return 0;
}