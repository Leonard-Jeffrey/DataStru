#include"Stack.h"

//初始化栈
struct SStack* initStack() {
	struct SStack *sstack = (struct SStack *)malloc(sizeof(struct SStack));
	sstack->size = 0;
	return sstack;
}

//入栈
void pushStack(struct SStack * sstack, void * val) {
	if (NULL == sstack)
		return;
	if (NULL == val)
		return;
	if (sstack->size == Max)
		return;
	sstack->data[sstack->size] = val;
	sstack->size++;
}

//出栈
void * popStack(struct SStack* sstack) {
	if (NULL == sstack)
		return NULL;
	if (sstack->size == 0)
		return NULL;
	void* p = sstack->data[sstack->size-1];
	sstack->size--;
	return p;
}

//获取栈顶元素
void* getTop(struct SStack *sstack) {
	if (NULL == sstack)
		return NULL;
	if (sstack->size == 0)
		return NULL;
	return sstack->data[sstack->size-1];
}

//返回栈大小
int getSize(struct SStack *sstack) {
	if (NULL == sstack)
		return -1;
	return sstack->size;
}

//判断栈是否为空；
int isEmpty(struct SStack* sstack) {
	if (NULL == sstack)
		return -1;
	if (sstack->size > 0)
		return 0;
	else
		return 1;
}

//销毁栈
void destoryStack(struct SStack* sstack) {
	if (NULL == sstack)
		return;
	free(sstack);
	sstack = NULL;
}