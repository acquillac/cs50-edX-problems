// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

// 8 bit 1 byte
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // 8 bit 1 byte
    BYTE header[HEADER_SIZE];

    // Copy header from input to output
    fread(&header, sizeof(header), 1, input);
    fwrite(&header, sizeof(header), 1, output);

    // 16 bit2 bytes
    int16_t buffer;

    // read every 2 byte sample
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        // multiply sample by factor
        buffer *= factor;
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
