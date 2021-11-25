/*Задача№1: Все отрицательные элементы массива X перенести в его начало, а все остальные — в
конец, сохраняя  исходное  взаимное  расположение, как  среди  отрицательных, так  и
среди остальных элементов.Дополнительный массив не заводить.*/
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
int main()
{
	setlocale(LC_ALL, "");
	int m = 1, num;
	while (m == 1)
	{
		int* A;
		int n = 0;
		cout << "Введите кол-во элементов: "; cin >> n;
		A = new int[n];

		cout << "Наш изначальный массив:" << endl;
		for (int i = 0; i < n; i++)
		{
			A[i] = rand() % 201 - 100;// заполняем рандомными числами от -80 до 80
			cout << setw(6) << A[i]; // вывод массива 
		}
		cout << endl;
		cout << "Наглядное представление работы программы:" << endl;
		bool flag = true;
		while (flag)
		{
			for (int i = 0; i < n - 1; i++) // цикл поиска отрицательных элементов 
			{
				if ((A[i] >= 0) and (A[i + 1] < 0))
				{
					swap(A[i], A[i + 1]); // замена идущего на последующее
					/*int temp = A[i]; //второй вариант замены
					A[i] = A[i + 1];
					A[i + 1] = temp;*/
					for (int j = 0; j < n; j++) // вывод промежуточного массива
						cout << setw(6) << A[j];
					cout << endl;
					break;
				}
				if (i == n - 2) // проверка на выход из цикла
					flag = false;
			}
		}

		cout << "Полученный массив:" << endl;
		for (int j = 0; j < n; j++)
			cout << setw(6) << A[j];
		cout << endl;
		delete[] A;
		cout << "Построить новый массив элементов? (1-Да)\n"; // меню продолжения
		cin >> m;
	}
	system("pause");
	return 0;
}

