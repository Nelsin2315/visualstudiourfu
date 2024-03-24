#include <iostream>
#include<conio.h>
using namespace std;


// Объявление функции power
int power(int x, int n);

int main() {
    setlocale(LC_ALL, "ru"); // Кодировка
    int i, k;
    int base;
//Вводим основание
    cout << "Введите основание: ";
    cin >> base;
    
    // Вычисление  степеней от 0 до 9
    for (i = 0; i < 10; i++) {
        k = power(base, i); // Вызов функции power для вычисления степени
        cout << "Степень = " << i << ", Итоговое число = " << k << endl;
    }

    return 0;
}

// Определение функции power для вычисления степени x в степени n
int power(int x, int n) {
    int p = 1;
    // Умножаем основание на себя n раз
    for (int i = 0; i < n; i++) {
        p *= x;
    }
    return p; // Возвращение результата
}