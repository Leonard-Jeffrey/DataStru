#pragma once
#include<stdio.h>
#include<stdlib.h>

void staticLinkedList();
void dynamicLinkedList();
struct LinkNode* initLinkedListByHead();
struct LinkNode* initLinkedListByTail();
void foreachLinkedList(struct LinkNode *pHead);
void addNode(struct LinkNode *pHead, int oldVal, int newVal);
void deleteNode(struct LinkNode *pHead, int Val);
void searchNode(struct LinkNode *pHead, int Val);
void modifyNode(struct LinkNode *pHead, int oldVal, int newVal);
void clearLinkedList(struct LinkNode *pHead);
void destoryLinkedList(struct LinkNode *pHead);
void reverseLinkedList(struct LinkNode *pHead);
void reverseForeachLinkedList(struct LinkNode *pHead);
int sizeLinkedList(struct LinkNode *pHead);