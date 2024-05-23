#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "addfuncs.h"
#include "leaf.h"
#include "tree.h"

Tree* CreateTree(void){
    Tree* t = (Tree*)malloc(sizeof(Tree));
    t->root = NULL;
    t->size = 0;
    t->count_opers = 0;
    return t;
}

void NewRoot(Tree* t, Leaf* l){
    t->root = l;
}

void SplittingOper(Tree* tree, Leaf* leaf, semi_stack* exp, Index* in){
    int i = GetIndex(in);
    if ((exp->stack[i][0] == '-' && is_digit(exp->stack[i][1])) || is_digit(exp->stack[i][0])){
        leaf->data_int = char_into_int(exp->stack[i]);
        return;
    } else if (exp->stack[i][0] == '-' && exp->stack[i][1] != '\0'){
    	leaf->data_char = exp->stack[i][1];
    	leaf->minus = true;
    	return;
    } else {
    	leaf->data_char = exp->stack[i][0];
    	if (is_oper(exp->stack[i][0])){
    	    leaf->is_oper = true;
    	    tree->count_opers++;
    	    if (exp->stack[i][0] == '~'){
    	    	leaf->left = CreateLeaf();
    	    	leaf->left->father = leaf;
    	    	leaf->left->older = true;
    	    	NextIndex(in);
    	    	SplittingOper(tree, leaf->left, exp, in);
    	    } else {
    	    	leaf->left = CreateLeaf();
    	    	leaf->left->father = leaf;
    	    	leaf->left->older = true;
    	    	NextIndex(in);
    	    	SplittingOper(tree, leaf->left, exp, in);
    	    	leaf->right = CreateLeaf();
    	    	leaf->right->father = leaf;
    	    	NextIndex(in);
    	    	SplittingOper(tree, leaf->right, exp, in);
    	    }
    	}
    }
}

Tree* ExpressionIntoTree(semi_stack* exp){
    Tree* tree = CreateTree();
    NewRoot(tree, CreateLeaf());
    tree->size = SizeSS(exp);
    Index* in = CreateIndex(SizeSS(exp)-1);
    SplittingOper(tree, tree->root, exp, in);
    DeleteIndex(in);
    DeleteSemi_Stack(exp);
    return tree;    
}

void DeleteTree(Tree* t){
    DeleteLeaf(t->root);
    t->root = NULL;
    free(t);
}

void PrintTree(Leaf* l, int len){
    if(l->right != NULL){ PrintTree(l->right, len+4); }
    PrintTab(len);
    if(l->data_char == '\0'){ printf("%d\n", l->data_int); }
    else if (l->minus){ printf("-%c\n", l->data_char); }
    else {printf("%c\n", l->data_char); }
    if(l->left != NULL){ PrintTree(l->left, len+4); }
}

void Join(Leaf* l, semi_stack* s){
    if(l->right != NULL){
    	Join(l->right, s);
    }
    if (l->left != NULL){
    	Join(l->left, s);
    }
    if(l->data_char == '\0'){
    	int_in_char(s->stack[SizeSS(s)], l->data_int);
    } else if (l->minus) {
    	s->stack[SizeSS(s)][0] = '-';
    	s->stack[SizeSS(s)][1] = l->data_char;
    } else {
    	s->stack[SizeSS(s)][0] = l->data_char;
    }
    s->size++;
}

semi_stack* TreeIntoExpression(Tree* t){
    semi_stack* s = CreateSemi_Stack();
    Join(t->root, s);
    return s;
}

