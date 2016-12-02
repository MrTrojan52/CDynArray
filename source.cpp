#include "CDArr.h"
#include <stdio.h>
#include <iostream>
#include <conio.h>
#define SIZE 5
#define LEN 50
#define DOWN_ARROW 80
#define UP_ARROW 72

int menu(); 

template <typename Type>
void CreateArray()
{
	int size = 0;
	std::cout << std::endl << "Size = ";
	std::cin >> size;
	CDArray<Type> obj(size);
	obj.fillArrayFK();
	system("cls");
	std::cout << std::endl << "Size of the array = " << obj.getSize();
	for (int i = 0; i < obj.getSize(); i++)
	{
		std::cout << std::endl << obj[i];
	}
	_getch();
}

int main()
{
	
	do
	{
		int choice = menu();

		switch (choice)
		{
			case 1:
			{
				CreateArray<float>();
				break;
			}
			case 2:
			{
				CreateArray<char>();
				break;
			}
			case 3:
			{
				CreateArray<int>();
				break;
			}
			case 4:
			{
				CreateArray<double>();
				break;
			}
			case 5:
				return 0;


		default:
			break;
		}
	} while (true);

	
}



int menu()
{
	char a[SIZE][LEN] = {
		"Create float array",
		"Create char array",
		"Create int array",
		"Create double array",
		"Exit"
		
	};


	int choice = 0;
	int Key = 0;



	do
	{
		system("cls");
		for (int i = 0; i < SIZE; i++)
		{
			if (choice == i)
			{
				std::cout << "\t>> " << a[i] << std::endl << std::endl;

			}
			else
			{
				std::cout << "\t" << a[i] << std::endl << std::endl;

			}
		}
		Key = _getch();
		if (Key == 224)
		{
			Key = _getch();
			switch (Key)
			{
			case UP_ARROW:
				if (choice - 1 >= 0)
				{
					choice--;
				}
				else
				{
					choice = SIZE - 1;
				}
				break;
			case DOWN_ARROW:
				if (choice + 1 < SIZE)
				{
					choice++;
				}
				else
				{
					choice = 0;
				}
				break;
			default:
				break;
			}
		}

	} while (Key != 13);
	system("cls");
	return choice + 1;



}