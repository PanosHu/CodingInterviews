/********************************
 *@file:
 *@author: Pan HU
 *@data: 2015-8-16
 *@version: 0.1
 *@describe:
 ********************************/
#include <iostream>
using namespace std;

int Fibonacci(int n);

int main()
{
    for(int i = -2; i<10; ++i)
    {
        cout<<Fibonacci(i)<<endl;
    }
    
	return 0;
}
int Fibonacci(int n)
{
        if(n < 1){
            return 0;
        }
        else if(n < 3){
            return 1;
        }
         
        int r1 = 1;
        int r2 = 1;
        int r  = 0;
        for(int i=3; i<=n; ++i){
            r = r1 + r2;
            r1= r2;
            r2= r;
        }
        return r;
    }
}
