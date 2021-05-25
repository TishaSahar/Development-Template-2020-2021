#include "TreeString.h"
#include <conio.h>

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");

	string str = "Ехал грека через реку, видит грека в реке рак, сунул грека руку в реку - рак за руку греку цап!";

	Text tr(str);
	cout << tr.getCount("грека") << endl;
	_getch();
	return 0;
}