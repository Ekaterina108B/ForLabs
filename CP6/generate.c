#include <stdio.h>
#include <stdlib.h>

#include "applicant.h"
#include "io.h"

int main(int argc, char *argv[]){
    if (argc != 3){
        printf("Usage:\n\t./generate FILE_FROM FILE_TO\n");
        exit(0);
    }
    
    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "wb");
    
    if (!in){
        printf("I/O Error: can't open input file.\n");
        fclose(out);
        exit(1);
    }
    if (!out){
        printf("I/O Error: can't open output file.\n");
        fclose(in);
        exit(1);
    }
    
    Applicant a = {0};
    
    while (applicant_read_txt(&a, in)){
            applicant_write_bin(&a, out);
    }
    
    fclose(in);
    fclose(out);
    
    return 0;
}
