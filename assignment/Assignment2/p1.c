#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** split(char letter, char* str, int* p_size) {
    char** result = NULL;
    int size = 0;
    char* token;
    char delimiters[] = " \t\n";

    // Convert the letter to both lower and upper case
    char lower_letter = tolower(letter);
    char upper_letter = toupper(letter);

    // Make a copy of the input string to avoid modifying the original
    char* str_copy = _strdup(str);
    if (str_copy == NULL) {
        *p_size = 0;
        return NULL;
    }

    // Tokenize the string
    char* context;
    token = strtok_s(str_copy, delimiters, &context);
    while (token != NULL) {
        // Check if the word starts with the specified letter
        if (token[0] == lower_letter || token[0] == upper_letter) {
            // Allocate or reallocate memory for the result array
            char** temp = realloc(result, (size + 1) * sizeof(char*));
            if (temp == NULL) {
                // Free previously allocated memory and return NULL
                for (int i = 0; i < size; i++) {
                    free(result[i]);
                }
                free(result);
                free(str_copy);
                *p_size = 0;
                return NULL;
            }
            result = temp;

            // Allocate memory for the new word and copy it to the result array
            result[size] = _strdup(token);
            if (result[size] == NULL) {
                // Free previously allocated memory and return NULL
                for (int i = 0; i < size; i++) {
                    free(result[i]);
                }
                free(result);
                free(str_copy);
                *p_size = 0;
                return NULL;
            }
            size++;
        }

        // Get the next token
        token = strtok_s(NULL, delimiters, &context);
    }
    // Free the copy of the original string
    free(str_copy);
    // Set the size and return the result
    *p_size = size;
    return result;
}

void printStringsArray(char** str_arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s\n", str_arr[i]);
    }
}

void freeMatrix(void** A, int rows) {
    for (int i = 0; i < rows; i++) {
        free(A[i]);
    }
    free(A);
}

int main() {
    char letter = 'g';
    char str[] = "Rony Goodman got a good mark";
    
    int size = 0;
    char** result = split(letter, str, &size);
    if (result != NULL) {
        printStringsArray(result, size);
        freeMatrix((void**)result, size);
    }
    else {
        printf("No words found starting with the letter '%c'.\n", letter);
    }

    return 0;
}
