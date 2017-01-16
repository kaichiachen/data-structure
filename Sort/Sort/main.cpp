//
//  main.cpp
//  Sort
//
//  Created by Andy Chen on 15/01/2017.
//  Copyright © 2017 Andy chen. All rights reserved.
//

#include <iostream>
#include <iomanip>
#define maxsize 7

using namespace std;

void initArray(int *array);
void insertSort();
void selectSort();
void bubbleSort();
void quickSort(int *array, int l, int r);
void heapSort(); //堆排序
void sift(int array[], int low, int high); //給heap sort用的

void displayData(int *array);

int main(int argc, const char * argv[]) {
    insertSort();
    bubbleSort();
    
    int arr[maxsize];
    initArray(arr);
    quickSort(arr, 0, maxsize-1);
    displayData(arr);
    
    selectSort();
    heapSort();
    return 0;
}

void initArray(int *array) {
    int arr[maxsize] = {6, 3, 1, 8, 9, 4, 5};
    for(int i = 0;i<maxsize;i++) {
        array[i] = arr[i];
    }
}

void insertSort() {
    int arr[maxsize];
    initArray(arr);
    int temp;
    for(int i = 1;i<maxsize;i++) {
        temp = arr[i]; //儲存待插入元素
        int j = i - 1;
        while(j>=0 && temp<arr[j]) {
            arr[j+1] = arr[j]; //然後用冒泡的方式位移
            j--;
        }
        arr[j+1] = temp;
    }
    displayData(arr);
}

void bubbleSort() {
    int arr[maxsize];
    initArray(arr);
    for(int i = 0;i<maxsize - 1;i++) {
        for(int j = maxsize - 1;j>i;j--) {
            if(arr[j] < arr [j-1]) {
                arr[j] ^= arr[j-1];
                arr[j-1] ^= arr[j];
                arr[j] ^= arr[j-1];
            }
        }
    }
    displayData(arr);
}

void quickSort(int *array, int l, int r) {
    int temp;
    int i = l, j = r;
    if(l<r) {
        temp = array[l]; // temp就是pivot
        while(i!=j) {
            while(j>i && array[j] > temp) { //找小於temp
                j--;
            }
            if(i<j) { //找到後放到temp左邊
                array[i] = array[j];
                i++;
            }
            while(i<j && array[i] < temp) { //找大於temp
                i++;
            }
            if(i<j) { //找到後放到temp右邊
                array[j] = array[i];
                j--;
            }
            array[i] = temp; //把temp放在最終位置
        }
        quickSort(array, l, i-1);
        quickSort(array, i+1, r);
    }
    
}

void selectSort() {
    int arr[maxsize];
    initArray(arr);
    
    for(int i = 0;i<maxsize-1;i++) {
        int min = 100;
        int index = maxsize;
        for(int j = i;j<maxsize;j++) {
            if(arr[j] < min) {
                min = arr[j];
                index = j;
            }
        }
        if(index != maxsize && index != i) {
            arr[i] ^= arr[index];
            arr[index] ^= arr[i];
            arr[i] ^= arr[index];
        }
    }
    displayData(arr);
}

void heapSort() {
    int arr[maxsize];
    initArray(arr);
    
    for(int i = maxsize/2 - 1;i>=0;i--) { //建立初始堆
        sift(arr, i, maxsize-1);
    }
    for(int i = maxsize-1;i>0;i--) { //把根結點放最後，就不用管他了
        arr[0] ^= arr[i];
        arr[i] ^= arr[0];
        arr[0] ^= arr[i];
        sift(arr, 0, i - 1);
    }
    displayData(arr);
}

void sift(int array[], int low, int high) {
    int i = low, j = i * 2 + 1; //array[j]是array[i]的左孩子
    int temp = array[i];
    while(j <= high) {
        if(j < high && array[j] < array[j+1]) { // 如果右比左大，就拿右比較
            j++;
        }
        if( temp < array[j]) {
            array[i] = array[j];
            i = j;
            j = 2 * i + 1;
        } else {
            break;
        }
    }
    array[i] = temp;
}

void displayData(int *arr) {
    for(int i = 0;i<maxsize;i++) {
        cout<<arr[i]<<"   ";
    }
    cout<<endl;
}
