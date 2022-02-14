#pragma once
#include<stdio.h>
#include<stdlib.h>

//定义顺序栈的结构体
#define Max 1024
struct SStack {
	void* data[Max];
	int size;
};

//顺序型栈
//初始化栈
struct SStack* initStack();

//入栈
void pushStack(struct SStack* sstack, void* val);

//出栈
void* popStack(struct SStack* sstack);

//获取栈顶元素
void* getTop(struct SStack* sstack);

//返回栈大小
int getSize(struct SStack* sstack);

//判断栈是否为空；
int isEmpty(struct SStack* sstack);

//销毁栈
void destoryStack(struct SStack* sstack);


//定义链式栈的结构体
//链式存储栈

//定义链表节点
struct LinkNode {
	struct LinkNode* next;
	void* data;
};

//定义栈结构体
struct LStack {
	struct LinkNode pHead;
	int size;
};

//初始化栈
struct LStack* initLStack();

//入栈
void pushLStack(struct LStack* lstack, void* val);

//出栈
void popLStack(struct LStack* lstack);

//获取栈顶元素
void* getLSTop(struct LStack* lstack);

//获取栈大小
int getLSSize(struct LStack* lstack);

//判断栈是否为空
int isLSEmpty(struct LStack* lstack);

//摧毁栈
void destoryLStack(struct LStack* lstack);