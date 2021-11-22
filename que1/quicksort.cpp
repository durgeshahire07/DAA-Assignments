/*1a - Write a program to analyse Quick Sort algorithm and Merge Sort algorithms using Divide
and Conquer approach.*/

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void Swap(int* a, int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int Partition(int array[], int low, int high)
{
    int pivot=array[high];
    int i=(low-1);
    for(int j=low; j<=high-1; j++)
    {
        if (array[j]<pivot)
        { 
            i++;
            Swap(&array[i], &array[j]);
        }
    }
    Swap(&array[i+1], &array[high]);
    return (i+1);
}

void QuickSort(int array[], int low, int high)
{
    if (low<high)
    {
        int pi=Partition(array,low,high);
        Partition(array,low,pi-1);
        QuickSort(array,pi+1,high);
    }
}

int main()
{
    int i,size;
    cout<<"Enter the size of an array: ";
    cin>>size;
   int array[size];
    for(int i=0;i<size;i++){
        cin>>array[i];
    }
    
    auto start = high_resolution_clock::now();
    cout<<"Array :\n";
    for(int i=0;i<6;i++)
        cout<<array[i]<<"  ";
    int n = sizeof(array) / sizeof(array[0]);
   
    QuickSort(array, 0, n - 1);
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start);
    
    cout << "\n\nSorted array: \n";
    for (i=0;i<n;i++)
        cout<<array[i]<< " ";
    cout<<endl; 
     cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
 return 0;
}