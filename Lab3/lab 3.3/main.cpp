#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Функция для сортировки массива
void customSort(vector<int>& arr) {
    // Разделение массива на четные и нечетные значения
    vector<int> even;
    vector<int> odd;
    for (int num : arr) {
        if (num % 2 == 0)
            even.push_back(num);
        else
            odd.push_back(num);
    }

    // Сортировка четных значений по возрастанию
    sort(even.begin(), even.end());

    // Сортировка нечетных значений по убыванию
    sort(odd.begin(), odd.end(), greater<int>());

    // Обновление исходного массива
    int i = 0;
    for (int num : even) {
        arr[i++] = num;
    }
    for (int num : odd) {
        arr[i++] = num;
    }
}

int main() {
    setlocale(LC_ALL, "ru"); // Кодировка
    vector<int> arr = {2,5,-83,-41,6,3, 10, 23, 324,34, 34, 87,3,-90,4,9};

    cout << "Исходный массив:" << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Вызов пользовательской функции сортировки
    customSort(arr);

    cout << "Отсортированный массив:" << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}