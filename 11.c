#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Item{
	struct Item * prev;
	struct Item * next;
	char surname[100];
	char name[100];
	char patronymic[100];
	int day;
	int month;
	int year;
	char city[100];
	char street[100];
	char house_number[10];
	int apart_number;
	char number[11];
} Item;

typedef struct List{
	struct Item * head;
	struct Item * tail;
} List;

void PrintList (const List * L){
	Item * I;
	int i = 1;
	for(I = L -> head; I != NULL; I = I -> next, i++){
		printf(" ���� %d-�", i);
		printf("\n �������: %s", I->surname);
		printf("\n ���: %s", I->name);
		printf("\n ��������: %s", I->patronymic);
		printf("\n ���� ��������: %d.%d.%d", I->day, I->month, I->year);
		printf("\n ����� ����������:");
		printf("\n  �����: %s", I->city);
		printf("\n  �����: %s", I->street);
		printf("\n  ����� ����: %s", I->house_number);
		printf("\n  ����� ��������: %d", I->apart_number);
		printf("\n ����� ��������: %s", I->number);
		printf("\n\n");
	}
}

void Add (List * L, Item * I){
	if(I && L){
		I -> prev = L -> tail;
		I -> next = NULL;
		if(L -> head == NULL)
			L -> head = I;
		else
			L -> tail -> next = I;
		L -> tail = I;
		getchar(); // ����� ��� ���������� ������ gets, ����� ������� ������
		printf("\n �������: ");
		gets(I->surname);
		printf(" ���: ");
		gets(I->name);
		printf(" ��������: ");
		gets(I->patronymic);
		printf(" ���� �������� (������ ����.�����.���): ");
		scanf("%d.%d.%d", &I->day, &I->month, &I->year);
		printf(" ����� ����������:\n");
		getchar();
		printf("  �����: ");
		gets(I->city);
		printf("  �����: ");
		gets(I->street);
		printf("  ����� ����: ");
		gets(I->house_number);
		printf("  ����� ��������: ");
		scanf("%d", &I->apart_number);
		getchar();
		printf(" ����� ��������: ");
		scanf("%s",I->number);
	}
}

void Delete (List * L, int n){
	Item * I;
	int Count, i = 0;
	if(L)
		for(I = L -> head; I; I = I -> next, Count++);
	else return ;
	if(n > 0 && n <= Count){
		i = 1;
		for(I = L -> head; i != n; I = I -> next, i++);
	}
	else return ;
	if(I){
		if(L -> head == L -> tail){
			L -> head = NULL;
			L -> tail = NULL;
		}
		else if(I -> prev == NULL){
			L -> head = I -> next;
			L -> head -> prev = NULL;
		}
		else if(I -> next == NULL){
			L -> tail = I -> prev;
			L -> tail -> next = NULL;
		}
		else{
			I -> prev -> next = I -> next;
			I -> next -> prev = I -> prev;
		}
		free(I);
	}
	else return ;
}

void PrintTask(const List * L){
	Item * I;
	int i = 1, mnth;
	printf("������� �����: ");
	scanf("%d", &mnth);
	system("cls");
	for(I = L -> head; I != NULL; I = I -> next, i++){
		if(mnth == I->month){
			printf(" ���� %d-�", i);
			printf("\n �������: %s", I->surname);
			printf("\n ���: %s", I->name);
			printf("\n ��������: %s", I->patronymic);
			printf("\n ���� ��������: %d.%d.%d", I->day, I->month, I->year);
			printf("\n ����� ����������:");
			printf("\n  �����: %s", I->city);
			printf("\n  �����: %s", I->street);
			printf("\n  ����� ����: %s", I->house_number);
			printf("\n  ����� ��������: %d", I->apart_number);
			printf("\n ����� ��������: %s", I->number);
			printf("\n\n");
		}
	}
}

int main(){
	system("chcp 1251 > nul");
	List L = {NULL, NULL};
	Item * I = NULL, * element;
	int numb, key;
	do{
		printf("���������: ������ \n\n����� ��������:\n\n 1 - �������� �����\n 2 - ������� �����\n"
		" 3 - ������� ������ ������\n 4 - ������� ������ ������ �� ��������\n 0 - �����\n\n������� �����: ");
		fflush(stdin);
		if(scanf("%d", &key) != 1 || key < 0 || key > 9)
			key = -1;
		switch(key){
			case 1:
				system("cls");
				element = malloc(sizeof(Item));
				Add(&L, element);
				system("cls");
				break;
			case 2:
				system("cls");
				printf("\n������� �����(����������) �����: ");
				scanf("%d", &numb);
				if(L.head){
					Delete(&L, numb);
					printf("\n���� %d ��� ������\n", numb);
				}
				else
					printf("\n��� ������, ���������� �������� ���� �� ������� ����� � ������\n");
				break;
			case 3:
				system("cls");
				PrintList(&L);
				break;
			case 4:
				system("cls");
				PrintTask(&L);
				break;
			case -1:
				system("cls");
				printf("\n����� �������� ���\n");
				break;
			case 0:
				key = 0;
				break;
		}
	} while(key);
	system ("pause");
	return 0;
}