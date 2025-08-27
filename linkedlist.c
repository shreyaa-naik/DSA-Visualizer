#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert_end(int val) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void delete_val(int val) {
    struct Node *temp = head, *prev = NULL;
    if(temp != NULL && temp->data == val) {
        head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Value not found!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void display_list() {
    struct Node* temp = head;
    if(temp == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Linked List: ");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void linkedlist_menu() {
    int choice, val;
    do {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at End\n2. Delete Value\n3. Display\n0. Back\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert_end(val);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                delete_val(val);
                break;
            case 3:
                display_list();
                break;
            case 0: break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 0);
}
