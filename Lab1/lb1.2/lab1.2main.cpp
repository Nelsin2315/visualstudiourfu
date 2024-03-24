#include <iostream> 
#define PR(x)  printf("x=%u, *x=%f, &x=%u \n",x,*x, &x) 
#include <stdio.h> 

using namespace std;

int main()
{
    // Кодировка
    setlocale(LC_ALL, "ru"); 
    // Объявление массива
    float mas[] = { 563.4, 543.5, 345.2 }; 
    // Объявление указателей 
    float* ptrl, * ptr2; 
    // Указатель на массив 
    ptrl = mas; 
    // Указатель адрес массива 
    ptr2 = &mas[2]; 
    // Вывод значения
    PR(ptrl); 
    // Переход к следующему элементу указателя 
    ptrl++; 
    PR(ptrl);
    PR(ptr2);
    ++ptr2;
    PR(ptr2);
    printf("ptr2-ptrl=%d\n", ptr2 - ptrl);

}