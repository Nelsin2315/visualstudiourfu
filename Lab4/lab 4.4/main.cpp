#include <iostream> 
#include <cstdlib>
#include <sec_api/string_s.h>
using namespace std;

int main()
{ 
	int dlina1(char*);
	int dlina2(char*);
	int dlina3(char*);
	void kopir(char*, char*);
	int compr(char*, char*);
	void concat(char*, char*);
    char* str, * str1;
	// Используем calloc() вместо malloc()
	str = (char*)calloc(100, sizeof(char));
	str1 = (char*)calloc(100, sizeof(char));
	strncpy_s(str, 7, "qwerty", 7);
	strncpy_s(str1, 11, "1234567890", 11);
	

	cout << "Функция определяющая длину строки с помощью цикла for: " << dlina1(str) << endl;
	cout << "Функция определяющая длину строки с помощью цикла while: " << dlina2(str) << endl;
	cout << "Функция определяющая длину строки с помощью перевода массива в строку и применения к ней стандартой функции length(): " << dlina3(str) << endl;
	kopir(str1, str);
	cout << "Функция копирующая одну строку в другую: " << str1 << endl;
	cout << "Функция,сравнивающая строки: " << compr(str, str1) << endl;
	concat(str1, str);
	cout << "Функция,склеивающая строки (конкатенация): " << str1 << endl;
    free(str);
	free(str1);
}

// Функция определяющая длину строки с помощью цикла for 
int dlina1(char* arr)
{
	int count = 0;
	for (int i = 0; arr[i] != '\0'; i++)
	{
		count++;
	}
	return count;
}

// Функция определяющая длину строки с помощью цикла while 
int dlina2(char* arr)
{
	char* chr = (char*)malloc(100);
	int count = 0;
	while (*chr != '\0') {
		count++;
		chr++;
	}
	return count;
}

//Функция определяющая длину строки с помощью перевода массива в строку и применения к ней стандартой функции length() 
int dlina3(char* arr)
{
	string str(arr);
	return str.length();
}

// Функция копирующая одну строку в другую 
void kopir(char* arr1, char* arr)
{
	for (int i = 0; arr[i] != '\0'; i++)
	{
		arr1[i] = arr[i];
	}
}

// Функция сравнивающая строки 
int compr(char* arr, char* arr1)
{
	int i = 0, result = 0;
	while (((arr[i] != '\0') && (arr1[i] != '\0')))
	{
		if (int(arr[i]) > int(arr1[i]))
		{
			result = 1;
			break;
		}
		if (int(arr[i]) < int(arr1[i]))
		{
			result = -1;
			break;
		}
		i++;
	}
	return result;
}

// Функция склеивающая строки (конкатенация) 
void concat(char* a, char* b)
{
	int len = dlina2(a);
	len += 0;
	int i = 0;
	for (; b[i] != '\0'; i++)
	{
		a[len + i] = b[i];
	}
	a[len + i] = '\0';
}