#include"DynamicArray.h"




int main() {
	//��ʼ��һ����̬����
	struct DynamicArray* arr = initDA(6);

	//�����̬��������
	printf("��̬��������Ϊ%d\n",(arr->capacity));

	//����6������
	struct person p1 = { "jeffrey",24 };
	struct person p2 = { "Jason", 25 };
	struct person p3 = { "Maria",23};
	struct person p4 = { "Leonard",26};
	struct person p5 = { "Kwhi",29};
	struct person p6 = { "Geoge",30};
	struct person p7 = {"Winslow",32};



	//�����ݷ�������
	insertDA(arr,0,&p1);
	insertDA(arr,0,&p2);
	insertDA(arr,0,&p3);
	insertDA(arr,0,&p4);
	insertDA(arr,0,&p5);
	insertDA(arr,0,&p6);
	insertDA(arr,0,&p7);

	//������̬����
	foreachDA(arr,myForeach);
	//�����̬��������
	printf("��̬��������Ϊ%d\n", (arr->capacity));

	deleteDAByPosition(arr,6);
	//������̬����
	foreachDA(arr, myForeach);

	printf("\n");
	struct person p = {"Jason", 25};
	printf("ɾ��jason\n");
	deleteDAByValue(arr, &p, myCompare);
	//������̬����
	foreachDA(arr, myForeach);

	destoryDA(arr);
	//insertDA(arr,0,&p1);
	//������̬����
	foreachDA(arr,myForeach);
	return 0;
}