#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef enum _kState
{
	WORD,
	CONNECTION
} kState;

unsigned int char_to_set(char literal){
    literal = tolower(literal);
    if(literal < 'a' || literal > 'z'){
        return 0;
    }
    else{
        return (1 << (literal-'a'));
    }
}

unsigned int vowel_generation(void){
    unsigned int gen = 0;
    gen |= (1 << ('e'-'a'));
    gen |= (1 << ('y'-'a'));
    gen |= (1 << ('u'-'a'));
    gen |= (1 << ('i'-'a'));
    gen |= (1 << ('o'-'a'));
    gen |= (1 << ('a'-'a'));
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
	unsigned int VOWELS  = 17842449;
	unsigned int set_word_1 = 0, set_word_2 = 0;
	int flag_of_connection = 0;
	char result[1000000] = {0}, word_1[1000] = {0}, word_2[1000] = {0};
	int index = 0, count = 0;
	kState state = WORD;
	while ((ch = getchar()) != EOF){
		switch (state)
		{
			case WORD:
			{
			    if (is_delimiter(ch)) state = CONNECTION;
			    else{
			        set_word_2 |= char_to_set(ch);
			        word_2[index] = ch;
			        index++;
			    }
			}
			break;
			
			case CONNECTION:
			{
			    set_word_2 = set_word_2 & VOWELS;
			    if((set_word_2 & set_word_1) != 0){
			        flag_of_connection = 1;
			        strcat(result, "<<");
			        strcat(result, word_1);
			        strcat(result, ">> and <<");
			        strcat(result, word_2);
			        strcat(result, ">>;\n");
			        count++;
			    }
			    index = 1;
			    set_word_1 = set_word_2 & VOWELS;
			    set_word_2 = 0;
			    set_word_2 |= char_to_set(ch);
			    strcpy(word_1, word_2);
			    memset(word_2, 0, strlen(word_2) * sizeof(int));
			    word_2[0] = ch;
			    state = WORD;
			}
			break;
		}
	}
	set_word_2 = set_word_2 & VOWELS;
	if((set_word_2 & set_word_1) != 0){
		flag_of_connection = 1;
		strcat(result, "<<");
		strcat(result, word_1);
		strcat(result, ">> and <<");
		strcat(result, word_2);
		strcat(result, ">>;\n");
		count++;
	}
	
	if (flag_of_connection){
	    printf("\n\nWe found %d neighboring pairs of words with intersecting vowels:\n%sand took them out.\n", count, result);
	}
	else{
	    printf("\n\nThere are no neighboring words with intersecting vowels.\n");
	}
    return 0;
}
