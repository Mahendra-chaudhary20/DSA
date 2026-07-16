#include<iostream>
#include<vector>
#include<unordered_map>
#include<math.h>
#include<limits.h>
using namespace std;

unordered_map<int,bool> rowCheck;
unordered_map<int,bool> upperLeftDiagnolCheck;
unordered_map<int,bool> bottomLeftDiagnolCheck;

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
    if(rowCheck[row] == true )
     return false;

    if(upperLeftDiagnolCheck[n-1+col-row] == true)
    return false;

    if(bottomLeftDiagnolCheck[row+col] = true)
    return false;

return true;
//     int i=row;
//     int j=col;
//     // left side me check karna hai ki safe hai ki nhi
//     while(j>=0)
//     {
//      if (board[i][j]=='Q')
//      {
//        return false;
//      }
//      j--;
//      }
//      // upper diagonal element me check karna hai
//       i=row;
//      j=col;
//      while(i>=0 && j>=0)
//      {
//         if (board[i][j]=='Q')
//      {
//        return false;
//      }
//      i--;
//      j--;
//      }
//       // lower diagonal element me check karna hai
//      i=row;
//      j=col;
//      while(i<n && j>=0)
//      {
//         if (board[i][j]=='Q')
//      {
//        return false;
//      }
//      i++;
//      j--;
//      }

//      // if all case pass its mean no queen is found then return true
//      return true;
// 
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

        rowCheck[row] = true;
        upperLeftDiagnolCheck[n-1+col-row] = true;
        bottomLeftDiagnolCheck[row+col] = true;

        // recursion sambhal lega
        solve(board, col+1,n);
        // backtracking
        board[row][col]='-';
        rowCheck[row] = false;
        upperLeftDiagnolCheck[n-1+col-row] = false;
        bottomLeftDiagnolCheck[row+col] = false;
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
