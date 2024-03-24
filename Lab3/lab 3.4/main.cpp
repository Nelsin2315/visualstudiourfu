#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Функция для сортировки массива по возрастанию на интервале от N1 до N2
void customSort(vector<int>& arr, int N1, int N2) {
    if (N1 < 0 || N2 >= arr.size() || N1 >= N2) {
        cout << "Неправильно задан интервал" << endl;
        return;
    }

    // Выделение подмассива, который нужно отсортировать
    vector<int>::iterator start = arr.begin() + N1;
    vector<int>::iterator end = arr.begin() + N2 + 1;

    // Сортировка подмассива по возрастанию
    sort(start, end);
}

int main() {
    setlocale(LC_ALL, "ru"); // Кодировка
    vector<int> arr = {2,5,-83,-41,6,3, 10, 23, 324,34, 34, 87,3,-90,4,9};
    int N1 = 2; // Начальный индекс интервала
    int N2 = 5; // Конечный индекс интервала

    cout << "Исходный массив:" << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Вызов пользовательской функции сортировки с указанием интервала
    customSort(arr, N1, N2);

    cout << "Отсортированный массив на интервале от " << N1 << " до " << N2 << ":" << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}