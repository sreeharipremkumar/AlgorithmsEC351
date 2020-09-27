#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;


int mergesort(double arr[],int l,int h)
{
    if(l<h)
    {
        int mid = (l+h)/2;

        mergesort(arr,l,mid);
        mergesort(arr,mid+1,h);

        int nleft = mid - l + 1;
        int nright = h - mid;
        double L[nleft];
        double R[nright];

        for(int i=0;i<nleft;i++)
        {
            L[i] = arr[l+i];
        }
        for(int i=0;i<nright;i++)
        {
            R[i] = arr[mid+1 +i];
        }

        int left=0,right=0,main=l;

        while(left<nleft && right<nright)
        {
            if(L[left]<R[right])
            {
                arr[main++] = L[left++];
            }
            else
            {
                arr[main++] = R[right++];
            }
        }

        while(left<nleft)
        {
            arr[main++] = L[left++];
        }
        while(right<nright)
        {
            arr[main++] = R[right++];
        }
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
    mergesort(A,0,lenA-1);
    auto stopA = high_resolution_clock::now();
    auto durationA = duration_cast<microseconds>(stopA - startA); 

    auto startB = high_resolution_clock::now();
    mergesort(B,0,lenB-1);
    auto stopB = high_resolution_clock::now();
    auto durationB = duration_cast<microseconds>(stopB - startB); 
  
    cout<<"\nSorted Array A: ";
    for(int i = 0;i<=lenA-1;i++)
    { 
        cout<<A[i]<<", ";
    }
    cout<<endl;
    cout<<"Time taken by MergeSort for Arr A: "<<durationA.count()<<" microseconds"<<endl; 

    cout<<"\n\nSorted Array B: ";
    for(int i = 0;i<=lenB-1;i++)
    { 
        cout<<B[i]<<", ";
    }
    cout<<endl;
    cout<<"Time taken by MergeSort for Arr A: "<<durationB.count()<<" microseconds"<<endl; 
}
