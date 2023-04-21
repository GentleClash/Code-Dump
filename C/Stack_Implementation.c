#include <stdio.h>
#include <unistd.h>


void push ( int *stack, int top, int item );
void pop (int *stack, int top );
void isEmpty (int top);
void isFull ( int top, int maxStack );

int main(){
	int top = -1, item, maxStack, operationChoice;
	
	printf("How many elements in the stack? ");
	scanf("%d", &maxStack);
	
	int stack[maxStack];
	
	
	while ( maxStack ) {
	usleep(2000000);
	printf("What operations you want to do?");
	printf("\n1) PUSH");
	printf("\n2) POP");
	printf("\n3) isEmpty");
	printf("\n4) isFull");
	printf("\nAny other key to end the program\n");
	
	scanf("%d", &operationChoice); 
	
	
	switch ( operationChoice ){
		case 1: if (top >= maxStack-1){ printf("\nStack overflow\n\n"); }
			else{
				printf("Enter the element: ");
				scanf("%d", &item);
				push ( stack, ++(top), item );
				 }
			break;
		
		case 2: if (top == -1){ printf("\nUnderflow\n"); } 
			else{ pop ( stack, (top)-- ); }
			break;
		
		case 3: isEmpty ( top );
			break;
		
		case 4: isFull ( top, maxStack );
			break;
		
		default: exit (1);
		
		}
	}
	
return 0;
}
void push ( int *stack, int top, int item ){

	stack[ top ] = item ;
}
	
	
void pop (int *stack, int top ) { 
	 printf("%d removed\n", stack[ top ]);
	}
void isEmpty (int top){
	top == -1 ? printf("\nTrue\n\n") : printf ("\n\nFalse\n\n");
}
 
void isFull ( int top, int maxStack ){
	top == maxStack-1 ? printf("\nTrue\n\n") : printf("\nFalse\n\n");
}


