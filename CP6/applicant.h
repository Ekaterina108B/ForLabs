#ifndef _APPLICANT_H_
#define _APPLICANT_H_

#define STR_SIZE 24

typedef struct{
    char name[STR_SIZE];
    char initials[STR_SIZE];
    char gender[STR_SIZE];
    int school;
    char medal[STR_SIZE];
    int rus;
    int math;
    int inf;
    char essay[STR_SIZE];
} Applicant;

#endif

