#include <stdio.h>

typedef struct account {
	int id;
	int pass;
	int balance;
}Account;

Account acc[10];
int numOfAccount = 0;

void showMenu();
void join();
void login();
void showSubMenu();
int transaction(int x);

int main()
{
	int choice;
	do
	{
		showMenu();
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			join(); break;
		case 2:
			login(); break;
		case 3:
			return 0;
		default:
			printf("Wrong Input!");
		}
		printf(acc);
	} while (1);
}
//1번 회원가입, 2번 로그인, 3번 종료

void showMenu() {
	printf("------------------------\n");
	printf("1. Join\n");
	printf("2. Login\n");
	printf("3. Exit\n");
	printf("choice : ");
}
void showSubMenu() {
	printf("------------------------\n");
	printf("1. Deposit\n");
	printf("2. Withdraw\n");
	printf("3. Query\n");
	printf("4. SendMoney\n");
	printf("5. Logout\n");
	printf("choice : ");
}

void join() {
	int id, pass;
	int i;
	printf("Enter id : ");
	scanf_s("%d", &id);
	for (i = 0; i < numOfAccount; i++) {
		if (acc[i].id == id)
		{
			printf("already exist!\n");
			break;
		}
	}

	if (i == numOfAccount) {
		acc[numOfAccount].id = id;
		printf("Enter passward : ");
		scanf_s("%d", &pass);
		acc[numOfAccount].pass = pass;
		acc[numOfAccount].balance = 0;
		numOfAccount++;
		printf("%d \n", numOfAccount);
	}
	else
		join();
}

int transaction(int x) {
	int choice;
	int query, deposit, withdraw;
	query = acc[x].balance;
	int yourid;
	int money;

	do
	{
		showSubMenu();
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Deposit!!\n");
			printf("Input Money : ");
			scanf_s("%d", &deposit);
			acc[x].balance += deposit;
			break;
		case 2:
			printf("Withdraw!!\n");
			printf("Input Money : ");
			scanf_s("%d", &withdraw);
			acc[x].balance = acc[x].balance - withdraw;
			break;
		case 3:
			printf("Query\n");
			printf("%dWon\n", acc[x].balance);;
			break;
		case 4:
			printf("Who? ");
			scanf_s("%d", &yourid);
			yourid = yourid - 1;
			printf("How much?");
			scanf_s("%d", &money);
			if (acc[x].balance - money > -1) {
				acc[yourid].balance = acc[yourid].balance + money;
				acc[x].balance = acc[x].balance - money;
			}
			else
				printf("No Money!\n");
			break;
		case 5:;
			printf("LogOut!\n");
			return 0;
		default:
			printf("Wrong Input!\n");
		}
	} while (1);
}

void login() {
	int i;
	int id, pass;
	printf("Input id : ");
	scanf_s("%d", &id);

	printf("Input passward : ");
	scanf_s("%d", &pass);

	for (i = 0; i < numOfAccount; i++) {
		if (acc[i].id == id && acc[i].pass == pass)
		{
			printf("LOGIN!!\n");
			transaction(i);
			break;
		}
		else if (acc[i].id == id)
		{
			printf("Wrong Password!");
			break;
		}
	}

	if (i == numOfAccount)
		printf("Not Exist\n");
}

