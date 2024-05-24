#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct CircularDoublyLinkedList{
    struct Node *head;
    struct Node *tail;
};


void insertAtBegin(struct CircularDoublyLinkedList *cdll,int data){
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    if(!cdll->head){
        cdll->head = cdll->tail = node;
        cdll->tail->next = cdll->head;
        cdll->head->prev = cdll->tail;
    }
    else{
        cdll->head->prev = node;
        node->next = cdll->head;
        node->prev = cdll->tail;
        cdll->tail->next = node;
        cdll->head = node;
    }
}

void insertAtEnd(struct CircularDoublyLinkedList *cdll,int data){
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    if(!cdll->head){
        cdll->head = cdll->tail = node;
        cdll->head->prev = node;
        node->next = cdll->head;
    }
    else{
        cdll->tail->next = node;
        node->prev = cdll->tail;
        node->next = cdll->head;
        cdll->head->prev = node;
        cdll->tail = node;
    }
}


void insertAtIndex(struct CircularDoublyLinkedList *cdll,int index,int data){
    
    if(index == 0){
        insertAtBegin(cdll,data);
    }
    else{
        struct Node *node = (struct Node*)malloc(sizeof(struct Node));
        node->data = data;
        int i = 0;
        struct Node* curr = cdll->head;
        while(i<index-1 && curr){
            i++;
            curr = curr->next;
        }

        if(curr){
            curr->next->prev = node;
            node->next = curr->next;
            curr->next = node;
            node->prev = curr;
            if(node->next == NULL){
                node->next = cdll->head;
                cdll->head->prev = node;
            }
        }
        else{
            printf("Index out of range");
        }
    }
}


void deleteAtBegin(struct CircularDoublyLinkedList *cdll)
{
    if(!cdll->head){
        printf("LinkedList is Empty");
    }
    else if(cdll->head == cdll->tail){
        cdll->head = cdll->tail = NULL;
    }
    else{
        struct Node *delNode = cdll->head;
        cdll->head = cdll->head->next;
        cdll->head->prev = cdll->tail;
        cdll->tail->next = cdll->head;
        cdll->head->prev = NULL;
        free(delNode);
    }
}

void deleteAtEnd(struct CircularDoublyLinkedList *cdll){
    if(!cdll->head){
        printf("LinkedList is Empty");
    }
    else if(!cdll->head->next){
        cdll->head = cdll->tail = NULL;
    }
    else{
        struct Node *delNode = cdll->tail;
        cdll->tail = cdll->tail->prev;
        cdll->tail->next = cdll->head;
        cdll->head->prev = cdll->tail;
        cdll->tail->next = NULL;
        free(delNode);
    }
}


void deleteAtIndex(struct CircularDoublyLinkedList* cdll,int index){
    if(!cdll->head){
        printf("LinkedList is Empty");
    }
    else if(index == 0){
        deleteAtBegin(cdll);
        return;
    }
    else{
        struct Node* curr = cdll->head;
        int i=0;
        while(i<index-1 && curr){
            i++;
            curr = curr->next;
        }
        if(curr && curr->next){
            struct Node* delNode = curr->next;
            curr->next = curr->next->next;
            if(!curr->next){
                cdll->tail = curr;
                cdll->tail->next = cdll->head;
                cdll->head->prev = cdll->tail;
            }
            else{
                curr->next->prev = curr;
            }
            free(delNode);
        }
        else{
            printf("Index out of range");
        }
    }
}


void displayForward(struct CircularDoublyLinkedList* cdll){
    if(!cdll->head){
        printf("Linked List is Empty\n");
        return;
    }
    struct Node* curr = cdll->head;
    while(curr!=cdll->tail){
        printf("%d->",curr->data);
        curr = curr->next;
    }
    printf("%d->NULL\n",cdll->tail->data);                   
}

void displayBackward(struct CircularDoublyLinkedList* cdll){
    if(!cdll->head){
        printf("Linked List is Empty\n");
        return;
    }
    struct Node* curr = cdll->tail;
    while(curr!=cdll->head){
        printf("%d->",curr->data);
        curr = curr->prev;
    }
    printf("%d->NULL\n",cdll->head->data);    
}


int main(){
    struct CircularDoublyLinkedList cdll = {NULL,NULL};
    insertAtBegin(&cdll,10);
    displayForward(&cdll);
    displayBackward(&cdll);
    insertAtBegin(&cdll,20);
    displayForward(&cdll);
    displayBackward(&cdll);
    insertAtEnd(&cdll,30);
    displayForward(&cdll);
    displayBackward(&cdll);
    insertAtIndex(&cdll,1,40);
    displayForward(&cdll);
    displayBackward(&cdll);
    deleteAtBegin(&cdll);
    displayForward(&cdll);
    displayBackward(&cdll);
    deleteAtEnd(&cdll);
    displayForward(&cdll);
    displayBackward(&cdll);
    deleteAtIndex(&cdll,1);
    displayForward(&cdll);
    displayBackward(&cdll);
    deleteAtIndex(&cdll,0);
    displayForward(&cdll);
    displayBackward(&cdll);
}