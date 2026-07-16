#include<iostream>
#include<vector>
#include<math.h>
#include<limits.h>
using namespace std;
void print(vector<vector<char>> &board, int n)
{ cout<<"print the value:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
bool issafe(int row, int col, vector<vector<char>> &board, int n)
{
    int i=row;
    int j=col;
    // left side me check karna hai ki safe hai ki nhi
    while(j>=0)
    {
     if (board[i][j]=='Q')
     {
       return false;
     }
     j--;
     }
     // upper diagonal element me check karna hai
      i=row;
     j=col;
     while(i>=0 && j>=0)
     {
        if (board[i][j]=='Q')
     {
       return false;
     }
     i--;
     j--;
     }
      // lower diagonal element me check karna hai
     i=row;
     j=col;
     while(i<n && j>=0)
     {
        if (board[i][j]=='Q')
     {
       return false;
     }
     i++;
     j--;
     }

     // if all case pass its mean no queen is found then return true
     return true;
}
void solve(vector<vector<char>> &board, int col,int n)
{
    // base case
    if(col>=n){
        // print the board
        print(board, n);
        return;
    }

    // recursion
   for(int row=0; row<n; row++)
   {
     if(issafe(row,col,board, n))
     {
        // put the queen
        board[row][col]= 'Q';
        // recursion sambhal lega
        solve(board, col+1,n);
        // backtracking
        board[row][col]='-';
     }
   }
}
int main()
{
    int n=4;
    vector<vector<char>> board(n,vector<char>(n,'-'));
    int col=0;
    solve(board, col, n);
    return 0;

}
