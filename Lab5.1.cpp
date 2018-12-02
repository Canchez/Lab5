#include "pch.h"
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <locale>
#include <memory.h>
#include <Windows.h>
#ifdef _DEBUG				// Для подключения функции, проверяющей утечки памяти
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#endif

int menu()
{
	int key = 1;
	while (key == 1)
	{
		printf("\t\tПрограмма для работы с массивами\n\nВыберите действие с помощью клавиш с цифрами: \n");
		printf("1. Ввести строку\n");
		printf("2. Найти самое короткое слово\n");
		printf("3. Вывести самое короткое слово\n");
		printf("4. О программе\n");
		printf("5. Об авторе\n");
		printf("6. Выход\n");

		int ctrl = _getch();
		switch (ctrl - 48)
		{
		case 1:
			return 1;
		case 2:
			return 2;
		case 3:
			return 3;
		case 4:
			while (true)
			{
				system("cls");
				printf("\t\tО программе\n\n");
				printf("Данная программа находит в строке самое короткое слово\n");
				printf("\nУправление производится клавишами 1-5\n");
				printf("\n1. Назад\n");

				int ctrl2 = _getch();
				switch (ctrl2 - 48)
				{
				case 1:
					system("cls");
					break;
				default:;
				}
				if (ctrl2 - 48 == 1) break;
			}
			break;
		case 5:
			while (true)
			{
				system("cls");
				printf("\t\tОб авторе\n\n");
				printf("Азанов Никита Олегович\n");
				printf("Обучается в СФУ ИКИТ Программная инженерия\n");
				printf("Группа КИ18-17/2б\n");
				printf("\n1. Назад\n");

				int ctrl2 = _getch();
				switch (ctrl2 - 48)
				{
				case 1:
					system("cls");
					break;
				default:;
				}
				if (ctrl2 - 48 == 1) break;
			}
			break;
		case 6:
			return 6;
		default:
			system("cls");
			break;
		}
	}
}
char* input()
{	
	printf("Введите строку: \n");
	char* string = new char[1];
	string[0] = '\0';
	char* tmp = NULL;
	char ch = '0';
	int symbols = 0;
	int len = 0;

	while (true)
	{	
		if (symbols >= 128)
		{
			printf("\n\nYou can't write more!");
			printf("\nPress any button...");
			_getch();
			_getch();
			break;
		}
		_getch();
		ch = _getch();
		
		len = strlen(string);


		printf("%c", ch);

		if (ch == '\0')
		{
			continue;
		}

		if (ch == 8)
		{
			if (strlen(string) == 0)
			{
				continue;
			}

			printf(" %c", 8);  // Графическая очистка строки

			tmp = new char[len];

			for (int i = 0; i < len; i++)
			{
				tmp[i] = string[i];
			}

			tmp[len - 1] = '\0';

			delete[] string;
			string = tmp;

			continue;
		}

		if (ch == 13)
		{
			printf("\n");
			break;
		}

		tmp = new char[len + 2];

		strcpy(tmp, string);

		tmp[len] = ch;
		tmp[len + 1] = '\0';

		delete[] string;
		string = tmp;

		symbols++;
	}

	return string;
}
char* searchShort(char* string)
{	
	const int MAX_LEN = 1000;
	int lenString = strlen(string);
	int minLenWord = MAX_LEN;
	int counter = 0;
	int index = 0;
	int nextIndex = 0;
	char* resultWord = NULL;
	
	for (int i = 0; i <= lenString; i++)
	{
		if ((string[i] != ' ') && (string[i] != '\0') && (string[i] != ',') && (string[i] != '.') && (string[i] != '!') && (string[i] != '?') && (string[i] != ':') && (string[i] != '(') && (string[i] != ')'))
		{
			counter++;
		}

		else
		{
			if (counter == 0)
			{
				nextIndex = i + 1;
				continue;
			}

			if (minLenWord > counter)
			{
				minLenWord = counter;
				index = nextIndex;
			}

			counter = 0;
			nextIndex = i + 1;
		}
	}

	resultWord = new char[minLenWord + 1];
	strncpy(resultWord, (string + index), minLenWord);
	resultWord[minLenWord] = '\0';

	return resultWord;
}
void output(char* result)
{
	system("cls");

	printf("Самое короткое найденное слово: %s", result);
	printf("\nНажмите любую клавишу для продолжения..");
	_getch();
	_getch();
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int menu_choice = 0;
	char* string = NULL;
	char* result = NULL;
	char* shortWord = NULL;
	while (true)
	{
		system("cls");
		menu_choice = menu();

		if (menu_choice == 1)
		{
			system("cls");

			if (string != NULL)
			{
				delete[] string;
			}

			string = input();
		}

		if (menu_choice == 2)
		{	
			if (string != NULL)
			{
				if (shortWord != NULL)
				{
					delete[] shortWord;
				}

				shortWord = searchShort(string);

				if (result != NULL)
				{
					delete[] result;
				}

				result = new char[strlen(shortWord) + 1];

				strcpy(result, shortWord);

				printf("\nСамое короткое слово найдено!\nНажмите любую клавишу для продолжения..");
				_getch();
				_getch();
			}
			else
			{
				printf("\nВы не ввели строку!\nНажмите любую клавишу для продолжения..");
				_getch();
				_getch();
			}
		}

		if (menu_choice == 3)
		{
			if (result != NULL)
			{
				output(result);
			}
			else
			{
				printf("Слово ещё не найдено!\nНажмите любую клавишу для продолжения..");
				_getch();
				_getch();
			}
		}

		if (menu_choice == 6)
		{
			break;
		}
	}

	delete[] shortWord;
	delete[] result;
	delete[] string;

	_CrtDumpMemoryLeaks(); // Поиск утечек памяти

	return 0;
}
