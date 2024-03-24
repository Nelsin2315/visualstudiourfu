#include <iostream>
using namespace std;

// Функция обмена значений двух переменных, переданных по ссылке
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    setlocale(LC_ALL, "ru"); 
    int x = 6, y = 2;
    cout << "x до обмена: " << x << endl;
    cout << "y до обмена: " << y << endl;
    // Вызываем функцию обмена значений, передавая ссылки на переменные
    swap(x, y);
    // Выводим измененные значения переменных
    cout << "x после обмена: " << x << endl;
    cout << "y после обмена: " << y << endl;
    return 0;
}