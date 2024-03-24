#include <iostream.h>
#include <string.h>

template <class T>
using namespace std;

T getmax(T t1, T t2)		//Возврашает больший из двух 
{					// параметров
	return t1 > t2?t1:t2;
}
char* getmax(char s1, char s2){
	return strcmp(s1, s2) >0? S1: s2;
}
template <class T>
T getmax(T t[], size_t size)
{
	T retval = t[0];
	int i;
	for(i = 0; i < size; i++)
		if(t[i] > retval) retval = t[i];
	return retval;
}

void main(void)
{
	int i1 = 3, i2 = 5;
char * s1 = "строка1";
char * s2 = "строка2";
cout << "max int = " << getmax(i1, i2) << endl;
cout << "max str = " << getmax(s1, s2) << endl;
}
