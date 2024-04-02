// Modifies the volume of an audio file
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;
const int CHUNK_SIZE = 1024;

void changeVolume(float factor, short *buffer, size_t size);

int main(int argc, char *argv[]){
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    uint8_t header[HEADER_SIZE];
    int16_t buffer[CHUNK_SIZE];
    size_t samplesRead;

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

    fread(&header, HEADER_SIZE, 1, input);

    fwrite(&header, HEADER_SIZE, 1, output);

    // Read and write the samples
    while ((samplesRead = fread(buffer, sizeof(int16_t), CHUNK_SIZE, input)) > 0) {
        changeVolume(factor, buffer, samplesRead);
        fwrite(buffer, sizeof(int16_t), samplesRead, output);
    }


    // Close files
    fclose(input);
    fclose(output);
}


void changeVolume(float factor, short *buffer, size_t size) {
    for (size_t i = 0; i < size; i++) {
        float sampleFloat = (float)buffer[i] * factor;
            // Ensure the adjusted sample value stays within the range of int16_t
        buffer[i] = (int16_t)(sampleFloat > INT16_MAX ? INT16_MAX : (sampleFloat < INT16_MIN ? INT16_MIN : sampleFloat));

    }
}

