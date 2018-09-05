#include <stdio.h>

typedef struct account {
	int id;
	int pass;
	int balance;
}Account;

Account acc[10];
int numOfAccount = 0;

void join();
void login();
void showMenu();
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
	} while (1);
}
//1�� ȸ������, 2�� �α���, 3�� ����

//print text
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

//make ID and Passward, id�ߺ� �ȵ�!
void join() {
	int id, pass;
	int i;
	printf("Enter id : ");
	scanf_s("%d", &id);
	for (i = 0; i < numOfAccount; i++)
	{
		// ���� �迭�ȿ� ���� �ۼ��� ���̵� �����Ѵٸ� already exist�� ����� ������ break
		if (acc[i].id == id)
		{
			printf("already exist!\n");
			break;
		}
	}

	// ���� for���� ������ �����Ͽ����� �����ϴ� ���̵� ���°����� �����ϸ� passward�� �ۼ�
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

//id�� ������ not exist�� ������ ����
// passward�� Ʋ���� worng passward��� �� passward �ٽ� �Է�
void login() {
	int i;
	int id, pass;
	
	printf("Input id : ");
	scanf_s("%d", &id);
	for (i = 0; i < numOfAccount; i++) {
		if (acc[i].id == id)
			break;
		else
		{
			while (1)
			{
				printf("Not exist ID!\n");
				printf("ReInput ID : ");
				scanf_s("%d", &id);
				if (acc[i].id == id)
					break;
			}
		}

	}

	printf("\nInput passward : ");
	scanf_s("%d", &pass);
	
	for (i = 0; i < numOfAccount; i++)
	{
		if (acc[i].id == id && acc[i].pass == pass)
		{
			printf("LOGIN Success!!\n");
			transaction(i);
			break;
		}

		else if (acc[i].id == id)
		{
			while (1)
			{
				printf("Wrong Password!\n");
				printf("ReInput passward : ");
				scanf_s("%d", &pass);
				if (acc[i].id == id && acc[i].pass == pass)
				{
					printf("LOGIN Success!!\n");
					transaction(i);
					break;
				}
			}	
		}
	}
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
			printf("Input Deposit Money : ");
			scanf_s("%d", &deposit);
			acc[x].balance += deposit;
			break;
		case 2:
			printf("Withdraw!!\n");
			printf("Input Withdraw Money : ");
			scanf_s("%d", &withdraw);
			acc[x].balance = acc[x].balance - withdraw;
			break;
		case 3:
			printf("Query!!\n");
			printf("%dWon\n", acc[x].balance);;
			break;
		case 4:
			printf("\nSendMoney!!\n");
			printf("Input User ID : ");
			scanf_s("%d", &yourid);

			yourid = yourid - 1;

			printf("Input Money : ");
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