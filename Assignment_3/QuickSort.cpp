#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int quick(double arr[],int l,int h)
{
    if(l<h)
    {
        int pivot = l;
        int p = l;
        int q = h;
        while(p<=q)
        {
            if(arr[p]>arr[pivot] && arr[q]<arr[pivot])
            {
                double t = arr[p];
                arr[p] = arr[q];
                arr[q] = t;
            }
            else
            {
                if(arr[p]<=arr[pivot])
                {
                    p++;
                }
                if(arr[q]>=arr[pivot])
                {
                    q--;
                }
            }
        }
        double t = arr[q];
        arr[q] = arr[pivot];
        arr[pivot] = t;

        quick(arr,l,q-1);
        quick(arr,q+1,h);
    }
    return 0;
}

int main()
{
    double A[] = {2.5,4.5,3.0,1.2,6.5,8.9,7.4,6.3};
    double B[] = {5,3,6,3,4,5,4,6,4};
    
    int lenA = end(A)-begin(A);
    int lenB = end(B)-begin(B);

    auto startA = high_resolution_clock::now();
    quick(A,0,lenA-1);
    auto stopA = high_resolution_clock::now();
    auto durationA = duration_cast<microseconds>(stopA - startA); 

    auto startB = high_resolution_clock::now();
    quick(B,0,lenB-1);
    auto stopB = high_resolution_clock::now();
    auto durationB = duration_cast<microseconds>(stopB - startB); 
  
    cout<<"\nSorted Array A: ";
    for(int i = 0;i<=lenA-1;i++)
    { 
        cout<<A[i]<<", ";
    }
    cout<<endl;
    cout<<"Time taken by function for Arr A: "<<durationA.count()<<" microseconds"<<endl; 

    cout<<"\n\nSorted Array B: ";
    for(int i = 0;i<=lenB-1;i++)
    { 
        cout<<B[i]<<", ";
    }
    cout<<endl;
    cout<<"Time taken by function for Arr A: "<<durationB.count()<<" microseconds"<<endl; 
}
