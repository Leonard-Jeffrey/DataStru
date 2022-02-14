#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//定义动态数组结构
struct DynamicArray {
	//这里的pHead指向的是一个数组（一级指针），因此pHead为二级指针；
	void** pHead;
	int capacity;
	int size;
};

struct person {
	char name[20];
	int age;
};

struct DynamicArray * initDA(int capacity);
void insertDA(struct DynamicArray *Array, int pos, void *Val);
void foreachDA(struct DynamicArray *Array, void(*myforeach)(void *));
void myForeach(void *data);
int myCompare(void *data, void *Val);
void deleteDAByPosition(struct DynamicArray *Array, int pos);
void deleteDAByValue(struct DynamicArray *Array, void *Val,int(*myCompare)(void*p1,void*p2));
void destoryDA(struct DynamicArray *Array);