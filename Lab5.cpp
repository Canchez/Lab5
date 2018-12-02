#include "pch.h"
#include <stdio.h>
#include <Windows.h>

int fibonacci(int n)
{
	if (n <= 1)
	{
		return n;
	}
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int sumN(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += i;
	}
	return sum;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("\tВыберите действие:\n1.Узнать N-ое число Фибоначчи\n2.Узнать сумму всех чисел до N\n");

	int menu = 0;
	scanf_s("%d", &menu, 1);

	int number = 0;

	if (menu == 1)
	{
		printf("Какое по счёту число Фибоначчи вы хотите узнать?\n");
		scanf_s("%d", &number, 1);

		system("cls");
		printf("%d-e число Фибоначч равно %d\n", number, fibonacci(number));
		system("pause");
	}

	if (menu == 2)
	{
		printf("Сумму до какого числа вы хотите узнать?\n");
		scanf_s("%d", &number, 1);

		system("cls");
		printf("Сумма чисел до %d равна %d\n", number, sumN(number));
		system("pause");
	}

	return 0;
}

