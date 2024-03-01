#include "compress.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void replaceFileExtension(char *outputFilename, const char *inputFilename, const char *newExtension) {
    strcpy(outputFilename, inputFilename);
    char *lastDot = strrchr(outputFilename, '.');
    if (lastDot != NULL) {
        *lastDot = '\0'; // Remove the original extension.
    }
    strcat(outputFilename, newExtension); // Add the new extension.
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./digitcompress -c|-d <file>\n");
        return 1;
    }

    char outputFilename[256];
    char *mode = argv[1];
    char *inputFilename = argv[2];

    if (strcmp(mode, "-c") == 0) {
        replaceFileExtension(outputFilename, inputFilename, ".bin");
        compressFile(inputFilename, outputFilename);
    } else if (strcmp(mode, "-d") == 0) {
        replaceFileExtension(outputFilename, inputFilename, ".txt");
        decompressFile(inputFilename, outputFilename);
    } else {
        printf("Invalid mode. Use -c for compress or -d for decompress.\n");
        return 1;
    }

    printf("Operation completed successfully. Output file: %s\n", outputFilename);
    return 0;
}
