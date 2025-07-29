#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// Function to create a file and write text to it
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

// Function to find the most common letter in the file
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

int main() {
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

    return 0;
}
