#include <stdio.h>
#include <stdlib.h>

//Input polynomials

//Polynomial 1
struct polynomial1 {
	int power;
	int coefficient;
	struct polynomial1 *next;
	}*start1=NULL;
struct polynomial1 * temp1= NULL;
struct polynomial1 * current1=NULL;

struct polynomial1* createNode1( int power, int coefficient );
void addNode1 ( struct polynomial1 * newNode );

//Polynomial 2
struct polynomial2 {
	int power;
	int coefficient;
	struct polynomial2 *next;
	}*start2=NULL;
struct polynomial2 * temp2= NULL;
struct polynomial2 * current2=NULL;

struct polynomial2* createNode2( int power, int coefficient );
void addNode2 ( struct polynomial2 * newNode );

struct resultant {
	int power;
	int coefficient;
	struct resultant *next;
	}*start=NULL;



void displayPolynomial( struct polynomial1 *start1, struct polynomial2 *start2 );
void displayResultant ( struct resultant *start);
void add(struct polynomial1 *start1, struct polynomial2 *start2);
void mul(struct polynomial1 *start1, struct  polynomial2 *start2);


int main(){
int degree, coeff, operationChoice;
printf("Enter the degree of polynomial 1: ");
if( scanf("%d", &degree)!=1 ){
	printf("invalid data type\n");
	return 1;
	}
for ( int i=degree; i>=0; i--){
	printf("Enter the coefficient of term with power %d: ", i);
	scanf("%d", &coeff);
	struct polynomial1 *newNode = createNode1 ( i, coeff );
	addNode1( newNode );
	
}

 
printf("Enter the degree of polynomial 2: ");
if( scanf("%d", &degree)!=1 ){
	printf("invalid data type\n");
	return 1;
	}
for ( int i=degree; i>=0; i--){
	printf("Enter the coefficient of term with power %d: ", i);
	scanf("%d", &coeff);
	struct polynomial2 *newNode = createNode2 ( i, coeff );
	addNode2( newNode );
	
}

displayPolynomial(start1, start2);

printf("\nWhat further operation you want to do?\n");
    printf("Choose from following:(Use the serial numbers as choice)\n");
    printf("1) Add\n");
    printf("2) Multiply\n");
    if(scanf(" %d", &operationChoice)!=1){
        printf("Invalid choice");
        return 2;
    }

    switch ( operationChoice ){
        case 1: add( start1, start2);
                break;
        case 2: mul( start1, start2);
				break;
        default: printf("Wrong input\n");
    }
	
free(start1);free(start2);
return 0;}


struct polynomial1* createNode1( int power, int coefficient ){
	struct polynomial1 * current1= (struct polynomial1 *)malloc(sizeof(struct polynomial1));
		current1->power=power;
		current1->coefficient=coefficient;
		current1->next=NULL;
		return current1;
}

struct polynomial2* createNode2( int power, int coefficient ){
	struct polynomial2 * current2= (struct polynomial2 *)malloc(sizeof(struct polynomial2));
		current2->power=power;
		current2->coefficient=coefficient;
		current2->next=NULL;
		return current2;
}

void addNode1 ( struct polynomial1 * newNode ){
	if (start1==NULL){
		start1=newNode;
		current1=start1;
		temp1=start1;
	}
	else{
		current1=start1;
		while((current1->next)!=NULL){
			current1=current1->next;
		}
		current1->next=newNode;
	}

}

void addNode2 ( struct polynomial2 * newNode ){
	if (start2==NULL){
		start2=newNode;
		current2=start2;
		temp2=start2;
	}
	else{
		current2=start2;
		while((current2->next)!=NULL){
			current2=current2->next;
		}
		current2->next=newNode;
	}

}

