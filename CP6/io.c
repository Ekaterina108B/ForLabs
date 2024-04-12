#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "applicant.h"
#include "io.h"

/* Applicant IO */
int applicant_read_txt(Applicant *a, FILE *in){
    fscanf(in, "%s", a->name);
    fscanf(in, "%s", a->initials);
    fscanf(in, "%s", a->gender);
    fscanf(in, "%d", &(a->school));
    fscanf(in, "%s", a->medal);
    fscanf(in, "%d", &(a->rus));
    fscanf(in, "%d", &(a->math));
    fscanf(in, "%d", &(a->inf));
    fscanf(in, "%s", a->essay);
    
    return !feof(in);

}

int  applicant_read_bin(Applicant *a, FILE *in){
    fread(a->name, sizeof(char), STR_SIZE, in);
    fread(a->initials, sizeof(char), STR_SIZE, in);
    fread(a->gender, sizeof(char), STR_SIZE, in);
    fread(&(a->school), sizeof(int), 1, in);
    fread(a->medal, sizeof(char), STR_SIZE, in);
    fread(&(a->rus), sizeof(int), 1, in);
    fread(&(a->math), sizeof(int), 1, in);
    fread(&(a->inf), sizeof(int), 1, in);
    fread(a->essay, sizeof(char), STR_SIZE, in);
    
    return !feof(in);
}

void applicant_write_bin(Applicant *a, FILE *out){
    fwrite(a->name, sizeof(char), STR_SIZE, out);
    fwrite(a->initials, sizeof(char), STR_SIZE, out);
    fwrite(a->gender, sizeof(char), STR_SIZE, out);
    fwrite(&(a->school), sizeof(int), 1, out);
    fwrite(a->medal, sizeof(char), STR_SIZE, out);
    fwrite(&(a->rus), sizeof(int), 1, out);
    fwrite(&(a->math), sizeof(int), 1, out);
    fwrite(&(a->inf), sizeof(int), 1, out);
    fwrite(a->essay, sizeof(char), STR_SIZE, out);
}

void applicant_print(Applicant *a){
    printf("Name: %s %s\n", a->name, a->initials);
    printf("Gender: %s\n", a->gender);
    printf("School: %d\n", a->school);
    printf("Medal: %s\n", a->medal);
    printf("Russian language: %d\n", a->rus);
    printf("Profile math: %d\n", a->math);
    printf("Informatics: %d\n", a->inf);
    printf("Essay: %s\n", a->essay);
    printf("\n");
}

