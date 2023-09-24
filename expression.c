#include <stdio.h>
#include <stdlib.h>
#include "abstract_stack.c"

int getSize (char * s) {
    char * t;
    int size = 0;

    for (t = s; *t != '\0'; t++) {
        size++;
    }

    return size-1;
}

bool isOpening(char c){
    return (c == '(' || c == '{' || c == '[' || c == '<');
}
bool isClosing(char c){
    return (c == ')' || c == '}' || c == ']' || c == '>');
}
bool isMatchingPair(char character1, char character2)
{
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else if ( character1 == '<' && character2 == '>'){
        return 1;
    }
    else
        return 0;
}
bool is_valid(char* str){
    struct Stack* stack = init_stack();
    for (size_t i = 0; i < getSize(str); i++){
        if(isOpening(str[i])){
            push(str[i],stack);
        }
        else if(isClosing(str[i])){
            if(isEmpty(stack)){
                return false;
            }
            else{
                if(isMatchingPair(get_top(stack),str[i])){
                    pop(stack);
                }
            }
        }
    }
    return isEmpty(stack);
}
int main(){
    char* exp;
    printf("Give in an expression with maximum of 100 characters: ");
    fgets(exp,100,stdin);
    
    if(is_valid(exp)){
        printf("\nYour expression is valid!\n");
    }
    else{
        printf("\nYour expression is NOT valid\n");
    }
    return 0;
}