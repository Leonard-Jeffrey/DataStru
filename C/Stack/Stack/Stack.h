#pragma once
#include<stdio.h>
#include<stdlib.h>

//����˳��ջ�Ľṹ��
#define Max 1024
struct SStack {
	void* data[Max];
	int size;
};

//˳����ջ
//��ʼ��ջ
struct SStack* initStack();

//��ջ
void pushStack(struct SStack* sstack, void* val);

//��ջ
void* popStack(struct SStack* sstack);

//��ȡջ��Ԫ��
void* getTop(struct SStack* sstack);

//����ջ��С
int getSize(struct SStack* sstack);

//�ж�ջ�Ƿ�Ϊ�գ�
int isEmpty(struct SStack* sstack);

//����ջ
void destoryStack(struct SStack* sstack);


//������ʽջ�Ľṹ��
//��ʽ�洢ջ

//��������ڵ�
struct LinkNode {
	struct LinkNode* next;
	void* data;
};

//����ջ�ṹ��
struct LStack {
	struct LinkNode pHead;
	int size;
};

//��ʼ��ջ
struct LStack* initLStack();

//��ջ
void pushLStack(struct LStack* lstack, void* val);

//��ջ
void popLStack(struct LStack* lstack);

//��ȡջ��Ԫ��
void* getLSTop(struct LStack* lstack);

//��ȡջ��С
int getLSSize(struct LStack* lstack);

//�ж�ջ�Ƿ�Ϊ��
int isLSEmpty(struct LStack* lstack);

//�ݻ�ջ
void destoryLStack(struct LStack* lstack);