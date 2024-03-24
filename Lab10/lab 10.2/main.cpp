#include<iostream>
using namespace std;
template<typename T>
struct Link {
	T data;
	Link* next;
};
template<typename T>
class List {
	Link<int>* first;
public:
	List() :first(NULL) {}
	~List() {
		Link<T>* current = first;
		while (current != NULL) {
			Link<T>* temp = current;
			current = current->next;
			delete temp;
		}
	}
	void add(int d) {
		Link<T>* newlink = new Link<T>;
		newlink->data = d;
		newlink->next = first;
		first = newlink;
	}
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