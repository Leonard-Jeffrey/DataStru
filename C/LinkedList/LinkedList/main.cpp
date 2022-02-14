#include"LinkedList.h"

int main() {
	struct LinkNode *pHead = initLinkedListByHead();
	printf("=============================\n");
	foreachLinkedList(pHead);
	addNode(pHead, 10, 20);
	addNode(pHead, 10, 30);
	addNode(pHead, 10, 40);
	printf("=============================\n");
	foreachLinkedList(pHead);
	//deleteNode(pHead,30);
	printf("=============================\n");
	foreachLinkedList(pHead);
	//clearNode(pHead);
	reverseLinkedList(pHead);
	printf("=============================\n");
	foreachLinkedList(pHead);
	printf("=============================\n");
	reverseForeachLinkedList(pHead);
	printf("=============================\n");
	searchNode(pHead, 10);
	modifyNode(pHead, 30, 25);
	foreachLinkedList(pHead);
	printf("链表长度为%d\n",sizeLinkedList(pHead));
	//foreachLinkedList(pHead);
	//destoryNode(pHead);
}