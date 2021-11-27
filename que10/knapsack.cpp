//Write a program to 0-1 Knapsack problem using the Branch and Bound method.
#include <iostream>
#include<time.h>
using namespace std;
int max(int a, int b) { 
    return (a > b) ? a : b; 
    
}
int knapSack(int W, int wt[], int val[], int n)
{
if (n == 0 || W == 0)
return 0;
if (wt[n - 1] > W)
return knapSack(W, wt, val, n - 1);
else
return max(val[n - 1]+ knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
}
int main()
{
    clock_t tStart = clock();
    
    int size;
    
    cout<<"Enter size: ";
    cin>>size;
    
int val[size] ;
int wt[size] ;
cout<<"Enter values: \n";
for(int i=0;i<size;i++)
{
    cin>>val[i];
}
cout<<"Enter weights: \n";
for(int i=0;i<size;i++)
{
    cin>>wt[i];
}
int W = 10;
int n = sizeof(val) / sizeof(val[0]);
cout<<"Maximum Value"<<" "<<endl;
cout << knapSack(W, wt, val, n);
printf("\n\nTime taken: %.9fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
return 0;
}