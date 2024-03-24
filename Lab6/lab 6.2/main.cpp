#include <iostream>
#include "MyString.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru"); // Кодировка
    MyString str1("ASDSDFDSF");
    MyString str2("ASDASDDAS");

    MyString str3 = str1 + str2;
    cout << "Объединенная строка: " << str3 << endl;

    if (str1 == str2) {
        cout << "Строки равны: " << endl;
    } else {
        cout << "Строки не равны:" << endl;
    }

    cout << "Длина строки:" << str1.length() << endl;

    MyString str4;
    cout << "Введите: ";
    cin >> str4;
    cout << "Введенная строка:" << str4 << endl;

    return 0;
}