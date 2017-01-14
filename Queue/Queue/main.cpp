//
//  main.cpp
//  Queue
//
//  Created by Andy Chen on 14/01/2017.
//  Copyright © 2017 Andy chen. All rights reserved.
//

#include <iostream>
#include <iomanip>
#define maxsize 5

using namespace std;

typedef struct sqQueue { //順序隊列
    int data[maxsize];
    int front; //尾(出隊時用) front = ( front + 1 ) % maxsize
    int rear;  //頭(進隊時用) rear = ( rear + 1 ) % maxsize
} sqQueue;

//隊空條件：front == rear
//隊滿條件：front == ( rear + 1 ) % maxsize

typedef struct QNode { //串鏈隊列
    int data;
    QNode *front;
    QNode *rear;
} QNode;

//隊空條件：front == NULL || rear == NULL
//隊滿條件：不存在

void initQueue(QNode *&qn);
bool isEmpty(QNode *&qn);
void insertIntoQueue(QNode *&qn, int data);
void deleteFromQueue(QNode *&qn);

void displayData(QNode *&qn);

int main(int argc, const char * argv[]) {
    int initialArray[5] = {1, 3, 5, 7, 9};
    QNode *qn;
    initQueue(qn);
    for(int i = 0;i<5;i++) {
        insertIntoQueue(qn, initialArray[i]);
    }
    deleteFromQueue(qn);
    displayData(qn);
    return 0;
}

void initQueue(QNode *&qn) {
    qn = (QNode*)malloc(sizeof(QNode));
    qn->front = qn->rear = NULL;
}

bool isEmpty(QNode *&qn) {
    if(qn->front == NULL || qn->rear == NULL) {
        return true;
    } else {
        return false;
    }
}

void insertIntoQueue(QNode *&qn, int data) {
    QNode *t = (QNode*)malloc(sizeof(QNode));
    t->data = data;
    t->rear = NULL;
    
    QNode *p = qn;
    while(p->rear != NULL) {
        p = p->rear;
    }
    t->front = p;
    p->rear = t;
}

void deleteFromQueue(QNode *&qn) {
    if(qn->rear == NULL) { //隊空
        
    } else {
        qn = qn->rear;
        qn->front = NULL;
    }
}

void displayData(QNode *&qn) {
    QNode *p = qn;
    while(p->rear != NULL) {
        p = p->rear;
        cout<<p->data<<setw(3);
    }
    cout<<endl;
}
