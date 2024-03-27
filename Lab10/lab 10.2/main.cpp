#include<iostream>
using namespace std;

// Структура Link для представления элемента списка
template<typename T>
struct Link {
	T data;
	Link* next;
};
// Класс List для реализации списка
template<typename T>
class List {
	Link<int>* first; // Указатель на первый элемент списка
public:

	// Конструктор по умолчанию
	List() :first(NULL) {}

	// Деструктор для освобождения памяти, занятой элементами списка
	~List() {
		Link<T>* current = first;
		while (current != NULL) {
			Link<T>* temp = current;
			current = current->next;
			delete temp;
		}
	}

	// Метод для добавления элемента в начало списка
	void add(int d) {
		Link<T>* newlink = new Link<T>;
		newlink->data = d;
		newlink->next = first;
		first = newlink;
	}

	// Метод для вывода и удаления первого элемента списка
	void pop() { //вывод значения списка
		Link<T>* current = first;
		if (current != NULL) {
			cout << current->data << endl;
			first = current->next;
		}
	}
};
int main() {
	List<int> LS;
	int n = 3;
	for (int i = 0; i < n; i++) {
		LS.add(i);
	}

	LS.pop();
	LS.pop();
	LS.pop();
	LS.pop();
}