#include <iostream>
using namespace std;
template <class T>
T getmax(T t1, T t2)//Возвращает больший из двух
{	//параметров
    return t1 > t2 ? t1 : t2;
}
template <class T>

// Шаблонная функция getmax, которая возвращает максимальное значение из массива
T getmax(T t[], size_t size)
{
    T retval = t[0]; int i; // Инициализация переменной retval значением первого элемента массива
    for (i = 0; i < size; i++) // Цикл для перебора элементов массива
        if (t[i] > retval)
            retval = t[i];
    return retval;
}
int main()
{
    int il = 3, i2 = 5; int mas[] = { 3, 9, 5, 8 }; // Объявление двух целочисленных переменных
    cout << "max int = " << getmax(il, i2) << endl; // Вывод максимального из двух целочисленных переменных
    cout << "max int = " << getmax(mas, sizeof(mas) / sizeof(mas[0])) << endl; cout << "max int = " << getmax(mas, sizeof(mas) / sizeof(mas[0])) << endl;
}