#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//���嶯̬����ṹ
struct DynamicArray {
	//�����pHeadָ�����һ�����飨һ��ָ�룩�����pHeadΪ����ָ�룻
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