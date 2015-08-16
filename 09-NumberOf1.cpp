/********************************
 *@file:
 *@author: Pan HU
 *@data: 2015-8-16
 *@version: 0.1
 *@describe:
 ********************************/
#include <iostream>
using namespace std;

int NumberOf1(int n);

int main()
{
    for(int i = -2; i<10; ++i)
    {
        cout<<NumberOf1(i)<<endl;
    }
    
	return 0;
}

int NumberOf1(int n)
{
	int number(0);
	while (n)
	{
		++number;
		n &= n-1;
	}
	return number;
}