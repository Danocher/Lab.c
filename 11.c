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
		printf(" Друг %d-й", i);
		printf("\n Фамилия: %s", I->surname);
		printf("\n Имя: %s", I->name);
		printf("\n Отчество: %s", I->patronymic);
		printf("\n Дата рождения: %d.%d.%d", I->day, I->month, I->year);
		printf("\n Место проживания:");
		printf("\n  Город: %s", I->city);
		printf("\n  Улица: %s", I->street);
		printf("\n  Номер дома: %s", I->house_number);
		printf("\n  Номер квартиры: %d", I->apart_number);
		printf("\n Номер телефона: %s", I->number);
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
		getchar(); // нужен для адекватной работы gets, ловит перевод строки
		printf("\n Фамилия: ");
		gets(I->surname);
		printf(" Имя: ");
		gets(I->name);
		printf(" Отчество: ");
		gets(I->patronymic);
		printf(" Дата рождения (формат День.Месяц.Год): ");
		scanf("%d.%d.%d", &I->day, &I->month, &I->year);
		printf(" Место проживания:\n");
		getchar();
		printf("  Город: ");
		gets(I->city);
		printf("  Улица: ");
		gets(I->street);
		printf("  Номер дома: ");
		gets(I->house_number);
		printf("  Номер квартиры: ");
		scanf("%d", &I->apart_number);
		getchar();
		printf(" Номер телефона: ");
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
	printf("Введите месяц: ");
	scanf("%d", &mnth);
	system("cls");
	for(I = L -> head; I != NULL; I = I -> next, i++){
		if(mnth == I->month){
			printf(" Друг %d-й", i);
			printf("\n Фамилия: %s", I->surname);
			printf("\n Имя: %s", I->name);
			printf("\n Отчество: %s", I->patronymic);
			printf("\n Дата рождения: %d.%d.%d", I->day, I->month, I->year);
			printf("\n Место проживания:");
			printf("\n  Город: %s", I->city);
			printf("\n  Улица: %s", I->street);
			printf("\n  Номер дома: %s", I->house_number);
			printf("\n  Номер квартиры: %d", I->apart_number);
			printf("\n Номер телефона: %s", I->number);
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
		printf("Программа: Друзья \n\nВыбор операции:\n\n 1 - Добавить друга\n 2 - Удалить друга\n"
		" 3 - Вывести список друзей\n 4 - Вывести список друзей по критерию\n 0 - Выход\n\nВведите номер: ");
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
				printf("\nВведите номер(порядковый) друга: ");
				scanf("%d", &numb);
				if(L.head){
					Delete(&L, numb);
					printf("\nДруг %d был удален\n", numb);
				}
				else
					printf("\nДля работы, необходимо добавить хотя бы одиного друга в список\n");
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
				printf("\nТакой операции нет\n");
				break;
			case 0:
				key = 0;
				break;
		}
	} while(key);
	system ("pause");
	return 0;
}