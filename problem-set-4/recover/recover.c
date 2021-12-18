#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // usage
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw");
        return 1;
    }

    // Open memorycard
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        return 1;
    }

    // seting variables
    int imgCounter = 0;
    int jpgFound = 1;
    int qty = 512;
    char output[8];
    BYTE buffer[512];
    FILE *img;

    // reading file --> fread(buffer, size, qty, file pointer);
    while (fread(&buffer, sizeof(BYTE), qty, file))
    {
        // checking for jpg header
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // if new jpg has been found
            if (jpgFound == 1)
            {
                sprintf(output, "%03i.jpg", imgCounter);
                img = fopen(output, "w");
                fwrite(buffer, sizeof(uint8_t), qty, img);
                jpgFound = 0;
            }
            else
            {
                fclose(img);
                imgCounter++;
                sprintf(output, "%03i.jpg", imgCounter);
                img = fopen(output, "w");
                fwrite(&buffer, sizeof(uint8_t), qty, img);
            }
        }
        else if (jpgFound == 0)
        {
            fwrite(&buffer, sizeof(uint8_t), qty, img);
        }
    }

    // closing memory card
    fclose(file);
    return 0;
}