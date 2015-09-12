#include <iostream>
#include <cmath>
using namespace std;

//实现乘方
double mypow(double base,int ex)
{
    if(base == 0)
    {
        return 0;
    }
    if(0 == ex)
    {
        return 1;
    }
    if(ex == 1)
    {
        return base;
    }

    double result = mypow(base,ex>>1);
    result *= result;
    if(ex & 0x1 == 1)
    {
        result *= base;
    }
    return result;
}

template <typename  T>
bool isfavor(T n)
{
    if(n == 1)
    {
        cout<<"1!!!!"<<endl;
        return false;
    }
    for(T i = sqrt(n); i >= 2; --i)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

//素因子分解
template <typename  T>
void favor(T n)
{
    if(isfavor(n))
    {
        cout<<n<<endl;
    }
    else
    {
        T result = 0;
        for(T i = n/2; i >= 2; --i)
        {
            if(n%i == 0)
            {
                favor(i);
                favor(n/i);
                break;
            }
        }
    }
}
