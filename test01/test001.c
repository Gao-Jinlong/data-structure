#include<stdio.h>
#include<stdlib.h>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define list_init_size 10 //initial memory
#define list_increament 10 //increment memory

//dynamic SequenceList Struct
typedef struct {
	int *elem; //memory basic address
	int length; //current length
	int list_size; //current storage capacty(sizeof(int))
}SqList;

//initialize SqList
int InitList_Sq(SqList* L) {
	//dynamic creation storage
	L->elem = (int*)malloc(list_init_size * sizeof(int));
	//creation memory false
	if (!L->elem)
		exit(OVERFLOW);
	L->length = 0; //initialize list length
	L->list_size = list_init_size; //initialize storage capacity
	return OK;
}

//input data
int Input_Sq(SqList *L, int n) {
	int i, * newbase;
	if (n < 0) {
		return ERROR;
	}
	//detection size
	if (n > L->list_size) {
		newbase = (int*)realloc(L->elem, n * sizeof(int));
		if (!newbase)
			exit(OVERFLOW);
		L->elem = newbase;//redistribution memory
		L->list_size += list_increament;
	}
	printf("please input data:\n");
	for (i = 0; i < n; i++) {
		scanf("%d",&L->elem[i]);
		L->length++;
	}
	return OK;
}
//print SqList
int Output_Sq(SqList *L) {
	printf("current list content:\n");
	int i = 0;
	for (i = 0; i < L->length; i++) {
		printf("%d\t", L->elem[i]);
	}

    return 0;
}
//ListInsert.Sq
int InsertList_Sq(SqList* L, int position, int data) {
	int* newbase;
	int* p;
	int* q;
	if (position < 1 | position > L->length + 1) return ERROR;
	if (L->length >= L->list_size) {
		newbase = (int*)realloc(L->elem, (L->list_size + list_increament) * sizeof(int));
		if (!newbase) exit(OVERFLOW);
		L->elem = newbase;
		L->list_size += list_increament;
	}
	q = &(L->elem[position - 1]);
	for (p = &(L->elem[L->length - 1]); p >= q; p--) {
		*(p + 1) = *p;
	}
	*q = data;
	L->length += 1;
	return OK;
}

//DeleteList.Sq
int DeleteList_Sq(SqList* L, int i, int e) {
	if ((i < 1) || (i > L->length)) return ERROR;
	int* p, * q;
	p = &(L->elem[i - 1]);
	for (p++, q = &(L->elem[L->length - 1]); p <= q; p++) *(p - 1) = *p;
	--L->length;
	return OK;
}

//find ele
int LocateElem_Sq(SqList* L, int e) {
	int i = 0, *p;
	p = L->elem;
	while (i < L->length && (*p) != e) { 
		p++, ++i; 
	}
	if (i < L->length)return i + 1;
	else return 0;
}

//?????
int main() {
	SqList MYL;
	char a;
	a = 'Y';
	int num, data, position, *e;
	InitList_Sq(&MYL);
	printf("please enter amount of data:\n");
	scanf("%d", &num);
	//enter data
	Input_Sq(&MYL,num);
	//traversal SqList
	Output_Sq(&MYL);
	/*-----------
	printf("\nplease enter the position to be insert:\n");
	scanf("%d", &position);
	printf("palease enter the data to ne insert:\n");
	scanf("%d", &data);
	InsertList_Sq(&MYL, position, data);

	Output_Sq(&MYL); 

	printf("\nPlease enter delete position:\n");
	scanf("%d", &position);
	DeleteList_Sq(&MYL, position, &data);
	printf("Delete ele is \n%d\n",data);

	Output_Sq(&MYL);
	----*/
	printf("\nPlease enter locate value:\n");
	scanf("%d", &data);
	position = LocateElem_Sq(&MYL, data);
	if (position) {
		printf("Elem %d on %d\n", data, position);
	}
	else {
		printf("Elem %d is not located", data);
	}

	Output_Sq(&MYL);

    return 0;
}