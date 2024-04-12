#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "applicant.h"
#include "io.h"

int main(int argc, char *argv[]){
    
    if (argc != 2){
        printf("Usage:\n\t./print DB_FILE\n");
        exit(0);
    }
    
    FILE *in = fopen(argv[1], "r");
    if (!in){
        printf("I/O Error: can't open file.\n");
        exit(1);
    }
    
    Applicant a;
    
    while (applicant_read_bin(&a, in)){
        applicant_print(&a);
    }
    
    fclose(in);
    
    return 0;
}
