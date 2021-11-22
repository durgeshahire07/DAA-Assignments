/*3 - Find Maximum and Minimum elements from an array of integers using Divide and
Conquer Approach.*/

#include <iostream>
#include <climits>
#include <chrono>

using namespace std;
using namespace std::chrono;
void MinMax(int arr[], int low, int high, int &min, int &max)
{
    if (low==high)
    {
        if (max<arr[low])
        {
            max=arr[low];
        }
        if (min>arr[high])
        {
            min=arr[high];
        }
        return;
    }
    if (high-low==1)
    {
        if (arr[low]<arr[high])
        {
            if (min>arr[low])
            {
                min=arr[low];
            }
            if (max<arr[high])
            {
                max=arr[high];
            }
        }
        else
        {
            if (min>arr[high])
            {
                min=arr[high];
            }
            if (max<arr[low])
            {
                max=arr[low];
            }
        }
        return;
    }
    
    int mid=(low+high)/2;
    MinMax(arr,low,mid,min,max);
    MinMax(arr,mid+1,high,min,max);
}

int main()
{
    // int arr[]={67,5,84,8,33,12,40};
    cout<<"Enter the size of an array: ";
    int size;
    cin>>size;
    int arr[size];
    for(int i = 0;i<size;i++){
        cin>>arr[i];
    }
    auto start = high_resolution_clock::now();
    int n=sizeof(arr)/sizeof(arr[0]);
    int max=INT_MIN, min=INT_MAX;
    
    
    MinMax(arr,0,n-1,min,max);
    
    
    cout<<"The minimum array element is "<<min<<endl;
    cout<<"The maximum array element is "<<max;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
  
    cout << "\nTime taken by function: "
         << duration.count() << " microseconds" << endl;
    return 0;
}