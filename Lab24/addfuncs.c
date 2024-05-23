#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "addfuncs.h"

bool is_digit(char c){
    if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0'){
        return true;
    }
    return false;
}

bool is_oper(char c){
    if(c == '+'|| c == '-' || c == '/' || c == '*' || c == '^' || c == '(' || c == ')' || c == '~'){
        return true;
    }
    return false;
}

bool is_lit(char c){
    if (!is_digit(c) && !is_oper(c) && !(c == ' ')){
        return true;
    }
    return false;
}

bool inss(semi_stack* s, char elem){
    for (int i=0; i<s->size; i++){
        if (s->stack[i][0] == elem){
            return true;
        }
    }
    return false;
}

bool in(char* s, int len, char elem){
    for (int i=0; i<len; i++){
        if (s[i] == elem){
            return true;
        }
    }
    return false;
}

void saw(semi_stack* con, semi_stack* semi_tree, char* m, int l){
    int q = semi_tree->size - 1;
    bool flag = false;
    while (true){
    	for (int j=0; j<l; j++){
    	    if (inss(semi_tree, m[j])){
    	        flag = true;
    	        break;
    	    }
    	}
    	if (!flag){
    	    return;
    	}
    	if (in(m, l, semi_tree->stack[q][0])){
    	    con->stack[con->size][0] = semi_tree->stack[q][0];
    	    con->size++;
    	    semi_tree->stack[q][0] = '\0';
    	    semi_tree->size--;
    	    q--;
    	} else if (semi_tree->stack[q][0] == '('){
    	    return;
    	} else {
    	    q--;
    	}
    	flag = false;
    }
}

semi_stack* CreateSemi_Stack(void){
    semi_stack* s = (semi_stack*)malloc(sizeof(semi_stack));
    s->size = 0;
    for(int i=0; i<MAX_SIZE; i++){
    	for(int j=0; j<MAX_SIZE; j++){
    	    s->stack[i][j] = '\0';
    	}
    }
    return s;
}

semi_stack* reverse_polish_notation(char* exp){
    semi_stack* semi_tree = CreateSemi_Stack();
    semi_stack* con = CreateSemi_Stack();
    int i = 0;
    int ibuf = 0;
    char stat = '8';
    while (exp[i] != '\0'){
        switch(stat){
            
            case '0':
            {
            	while (exp[i] == ' '){
     	           i++;
     	       }
            	if(is_digit(exp[i])){
            	    stat = '1';
   	        } else if(is_oper(exp[i])){
            	    stat = '2';
        	} else if (exp[i] == ' '){
            	    i++;
        	} else {
            	    stat = '3';
        	}
            }
            break;
            
            
            case '1':
            {
                while (is_digit(exp[i])){
                    con->stack[con->size][ibuf] = exp[i];
                    i++;
                    ibuf++;
            	}
            	con->size++;
            	ibuf = 0;
            	stat = '9';
            }
            break;
        
    	    case '2':
    	    {
    	        if (exp[i] == '^'){
    	            char m[] = {'~'};
    	            saw(con, semi_tree, m, 1);
    	            semi_tree->stack[semi_tree->size][0] = '^';
    	            semi_tree->size++;
    	        } else if (exp[i] == '*'){
    	            char m[] = {'~', '^', '/'};
    	            saw(con, semi_tree, m, 3);
    	            semi_tree->stack[semi_tree->size][0] = '*';
    	            semi_tree->size++;
    	        } else if (exp[i] == '/'){
    	            char m[] = {'~', '^', '*'};
    	            saw(con, semi_tree, m, 3);
    	            semi_tree->stack[semi_tree->size][0] = '/';
    	            semi_tree->size++;
    	        } else if (exp[i] == '+'){
    	            char m[] = {'~', '^', '*', '/', '-'};
    	            saw(con, semi_tree, m, 5);
    	            semi_tree->stack[semi_tree->size][0] = '+';
    	            semi_tree->size++;
    	        } else if (exp[i] == '-'){
    	            char m[] = {'~', '^', '*', '/', '+', '-'};
    	            saw(con, semi_tree, m, 6);
    	            semi_tree->stack[semi_tree->size][0] = '-';
    	            semi_tree->size++;
    	        } else if (exp[i] == '('){
    	            semi_tree->stack[semi_tree->size][0] = '(';
    	            semi_tree->size++;
    	            stat = '8';
    	        } else if (exp[i] == ')'){
    	            while(semi_tree->stack[semi_tree->size-1][0] != '('){
    	                con->stack[con->size][0] = semi_tree->stack[semi_tree->size-1][0];
    	                con->size++;
    	                semi_tree->stack[semi_tree->size-1][0] = '\0';
    	                semi_tree->size--;
    	            }
    	            semi_tree->stack[semi_tree->size-1][0] = '\0';
    	            semi_tree->size--;
    	            stat = '9';
    	        }
    	        i++;
    	        if(stat == '2'){
    	            stat = '0';
    	        }
     	   }
     	   break;
     	   
     	   case '3':
     	   {
                con->stack[con->size][ibuf] = exp[i];
                i++;
            	con->size++;
            	ibuf = 0;
            	stat = '9';
     	   }
     	   break;
     	   
     	   case '4':
     	   {
     	   	semi_tree->stack[semi_tree->size][0] = '~';
    	        semi_tree->size++;
    	        i++;
    	        stat = '0';
     	   }
     	   break;
     	   
     	   case '8':
     	   {
     	       while (exp[i] == ' '){
     	           i++;
     	       }
     	       if (exp[i] == '-' && exp[i+1] != '('){
     	           con->stack[con->size][ibuf] = exp[i];
                   i++;
                   ibuf++;
                   stat = '0';
     	       } else if (exp[i] == '-' && exp[i+1] == '('){
     	           stat = '4';
     	       } else {
     	           stat = '0';
     	       }
     	   }
     	   break;
     	   
     	   case '9':
     	   {
     	       while (exp[i] == ' '){
     	           i++;
     	       }
     	       if(is_digit(exp[i]) || is_lit(exp[i]) || exp[i] == '('){
     	           char m[] = {'^'};
     	           saw(con, semi_tree, m, 1);
    	           semi_tree->stack[semi_tree->size][0] = '*';
    	           semi_tree->size++;
    	       }
     	       stat = '0';
     	   }
     	   break;
    	}
    }
    while(semi_tree->size != 0){
	con->stack[con->size][0] = semi_tree->stack[semi_tree->size-1][0];
	con->size++;
	semi_tree->stack[semi_tree->size-1][0] = '\0';
	semi_tree->size--;
	}
	DeleteSemi_Stack(semi_tree);
    return con;
}

