#include <stdio.h>
#include "stack.h"

#define MAX 5
int stack[MAX], top = -1;

void push(int x) {
    if(top == MAX-1)
        printf("Stack Overflow!\n");
    else
        stack[++top] = x;
}

void pop() {
    if(top == -1)
        printf("Stack Underflow!\n");
    else
        printf("Popped: %d\n", stack[top--]);
}

void display_stack() {
    if(top == -1)
        printf("Stack Empty!\n");
    else {
        printf("Stack: ");
        for(int i=0; i<=top; i++)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

void stack_menu() {
    int choice, val;
    do {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Display\n0. Back\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: 
                printf("Enter value: "); 
                scanf("%d", &val); 
                push(val); 
                break;
            case 2: pop(); break;
            case 3: display_stack(); break;
            case 0: break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 0);
}
