/*Write a C/C++ program to implement a parenthesis checker using Stack. Your program will take a
parenthesized expression as input and check whether parentheses are closed properly or not. In this
program, you have to use dynamic memory allocation (DMA) and linked list for the implementation
of stack.
• The expression “[()][()()]()” is a balanced expression
• The expression “[(])” is not a balanced expression.
*/


#include <stdio.h>
#include <stdlib.h>



struct Node{
    char data;
    struct Node *next;
};

struct Node* createNode (char data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node* *top, char bracket){
    struct Node* newNode = createNode(bracket);
    newNode->next = *top;
    *top = newNode;
}

char pop(struct Node* *top){
    if(*top == NULL){
        return "Underflow";
    }
    struct Node* temp = *top;
    char data = temp->data;
    *top = (*top)->next;
    return data;
}


int main(){
    char expression[200];
    printf("Enter the expression: ");
    fgets(expression, 200, stdin);



    struct Node *stack = NULL;
    int valid = 1;
    for(int i = 0; expression[i]!= '\0' && valid==1; i++){
        switch( expression[i] ){
            case '(' : case '{' : case '[' : push(&stack, expression[i]); printf("Pushed %c", expression[i]); break;
            case ')' :
                        if(!(pop(&stack)=='(')){
                                valid = 0;
                                break;
                        }
            case '}' :
                        if(!(pop(&stack)=='{')){
                                valid = 0;
                                break;
                        }
            case ']' :
                        if(!(pop(&stack)=='[')){
                                valid = 0;
                                break;
                        }

        }
    }

    valid==1?printf("Balanced"):printf("Unbalanced");



    return 0;
}