#include"DynamicArray.h"


//初始化动态数组
struct DynamicArray* initDA(int capacity) {
	//判断容量是否合法
	if (capacity <= 0)
		return NULL;
	struct DynamicArray* Array = (struct DynamicArray*)malloc(sizeof(struct DynamicArray));
	//判断空间开辟是否成功
	if (Array == NULL)
		return NULL;

	//设置容量
	Array->capacity = capacity;
	//设置大小
	Array->size = 0;
	//根据容量开辟数组空间，默认类型为void *，即可以指向任何类型的数据；
	Array->pHead = (void **)malloc(sizeof(void*) * Array->capacity);
	return Array;
}
//插入元素
void insertDA(struct DynamicArray * Array,int pos, void * Val) {
	if (Array == NULL)
		return; 
	//如果位置小于0大于最大值，则尾插；
	if (pos < 0 || pos >= Array->size) {
		Array->pHead[Array->size] = Val;
		Array->size++;
	}
	else {
		//如果容量不够，则重新开辟 原来容量的2倍；
		int newCapacity = 2 * Array->capacity;
		if (Array->size >= Array->capacity) {
			//开辟新空间,容量为原来的2倍
			void** pNewHead = (void**)malloc(sizeof(void*) * newCapacity);
			//判断是否开辟成功
			if (pNewHead == NULL)
				return;
			//挪动数据
			memcpy(pNewHead, Array->pHead, sizeof(void*) * Array->size);
			//释放原有空间
			free(Array->pHead);
			//修改指针和容量
			Array->pHead = pNewHead;
			Array->capacity = newCapacity;
		}
		//整体元素后移，腾出pos位置，将Val插入到pos位置；
		//printf("数组大小为%d\n", Array->size);
		for (int i = Array->size - 1;i >= pos;i--) {
			Array->pHead[i + 1] = Array->pHead[i];
		}
		//插入数据
		Array->pHead[pos] = Val;
		//更新大小
		Array->size++;
	}
}

//遍历动态数组
//由用户自己编写遍历方式
void myForeach(void* data) {
	if (data == NULL)
		return;
	struct person* p = (struct person*)data;
	printf("名字：%s\t", p->name);
	printf("年龄：%d\n", p->age);
}


void foreachDA(struct DynamicArray * Array, void(*myForeach)(void *)) {//回调函数
	if (Array == NULL) {
		printf("hello");
		return;
	}
	if (myForeach == NULL)
		return;

	for (int i = 0; i < Array->size;i++){
		myForeach(Array->pHead[i]);
	}
}

//按照位置删除
void deleteDAByPosition(struct DynamicArray * Array, int pos) {
	if (Array == NULL)
		return;
	if (pos < 0 || pos >= Array->size)
		return;
	for (int i = pos;i < Array->size-1;i++) {
		Array->pHead[i] = Array->pHead[i + 1];
	}
	Array->size--;
}

//按照值来删除
//用户自己确定比较函数
int myCompare(void* data, void* Val) {
	if (data == NULL || Val == NULL)
		return 0;
	struct person* p1 = (struct person*)data;
	struct person* p2 = (struct person*)Val;
	if (!strcmp(p1->name, p2->name) && p1->age == p2->age)
		return 1;
	else
		return 0;
}

void deleteDAByValue(struct DynamicArray *Array, void * Val, int(*myCompare)(void *p1, void *p2)) {
	if (Array == NULL)
		return;
	if (Val == NULL)
		return;
	if (myCompare == NULL)
		return;
	for (int i = 0;i < Array->size;i++) {
		if (myCompare(Array->pHead[i], Val)) {
			deleteDAByPosition(Array, i);
			break;
		}
	}
}

//摧毁动态数组
void destoryDA(struct DynamicArray* Array) {
	if (Array == NULL)
		return;
	if (Array->pHead != NULL) {
		free(Array->pHead);
		Array->pHead == NULL;
	}
	free(Array);
	Array = NULL;
}