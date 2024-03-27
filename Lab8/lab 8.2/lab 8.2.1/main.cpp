#include <iostream>

using namespace std;

template <class T>
T getmax(T t1, T t2)		//Возврашает больший из двух 
{					// параметров
	return t1 > t2?t1:t2;
}

template <class T>
T getmax(T t[], size_t size)
{
	T retval = t[0]; // Инициализация переменной retval значением первого элемента массива
	int i;
	for(i = 0; i < size; i++) // Цикл для перебора элементов массива
		if(t[i] > retval) retval = t[i]; // Если текущий элемент больше, чем текущее максимальное значение, обновить максимальное значение
	return retval; // Вернуть максимальное значение
}

void main(void)
{
	int i1 = 3, i2 = 5;
int mas[] = {3, 9, 5, 8};
cout << "max int = " << getmax(i1, i2) << endl;
cout << "max int = " << getmax(sizeof(mas)/sizeof(mas[0])) << endl; // Вывод максимального из двух целочисленных переменных
}
