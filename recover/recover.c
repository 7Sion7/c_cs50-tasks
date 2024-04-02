#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512
#define FILENAME_SIZE 8

int main(int argc, char *argv[]){
    if (argc != 2){
        fprintf(stderr, "Usage: ./recover image\n"); //stderr is to differentiate error messages from standard output
        return 1;
    }

    char *input_fileName = argv[1];

    FILE *input_file = fopen(input_fileName, "r");
    if (input_file == NULL)
    {
        fprintf(stderr, "Could not open %s for reading.\n", input_fileName);
        return 1;
    }

    uint8_t buffer[BLOCK_SIZE];
    char filename[FILENAME_SIZE];
    FILE *output_file = NULL;
    int jpg_count = 0;
    int found_jpg = 0;

    while (fread(buffer, BLOCK_SIZE, 1, input_file)){

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0){
            if (found_jpg)
            {
                fclose(output_file);
            } else {
                found_jpg = 1;
            }

            sprintf(filename, "%03d.jpg", jpg_count++);
            output_file = fopen(filename, "w");
            if (output_file == NULL){
                fclose(input_file);
                fprintf(stderr, "Could not create %s.\n", filename);
                return 1;
            }
        }

        if (found_jpg){
            fwrite(buffer, BLOCK_SIZE, 1, output_file);
        }
    }

    fclose(input_file);
    if (output_file != NULL) {
        fclose(output_file);
    }

    return 0;
}

