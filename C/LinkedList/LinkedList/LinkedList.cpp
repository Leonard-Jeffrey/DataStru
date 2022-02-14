#include"LinkedList.h"
#define D_CRT_SECURE_NO_WARNINGS

//定义链表节点
struct LinkNode {
	int data;
	struct LinkNode* next;
};

//实现静态链表
void staticLinkedList() {
	//定义5个节点
	struct LinkNode node1 = {11, NULL};
	struct LinkNode node2 = {22, NULL};
	struct LinkNode node3 = {33, NULL};
	struct LinkNode node4 = {44, NULL};
	struct LinkNode node5 = {55, NULL};

	//链接成链表
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	node5.next = NULL;

	//定义链表头部指针
	struct LinkNode* pCurrent = &node1;

	//遍历链表
	while (pCurrent != NULL) {
		printf("%d\n", pCurrent->data);
		pCurrent = pCurrent->next;
	}
}


//实现动态链表
void dynamicLinkedList() {
	//定义5个链表节点
	struct LinkNode* node1 = (struct LinkNode *)malloc(sizeof(struct LinkNode));
	struct LinkNode* node2 = (struct LinkNode*)malloc(sizeof(struct LinkNode));
	struct LinkNode* node3 = (struct LinkNode*)malloc(sizeof(struct LinkNode));
	struct LinkNode* node4 = (struct LinkNode*)malloc(sizeof(struct LinkNode));
	struct LinkNode* node5 = (struct LinkNode*)malloc(sizeof(struct LinkNode));

	//形成链表
	node1->data = 111;
	node2->data = 222;
	node3->data = 333;
	node4->data = 444;
	node5->data = 555;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;

	//
	struct LinkNode* pCurrent = node1;
	while (pCurrent != NULL) {
		printf("%d\n",pCurrent->data);
		pCurrent = pCurrent->next;
	}

	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
}