void DeleteSemi_Stack(semi_stack* s){
    free(s);
}

int SizeSS(semi_stack* s){
    return s->size;
}

Index* CreateIndex(int i){
    Index* in = (Index*)malloc(sizeof(Index));
    in->index = i;
    return in;
}

int GetIndex(Index* in){
    return in->index;
}

void NextIndex(Index* in){
    in->index--;
}

void DeleteIndex(Index* in){
    free(in);
}

int xp(int x, int y){
    int z = 1;
    for (int i=0; i < y; i++){
    	z *= x;
    }
    return z;
}

int char_into_int(char* s){
    int num=0;
    int j=0;
    int dec = 1;
    while(s[j]!='\0'){ j++; }
    j--;
    int i;
    if (s[0]=='-'){
    	i = 0;
    } else {
    	i = -1;
    }
    while(j>i){
    	if(s[j] == '0'){
    	    num += 0;
    	} else if(s[j] == '1'){
    	    num += 1*dec;
    	} else if(s[j] == '2'){
    	    num += 2*dec;
    	} else if(s[j] == '3'){
    	    num += 3*dec;
    	} else if(s[j] == '4'){
    	    num += 4*dec;
    	} else if(s[j] == '5'){
    	    num += 5*dec;
    	} else if(s[j] == '6'){
    	    num += 6*dec;
    	} else if(s[j] == '7'){
    	    num += 7*dec;
    	} else if(s[j] == '8'){
    	    num += 8*dec;
    	} else if(s[j] == '9'){
    	    num += 9*dec;
    	}
    	j--;
    	dec *= 10;
    }
    if(s[0]=='-'){ num = -num; }
    return num;   
}

void PrintTab(int i){
    while(i>0){
    	printf(" ");
    	i--;
    }
}

