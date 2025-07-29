#include <stdio.h>
#include <stdlib.h>

void createFile(char *filename) {
    FILE *file;
    char ch;
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    printf("Enter text to write to the file. Press Ctrl+Z to finish.\n");
    while ((ch = getchar()) != EOF) {
        fputc(ch, file);
    }

    fclose(file);
    printf("File %s created and written successfully.\n", filename);
}

int main() {
    char filename[100];

    printf("Enter the filename: ");
    scanf("%s", filename);
    createFile(filename);

    return 0;
}
