#include <iostream>
#include <cstring>
using namespace std;
// Шаблонная функция getmax для возвращения большего из двух параметров
template <class T>
T getmax(T t1, T t2)	//Возвращает больший из двух
{	//параметров
    return t1 > t2 ? t1 : t2;
}

// Функция getmax для сравнения строк и возвращения указателя на большую строку
char* getmax(char* s1, char* s2)
{
    return strcmp(s1, s2) > 0 ? s1 : s2;
}
// Шаблонная функция getmax для возвращения максимального значения из массива
template <class T>
T getmax(T t[], size_t size)
{
    T retval = t[0]; int i; // Инициализация retval первым элементом массива
    // Поиск максимального элемента в массиве
    for (i = 0; i < size; i++)
        if (t[i] > retval)
            retval = t[i];
    return retval;
}
int main()
{
    int il = 3, i2 = 5;
    char* sl = "string1"; char* s2 = "string2";
     // Вызов шаблонной функции для нахождения максимального из двух чисел
    cout << "max int = " << getmax(il, i2) << endl;
    // Вызов функции для сравнения строк и нахождения максимальной строки
    cout << "max str = " << getmax(sl, s2) << endl;
}