//尾插法实现初始化链表
 struct LinkNode * initLinkedListByHead() {
	//定义链表头部
	struct LinkNode* pHead = (struct LinkNode*)malloc(sizeof(struct LinkNode));
	if (pHead == NULL)
		return NULL;
	//初始化赋值
	pHead->data = 0;
	pHead->next = NULL;

	//定义尾节点
	struct LinkNode * pTail = (struct LinkNode*)malloc(sizeof(struct LinkNode));
	pTail->next = pHead;

	while (1) {
		printf("初始化（-1结束）：");
		int val;
		scanf_s("%d",&val);
		if (val == -1)
			break;
		struct LinkNode *newNode = (struct LinkNode*)malloc(sizeof(struct LinkNode));
		newNode->data = val;
		newNode->next = pHead->next;
		pHead->next = newNode;
	}
	return pHead;
}

 //wei插法实现初始化链表
 struct LinkNode* initLinkedListByTail() {
	 //定义链表头部
	 struct LinkNode* pHead = (struct LinkNode*)malloc(sizeof(struct LinkNode));
	 if (pHead == NULL)
		 return NULL;
	 //初始化赋值
	 pHead->data = 0;
	 pHead->next = NULL;

	 //定义尾节点
	 struct LinkNode* pTail = pHead;

	 while (1) {
		 printf("初始化（-1结束）：");
		 int val;
		 scanf_s("%d", &val);
		 if (val == -1)
			 break;
		 struct LinkNode * newNode = (struct LinkNode*)malloc(sizeof(struct LinkNode));
		 if (newNode == NULL) {
			 printf("初始化失败");
			 return NULL;
		 }
		 newNode->data = val;
		 newNode->next = NULL;

		 pTail->next = newNode;
		 pTail = pTail->next;
	 }
	 return pHead;
 }

 //遍历链表
 void foreachLinkedList(struct LinkNode *pHead) {
	 if (pHead->next == NULL)
		 return;
	 struct LinkNode* pCurrent = pHead->next;
	 while (pCurrent != NULL) {
		 printf("%d\n",pCurrent->data);
		 pCurrent = pCurrent->next;
	 }
 }

 //增加:将newVal插入到oldVal前，若oldVal不存在，进行尾插；
 void addNode(struct LinkNode *pHead, int oldVal, int newVal) {
	 if (pHead->next == NULL)
		 return;
	 struct LinkNode* pPre = pHead, * pCurrent = pHead->next;
	 while (pCurrent != NULL) {
		 if (pCurrent->data == oldVal)
			 break;
		 pPre = pCurrent;
		 pCurrent = pCurrent->next;
	 }
	 struct LinkNode* newNode = (struct LinkNode*)malloc(sizeof(struct LinkNode));
	 newNode->data = newVal;
	 newNode->next = pCurrent;
	 pPre->next = newNode;
 }

 //删除
 void deleteNode(struct LinkNode* pHead, int Val) {
	 if (pHead == NULL)
		 return;
	 struct LinkNode* pPre = pHead, * pCurrent = pHead->next;
	 while (pCurrent != NULL) {
		 if (pCurrent->data == Val)
			 break;
		 pPre = pCurrent;
		 pCurrent = pCurrent->next;
	 }
	 if (pCurrent == NULL)
		 return;
	 pPre->next = pCurrent->next;
	 free(pCurrent);
 }

 //查询
 void searchNode(struct LinkNode* pHead, int Val) {
	 if (pHead == NULL)
		 return;
	 struct LinkNode* pCurrent = pHead->next;
	 while (pCurrent != NULL) {
		 if (pCurrent->data == Val)
			 break;
		 pCurrent = pCurrent->next;
	 }
	 if (pCurrent != NULL)
		 printf("值存在！\n");
	 else
		 printf("未找到该值！\n");
 }

 //改
 void modifyNode(struct LinkNode* pHead, int oldVal, int newVal) {
	 if (pHead == NULL)
		 return;
	 struct LinkNode* pCurrent = pHead->next;
	 while (pCurrent != NULL) {
		 if (pCurrent->data == oldVal)
			 break;
		 pCurrent = pCurrent->next;
	 }
	 if (pCurrent == NULL)
		 printf("要修改的值不存在！\n");
	 else
		 pCurrent->data = newVal;
 }

 //清空
 void clearLinkedList(struct LinkNode* pHead) {
	 if (pHead == NULL)
		 return;
	 struct LinkNode * pCurrent = pHead->next;


	 while (pCurrent != NULL) {
		 struct LinkNode* pNext = pCurrent->next;
		 free(pCurrent);
		 pCurrent = pNext;
	 }
	 pHead->next = NULL;
 }

 //销毁
 void destoryLinkedList(struct LinkNode *pHead) {
	 if (pHead == NULL)
		 return;
	 clearLinkedList(pHead);
	 free(pHead);
 }

 //反转
 void reverseLinkedList(struct LinkNode* pHead) {
	 if (pHead == NULL)
		 return;
	 //struct LinkNode* newNode = (struct LinkNode*)malloc(sizeof(struct LinkNode));
	 struct LinkNode* newNode = NULL;
	 struct LinkNode* pCurrent = pHead->next;
	 struct LinkNode* pNext = NULL;
	 while (pCurrent != NULL) {
		 pNext = pCurrent->next;
		 pCurrent->next = newNode;
		 newNode = pCurrent;
		 pCurrent = pNext;
	 }
	 pHead->next = newNode;
 }

 //逆序遍历-递归
 void reverseForeachLinkedList(struct LinkNode *pHead) {
	 if (pHead->next == NULL)
		 return;
	 reverseForeachLinkedList(pHead->next);
	 printf("%d\n",pHead->next->data);
 }

 ////反转-递归
 //void insert(struct LinkNode *pHead, struct LinkNode *pCurrent) {
	// pCurrent->next = NULL;
	// struct LinkNode* pTemp = pHead;
	// while (pTemp->next != NULL) {
	//	 pTemp = pTemp->next;
	// }
	// pTemp->next = pCurrent;
 //}
 //void reverse(struct LinkNode *pHead) {
	// if (pHead == NULL)
	//	 return;
	// struct LinkNode* pCurrent = pHead->next;
	// if(pCurrent->next != NULL)
	//	reverse(pHead->next);
	// else
	// {
	//	 insert(pHead,pCurrent);
	// }

 //}

 //求链表长度
 int sizeLinkedList(struct LinkNode* pHead){
	 if (pHead == NULL)
		 return 0;
	 struct LinkNode* pCurrent = pHead->next;
	 int size=0;
	 while (pCurrent != NULL) {
		 size++;
		 pCurrent = pCurrent->next;
	 }
	 return size;
 }