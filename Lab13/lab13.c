#include <stdio.h>
#include <ctype.h>
unsigned int lu = 1;

typedef enum _kState
{
	FIND,
	WORD,
	CONNECTION
} kState;

unsigned int char_to_set(literal){
    literal = tolower(literal);
    if(literal < 'a' || literal > 'z'){
        return 0;
    }
    else{
        return lu << (literal-'a');
    }
}

int vowel_generation(void){
    unsigned int gen;
    gen = (lu << ('a'-'a') | lu << ('e'-'a') | lu << ('i'-'a') | lu << ('o'-'a') | lu << ('u'-'a'));
    return gen;
}

int is_delimiter(int literal){
    if (literal == ' ' || literal == ',' || literal == '\t' || literal == '\n'){
        return 1;
    }
    return 0;
}

int main(void){
	char ch;
	unsigned int VOWELS  = vowel_generation();
	unsigned int set_word_1 = 0, set_word_2 = 0;
	int flag_of_connection = 0;
	kState state = WORD;
	while ((ch = getchar()) != EOF){
		switch (state)
		{
			case FIND:
			{
			    if (is_delimiter(ch)) state = WORD;
			}
			break;
			
			case WORD:
			{
			    if (is_delimiter(ch)) state = CONNECTION;
			    else{
			        set_word_2 = set_word_2 | char_to_set(ch);
			    }
			}
			break;
			
			case CONNECTION:
			{
			    set_word_2 = set_word_2 & VOWELS;
			    if(set_word_2 & set_word_1 != 0){
			        flag_of_connection = 1;
			    }
			    set_word_1 = set_word_2;
			    set_word_2 = 0;
			    set_word_2 = set_word_2 | char_to_set(ch);
			    state = WORD;
			}
			break;
		}
	}
	set_word_2 = set_word_2 & VOWELS;
	if(set_word_2 & set_word_1 != 0){
		flag_of_connection = 1;
	}
	
	if (flag_of_connection){
	    printf("\nTRUE\n");
	}
	else{
	    printf("\nFALSE\n");
	}
    return 0;
}
