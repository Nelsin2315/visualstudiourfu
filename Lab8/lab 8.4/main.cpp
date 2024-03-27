#include <iostream>
#include <iostream>
#include<ctype.h>
#include<fstream>
#include<stdlib.h>
using namespace std;
int main()
{
 char fname[15], c;
 cout << "Напишите имя файла для создания: "; cin >> fname;
 // Открыли входной файл
 ifstream inf;
 inf.open(fname, ios::in);
 if (!inf.is_open()) //Проверяем поток
 {
 cout << "Не открывается входной файл " << fname;
 return 0;
 }
 else
 {
 cout << "Имя выходного файла для печати: ";
 cin >> fname;
 //Открытие выходного файла
 ofstream ofs;
 ofs.open(fname, ios::out | ios::trunc);
 if (!ofs.is_open()) //Проверяем поток
 {
 cout << "Не открывается выходной файл: " << fname;
 }
 //Пока не конец файла
 while (!inf.eof())
 {
 inf.get(c);
 // Чтение символа из файла //Переводим прочитанный символ в верхний регистр
 c = toupper(c);
 ofs.put(c); //Запись символа в файл
 }
 }
}