#include <stdio.h>
#include <stdlib.h>

void insert(int *queue, int *front, int *rear, int maxQ, int item);
void delete(int *queue, int *front, int *rear, int maxQ);

int main() {
    int front = 0, rear = 0, maxQ, operationChoice, item;

    printf("How many elements in the queue? ");
    scanf("%d", &maxQ);

    int queue[maxQ];

    while (1) {
        printf("What operations do you want to perform?\n");
        printf("\n1) INSERT");
        printf("\n2) DELETE");
        printf("\nAny other key to end the program\n");

        scanf("%d", &operationChoice);

        switch (operationChoice) {
            case 1:
                if ((front == rear + 1) || ((front == 1) && (rear == maxQ))) {
                    printf("\nOverflow\n\n");
                } else {
                    printf("Enter the element: ");
                    scanf("%d", &item);
                    insert(queue, &front, &rear, maxQ, item);
                }
                break;

            case 2:
                if (front == 0) {
                    printf("\nUnderflow\n");
                } else {
                    delete(queue, &front, &rear, maxQ);
                }
                break;

            default:
                exit(1);
        }
    }
}

void insert(int *queue, int *front, int *rear, int maxQ, int item) {
    if (*front == 0) {
        *front = 1;
        *rear = 1;
    } else if (*rear == maxQ) {
        *rear = 1;
    } else {
        (*rear)++;
    }
    queue[*rear] = item;
}

void delete(int *queue, int *front, int *rear, int maxQ) {
    int item = queue[*front];

    if (*front == *rear) {
        *front = 0;
        *rear = 0;
    } else if (*front == maxQ) {
        *front = 1;
    } else {
        (*front)++;
    }

    printf("%d removed\n", item);
}
