#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    float data;
    int degree;
    int prev_index;
    struct Node* prev;
    struct Node* foliage[100]; 
} Node;

typedef struct Wood {
    int degree;
    int vertex_count;
    struct Node* vertex_root;
} Wood;

//---------------------------------------
//ФУНКЦИИ ДЛЯ УЗЛОВ ДЕРЕВА

void Create(Node* n){
    n->data = 0;
    n->degree = 0;
    n->prev = 0;
    n->prev_index = 0;
    return;
}

int Search_Degree_Wood(Node* n){
    int max_degree = n->degree;
    for (int i = 0; i < n->degree; i++){
        int degree_subtree = Search_Degree_Wood(n->foliage[i]);
        if (max_degree < degree_subtree){
            max_degree = degree_subtree;
        }
    }
    return max_degree;
}

bool Push(Wood* w, Node* n_father, float val){
    if (n_father == NULL){
        return false;
    }
    if (n_father->degree >= 100){
        return false;
    }
    struct Node* new_n = malloc(sizeof(struct Node));
    if (!new_n){
        return false;
    }
    new_n->data = val;
    new_n->degree = 0;
    new_n->prev = n_father;
    new_n->prev_index = n_father->degree;
    n_father->foliage[n_father->degree] = new_n;
    n_father->degree++;
    w->vertex_count++;
    if (n_father->degree > w->degree){
        w->degree = n_father->degree;
    }
    return true;
}

bool Pop(Wood* w, Node* n){
    if (n == NULL){
        return false;
    }
    if (n->prev == 0){
    	return false;
    }
    for (int i = n->degree-1; i >= 0; i--){
        Pop(w, n->foliage[i]);
    }
    if (n->prev_index != n->prev->degree-1){
        for (int i = n->prev_index; i < n->prev->degree-1; i++){
            n->prev->foliage[i] = n->prev->foliage[i+1];
            n->prev->foliage[i]->prev_index = i;
        }
        n->prev->foliage[n->prev->degree-1] = 0;
    } else n->prev->foliage[n->prev_index] = 0;
    n->prev->degree--;
    free(n);
    w->vertex_count--;
    w->degree = Search_Degree_Wood(w->vertex_root);
    return true;
}

Node* Search(Node* n, float val){
    if (n->data == val){
        return n;
    }
    Node* n_find = NULL;
    for (int i = 0; i < n->degree; i++){
        n_find = Search(n->foliage[i], val);
        if (n_find != NULL){
            break;
        }
    }
    return n_find;
}

bool Val_In_Wood(Node* root, float val){
    if (Search(root, val) != NULL){
        return true;
    }
    return false;
}

bool Modification_Node_Data(Node* n, float val){
    if (n == NULL){
        return false;
    }
    n->data = val;
    return true;
}

void Paint(Node* n, int deep){
    for (int j = 0; j < deep; j++){
        printf("    ");
    }
    printf("%f\n", n->data);
    for (int i = 0; i < n->degree; i++){
        Paint(n->foliage[i], deep+1);
    }
    return;
}


//---------------------------------------
//ОСНОВНАЯ ПРОГА

int main(){
    char stat = 'e';
    float val = 0;
    float val_father = 0;
    
    Wood* wood = malloc(sizeof(struct Wood));
    if (!wood){
        return 1;
    }
    Node* root = malloc(sizeof(struct Node));
    if (!root){
        return 1;
    }
    Create(root);
    wood->degree = 0;
    wood->vertex_count = 1;
    wood->vertex_root = root;
    printf("Добро пожаловать!\n");
    printf("На данный момент дерева не существует. Введите значение корневого узла: ");
    scanf(" %f", &val);
    root->data = val;
    printf("Дерево успешно создано!\n\n");
    printf("----------------------------------\n\n");
    
    
    while ((stat != 'Q') && (stat != 'q')) {
        printf("M для изменения значения узла,\nC для добавления узла,\nD для удаления узла,\nP для текстовой визуализации,\nA для подсчёта количества вершин,\nQ для выхода,\nH для более подробного описания команд.\nВведите букву команды: ");
        scanf(" %c", &stat);
        
        switch(stat){
            
            case 'M':
            case 'm':
            {
                printf("Введите старое значение узла: ");
                scanf(" %f", &val_father);
                printf("Введите новое значение узла: ");
                scanf(" %f", &val);
                if (Modification_Node_Data(Search(root, val_father), val)){
                    printf("Значение изменено.\n\n");
                } else {
                    printf("Узел не найден.\n\n");
                }
            }
            break;
                
            case 'C':
            case 'c':
            {
                printf("Введите значение для нового узла: ");
                scanf(" %f", &val);
                printf("Введите значение отцовского узла: ");
                scanf(" %f", &val_father);
                if (Val_In_Wood(root, val)){
                    printf("Узел с таким значением уже существует.\n\n");
                } else if (Push(wood, Search(root, val_father), val)){
                    printf("Узел добавлен.\n\n");
                } else{
                    printf("Память не выделена, количество потомков у узла превышено или узел не найден.\n\n");
                }
            }
            break;
                
            case 'D':
            case 'd':
            {
                printf("Введите значение удаляемого узла: ");
                scanf(" %f", &val_father);
                if (Pop(wood, Search(root, val_father))){
                    printf("Узел удалён.\n\n");
                } else{
                    printf("Попытка удаления корневого узла или узел не найден.\n\n");
                }
            }
            break;
            
            case 'P':
            case 'p':
            {
                Paint(root, 0);
                printf("\n");
            }
            break;
            
            case 'A':
            case 'a':
            {
                printf("Степень дерева: %d\n", wood->degree);
                printf("Количество вершин в дереве: %d\n\n", wood->vertex_count);
            }
            break;
            
            case 'H':
            case 'h':
            {
                printf("M (Modification) -- позволяет изменить значение любого узла, в т.ч. корневого, без потери предков и потомков.\n");
                printf("C (Create) -- позволяет создать новый узел дерева, прикрепив к любому другому узлу.\n");
                printf("D (Delete) -- позволяет удалить любой узел дерева, кроме корневого. Все поддеревья, исходящие из удаляемого узла, также будут удалены. Для обнуления всего дерева перезагрузите программу.\n");
                printf("P (Painting) -- позволяет в текстовом формате визуализировать дерево.\n");
                printf("A (Account) -- выводит общее количество вершин в дереве с учётом корневого, а также степень дерева.\n");
                printf("Q (Quit) -- выход из программы. При этом существующее дерево полностью удаляется.\n\n");
            }
            break;
        } 
    } 
    printf("\n----------------------------------\n\nУдаление дерева...\n");
    for (int i = root->degree-1; i >= 0; i--){
        Pop(wood, root->foliage[i]);
    }
    free(root);
    wood->vertex_root = NULL;
    free(wood);
    printf("До свидания!\n\n----------------------------------\n");
    return 0;
}
