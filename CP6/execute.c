#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "applicant.h"
#include "io.h"

float average(FILE *in){
    double sum = 0;
    int count_of_applicants = 0;
    Applicant a;
    float result = 0;
    while(applicant_read_bin(&a, in)){
        sum = sum + a.rus + a.math + a.inf;
        count_of_applicants++;
    }
    if (count_of_applicants != 0){
        result = sum / count_of_applicants;
        return result;
    } else {
        printf("Error: incorrect data in the file.\n");
        fclose(in);
        exit(0);
    }
}


int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage:\n\t./execute DB_FILE\n");
        exit(0);
    }

    FILE *in = fopen(argv[1], "rb");
    if (!in) {
        printf("I/O Error: can't open file.\n");
        exit(1);
    }
    
    float aver = average(in);
    int sum = 0;
    Applicant a;
    rewind(in);
    
    while(applicant_read_bin(&a, in)){
        sum = a.rus + a.math + a.inf;
        if (sum > aver && strcmp(a.medal, "no") == 0){
            printf("%s %s, school %d\n", a.name, a.initials, a.school);
        }
    }
    
    fclose(in);
    
    return 0;
}
