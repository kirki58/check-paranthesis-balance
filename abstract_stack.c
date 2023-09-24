#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    char data;
    struct Node* next;
};

struct Stack{
    int top;
    struct Node* list;
};

struct Stack* init_stack(){
    struct Stack* new_stack = (struct Stack*) malloc(sizeof(struct Stack));
    new_stack->top = -1;
    new_stack->list = (struct Node*) malloc(sizeof(struct Node));
    return new_stack;
}

bool isEmpty(struct Stack* stack){
    return (stack->top<=-1);
}

void print_stack(struct Stack* stack){
    if(!isEmpty(stack)){
        struct Node* temp = stack->list;
        printf("[ ");
        for (int i = 0; i <= stack->top; i++)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("]\n");
    }
    else{
        printf("[ ]\n");
    }
}

void push(char val, struct Stack* stack){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = stack->list;
    stack->top++;
    stack->list = newNode;
}

void pop(struct Stack* stack){
    if(!isEmpty(stack)){
        stack->top--;
        struct Node* current_top = stack->list;
        stack->list=stack->list->next;
        free(current_top);
    }
}
int get_top(struct Stack* stack){
    if(!isEmpty(stack)){
        return stack->list->data;
    }
    else{
        return -1;
    }
}