int clean_up(Tree* t, Leaf* l){
    int error = 0;
    if (l->is_oper){
    	if (l->left->is_oper) { error = clean_up(t, l->left); }
    	if (error == 0 && l->right != NULL) { if (l->right->is_oper){ error = clean_up(t, l->right); }}
    	if (error != 0) { return error; }
    }
    
    if (l->data_char == '/'){
    	if (l->left->data_char == '\0' && l->left->data_int == 0){ return 1; }
    	else if (l->right->data_char == '\0' && l->right->data_int == 0){
    	    if (l->father != NULL){
    	    	relocate(l, true, l->older);
    	    } else {
    	    	copy(l, l->right);
    	    	free(l->left);
    	    	if (!l->right->is_oper){
    	    	    free(l->right);
    	    	    l->left = NULL;
    	    	    l->right = NULL;
    	    	} else {
    	    	    l->left = l->right->left;
    	    	    l->left->father = l;
    	    	    l->right = l->right->right;
    	    	    free(l->right->father);
    	    	    l->right->father = l; 
    	    	}
    	    }
    	} else if (l->left->data_char == '\0' && l->right->data_char == '\0'){
    	    if (l->right->data_int%l->left->data_int == 0){
    	    	l->right->data_int /= l->left->data_int;
    	    	l->left->data_int /= l->left->data_int;
    	    }
    	    if (l->left->data_int == 1){
    	    	if (l->father != NULL){
    	    	    relocate(l, true, l->older);
    	    	} else {
    	    	    copy(l, l->right);
    	    	    free(l->left);
    	    	    if (!l->right->is_oper){
    	    	    free(l->right);
    	    	    l->left = NULL;
    	    	    l->right = NULL;
    	    	} else {
    	    	    l->left = l->right->left;
    	    	    l->left->father = l;
    	    	    l->right = l->right->right;
    	    	    free(l->right->father);
    	    	    l->right->father = l; 
    	    	}
    	    	}
    	    }
    	} else if (l->left->data_int == 1 || l->left->data_int == -1){
    	    if (l->right->is_oper){
    	    	if (l->left->data_int == -1){
    	    	    l->data_char = '~';
    	    	    free(l->left);
    	    	    l->left = l->right;
    	    	    l->right = NULL;
    	    	    l->left->older = true;
    	    	} else {
    	    	    copy(l, l->right);
    	    	    DeleteLeaf(l->left);
    	    	    l->left = l->right->left;
    	    	    l->right = l->right->right;
    	    	    free(l->left->father);
    	    	    l->left->father = l;
    	    	    l->right->father = l;
    	    	}
    	    } else {
    	    	if (l->left->data_int == -1){
    	    	    if (l->right->data_char == '\0') { l->right->data_int = -l->right->data_int; }
    	    	    else if (l->right->minus){ l->right->minus = false; }
    	    	    else { l->right->minus = true; }
    	    	}
    	    	if (l->father != NULL){
    	    	    relocate(l, true, l->older);
    	    	} else {
    	    	    copy(l, l->right);
    	    	    free(l->left);
    	    	    if (!l->right->is_oper){
    	    	    free(l->right);
    	    	    l->left = NULL;
    	    	    l->right = NULL;
    	    	} else {
    	    	    l->left = l->right->left;
    	    	    l->left->father = l;
    	    	    l->right = l->right->right;
    	    	    free(l->right->father);
    	    	    l->right->father = l; 
    	    	}
    	    	}
    	    }
    	}
    } else if (l->data_char == '*'){
    	if ((l->right->data_char == '\0' && l->right->data_int == 0) || (l->left->data_char == '\0' && l->left->data_int == 0)){
    	    DeleteLeaf(l->right);
    	    DeleteLeaf(l->left);
    	    l->right = NULL;
    	    l->left = NULL;
    	    l->data_char = '\0';
    	    l->data_int = 0;
    	    l->is_oper = false;
    	} else if (l->right->data_int == 1){
    	    if (l->father != NULL){ relocate(l, false, l->older); }
    	    else {
    	    	copy(l, l->left);
    	    	free(l->right);
    	    	if (!l->left->is_oper){
    	    	    free(l->left);
    	    	    l->left = NULL;
    	    	    l->right = NULL;
    	    	} else {
    	    	    l->right = l->right->right;
    	    	    l->right->father = l;
    	    	    l->left = l->left->left;
    	    	    free(l->left->father);
    	    	    l->left->father = l; 
    	    	}
    	    }
    	} else if (l->left->data_int == 1){
    	    if (l->father != NULL){ relocate(l, true, l->older); }
    	    else {
    	    	copy(l, l->right);
    	    	    free(l->left);
    	    	    if (!l->right->is_oper){
    	    	    free(l->right);
    	    	    l->left = NULL;
    	    	    l->right = NULL;
    	    	} else {
    	    	    l->left = l->right->left;
    	    	    l->left->father = l;
    	    	    l->right = l->right->right;
    	    	    free(l->right->father);
    	    	    l->right->father = l; 
    	    	}
    	    }
    	} else if (l->left->data_char == '\0' && l->right->data_char == '\0'){
    	    l->is_oper = false;
    	    l->data_char = '\0';
    	    l->data_int = l->left->data_int * l->right->data_int;
    	    DeleteLeaf(l->right);
    	    DeleteLeaf(l->left);
    	    l->right = NULL;
    	    l->left = NULL;
    	}
    } else if (l->data_char == '+'){
    	if (l->right->data_char == '\0' && l->right->data_int == 0){
    	    if (l->father != NULL){ relocate(l, false, l->older); }
    	    else {
    	    	copy(l, l->left);
    	    	free(l->right);
    	    	if (!l->left->is_oper){
    	    	    free(l->left);
    	    	    l->left = NULL;
    	    	    l->right = NULL;
    	    	} else {
    	    	    l->right = l->right->right;
    	    	    l->right->father = l;
    	    	    l->left = l->left->left;
    	    	    free(l->left->father);
    	    	    l->left->father = l; 
    	    	}
    	    }
    	} else if (l->left->data_char == '\0' && l->left->data_int == 0){
    	    if (l->father != NULL){ relocate(l, true, l->older); }
    	    else {
    	    	copy(l, l->right);
    	    	    free(l->left);
    	    	    if (!l->right->is_oper){
    	    	    free(l->right);
    	    	    l->left = NULL;
    	    	    l->right = NULL;
    	    	} else {
    	    	    l->left = l->right->left;
    	    	    l->left->father = l;
    	    	    l->right = l->right->right;
    	    	    free(l->right->father);
    	    	    l->right->father = l; 
    	    	}
    	    }
    	} else if (l->left->data_char == '\0' && l->right->data_char == '\0'){
    	    l->is_oper = false;
    	    l->data_char = '\0';
    	    l->data_int = l->left->data_int + l->right->data_int;
    	    DeleteLeaf(l->right);
    	    DeleteLeaf(l->left);
    	    l->right = NULL;
    	    l->left = NULL;
    	}
    } else if (l->data_char == '-') {
    	if (l->right->data_char == '\0' && l->right->data_int == 0){
    	    if (l->left->data_char == '\0'){ l->left->data_int = -(l->left->data_int); }
    	    else if (l->left->minus) { l->left->minus = false; }
    	    else { l->left->minus = true; }
    	    if (l->father != NULL){ relocate(l, false, l->older);}
    	    else {
    	    	copy(l, l->left);
    	    	free(l->right);
    	    	if (!l->left->is_oper){
    	    	    free(l->left);
    	    	    l->left = NULL;
    	    	    l->right = NULL;
    	    	} else {
    	    	    l->right = l->right->right;
    	    	    l->right->father = l;
    	    	    l->left = l->left->left;
    	    	    free(l->left->father);
    	    	    l->left->father = l; 
    	    	}
    	    }
    	} else if (l->left->data_char == '\0' && l->left->data_int == 0){
    	    if (l->father != NULL){ relocate(l, true, l->older); }
    	    else {
    	    	copy(l, l->right);
    	    	    free(l->left);
    	    	    if (!l->right->is_oper){
    	    	    free(l->right);
    	    	    l->left = NULL;
    	    	    l->right = NULL;
    	    	} else {
    	    	    l->left = l->right->left;
    	    	    l->left->father = l;
    	    	    l->right = l->right->right;
    	    	    free(l->right->father);
    	    	    l->right->father = l; 
    	    	}
    	    }
    	} else if (l->left->data_char == '\0' && l->right->data_char == '\0'){
    	    l->is_oper = false;
    	    l->data_char = '\0';
    	    l->data_int = l->right->data_int - l->left->data_int;
    	    DeleteLeaf(l->right);
    	    DeleteLeaf(l->left);
    	    l->right = NULL;
    	    l->left = NULL;
    	}
    } else if (l->data_char == '^') {
    	if (l->left->is_oper || l->left->data_char != '\0'){ return 2; }
    	if (!l->right->is_oper && l->right->minus){
    	    l->right->minus = false;
    	    if (l->left->data_int%2!=0){
    	    	l->data_char = '*';
    	    	int rep = l->left->data_int;
    	    	free(l->left);
    	    	l->left = CreateLeaf();
    	    	l->left->older = true;
    	    	l->left->is_oper = true;
    	    	l->left->data_char = '^';
    	    	l->left->father = l;
    	    	l->left->right = l->right;
    	    	l->right->father = l->left;
    	    	l->right = NULL;
    	    	l->left->left = CreateLeaf();
    	    	l->left->left->older = true;
    	    	l->left->left->data_int = rep;
    	    	l->left->left->father = l->left;
    	    	l->right = CreateLeaf();
    	    	l->right->data_int = -1;
    	    	l->right->father = l;
    	    	return 0;
    	    }
    	}
    	if (l->left->data_int == 0){
    	    l->is_oper = false;
    	    l->data_char = '\0';
    	    l->data_int = 1;
    	    DeleteLeaf(l->right);
    	    DeleteLeaf(l->left);
    	    l->right = NULL;
    	    l->left = NULL;
    	} else if (l->left->data_int == 1){
    	    if (l->father != NULL){ relocate(l, true, l->older); }
    	    else {
    	        copy(l, l->right);
    	    	    free(l->left);
    	    	    if (!l->right->is_oper){
    	    	    free(l->right);
    	    	    l->left = NULL;
    	    	    l->right = NULL;
    	    	} else {
    	    	    l->left = l->right->left;
    	    	    l->left->father = l;
    	    	    l->right = l->right->right;
    	    	    free(l->right->father);
    	    	    l->right->father = l; 
    	    	}
    	    }
    	} else if (l->right->data_char == '\0' && l->right->data_int == 0){
    	    l->is_oper = false;
    	    l->data_char = '\0';
    	    l->data_int = 0;
    	    DeleteLeaf(l->right);
    	    DeleteLeaf(l->left);
    	    l->right = NULL;
    	    l->left = NULL;
    	} else if (l->right->data_char == '\0' && l->right->data_int == 1){
    	    if (l->father != NULL){ relocate(l, true, l->older); }
    	    else {
    	        copy(l, l->right);
    	    	    free(l->left);
    	    	    if (!l->right->is_oper){
    	    	    free(l->right);
    	    	    l->left = NULL;
    	    	    l->right = NULL;
    	    	} else {
    	    	    l->left = l->right->left;
    	    	    l->left->father = l;
    	    	    l->right = l->right->right;
    	    	    free(l->right->father);
    	    	    l->right->father = l; 
    	    	}
    	    }
    	} else if (l->right->data_char == '\0' && l->right->data_int == -1){
    	    if (l->left->data_int%2==0) { l->right->data_int = 1; }
    	    if (l->father != NULL){ relocate(l, true, l->older); }
    	    else {
    	        copy(l, l->right);
    	    	    free(l->left);
    	    	    if (!l->right->is_oper){
    	    	    free(l->right);
    	    	    l->left = NULL;
    	    	    l->right = NULL;
    	    	} else {
    	    	    l->left = l->right->left;
    	    	    l->left->father = l;
    	    	    l->right = l->right->right;
    	    	    free(l->right->father);
    	    	    l->right->father = l; 
    	    	}
    	    }
    	} else if (l->right->data_char == '\0' && l->left->data_int > 0){
    	    l->is_oper = false;
    	    l->data_char = '\0';
    	    l->data_int = xp(l->right->data_int, l->left->data_int);
    	    DeleteLeaf(l->right);
    	    DeleteLeaf(l->left);
    	    l->right = NULL;
    	    l->left = NULL;
    	} else if (l->left->data_int < 0){
    	    if (l->father != NULL){
    	    	l->left->data_int = -(l->left->data_int);
    	    	if(l->older){
    	    	    l->father->left = CreateLeaf();
    	    	    l->father->left->father = l->father;
    	    	    l->father->left->older = true;
    	    	    l->father->left->data_char = '/';
    	    	    l->father->left->is_oper = true;
    	    	    l->father->left->right = CreateLeaf();
    	    	    l->father->left->right->father = l->father->left;
    	    	    l->father->left->right->data_int = 1;
    	    	    l->father->left->left = l;
    	    	    l->father = l->father->left;
    	    	    error = clean_up(t, l->father);
    	    	    return error;
    	    	} else {
    	    	    l->father->right = CreateLeaf();
    	    	    l->father->right->father = l->father;
    	    	    l->father->right->data_char = '/';
    	    	    l->father->right->is_oper = true;
    	    	    l->older = true;
    	    	    l->father->right->right = CreateLeaf();
    	    	    l->father->right->right->father = l->father->right;
    	    	    l->father->right->right->data_int = 1;
    	    	    l->father->right->left = l;
    	    	    l->father = l->father->right;
    	    	    error = clean_up(t, l->father);
    	    	    return error;
    	    	}
    	     } else {
    	    	l->left->left = CreateLeaf();
    	    	l->left->left->father = l->left;
    	    	copy(l->left->left, l->left);
    	    	l->left->left->older = true;
    	    	l->left->right = CreateLeaf();
    	    	l->left->right->father = l->left;
    	    	copy(l->left->right, l->right);
    	    	l->left->data_int = 0;
    	    	l->left->data_char = '^';
    	    	l->left->is_oper = true;
    	    	l->left->minus = false;
    	    	l->data_char = '/';
    	    	l->right->data_int = 1;
    	    	l->right->data_char = '\0';
    	    	l->right->is_oper = false;
    	    	l->right->minus = false;
    	    	error = clean_up(t, l);
    	    	return error;
    	    }
    	}
    } else if (l->data_char == '~') {
    	if (l->left->data_char == '\0' && l->left->data_int == 0){
    	    l->is_oper = false;
    	    l->data_char = '\0';
    	    l->data_int = 0;
    	    DeleteLeaf(l->left);
    	    l->right = NULL;
    	    l->left = NULL;
    	} else if (l->left->data_char == '\0'){
    	    l->is_oper = false;
    	    l->data_char = '\0';
    	    l->data_int = -(l->left->data_int);
    	    DeleteLeaf(l->left);
    	    l->right = NULL;
    	    l->left = NULL;
    	}
    }
    return error;
}

void relocate(Leaf* e, bool x, bool y){
    if(x && y){
	e->father->left = e->right;
	e->right->father = e->father;
	e->right->older = true;
	e->right = NULL;
    } else if(!x && y){
	e->father->left = e->left;
	e->left->father = e->father;
	e->left->older = true;
	e->left = NULL;
    } else if(x && !y){
	e->father->right = e->right;
	e->right->father = e->father;
	e->right->older = false;
	e->right = NULL;
    } else {
	e->father->right = e->left;
	e->left->father = e->father;
	e->left->older = false;
	e->left = NULL;
    }
    e->father = NULL;
    DeleteLeaf(e);
}

void copy(Leaf* l, Leaf* x){
    l->is_oper = x->is_oper;
    l->data_char = x->data_char;
    l->data_int = x->data_int;
    l->minus = x->minus;
}
