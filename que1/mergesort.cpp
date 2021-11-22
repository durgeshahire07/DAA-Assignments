/*1b - Write a program to analyse Quick Sort algorithm and Merge Sort algorithms using Divide
and Conquer approach.*/

#include<iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
void display(int *arr,int size) 
{
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void merge(int *arr,int l,int m,int r) 
{
    int i,j,k,nl,nr;   
    
    //size of 2 sub arrays
    nl=m-l+1; 
    nr=r-m;
    int larr[nl],rarr[nr];
    
    //filling the 2 sub-arrays
    for(i=0;i<nl;i++)
        larr[i]=arr[l+i];
    for(j=0;j<nr;j++)
        rarr[j]=arr[m+1+j];
    i=0;j=0;k=l;
    
    //merging 
    while(i<nl && j<nr) 
    {
        if(larr[i]<=rarr[j]) 
        {
            arr[k]=larr[i];
            i++;
        }
        
        else
        {
            arr[k] = rarr[j];
            j++;
        }
        k++;
    }
    
    while(i<nl) //extra element in left array
    {        
        arr[k]=larr[i];
        i++; k++;
    }
    
    while(j<nr) //extra element in right array
    {
        arr[k]=rarr[j];
        j++; 
        k++;
    }
}

void mergeSort(int *arr,int l,int r) 
{
    int m;
    if(l<r) 
    {
        int m=l+(r-l)/2;
       
        // Sort 1st & 2nd array
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main() 
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];     //create an array with given number of elements
    cout<<"Enter elements: "<<endl;
    
    for(int i=0;i<n;i++) 
    {
        cin>>arr[i];
    }
    
    auto start = high_resolution_clock::now();
    cout<<"\nBefore Sorting: \n";
    display(arr,n);
    
    mergeSort(arr,0,n-1);   
    
    cout<<"\nAfter Sorting: \n";
    display(arr, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
  
    cout << "\nTime taken by function: "
         << duration.count() << " microseconds" << endl;
}