void int_in_char(char* s, int num){
    int i=0;
    if (num<0){
    	s[i] = '-';
    	i++;
    	num = -num;
    }
    int num_m = num / 10;
    int dec = 0;
    while(num_m != 0){
    	dec += 1;
    	num_m /= 10;
    }
    if (num == 0){
    	s[i] = '0';
    }
    while(num != 0){
    	if (num%10==0){
    	    s[i+dec] = '0';
    	} else if(num%10==1){
    	    s[i+dec] = '1';
    	} else if(num%10==2){
    	    s[i+dec] = '2';
    	} else if(num%10==3){
    	    s[i+dec] = '3';
    	} else if(num%10==4){
    	    s[i+dec] = '4';
    	} else if(num%10==5){
    	    s[i+dec] = '5';
    	} else if(num%10==6){
    	    s[i+dec] = '6';
    	} else if(num%10==7){
    	    s[i+dec] = '7';
    	} else if(num%10==8){
    	    s[i+dec] = '8';
    	} else if(num%10==9){
    	    s[i+dec] = '9';
    	}
    	dec--;
    	num/=10;
    }
}

Elem* CreateElem(void){
    Elem* e = (Elem*)malloc(sizeof(Elem));
    for (int i=0; i<100; i++) { e->data[i] = '\0'; }
    e->r = NULL;
    e->l = NULL;
    return e;
}

semi_list* CreateSemi_List(Elem* e){
    semi_list* sl = (semi_list*)malloc(sizeof(semi_list*));
    sl->start = e;
    return sl;
}

pointer* CreatePoint(Elem* e){
    pointer* p = (pointer*)malloc(sizeof(pointer));
    p->point = e;
    return p;
}

void fill_with_brackets(pointer* p, char elem){
    pointer* tab = (pointer*)malloc(sizeof(pointer));
    tab->point = p->point->r;
    p->point->data[0] = '(';
    p->point->r = CreateElem();
    p->point->r->l = p->point;
    p->point->r->r = CreateElem();
    p->point->r->r->data[0] = elem;
    p->point->r->r->l = p->point->r;
    p->point->r->r->r = CreateElem();
    p->point->r->r->r->l = p->point->r->r;
    p->point->r->r->r->r = CreateElem();
    p->point->r->r->r->r->data[0] = ')';
    p->point->r->r->r->r->l = p->point->r->r->r;
    p->point->r->r->r->r->r = tab->point;
    if (tab->point != NULL){
    	tab->point->l = p->point->r->r->r->r;
    }
    free(tab);
}

void fill(pointer* p, char elem){
    pointer* tab = (pointer*)malloc(sizeof(pointer));
    tab->point = p->point->r;
    p->point->r = CreateElem();
    p->point->r->l = p->point;
    p->point->r->data[0] = elem;
    p->point->r->r = CreateElem();
    p->point->r->r->l = p->point->r;
    p->point->r->r->r = tab->point;
    if (tab->point != NULL){
    	tab->point->l = p->point->r->r;
    }
    free(tab);
}

