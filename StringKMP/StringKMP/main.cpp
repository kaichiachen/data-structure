//
//  main.cpp
//  StringKMP
//
//  Created by Andy Chen on 14/01/2017.
//  Copyright © 2017 Andy chen. All rights reserved.
//

#include <iostream>
#define maxsize 20

typedef struct Str {
    char ch[maxsize+1]; // 還需\0
    int length;
} Str;

int KMP(Str str, Str substr, int next[]);
void getNext(Str substr, int next[]);
void initStr(Str &str, char *ch);

void displayData(Str str);

int main(int argc, const char * argv[]) {
    int next[maxsize];
    char charstr[] = {"Hello, World!"}, charsubstr[] = {"World"};
    Str str, substr;
    initStr(str, charstr);
    initStr(substr, charsubstr);
    getNext(substr, next);
    int location = KMP(str, substr, next);
    std::cout<<location<<std::endl;
    return 0;
}

void initStr(Str &str, char* ch) {
    int index = 0;
    while( *ch != '\0' ) {
        str.ch[index] = *ch;
        ch += sizeof(char);
        index++;
    }
    str.ch[index] = '\0';
    str.length = index;
}

int KMP(Str str, Str substr, int next[]) {
    int i=0, j=0;
    while( i<str.length && j<substr.length ) {
        if(str.ch[i] == substr.ch[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
            if(j==-1) {
                j = 0;
                ++i;
            }
        }
    }
    
    if(j == substr.length) {
        return i - substr.length;
    }
    else return -1;
}

void getNext(Str substr, int next[]) {
    int i = 0, j = -1;
    next[0] = -1;
    while( i < substr.length ) {
        if( j == -1 || substr.ch[i] == substr.ch[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

void displayData(Str str) {
    for(int i = 0;i<str.length;i++) {
        std::cout<<str.ch[i];
    }
    std::cout<<std::endl;
}
