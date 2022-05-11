#include <iostream>
#include "Header.h"

using namespace std;
int main()
{
	Animal a;
	Cat c;
	Dog d;
	a.call();
	c.call();
	d.call();
	Animal* p = &c;
	p->call();
}