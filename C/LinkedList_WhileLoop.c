//Basic linked list program
//Add, View and Delete Year of Births.

/*The program will keep taking inputs until the user decides otherwise*/

#include <stdio.h>
#include <stdlib.h>

//Structure of our linked list
struct node{
    int yearOfBirth;
    struct node *next;
}*start=NULL;
struct node *current=NULL; //Always set to current node
struct node *temp=NULL; //Will use while displaying content

struct node* createNode( int year ); //To create new nodes
void addNode( struct node* newNode );//To add new node at end of current node
void addAtPosition(struct node* newNode, int position );//To add new node at a given position
void deleteNode( int position );//To delete node from provided position
void displayLinkedList( struct node *start );//To display the nodes
int size( struct node* start); //To compute the length of list

int main(){
    int year, position, operationChoice;
    char choice;
    printf("Enter year of birth: ");
    if(scanf("%d", &year)!=1){      //Takes input and checks if user has input valid data type
        printf("Invalid input");
        return 1;
    }


    struct node *newNode = createNode(year); //First node created and added to the linked list
    addNode(newNode);

    printf("Do you want to continue?\n[Y/y](for Yes)\n[Any other key](for No)\n");
    scanf(" %c", &choice);

    while(choice=='Y'||choice=='y'){

        printf("Enter year of birth: ");
        if(scanf(" %d", &year)!=1){      //Checks if user has input valid data type
            printf("Invalid input");
            return 1;
        }

        struct node *newNode = createNode(year);
        addNode(newNode);

        printf("Do you want to continue?\n[Y/y](for Yes)\n[Any other key](for No)\n");
        scanf(" %c", &choice);
    }

    printf("What further operation you want to do?\n");
    printf("Choose from following:(Use the serial numbers as choice)\n");
    printf("1) Print the linked list\n");
    printf("2) Insert new element at desired position\n");
    printf("3) Delete an element at desired input\n");
    if(scanf(" %d", &operationChoice)!=1){
        printf("Invalid choice");
        return 2;
    }

    switch ( operationChoice ){
        case 1: displayLinkedList( start );
                break;
        case 2: printf("Enter the year of birth: ");
                if(scanf(" %d", &year)!=1){      
                printf("Invalid input");
                return 1;
                }
                struct node *newNode = createNode(year); 
                printf("Enter the position where you want to insert it: ");
                scanf(" %d", &position);
                addAtPosition( newNode, position);
                displayLinkedList( start );
                break;
        case 3: printf("Enter the position: ");
                if(scanf(" %d", &position)!=1){      
                printf("Invalid input");
                return 1;
                }
                deleteNode( position );
                displayLinkedList( start );
                break;
    }

    free(start);
    return 0;
}

struct node* createNode( int year ){
    struct node *newNode= (struct node *)malloc(sizeof(struct node));
    newNode->yearOfBirth = year;
    newNode->next=NULL;
    return newNode;
}

void addNode(struct node* newNode){

if(start==NULL){ //No initial nodes
        start=newNode;
        temp=start;     //temp will remain at start position and will be used while printing content
        current=start;  //current implies the current node
        }
    else{
        current=start;
        while((current->next)!=NULL){
            current=current->next;
        }
        current->next= newNode;

    }
}

void displayLinkedList( struct node *start ){
     temp = start;
     int counter=1;
     while (temp != NULL) {
        printf("Person %d year of birth is %d\n",counter++, temp->yearOfBirth);
        temp = temp->next;

    }
}

void addAtPosition(struct node* newNode, int position ){
    newNode->next=NULL;
    current=start;
    int length = size( start ); //Length of list
    if (position < 1 || position > length + 1) {
        printf("Invalid position\n");
        return;
    }

    current = start;

    if (position==1){
        newNode->next=start->next;
        start->next=newNode;
    }
    else{
        for(int i=1; i< position-1; ++i){
            current=current->next;
        }
        newNode->next=current->next;
        current->next=newNode;
    }
}

void deleteNode( int position ){
    current=start;
    int length=size( start );

    if (position < 1 || position > length + 1) {
        printf("Invalid position\n");
        return;
    }

    current = start;
    if(position==1){
        start=start->next;
    }
    for(int i=1; i< position-1; ++i){
        current=current->next;
    }
    current->next=current->next->next;
}

int size( struct node* start){
    int length = 0; 
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;

}