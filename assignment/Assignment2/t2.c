#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to create a file with user input
void createFile(char *filename) {
    FILE *fp;
    char input[100];

    // Open file for writing
    fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error opening file '%s' for writing!\n", filename);
        return;
    }

    printf("Enter a sequence of characters (press Enter to finish):\n");

    // Read characters from stdin until Enter is pressed
    fgets(input, sizeof(input), stdin);

    // Write the input string to the file
    fprintf(fp, "%s", input);

    printf("File '%s' successfully created with content:\n%s\n", filename, input);

    // Close the file
    fclose(fp);
}

// Function to find the most common letter in a text file
char commonestLetter(char *filename) {
    FILE *fp;
    int count[26] = {0};  // Array to count occurrences of each letter
    char c;
    char commonest = '\0';
    int maxCount = 0;

    // Open file for reading
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file '%s' for reading!\n", filename);
        return '0';
    }

    // Read characters and count occurrences
    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c)) {  // Check if character is alphabetic
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

    // Close the file
    fclose(fp);

    if (maxCount == 0) {
        return '0';  // No letters found in the file
    } else {
        return commonest;  // Return the commonest letter
    }
}

int main() {
    char filename[50];
    char mostCommon;

    // Part A: Create a file with user input
    printf("Enter filename for new text file: ");
    scanf("%s", filename);  // Read filename from user

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
