//
//  main.cpp
//  Stack
//
//  Created by Andy Chen on 14/01/2017.
//  Copyright © 2017 Andy chen. All rights reserved.
//

#include <iostream>
#include <iomanip>
#define maxsize 5

using namespace std;

typedef struct sqStack { //順序棧(ㄓㄢˋ)
    int data[maxsize];
    int top;
} sqStack;

typedef struct LNode { //鏈棧
    int data;
    LNode *next;
} LNode;

void init(sqStack &st); //pass by reference
void push(sqStack &st, int data);
int pop(sqStack &st);

void displayData(sqStack &st);

int main(int argc, const char * argv[]) {
    sqStack st;
    init(st);
    push(st, 5);
    push(st, 3);
    push(st, 1);
    cout<<"pop value:  "<<pop(st)<<endl;
    displayData(st);
    return 0;
}

void init(sqStack &st) {
    st.top = -1;
}

void push(sqStack &st, int data) {
    if(st.top + 1 < maxsize) {
        st.data[++st.top] = data;
    }
}

int pop(sqStack &st) {
    if(st.top > -1) {
        return st.data[st.top--];
    } else {
        return -1;
    }
}

void displayData(sqStack &st) {
    for(int i = 0;i<=st.top;i++) {
        cout<<st.data[i]<<setw(3);
    }
    cout<<endl;
}
