#include <iostream>
#include <string.h> 

using namespace std;

int main() {
    char str1[20] = "Hello";
    char str2[20] = " world";
    char str3[20]; // Объявление строки для хранения результата операций

    // Определение длины строки str1 с помощью функции strlen
    cout << "Длина строки str1: " << strlen(str1) << endl;

    // Конкатенация строк str1 и str2 с помощью функции strcat
    strcat(str1, str2);
    cout << "Результат конкатенации: " << str1 << endl;

    // Копирование содержимого строки str1 в строку str3 с помощью функции strcpy
    strcpy(str3, str1);
    cout << "Копия строки str1: " << str3 << endl;

    // Сравнение строк str1 и str3 с помощью функции strcmp
    int result = strcmp(str1, str3);
    if (result == 0)
        cout << "Строки str1 и str3 равны." << endl;
    else if (result < 0)
        cout << "Строка str1 меньше строки str3." << endl;
    else
        cout << "Строка str1 больше строки str3." << endl;

    return 0;
}