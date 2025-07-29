/*
        Assigned by:
        Matan Kar Mazin #207420415
        Lior Zvieli #211575873
*/

#define _CRT_SECURE_NO_WARNINGS

/* Libraries */

#include <ctype.h>
// #include <malloc.h> //remove before sending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constant definitions */

#define N 3

/* Function declarations */

void Ex1();
void Ex2();
void Ex3();

char** split(char letter, char* str, int* p_size);
void createFile(char* filename);
char commonestLetter(char* filename);
void decode(char* text);

/* Declarations of auxiliary functions */

void printStringsArray(char** str_arr, int size);
void freeMatrix(void** A, int rows);

/* ------------------------------- */

int main() {
    int select = 0, i, all_Ex_in_loop = 0;
    printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
    if (scanf("%d", &all_Ex_in_loop) == 1) do {
            for (i = 1; i <= N; i++) printf("Ex%d--->%d\n", i, i);
            printf("EXIT-->0\n");
            do {
                select = 0;
                printf("please select 0-%d : ", N);
                scanf("%d", &select);
            } while ((select < 0) || (select > N));
            switch (select) {
                case 1:
                    Ex1();
                    break;
                case 2:
                    Ex2();
                    break;
                case 3:
                    Ex3();
                    break;
            }
        } while (all_Ex_in_loop && select);
    return 0;
}

/* Function definitions */

void Ex1() {
    int size = 0;
    char letter, str[100];
    printf("Enter a string: ");
    getchar(); // Consume the newline character left by the previous scanf
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("Enter a letter: ");
    scanf(" %c", &letter);
    char** result = split(letter, str, &size);
    if (result != NULL) {
        printStringsArray(result, size);
        freeMatrix((void**)result, size);
    } else {
        printf("No words found starting with the letter '%c'.\n", letter);
    }
}

void Ex2() {
    char filename[50];
    char mostCommon;
    // Part A: Create a file with user input
    printf("Enter filename for new text file: ");
    scanf("%s", filename);  // Read filename from user
    // Clear the newline character left by scanf
    while (getchar() != '\n');
    createFile(filename);  // Call createFile function
    // Part B: Find the commonest letter in the created file
    mostCommon = commonestLetter(filename);
    if (mostCommon == '0') {
        printf("No letters found in the file or unable to open the file.\n");
    } else {
        printf("The most common letter in file '%s' is '%c'.\n", filename, mostCommon);
    }
}

void Ex3() {
    char str[] = "Btwlzx Dqqes Eq|pj2 Tjhvqujs Iqoqjy bpg Eqfxtx Xcwwtt";
    printf("string before decode:\n%s\n", str);
    decode(str);
    printf("string after decode:\n%s\n", str);
}

char** split(char letter, char* str, int* p_size) {
    char** result = NULL;
    int size = 0;
    char* token;
    char delimiters[] = " \t\n";

    // Convert the letter to both lower and upper case
    char lower_letter = tolower(letter);
    char upper_letter = toupper(letter);

    // Make a copy of the input string to avoid modifying the original
    char* str_copy = strdup(str);
    if (str_copy == NULL) {
        *p_size = 0;
        return NULL;
    }

    // Tokenize the string
    char* context;
    token = strtok(str_copy, delimiters);
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
            result[size] = strdup(token);
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
        token = strtok(NULL, delimiters);
    }
    // Free the copy of the original string
    free(str_copy);
    // Set the size and return the result
    *p_size = size;
    return result;
}


void createFile(char* filename) {
    FILE* file;
    char ch;

    // Open the file for writing
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    printf(
        "Enter text to write to the file. Press Ctrl+D (Linux/Mac) or Ctrl+Z (Windows) to "
        "finish.\n");

    // Read characters from keyboard and write them to the file
    while ((ch = getchar()) != EOF) {
        fputc(ch, file);
    }

    // Close the file
    fclose(file);
    printf("File %s created and written successfully.\n", filename);
}

char commonestLetter(char* filename) {
    FILE* file = fopen(filename, "r");
    char count[26] = {0};
    char c;
    char commonest = '\0';
    int maxCount = 0;

    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    while ((c = fgetc(file)) != EOF) {
        if (isalpha(c)) {    // Check if character is alphabetic
            c = toupper(c);  // Convert to uppercase for uniform comparison
            count[c - 'A']++;
        }
    }

    // Find the most common letter
    for (int i = 0; i < 26; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            commonest = 'A' + i;  // Convert index to corresponding letter
        } else if (count[i] == maxCount && maxCount > 0) {
            // If multiple letters have the same max count, choose the lexicographically largest one
            if ('A' + i > commonest) {
                commonest = 'A' + i;
            }
        }
    }

    fclose(file);
    if (maxCount == 0)
        return '0';
    else
        return commonest;
}

void decode(char* text) {
    int i, j;
    for (i = 0, j = 1; text[i] != '\0'; i++) {
        if (text[i] != ' ') {
            text[i] -= j++;
        } else {
            j = 1;
        }
    }
}

/* Definitions of auxiliary functions */

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

/* Write Definitions Here! */

/* ------------------- */