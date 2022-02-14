#include"Stack.h"

//��ʼ��ջ
struct SStack* initStack() {
	struct SStack *sstack = (struct SStack *)malloc(sizeof(struct SStack));
	sstack->size = 0;
	return sstack;
}

//��ջ
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

//��ջ
void * popStack(struct SStack* sstack) {
	if (NULL == sstack)
		return NULL;
	if (sstack->size == 0)
		return NULL;
	void* p = sstack->data[sstack->size-1];
	sstack->size--;
	return p;
}

//��ȡջ��Ԫ��
void* getTop(struct SStack *sstack) {
	if (NULL == sstack)
		return NULL;
	if (sstack->size == 0)
		return NULL;
	return sstack->data[sstack->size-1];
}

//����ջ��С
int getSize(struct SStack *sstack) {
	if (NULL == sstack)
		return -1;
	return sstack->size;
}

//�ж�ջ�Ƿ�Ϊ�գ�
int isEmpty(struct SStack* sstack) {
	if (NULL == sstack)
		return -1;
	if (sstack->size > 0)
		return 0;
	else
		return 1;
}

//����ջ
void destoryStack(struct SStack* sstack) {
	if (NULL == sstack)
		return;
	free(sstack);
	sstack = NULL;
}