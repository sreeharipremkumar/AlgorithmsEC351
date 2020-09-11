#include <iostream>
using namespace std;

int fib(int f)
{
	if((f==0)||(f==1))
	{
		return f;
	}
	else
	{
		return fib(f-2)+fib(f-1);
	}
}

int main()
{

	for(int i=0;i<5;i++)
    {
		cout<<i+1<<" : "<<fib(i)<<endl;
	}
}
