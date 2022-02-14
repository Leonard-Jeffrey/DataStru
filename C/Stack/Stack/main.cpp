#include"Stack.h"

//�û��Զ�������
struct person {
	char name[20];
	int age;
};
//�û��Զ��������ʽ
void printTop(void *pTop) {
	if (NULL == pTop)
		return;
	struct person* p = (struct person *)pTop;
	printf("������%s\t",p->name);
	printf("���䣺%d\n",p->age);
}

int main() {
	//��ʼ��ջ
	struct SStack* sstack = initStack();

	//����Ԫ��
	struct person p1 = {"Jeffrey",25};
	struct person p2 = {"Jason",26};
	struct person p3 = {"Tatum",24};
	struct person p4 = {"Kawhi",25};

	//��ջ
	pushStack(sstack,&p1);
	pushStack(sstack,&p2);
	pushStack(sstack,&p3);
	pushStack(sstack,&p4);

	//printf("%d",sstack->size);

	//���ջ��Ԫ�أ���ʹ���ջ��ͬʱ����ջ��С
	while (!isEmpty(sstack)){
		//printf("1");
		struct SStack *pTop = (struct SStack*)getTop(sstack);
		printTop(pTop);
		int size = getSize(sstack);
		printf("ջ��ǰ��СΪ%d\n",size);
		popStack(sstack);
	}
	destoryStack(sstack);

	//���濪ʼ��ʽ�洢ջ����
	printf("\n=========================================================\n");
	//��ʼ��ջ
	struct LStack* lstack = (struct LStack*)malloc(sizeof(struct LStack));
	//�ж�ջ�Ƿ��ʼ���ɹ�
	if (NULL == lstack)
		return -1;
	//��ʼ��ջ
	lstack->pHead.next = NULL;
	lstack->pHead.data = NULL;
	lstack->size = 0;

	//��ջ
	pushLStack(lstack,&p1);
	pushLStack(lstack,&p2);
	pushLStack(lstack,&p3);
	pushLStack(lstack,&p4);

	//��ȡջ��Ԫ�أ�ͬʱʹ���ջ��������ջ��С
	while (!isLSEmpty(lstack)) {
		struct LinkNode *pTop = (struct LinkNode*)getLSTop(lstack);
		printTop(pTop->data);
		printf("ջ�Ĵ�СΪ%d\n",lstack->size);
		popLStack(lstack);
	}
	return 0;
}