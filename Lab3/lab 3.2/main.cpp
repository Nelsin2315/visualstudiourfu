#include <iostream>
using namespace std;

// Функция для разделения массива на две части 
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; ++j) {
        // Если текущий элемент меньше или равен элементу
        if (arr[j] <= pivot) {
            ++i; // Увеличиваем индекс меньшего элемента
            swap(arr[i], arr[j]); // Меняем местами arr[i] и arr[j]
        }
    }
    swap(arr[i + 1], arr[high]); // Меняем местами arr[i + 1] и элемент
    return (i + 1); // Возвращаем индекс элемента
}

// Функция быстрой сортировки
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Рекурсивно сортируем элементы до и после элемента
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    setlocale(LC_ALL, "ru"); // Кодировка
    const int size = 16;
    int arr[size] = {2,5,-83,-41,6,3, 10, 23, 324,34, 34, 87,3,-90,4,9};

    cout << "Исходный массив:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, size - 1); // Вызов функции быстрой сортировки

    cout << "Отсортированный массив:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}