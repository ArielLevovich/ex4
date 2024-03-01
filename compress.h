#ifndef COMPRESS_H
#define COMPRESS_H

// Function to compress a given text file and save the result in a binary file.
void compressFile(const char *inputFileName, const char *outputFileName);

// Function to decompress a given binary file and save the result in a text file.
void decompressFile(const char *inputFileName, const char *outputFileName);

#endif // COMPRESS_H
