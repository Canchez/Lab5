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

int validation(int min, int max)
{
	char check = '\0';
	bool isOk = false;
	int value = 0;
	while (!isOk)
	{
		while (scanf_s("%d%c", &value, &check, 1) != 2 || check != '\n');
		{
			while (getchar() != '\n');
		}
		if ((value < min) || (value > max))
		{
			isOk = false;
		}
		else
		{
			isOk = true;
		}
	}
	return value;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("\tВыберите действие:\n1.Узнать N-ое число Фибоначчи\n2.Узнать сумму всех чисел до N\n");

	int menu = 0;
	menu = validation(1, 2);

	int number = 0;

	if (menu == 1)
	{
		printf("Какое по счёту число Фибоначчи вы хотите узнать?\n");
		number = validation(1, 256);

		system("cls");
		printf("%d-e число Фибоначч равно %d\n", number, fibonacci(number));
		system("pause");
	}

	if (menu == 2)
	{
		printf("Сумму до какого числа вы хотите узнать?\n");
		number = validation(1, 500);

		system("cls");
		printf("Сумма чисел до %d равна %d\n", number, sumN(number));
		system("pause");
	}

	return 0;
}

