#include <stdio.h>
#include "queue.h"

#define MAX 5
int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if(rear == MAX-1)
        printf("Queue Overflow!\n");
    else {
        if(front == -1) front = 0;
        queue[++rear] = x;
    }
}

void dequeue() {
    if(front == -1 || front > rear)
        printf("Queue Underflow!\n");
    else
        printf("Dequeued: %d\n", queue[front++]);
}

void display_queue() {
    if(front == -1 || front > rear)
        printf("Queue Empty!\n");
    else {
        printf("Queue: ");
        for(int i=front; i<=rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

void queue_menu() {
    int choice, val;
    do {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n0. Back\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: 
                printf("Enter value: "); 
                scanf("%d", &val); 
                enqueue(val); 
                break;
            case 2: dequeue(); break;
            case 3: display_queue(); break;
            case 0: break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 0);
}
