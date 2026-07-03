#include<iostream>
#include<vector>
#include<math.h>
#include<limits.h>
using namespace std;
void merge(int* arr, int s, int mid, int e)
{ int start= mid+1;
    if( arr[start]>= arr[mid]) //   this represent that array is all ready sorted
    {return;}
    // if not sorted then
     while (s <= mid && start<= e) 
     {   // Correct order
        if (arr[s] <= arr[start]) {
            s++;
        }
    else
    {
        int value= arr[start];
        int index= start;
        while(index!=s)
        {
            swap(arr[index], arr[index-1]);
            index--;
        }
        arr[s]=value;
        s++;
        start++;
        mid++;
    }
    
}  
    
    
    //   int mid= (s+e)/2;
//     int l= mid-s+1;
//     int r= e-mid;
//  // declaration of two array left and right part:
//     int * left= new int[l];
//     int * right= new int[r];
//     // copy the values in the new arrays
//     // left
//     int k=s;
//     for(int i=0;i<l;i++)
//     {
//         left[i]=arr[k];
//         k++;
//     }
//     // left
//     k=mid+1;
//     for(int i=0;i<r;i++)
//     {
//         right[i]=arr[k];
//         k++;
//     }
//     // merging start
//     int leftindex=0;
//     int rightindex=0;
//     int mainindex=s; // main array index
//     while(leftindex<l && rightindex <r)
//     {
//         if(left[leftindex]<right[rightindex])
//         {
//             arr[mainindex++]=left[leftindex++];
//         }
//         else
//         {
//              arr[mainindex++]= right[rightindex++];
//         }
//     }
//     // copy left array
//     while( leftindex<l)
//     {
//          arr[mainindex++]=left[leftindex++];
//     }
//     // copy right array
//     while(rightindex <r)
//     {
//           arr[mainindex++]= right[rightindex++];
//     }

}
void mergesort(int* arr, int s, int e)
{
   // base
   if(s>=e) return;
   // recursion
   int mid= (s+e)/2;
   mergesort( arr, s, mid);
    mergesort( arr, mid+1, e); 
    merge(arr, s,mid, e);
}
int main()
{
    int arr[]={2,2,5,4,3,1,8,5,9,10};
    int n=10;
    mergesort( arr, 0, n-1 );
    cout<< " sorted array:";
    for(int i=0; i<n;i++)
    {
        cout<< arr[i]<<" ";
    }
    return 0;
}