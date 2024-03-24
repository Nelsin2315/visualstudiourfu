#include <iostream.h>
#include <string.h>

using namespace std;

class Money
{
	long dollars;
	int cents;
public:
	Money(long d, int c)
	{
		dollars = d;
		cents = c;
}
int operator>(const Money&) const;
friend ostream& operator <<(ostream& , Money&);
};

int Money::operator>(const Money& amt) const
{
return (dollars > amt.dollars) || ((dollars == amt.dollars) && (cents> amt.cents));
}

ostream operator<<(ostream& os, Money &amt)
{
	os << “$” << amt.dollars << ‘.’ << amt.cents;
	return os;
}

int main(void)
{
	Money mas={	Money(19,10), 
Money(99,99), 
Money(99,95), 
Money(19,95)};
};
	Sort(mas, sizeof(mas)/sizeof(mas[0]));
	for(i = 0; i < sizeof(mas)/sizeof(mas[0]); i++)
		cout << "mas[" << i << "] =  << mas[i] << endl;
}