void Analyze(semi_stack* s, Index* in, pointer* p, int level){
    char elem;
    if (GetIndex(in) < 0){ return; }
    bool flag_digit = false;
    if ((s->stack[GetIndex(in)][0] == '-' && s->stack[GetIndex(in)][1] != '\0') || !is_oper(s->stack[GetIndex(in)][0])) { flag_digit = true; }
    elem = s->stack[GetIndex(in)][0];
    if (!flag_digit){
        if(elem == '+' && s->stack[GetIndex(in)+1][0] == '-'){
            fill_with_brackets(p, elem);
            NextIndex(in);
            pointer* p1 = CreatePoint(p->point->r->r->r);
            pointer* p2 = CreatePoint(p->point->r);
            Analyze(s, in, p1, 0);
            NextIndex(in);
            Analyze(s, in, p2, 0);
        } else if (elem == '+' || elem == '-'){
            if (level > 0){
            	fill_with_brackets(p, elem);
            	NextIndex(in);
            	pointer* p1 = CreatePoint(p->point->r->r->r);
            	pointer* p2 = CreatePoint(p->point->r);
            	Analyze(s, in, p1, 0);
            	NextIndex(in);
            	Analyze(s, in, p2, 0);
            } else {
            	fill(p, elem);
            	NextIndex(in);
            	pointer* p1 = CreatePoint(p->point->r->r);
            	pointer* p2 = CreatePoint(p->point);
            	Analyze(s, in, p1, 0);
            	NextIndex(in);
            	Analyze(s, in, p2, 0);
            }
        } else if (elem == '*' && s->stack[GetIndex(in)+1][0] == '/'){
            fill_with_brackets(p, elem);
            NextIndex(in);
            pointer* p1 = CreatePoint(p->point->r->r->r);
            pointer* p2 = CreatePoint(p->point->r);
            Analyze(s, in, p1, 0);
            NextIndex(in);
            Analyze(s, in, p2, 0);
        } else if (elem == '*' || elem == '/'){
            if (level > 1){
            	fill_with_brackets(p, elem);
            	NextIndex(in);
            	pointer* p1 = CreatePoint(p->point->r->r->r);
            	pointer* p2 = CreatePoint(p->point->r);
            	Analyze(s, in, p1, 1);
            	NextIndex(in);
            	Analyze(s, in, p2, 1);
            } else {
                fill(p, elem);
            	NextIndex(in);
            	pointer* p1 = CreatePoint(p->point->r->r);
            	pointer* p2 = CreatePoint(p->point);
            	Analyze(s, in, p1, 1);
            	NextIndex(in);
            	Analyze(s, in, p2, 1);
            }
        } else if (elem == '^'){
            if (level > 2){
            	fill_with_brackets(p, elem);
            	NextIndex(in);
            	pointer* p1 = CreatePoint(p->point->r->r->r);
            	pointer* p2 = CreatePoint(p->point->r);
            	Analyze(s, in, p1, 2);
            	NextIndex(in);
            	Analyze(s, in, p2, 2);
            } else {
                fill(p, elem);
            	NextIndex(in);
            	pointer* p1 = CreatePoint(p->point->r->r);
            	pointer* p2 = CreatePoint(p->point);
            	Analyze(s, in, p1, 2);
            	NextIndex(in);
            	Analyze(s, in, p2, 2);
            }
        } else {
            p->point->data[0] = '-';
            p->point->r = CreateElem();
            p->point->r->l = p->point;
            p->point->r->data[0] = '(';
            p->point->r->r = CreateElem();
            p->point->r->r->l = p->point->r;
            p->point->r->r->r = CreateElem();
            p->point->r->r->r->data[0] = ')';
            p->point->r->r->r->l = p->point->r->r;
            pointer* p1 = CreatePoint(p->point->r->r);
            NextIndex(in);
            Analyze(s, in, p1, 3);
        }
    } else {
    	if (p->point->l != NULL){
    	    if(p->point->l->data[0] != '(' && s->stack[GetIndex(in)][0] == '-'){
    	    	pointer* tab = (pointer*)malloc(sizeof(pointer));
    		tab->point = p->point->r;
    		p->point->data[0] = '(';
    		p->point->r = CreateElem();
    		p->point->r->l = p->point;
    		p->point->r->r = CreateElem();
    		p->point->r->r->l = p->point->r;
    		p->point->r->r->data[0] = ')';
    		p->point->r->r->r = tab->point;
    		if (tab->point != NULL){
    		    tab->point->l = p->point->r->r;
    		}
    		free(tab);
    		p->point = p->point->r;
    	    }
    	}
    	int i=0;
    	while (s->stack[GetIndex(in)][i] != '\0'){
    	    p->point->data[i] = s->stack[GetIndex(in)][i];
    	    i++;
    	}
    }
    free(p);
}

void math_expression(semi_stack* s, char* exp){
    semi_list* le = CreateSemi_List(CreateElem());
    Index* in = CreateIndex(SizeSS(s)-1);
    pointer* p2 = CreatePoint(le->start);
    Analyze(s, in, p2, 0);
    pointer* p = CreatePoint(le->start);
    while (p->point->l != NULL) { p->point = p->point->l; }
    free(in);
    int i = 0;
    while (p->point != NULL){
    	int j=0;
    	while (p->point->data[j] != '\0'){
    	    exp[i] = p->point->data[j];
    	    i++;
    	    j++;
    	}
    	if (p->point->r == NULL) {
    	    free(p->point);
    	    p->point = NULL;
    	}
    	else {
    	    p->point = p->point->r;
    	    free(p->point->l);
    	}
    }
    free(p);
    free(le);
    free(s);
}

char* clear_space(char* exp, char* neww){
    for (int i=0; i<MAX_SIZE; i++){ neww[i] = '\0'; }
    int i = 0;
    int j = 0;
    while (exp[j] != '\0'){
    	if (exp[j] != ' ' && exp[j] != '\n'){
    	    neww[i] = exp[j];
    	    i++;
    	}
    	j++;
    }
    return neww;
}
