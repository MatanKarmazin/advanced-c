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