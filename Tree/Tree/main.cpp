//
//  main.cpp
//  Tree
//
//  Created by Andy Chen on 14/01/2017.
//  Copyright © 2017 Andy chen. All rights reserved.
//

#include <iostream>
#include <iomanip>
#define maxsize 10

using namespace std;

typedef struct BTNode {
    char data;
    
    BTNode *lchild;
    BTNode *rchild;
} BTNode;

//線索二叉樹
typedef struct TBTNode {
    char data;
    //tag = 0 -> 指向(左/右)孩子 tag = 1 -> 指向(前驅/後繼)節點
    //前驅 -> 父結點最左邊  後繼 -> 父節點最右邊
    int ltag, rtag;
    TBTNode *lchild;
    TBTNode *rchild;
} TBTNode;

void initTree(BTNode *&tree);
void initFullTree(BTNode *&tree);
void preOrder(BTNode *&tree);
void inOrder(BTNode *&tree);
void postOrder(BTNode *&tree);
void levelOrder(BTNode *&tree);
bool isCompleteTree(BTNode *&tree);
int getTreeDepth(BTNode *&tree);

int main(int argc, const char * argv[]) {
    BTNode *tree;
    initFullTree(tree);
    cout<<"先序走訪: ";
    preOrder(tree);
    cout<<endl;
    
    cout<<"中序走訪: ";
    inOrder(tree);
    cout<<endl;
    
    cout<<"後序走訪: ";
    postOrder(tree);
    cout<<endl;
    
    cout<<"層次走訪: ";
    levelOrder(tree);
    cout<<endl;

    cout<<"是否為完全二叉樹: "<<isCompleteTree(tree)<<endl;
    
    cout<<"樹有"<<getTreeDepth(tree)<<"層深"<<endl;
    return 0;
}

void initTree(BTNode *&tree) {
    tree = (BTNode*)malloc(sizeof(BTNode));
    BTNode *p = tree;
    p->data = 'A';
    p->lchild = (BTNode*)malloc(sizeof(BTNode));
    p->lchild->data = 'B';
    p->lchild->rchild = NULL;
    
    p->lchild->lchild = (BTNode*)malloc(sizeof(BTNode));
    p->lchild->lchild->data = 'D';
    p->lchild->lchild->lchild = NULL;
    p->lchild->lchild->rchild = NULL;
    
    p->rchild = (BTNode*)malloc(sizeof(BTNode));
    p->rchild->data = 'C';
    
    p->rchild->lchild = (BTNode*)malloc(sizeof(BTNode));
    p->rchild->lchild->data = 'E';
    p->rchild->lchild->rchild = NULL;
    p->rchild->lchild->lchild = NULL;
    
    p->rchild->rchild = (BTNode*)malloc(sizeof(BTNode));
    p->rchild->rchild->data = 'F';
    p->rchild->rchild->rchild = NULL;
    p->rchild->rchild->lchild = NULL;
}

void initFullTree(BTNode *&tree) {
    tree = (BTNode*)malloc(sizeof(BTNode));
    BTNode *p = tree;
    p->data = 'A';
    p->lchild = (BTNode*)malloc(sizeof(BTNode));
    p->lchild->data = 'B';
    
    p->lchild->lchild = (BTNode*)malloc(sizeof(BTNode));
    p->lchild->lchild->data = 'D';
    p->lchild->lchild->lchild = NULL;
    p->lchild->lchild->rchild = NULL;
    
    p->lchild->rchild = (BTNode*)malloc(sizeof(BTNode));
    p->lchild->rchild->data = 'E';
    p->lchild->rchild->lchild = NULL;
    p->lchild->rchild->rchild = NULL;
    
    p->rchild = (BTNode*)malloc(sizeof(BTNode));
    p->rchild->data = 'C';
    p->rchild->lchild = NULL;
    
    p->rchild->lchild = (BTNode*)malloc(sizeof(BTNode));
    p->rchild->lchild->data = 'F';
    p->rchild->lchild->rchild = NULL;
    p->rchild->lchild->lchild = NULL;
    
    p->rchild->rchild = (BTNode*)malloc(sizeof(BTNode));
    p->rchild->rchild->data = 'G';
    p->rchild->rchild->rchild = NULL;
    p->rchild->rchild->lchild = NULL;
}

void preOrder(BTNode *&tree) {
    //先序走訪
    if(tree!=NULL) {
        cout<<tree->data<<setw(3);
        preOrder(tree->lchild);
        preOrder(tree->rchild);
    }
}
void inOrder(BTNode *&tree) {
    //中序走訪
    if(tree!=NULL) {
        inOrder(tree->lchild);
        cout<<tree->data<<setw(3);
        inOrder(tree->rchild);
    }
}
void postOrder(BTNode *&tree) {
    //後序走訪
    if(tree!=NULL) {
        postOrder(tree->lchild);
        postOrder(tree->rchild);
        cout<<tree->data<<setw(3);
    }
}
void levelOrder(BTNode *&tree) {
    int front, rear;
    BTNode *que[maxsize];
    front = rear = 0;
    BTNode *q;
    BTNode *p = tree;
    
    if(p != NULL) {
        rear = (rear+1) % maxsize;
        que[rear] = p;
        while(front != rear) {
            front = (front + 1) % maxsize;
            q = que[front];
            cout<<q->data<<setw(3);
            if(q->lchild != NULL) {
                rear = (rear + 1) % maxsize;
                que[rear] = q->lchild;
            }
            if(q->rchild != NULL) {
                rear = (rear + 1) % maxsize;
                que[rear] = q->rchild;
            }
        }
    }
}

//利用层序遍历（空节点也入队列），若遇到NULL节点后，还有非空节点，就不是完全二叉树
bool isCompleteTree(BTNode *&tree) {
    BTNode *p = tree;
    BTNode *que[maxsize];
    BTNode *q;
    bool isCompleteTree = true;
    bool startNULL = false;
    int front = 0, rear = 0;
    
    if(p!=NULL) {
        rear = (rear + 1) % maxsize;
        que[rear] = p;
        while(front != rear) {
            front = (front + 1) % maxsize;
            q = que[front];
            if(q->lchild == NULL) {
                startNULL = true;
            } else if(startNULL) {
                isCompleteTree = false;
                break;
            } else {
                rear = (rear + 1) % maxsize;
                que[rear] = q->lchild;
            }

            if(q->rchild == NULL) {
                startNULL = true;
            } else if(startNULL) {
                isCompleteTree = false;
                break;
            } else {
                rear = (rear + 1) % maxsize;
                que[rear] = q->rchild;
            }
        }
    }
    return isCompleteTree;
}

int getTreeDepth(BTNode *&tree) {
    int LD = 0, RD = 0;
    BTNode *p = tree;
    if(p==NULL) {
        return 0;
    }
    LD = getTreeDepth(p->lchild);
    RD = getTreeDepth(p->rchild);
    
    return (LD > RD ? LD : RD) + 1;
}
