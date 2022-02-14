#include"Stack.h"

//��ʽ�洢ջ


//��ʼ��ջ
struct LStack* initLStack() {
	struct LStack* lstack = (struct LStack*)malloc(sizeof(struct LStack));
	if (lstack == NULL)
		return NULL;
	lstack->pHead.next = NULL;
	lstack->pHead.data = NULL;
	lstack->size = 0;
	return lstack;
}

//��ջ
void pushLStack(struct LStack* lstack, void *val) {
	if (NULL == lstack)
		return;
	if (NULL == val)
		return;

	//�����µ�����ڵ�
	struct LinkNode* newNode = (struct LinkNode*)malloc(sizeof(struct LinkNode));
	//�ж��Ƿ�����ɹ�
	if (NULL == newNode)
		return;
	//Ԫ����ջ
	newNode->data = val;
	newNode->next = NULL;
	//����ڵ����ջ
		//�ҵ�ջ������ڵ�ָ��
	struct LinkNode* pNext = lstack->pHead.next;
		//�ں��������ջԪ�ص�����ڵ�
	newNode->next = pNext;
	lstack->pHead.next = newNode;
	//����ջ��С
	lstack->size++;
}

//��ջ
void popLStack(struct LStack*lstack) {
	//�ж�ջ�Ƿ����
	if (NULL == lstack)
		return;
	//�ж�ջ��С�Ƿ�Ϊ0
	if (lstack->size == 0)
		return;
	//�ҵ�ջ������ڵ�� ǰһ�� ����ڵ��ָ��
	struct LinkNode* pNext = lstack->pHead.next;
	lstack->pHead.next = pNext->next;
	//��Ҫ��ջ��ջ������ڵ� ��ջ���Ƴ�,���ͷ��ڴ�ռ䣻
	free(pNext);
	//����ջ��С
	lstack->size--;
}

//��ȡջ��Ԫ��
void* getLSTop(struct LStack *lstack) {
	if (NULL == lstack)
		return NULL;
	if (lstack->size == 0)
		return NULL;
	return lstack->pHead.next;
}

//��ȡջ��С
int getLSSize(struct LStack* lstack) {
	if (NULL == lstack)
		return 0;
	return lstack->size;
}

//�ж�ջ�Ƿ�Ϊ��
int isLSEmpty(struct LStack* lstack) {
	if (NULL == lstack)
		return -1;
	if (lstack->size == 0)
		return 1;
	return 0;
}

//�ݻ�ջ
void destoryLStack(struct LStack* lstack) {
	if (NULL == lstack)
		return;
	while (lstack->size--) {
		popLStack(lstack);
	}
	free(lstack);
}