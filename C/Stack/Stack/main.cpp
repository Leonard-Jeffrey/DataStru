#include"Stack.h"

//用户自定义类型
struct person {
	char name[20];
	int age;
};
//用户自定义输出方式
void printTop(void *pTop) {
	if (NULL == pTop)
		return;
	struct person* p = (struct person *)pTop;
	printf("姓名：%s\t",p->name);
	printf("年龄：%d\n",p->age);
}

int main() {
	//初始化栈
	struct SStack* sstack = initStack();

	//定义元素
	struct person p1 = {"Jeffrey",25};
	struct person p2 = {"Jason",26};
	struct person p3 = {"Tatum",24};
	struct person p4 = {"Kawhi",25};

	//入栈
	pushStack(sstack,&p1);
	pushStack(sstack,&p2);
	pushStack(sstack,&p3);
	pushStack(sstack,&p4);

	//printf("%d",sstack->size);

	//获得栈顶元素，并使其出栈，同时返回栈大小
	while (!isEmpty(sstack)){
		//printf("1");
		struct SStack *pTop = (struct SStack*)getTop(sstack);
		printTop(pTop);
		int size = getSize(sstack);
		printf("栈当前大小为%d\n",size);
		popStack(sstack);
	}
	destoryStack(sstack);

	//下面开始链式存储栈测试
	printf("\n=========================================================\n");
	//初始化栈
	struct LStack* lstack = (struct LStack*)malloc(sizeof(struct LStack));
	//判断栈是否初始化成功
	if (NULL == lstack)
		return -1;
	//初始化栈
	lstack->pHead.next = NULL;
	lstack->pHead.data = NULL;
	lstack->size = 0;

	//入栈
	pushLStack(lstack,&p1);
	pushLStack(lstack,&p2);
	pushLStack(lstack,&p3);
	pushLStack(lstack,&p4);

	//获取栈顶元素，同时使其出栈，并返回栈大小
	while (!isLSEmpty(lstack)) {
		struct LinkNode *pTop = (struct LinkNode*)getLSTop(lstack);
		printTop(pTop->data);
		printf("栈的大小为%d\n",lstack->size);
		popLStack(lstack);
	}
	return 0;
}