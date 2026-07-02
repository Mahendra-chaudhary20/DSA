#include<iostream>
#include<vector>
#include<math.h>
#include<limits.h>
using namespace std;
int segments(int n,int&x,int &y, int &z)
{
    if(n==0) return 0;
    if(n<0) return INT_MIN;

    // due to x
    int ans1= 1+ segments(n-x,x,y,z);
     // due to y
    int ans2= 1+ segments(n-y,x,y,z);
     // due to z
    int ans3= 1+ segments(n-z,x,y,z);
    return max(ans1,max(ans2,ans3));
}
int main()
{
    int n=7;
    int x=5;
    int y=2;
    int z=2;
    int ans= segments(n,x,y,z);
    if(ans <0) ans=0;
    cout<< ans;
}