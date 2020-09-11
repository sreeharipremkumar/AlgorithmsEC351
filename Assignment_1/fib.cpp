#include <iostream>
using namespace std;

int main()
{
    unsigned long long int n1=0,n2=1,fibo=0;

    for(int i=1;i<=5;i++)
    {
		if(fibo<n1)
		{break;}
		if (i==1)
		{
			cout<<i<<" : 0"<<endl;
		}
		else if(i==2)
		{
			 cout<<i<<" : 1"<<endl;
		}
		else
		{
    	    fibo = n1+n2;
    	    cout<<i<<" : "<<fibo<<endl;
    	    n1=n2;
    	    n2=fibo;
		}
	}
}
