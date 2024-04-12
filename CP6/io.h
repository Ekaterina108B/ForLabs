#ifndef _IO_H_
#define _IO_H_

#include "applicant.h"

int  applicant_read_txt(Applicant *a, FILE *in);
int  applicant_read_bin(Applicant *a, FILE *in);
void applicant_write_bin(Applicant *a, FILE *out);
void applicant_print(Applicant *a);

#endif
