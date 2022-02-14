#include"DynamicArray.h"


//��ʼ����̬����
struct DynamicArray* initDA(int capacity) {
	//�ж������Ƿ�Ϸ�
	if (capacity <= 0)
		return NULL;
	struct DynamicArray* Array = (struct DynamicArray*)malloc(sizeof(struct DynamicArray));
	//�жϿռ俪���Ƿ�ɹ�
	if (Array == NULL)
		return NULL;

	//��������
	Array->capacity = capacity;
	//���ô�С
	Array->size = 0;
	//����������������ռ䣬Ĭ������Ϊvoid *��������ָ���κ����͵����ݣ�
	Array->pHead = (void **)malloc(sizeof(void*) * Array->capacity);
	return Array;
}
//����Ԫ��
void insertDA(struct DynamicArray * Array,int pos, void * Val) {
	if (Array == NULL)
		return; 
	//���λ��С��0�������ֵ����β�壻
	if (pos < 0 || pos >= Array->size) {
		Array->pHead[Array->size] = Val;
		Array->size++;
	}
	else {
		//������������������¿��� ԭ��������2����
		int newCapacity = 2 * Array->capacity;
		if (Array->size >= Array->capacity) {
			//�����¿ռ�,����Ϊԭ����2��
			void** pNewHead = (void**)malloc(sizeof(void*) * newCapacity);
			//�ж��Ƿ񿪱ٳɹ�
			if (pNewHead == NULL)
				return;
			//Ų������
			memcpy(pNewHead, Array->pHead, sizeof(void*) * Array->size);
			//�ͷ�ԭ�пռ�
			free(Array->pHead);
			//�޸�ָ�������
			Array->pHead = pNewHead;
			Array->capacity = newCapacity;
		}
		//����Ԫ�غ��ƣ��ڳ�posλ�ã���Val���뵽posλ�ã�
		//printf("�����СΪ%d\n", Array->size);
		for (int i = Array->size - 1;i >= pos;i--) {
			Array->pHead[i + 1] = Array->pHead[i];
		}
		//��������
		Array->pHead[pos] = Val;
		//���´�С
		Array->size++;
	}
}

//������̬����
//���û��Լ���д������ʽ
void myForeach(void* data) {
	if (data == NULL)
		return;
	struct person* p = (struct person*)data;
	printf("���֣�%s\t", p->name);
	printf("���䣺%d\n", p->age);
}


void foreachDA(struct DynamicArray * Array, void(*myForeach)(void *)) {//�ص�����
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

//����λ��ɾ��
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

//����ֵ��ɾ��
//�û��Լ�ȷ���ȽϺ���
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

//�ݻٶ�̬����
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