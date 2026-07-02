#include<iostream>
#include<vector>
#include<math.h>
#include<limits.h>
using namespace std;
int partition( int* arr, int s, int e)
{   int pivotindex= s;
    int pivot= arr[s];  // make the pivot element

    // count number of element smaller than pivot
    int count=0;
    for(int i=s+1;i<=e;i++)
    {
        if(arr[i]<=pivot)
        {count++;}
    }

    pivotindex= s+count; // reassigning the pivot index
    // shift pivot to its correct postion
    swap(arr[s], arr[s+count]);
   
    int i=s;
    int j=e;
    while(i < pivotindex && j > pivotindex)
{
    while(i < pivotindex && arr[i] <= arr[pivotindex])
    {
        i++;
    }

    while(j > pivotindex && arr[j] > arr[pivotindex])
    {
        j--;
    }
 // agar koi element left side me bada hai or right side me koi element
    // chhota hai to unko swap kar do
    if(i < pivotindex && j > pivotindex)
    {
        swap(arr[i], arr[j]);
    }
}

   
    return pivotindex;

}
void quicksort( int* arr, int s, int e)
{
    // base case
    if(s>=e) return;

    // partition 
    int p= partition(arr,s,e);
    // recursion

  quicksort(arr,s,p-1);  // left of pivot element
  quicksort(arr,p+1,e);  // right of pivot element
}
int main()
{
    int arr[]={1,5,8,5,1,10,56,4,3,3};
    int n=10;
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
