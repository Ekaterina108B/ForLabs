#include <stdio.h>
#include <ctype.h>

typedef enum _kState
{
	FIND,
	NUMBER_CHECK
} kState;

int is_digit(char literal){
    if ((literal >= '0' && literal <= '9') || (literal == 'a' || literal == 'b' || literal == 'c' || literal == 'd' || literal == 'e' || literal == 'f' || literal == 'A' || literal == 'B' || literal == 'C' || literal == 'D' || literal == 'E' || literal == 'F')) {
        return 1;
    }
    return 0;
}

int is_delimiter(int literal){
    if (isspace(literal) || literal == ',' || literal == '\t' || literal == '\n'){
        return 1;
    }
    return 0;
}

int hex_to_dec(char literal){
    if (literal == '0') return 0;
    if (literal == '1') return 1;
    if (literal == '2') return 2;
    if (literal == '3') return 3;
    if (literal == '4') return 4;
    if (literal == '5') return 5;
    if (literal == '6') return 6;
    if (literal == '7') return 7;
    if (literal == '8') return 8;
    if (literal == '9') return 9;
    if (literal == 'a' || literal == 'A') return 10;
    if (literal == 'b' || literal == 'B') return 11;
    if (literal == 'c' || literal == 'C') return 12;
    if (literal == 'd' || literal == 'D') return 13;
    if (literal == 'e' || literal == 'E') return 14;
    if (literal == 'f' || literal == 'F') return 15;
}

int main(void){
	char ch;
	unsigned int number = 0, sum_number = 0;
	int if_number = 0;
	kState state = NUMBER_CHECK;
	while ((ch = getchar()) != EOF)
	{
		switch (state)
		{
			case FIND:
			{
			    if (is_delimiter(ch)) state = NUMBER_CHECK;
			}
			break;
			
			case NUMBER_CHECK:
			{
			    if((is_digit(ch)) && (hex_to_dec(ch) & 1)){
			        number += hex_to_dec(ch);
			    }
			    else if(is_digit(ch)){
			        number = number;
			    }
			    else if(is_delimiter(ch)){
			        sum_number += number;
			        number = 0;
			    }
			    else{
			        number = 0;
			        state = FIND;
			    }
			}
			break;
		}
	}
			
	printf("%X\n", sum_number);
    return 0;
}
