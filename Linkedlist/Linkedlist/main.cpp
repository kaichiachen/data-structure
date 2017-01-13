//
//  main.cpp
//  Linkedlist
//
//  Created by Andy Chen on 13/01/2017.
//  Copyright © 2017 Andy chen. All rights reserved.
//

#include <iostream>
#include <iomanip>

using namespace std;

typedef struct LNode{
    int data;
    struct LNode *next;
} LNode;

typedef struct DLNode{
    int data;
    struct DLNode *next;
    struct DLNode *prior;
}DLNode;

void initLNode(int *arr, int n, LNode *&ln);
void mergeNode(LNode *&ln1, LNode *&ln2, LNode *&output);
void mergeNodeWithOrder(LNode *&ln1, LNode *&ln2, LNode *&output);
void insertNode(LNode *&ln, int data);
void deleteNode(LNode *&ln, int index);
void displayLNodeData(LNode *&ln);


int main(int argc, const char * argv[]) {
    int initialArray[5] = { 1, 3, 5, 7, 9};
    int forMergeArray[5] = { -1, 2, 4, 6, 8};
    LNode *ln;
    LNode *forMergeln;
    LNode *mergeln;
    LNode *mergelnWithOrder;
    initLNode(initialArray, 5, ln);
    initLNode(forMergeArray, 5, forMergeln);
    mergeNode(ln, forMergeln, mergeln);
    mergeNodeWithOrder(ln, forMergeln, mergelnWithOrder);
    insertNode(ln, 11);
    deleteNode(ln, 3);
    displayLNodeData(ln);
    return 0;
}

void initLNode(int *arr, int n, LNode *&ln) {
    ln = (LNode*)malloc(sizeof(LNode));
    LNode *C = ln;
    for (int i = 0; i < n; i++) {
        LNode *t = (LNode*)malloc(sizeof(LNode));
        t->data = arr[i];
        C->next = t;
        C = C->next;
    }
}

void mergeNode(LNode *&ln1, LNode *&ln2, LNode *&output) {
    LNode *p = ln1;
    LNode *q = ln2;
    
    output = (LNode*)malloc(sizeof(LNode));
    LNode *ans = output;
    
    while(p->next != NULL) {
        LNode *t = (LNode*)malloc(sizeof(LNode));
        t->data = p->next->data; //記得判斷是next，就取next的data
        ans->next = t;
        ans = ans->next;
        p = p->next;
    }
    
    while(q->next != NULL) {
        LNode *t = (LNode*)malloc(sizeof(LNode));
        t->data = q->next->data;
        ans->next = t;
        ans = ans->next;
        q = q->next;
    }
}

void mergeNodeWithOrder(LNode *&ln1, LNode *&ln2, LNode *&output) {
    LNode *p = ln1;
    LNode *q = ln2;
    
    output = (LNode*)malloc(sizeof(LNode));
    LNode *ans = output;
    
    while(p->next != NULL && q->next != NULL) {
        if(p->next->data <= q->next->data) {
            LNode *t = (LNode*)malloc(sizeof(LNode));
            t->data = p->next->data;
            ans->next = t;
            ans = ans->next;
            p = p->next;
        } else {
            LNode *t = (LNode*)malloc(sizeof(LNode));
            t->data = q->next->data;
            ans->next = t;
            ans = ans->next;
            q = q->next;
        }
    }
    
    while(p->next != NULL) {
        LNode *t = (LNode*)malloc(sizeof(LNode));
        t->data = p->next->data; //記得判斷是next，就取next的data
        ans->next = t;
        ans = ans->next;
        p = p->next;
    }
    
    while(q->next != NULL) {
        LNode *t = (LNode*)malloc(sizeof(LNode));
        t->data = q->next->data;
        ans->next = t;
        ans = ans->next;
        q = q->next;
    }
}

void insertNode(LNode *&ln, int data) {
    LNode *p = ln;
    
    while(p->next != NULL) {
        p = p->next;
    }
    
    LNode *t = (LNode*)malloc(sizeof(LNode));
    t->data = data;
    p->next = t;
}

void deleteNode(LNode *&ln, int index) {
    LNode *p = ln;
    
    while(p->next != NULL && index > 0) {
        index--;
        p = p->next;
    }
    if(p->next != NULL) {
        if(p->next->next == NULL) {
            p->next = NULL;
        } else {
            p->next = p->next->next;
        }
    }
}

void displayLNodeData(LNode *&ln) {
    LNode *output = ln;
    while(output->next != NULL) {
        cout<<output->next->data<<setw(3);
        output = output->next;
    }
    cout<<endl;
}
