#include <stdio.h>
#include <stdlib.h>
// this version is not mine
struct sNode{
    int data;
    struct sNode* next;
};

struct sNode * newNode(int data){
    struct sNode * nNode = malloc(sizeof(struct sNode));
    nNode->data = data;
    nNode->next = nNode; // initialize to point to itself for circular lists
    return nNode;
}

struct sNode * insertAtBeg(struct sNode * head, int data){
    struct sNode * node = newNode(data);
    if (head == NULL) {
        node->next = node;
        return node;
    }
    struct sNode * last = head;
    while (last->next != head) {
        last = last->next;
    }
    node->next = head;
    last->next = node;
    return node;
}

struct sNode * insertAtEnd(struct sNode * head, int data){
    struct sNode * lNode = newNode(data);
    if (head == NULL) {
        lNode->next = lNode;
        return lNode;
    }
    struct sNode * crnt = head;
    while (crnt->next != head) {
        crnt = crnt->next;
    }
    crnt->next = lNode;
    lNode->next = head;
    return head;
}

struct sNode* insertAtPos(struct sNode *head, int pos, int data){
    if (pos < 1) {
        printf("The position entered is not valid. Make sure you enter >= 1 position\n");
        return head;
    }
    if (head == NULL || pos == 1) {
        return insertAtBeg(head, data);
    }
    struct sNode * npNode = newNode(data);
    struct sNode * crnt = head;
    int count = 1;
    while (crnt->next != head && count < pos - 1) {
        crnt = crnt->next;
        count++;
    }
    npNode->next = crnt->next;
    crnt->next = npNode;
    return head;
}

struct sNode * del_1st(struct sNode * head){
    if (head == NULL) {
        printf("\nList is already Empty ");
        return head;
    }
    if (head->next == head) {
        free(head);
        return NULL;
    }
    struct sNode * last = head;
    while (last->next != head) {
        last = last->next;
    }
    struct sNode * temp = head;
    head = head->next;
    last->next = head;
    free(temp);
    return head;
}

struct sNode * del_last(struct sNode * head){
    if (head == NULL) {
        printf("\nList is already Empty ");
        return head;
    }
    if (head->next == head) {
        free(head);
        return NULL;
    }
    struct sNode * crnt = head;
    struct sNode * prev = NULL;
    while (crnt->next != head) {
        prev = crnt;
        crnt = crnt->next;
    }
    prev->next = head;
    free(crnt);
    return head;
}

struct sNode * del_at_pos(struct sNode * head, int pos){
    if (head == NULL) {
        printf("\nList is already empty. ");
        return head;
    }
    if (pos <= 0) {
        printf("The position entered is not valid.\nTry to provide position starting from 1.\n");
        return head;
    }
    if (pos == 1) {
        return del_1st(head);
    }
    struct sNode * crnt = head;
    int count = 1;
    while (crnt->next != head && count < pos - 1) {
        crnt = crnt->next;
        count++;
    }
    if (crnt->next == head) {
        printf("\nThe position you entered is greater than the present count of nodes.\nHence deleting last node.");
        return del_last(head);
    }
    struct sNode * temp = crnt->next;
    crnt->next = temp->next;
    free(temp);
    return head;
}

struct sNode * reverse_list(struct sNode * head){
    if (head == NULL || head->next == head) {
        printf("\nThere is nothing to reverse.\n");
        return head;
    }
    struct sNode * prev = NULL, * crnt = head, * next = NULL, * last = head;
    do {
        next = crnt->next;
        crnt->next = prev;
        prev = crnt;
        crnt = next;
    } while (crnt != head);
    head->next = prev;
    head = prev;
    return head;
}

void traverse(struct sNode * head, const char *msg) {
    printf("%s", msg);
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct sNode * ptr = head;
    do {
        printf("-> %d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}

int main(){
    struct sNode * head = NULL;
    head = insertAtBeg(head, 20);
    head = insertAtBeg(head, 25);
    head = insertAtBeg(head, 69);
    head = insertAtEnd(head, 10);
    head = insertAtPos(head, 1, 100);
    head = insertAtPos(head, 3, 200);
    head = insertAtPos(head, 10, 300);
    head = insertAtPos(head, 7, 400);

    head = del_1st(head);
    head = del_last(head);
    head = del_at_pos(head, 10);
    head = del_at_pos(head, 1);
    head = del_at_pos(head, 6);

    head = reverse_list(head);

    traverse(head, "(1st is Reversed Version)\nThe 1st Circular Linked List: ");

    struct sNode * head2 = NULL;
    head2 = insertAtBeg(head2, 70);
    head2 = insertAtBeg(head2, 68);
    head2 = insertAtBeg(head2, 65);
    head2 = insertAtEnd(head2, 80);
    head2 = insertAtPos(head2, 1, 20);
    head2 = insertAtPos(head2, 3, 200);
    head2 = insertAtPos(head2, 10, 300);
    head2 = insertAtPos(head2, 7, 400);

    traverse(head2, "\nThe 2nd Circular Linked List: ");


    return 0;
}