void displayPolynomial(struct polynomial1 *start1, struct polynomial2 *start2) {
    struct polynomial1 *temp1 = start1;
    struct polynomial2 *temp2 = start2;

    printf("Polynomials are:\n");
    printf("Polynomial 1: ");
  while (temp1 != NULL) {
    if (temp1->coefficient != 0) {
        if (temp1->coefficient == 1) {
            if (temp1->power == 0) {
                printf("%d", temp1->coefficient);
            } else if (temp1->power == 1) {
                if (temp1->next == NULL || temp1->next->coefficient == 0) {
                    printf("x");
                } else {
                    printf("x + "); 
                }
            } else {
                printf("x^%d + ", temp1->power);
            }
        } else if (temp1->power == 0) {
            printf("%d", temp1->coefficient);
        } else if (temp1->power == 1) {
            if (temp1->next == NULL || temp1->next->coefficient == 0) {
                printf("%dx", temp1->coefficient);
            } else {
                printf("%dx + ", temp1->coefficient);
            }
        } else {
            printf("%dx^%d + ", temp1->coefficient, temp1->power);
        }
    }
    temp1 = temp1->next;
}

    printf("\nPolynomial 2: ");
   while (temp2 != NULL) {
    if (temp2->coefficient != 0) {
        if (temp2->coefficient == 1) {
            if (temp2->power == 0) {
                printf("%d", temp2->coefficient);
            } else if (temp2->power == 1) {
                if (temp2->next == NULL || temp2->next->coefficient == 0) {
                    printf("x");
                } else {
                    printf("x + ");
                }
            } else {
                printf("x^%d + ", temp2->power);
            }
        } else if (temp2->power == 0) {
            printf("%d", temp2->coefficient);
        } else if (temp2->power == 1) {
            if (temp2->next == NULL || temp2->next->coefficient == 0) {
                printf("%dx", temp2->coefficient);
            } else {
                printf("%dx + ", temp2->coefficient);
            }
        } else {
            printf("%dx^%d + ", temp2->coefficient, temp2->power);
        }
    }
    temp2 = temp2->next;
}


    printf("\n");
}


void add(struct polynomial1 *start1, struct polynomial2 *start2) {
    struct polynomial1 *temp1 = start1;
    struct polynomial2 *temp2 = start2;
    struct resultant *start = NULL;
    struct resultant *current = NULL;

    while (temp1 != NULL || temp2 != NULL) {
        int sum = 0;
        struct resultant *newNode = (struct resultant *)malloc(sizeof(struct resultant)); // Declare newNode

        if (temp1 != NULL && temp2 != NULL) {
            // Add coefficients of terms with same power
            if (temp1->power == temp2->power) {
                sum = temp1->coefficient + temp2->coefficient;
                newNode->power = temp1->power; // Assign power directly
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            // Move to the next term with higher power
            else if (temp1->power > temp2->power) {
                sum = temp1->coefficient;
                newNode->power = temp1->power; // Assign power directly
                temp1 = temp1->next;
            } else {
                sum = temp2->coefficient;
                newNode->power = temp2->power; // Assign power directly
                temp2 = temp2->next;
            }
        } else if (temp1 != NULL && temp2 == NULL) {
            sum = temp1->coefficient;
            newNode->power = temp1->power; // Assign power directly
            temp1 = temp1->next;
        } else {
            sum = temp2->coefficient;
            newNode->power = temp2->power; // Assign power directly
            temp2 = temp2->next;
        }

        newNode->coefficient = sum;
        newNode->next = NULL;

        if (start == NULL) {
            start = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = current->next;
        }
    }

    // Display the resultant polynomial
    printf("\nResultant Polynomial: ");
    displayResultant(start);
}




void displayResultant(struct resultant *start) {
    struct resultant *current = start;
    while (current != NULL) {
        if (current->coefficient != 0) {
            if (current->coefficient == 1) {
                if (current->power == 0) {
                    printf("%d", current->coefficient);
                } else if (current->power == 1) {
                    if (current->next != NULL && current->next->coefficient == 0) {
                        printf("x ");
                    } else {
                        printf("x + ");
                    }
                } else {
                    printf("x^%d + ", current->power);
                }
            } else if (current->power == 0) {
                printf("%d", current->coefficient);
            } else if (current->power == 1) {
                if (current->next != NULL && current->next->coefficient == 0) {
                    printf("%dx ", current->coefficient);
                } else {
                    printf("%dx + ", current->coefficient);
                }
            } else {
                printf("%dx^%d + ", current->coefficient, current->power);
            }
        }
        current = current->next;
    }
}


void mul( struct polynomial1 *start1, struct polynomial2 *start2)
{   
    struct polynomial1 *temp1 = start1;
    struct polynomial2 *temp2 = start2;
    struct resultant *start = NULL;
    struct resultant *current = NULL;

    while (temp1 != NULL) {
        temp2 = start2;
        while (temp2 != NULL) {
            int coefficient = temp1->coefficient * temp2->coefficient;
            int power = temp1->power + temp2->power;

            // Check if a term with the same power already exists in the resultant polynomial
            struct resultant *check = start;
            while (check != NULL) {
                if (check->power == power) {
                    check->coefficient += coefficient;
                    break;
                }
                check = check->next;
            }

            // If term with same power does not exist, create a new node in the resultant polynomial
            if (check == NULL) {
                struct resultant *newNode = (struct resultant *)malloc(sizeof(struct resultant));
                newNode->coefficient = coefficient;
                newNode->power = power;
                newNode->next = NULL;

                if (start == NULL) {
                    start = newNode;
                    current = newNode;
                } else {
                    current->next = newNode;
                    current = current->next;
                }
            }

            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    printf("\nResultant Polynomial: ");
    displayResultant( start );
}
