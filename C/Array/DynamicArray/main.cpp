#include"DynamicArray.h"




int main() {
	//初始化一个动态数组
	struct DynamicArray* arr = initDA(6);

	//输出动态数组容量
	printf("动态数组容量为%d\n",(arr->capacity));

	//生成6条数据
	struct person p1 = { "jeffrey",24 };
	struct person p2 = { "Jason", 25 };
	struct person p3 = { "Maria",23};
	struct person p4 = { "Leonard",26};
	struct person p5 = { "Kwhi",29};
	struct person p6 = { "Geoge",30};
	struct person p7 = {"Winslow",32};



	//将数据放入数组
	insertDA(arr,0,&p1);
	insertDA(arr,0,&p2);
	insertDA(arr,0,&p3);
	insertDA(arr,0,&p4);
	insertDA(arr,0,&p5);
	insertDA(arr,0,&p6);
	insertDA(arr,0,&p7);

	//遍历动态数组
	foreachDA(arr,myForeach);
	//输出动态数组容量
	printf("动态数组容量为%d\n", (arr->capacity));

	deleteDAByPosition(arr,6);
	//遍历动态数组
	foreachDA(arr, myForeach);

	printf("\n");
	struct person p = {"Jason", 25};
	printf("删除jason\n");
	deleteDAByValue(arr, &p, myCompare);
	//遍历动态数组
	foreachDA(arr, myForeach);

	destoryDA(arr);
	//insertDA(arr,0,&p1);
	//遍历动态数组
	foreachDA(arr,myForeach);
	return 0;
}