#include <iostream>
#include "MyString.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru"); // Кодировка

    // Создание двух объектов класса MyString с заданными строками
    MyString str1("ASDSDFDSF");
    MyString str2("ASDASDDAS");

// Объединение строк с использованием оператора +
    MyString str3 = str1 + str2;
    cout << "Объединенная строка: " << str3 << endl;

// Проверка на равенство строк с использованием оператора ==
    if (str1 == str2) {
        cout << "Строки равны: " << endl;
    } else {
        cout << "Строки не равны:" << endl;
    }

// Вывод длины строки с использованием метода length()
    cout << "Длина строки:" << str1.length() << endl;

// Создание объекта класса MyString и ввод строки с клавиатуры с использованием оператора >>
    MyString str4;
    cout << "Введите: ";
    cin >> str4;
    cout << "Введенная строка:" << str4 << endl;

    return 0;
}