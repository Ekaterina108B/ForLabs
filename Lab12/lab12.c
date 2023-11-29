#include <stdio.h>

typedef enum _kState
{
	FIND,
	NUMBER_CHECK,
	CONTINUE,
	CHECK_ZERO
} kState;

int is_digit(char literal){
    if (literal >= '0' && literal <= '9'){
        return 1;
    }
    return 0;
}

int is_delimiter(int literal){
    if (literal == ' ' || literal == ',' || literal == '\t' || literal == '\n'){
        return 1;
    }
    return 0;
}

int reverse(int num){
    int re_num = 0;
    while(num != 0){
        re_num = re_num * 10 + (num % 10);
        num = num / 10;
    }
    return re_num;
}

int is_sign(char literal){
    if (literal == '+' || literal == '-'){
        return 1;
    }
    return 0;
}

int main(void){
	char ch, last_ch = ' ';
	int result = 0;
	kState state = NUMBER_CHECK;
	while ((ch = getchar()) != EOF){
		switch (state)
		{
			case FIND:
			{
			    if (is_delimiter(ch)) state = NUMBER_CHECK;
			}
			break;
			
			case NUMBER_CHECK:
			{
			    if(is_digit(ch)){
			        if (ch == last_ch){
			            last_ch = ' ';
			            state = CONTINUE;
			            }
			        else if(ch == '0' && last_ch == ' '){
			            state = CHECK_ZERO;
			        }
			        else{
			            last_ch = ch;
			        }
			    }
			    else if(is_delimiter(ch)){
			        result = result * 10 + 2;
			        last_ch = ' ';
			    }
			    else if(is_sign(ch) && is_delimiter(last_ch)){
			        continue;
			    }
			    else{
			        result = result * 10 + 3;
			        state = FIND;
				last_ch = ' ';
			    }
			}
			break;
			
			case CONTINUE:
			{
			    if(is_digit(ch)){
			        continue;
			    }
			    else if(is_delimiter(ch)){
			        result = result * 10 + 1;
			        state = NUMBER_CHECK;
			    }
			    else{
			        result = result * 10 + 3;
			        state = FIND;
			    }
			}
			break;
			
			case CHECK_ZERO:
			{
			    if(ch == '0'){
			        continue;
			    }
			    else if(is_digit(ch)){
			        state = NUMBER_CHECK;
			        last_ch = ch;
			    }
			    else if(is_delimiter(ch)){
			        result = result * 10 + 2;
			        state = NUMBER_CHECK;
			    }
			    else{
			        result = result * 10 + 3;
			        state = FIND;
			    }
			}
			break;
		}
	}
	
	if(state == NUMBER_CHECK || state == CHECK_ZERO){
	    result = result * 10 + 2;
	}
	else if(state == CONTINUE){
	    result = result * 10 + 1;
	}
	result = reverse(result);
	printf("\n");
	while(result != 0){
        if(result % 10 == 1){
            printf("False | ");
        }
        else if (result % 10 == 2){
            printf("True | ");
        }
        else if (result % 10 == 3){
            printf("Incorrect input or not a number | ");
        }
        result = result / 10;
    }
    printf("\n");
    return 0;
}
