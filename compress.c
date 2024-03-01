#include "compress.h"
#include <stdio.h>
#include <stdlib.h>

unsigned char digitToInvertedBinary(char digit) {
    unsigned char binary = (unsigned char)(digit - '0'); 
    return (unsigned char)0xF - binary; 
}

char invertedBinaryToDigit(unsigned char binary) {
    unsigned char originalBinary = (~binary) & 0x0F;
    char digit = originalBinary + '0';
    return digit;
}

void compressFile(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "wb");
    if (!inputFile || !outputFile) {
        perror("Error opening file");
        exit(1);
    }

    int digit1, digit2;
    unsigned char buffer;
    while((digit1 = fgetc(inputFile)) != EOF){
        digit2 = fgetc(inputFile);
        if(digit2 != EOF){
            buffer = digitToInvertedBinary(digit1) << 4 | digitToInvertedBinary(digit2);
        }
        else{
            buffer = digitToInvertedBinary(digit1) << 4;
        }
        fwrite(&buffer, sizeof(unsigned char), 1, outputFile);
    }
    fclose(inputFile);
    fclose(outputFile);    
}

void decompressFile(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "rb");
    FILE *outputFile = fopen(outputFileName, "w");
    if (!inputFile || !outputFile) {
        perror("Error opening file");
        exit(1);
    }

    unsigned char buffer;
    while (fread(&buffer, sizeof(unsigned char), 1, inputFile) == 1) {
        fputc(invertedBinaryToDigit(buffer >> 4), outputFile);
        // Check if the second half of the byte is not padding.
        if ((buffer & 0x0F) != 0x0) { 
            fputc(invertedBinaryToDigit(buffer & 0x0F), outputFile);
        }
    }

    fclose(inputFile);
    fclose(outputFile);
}
