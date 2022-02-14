#include"Stack.h"

//链式存储栈


//初始化栈
struct LStack* initLStack() {
	struct LStack* lstack = (struct LStack*)malloc(sizeof(struct LStack));
	if (lstack == NULL)
		return NULL;
	lstack->pHead.next = NULL;
	lstack->pHead.data = NULL;
	lstack->size = 0;
	return lstack;
}

//入栈
void pushLStack(struct LStack* lstack, void *val) {
	if (NULL == lstack)
		return;
	if (NULL == val)
		return;

	//创建新的链表节点
	struct LinkNode* newNode = (struct LinkNode*)malloc(sizeof(struct LinkNode));
	//判断是否申请成功
	if (NULL == newNode)
		return;
	//元素入栈
	newNode->data = val;
	newNode->next = NULL;
	//链表节点插入栈
		//找到栈顶链表节点指针
	struct LinkNode* pNext = lstack->pHead.next;
		//在后面插入入栈元素的链表节点
	newNode->next = pNext;
	lstack->pHead.next = newNode;
	//更新栈大小
	lstack->size++;
}

//出栈
void popLStack(struct LStack*lstack) {
	//判断栈是否存在
	if (NULL == lstack)
		return;
	//判断栈大小是否为0
	if (lstack->size == 0)
		return;
	//找到栈顶链表节点的 前一个 链表节点的指针
	struct LinkNode* pNext = lstack->pHead.next;
	lstack->pHead.next = pNext->next;
	//将要出栈的栈顶链表节点 从栈中移除,并释放内存空间；
	free(pNext);
	//更新栈大小
	lstack->size--;
}

//获取栈顶元素
void* getLSTop(struct LStack *lstack) {
	if (NULL == lstack)
		return NULL;
	if (lstack->size == 0)
		return NULL;
	return lstack->pHead.next;
}

//获取栈大小
int getLSSize(struct LStack* lstack) {
	if (NULL == lstack)
		return 0;
	return lstack->size;
}

//判断栈是否为空
int isLSEmpty(struct LStack* lstack) {
	if (NULL == lstack)
		return -1;
	if (lstack->size == 0)
		return 1;
	return 0;
}

//摧毁栈
void destoryLStack(struct LStack* lstack) {
	if (NULL == lstack)
		return;
	while (lstack->size--) {
		popLStack(lstack);
	}
	free(lstack);
}