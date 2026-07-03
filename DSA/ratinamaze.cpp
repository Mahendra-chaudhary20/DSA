#include<iostream>
#include<vector>
#include<math.h>
#include<limits.h>
using namespace std;
bool safe(int x, int y,int &row,int &col, vector<vector<bool>>& visited,int maze[][3])
{
    // 3 condition on which rat cannot move
    // 1: (x>=0&& x<row) && (y>=0 && y<=col) 
    // 2: visited of that coordibnates should be false i.e. visited[x][y]= false
    // 3: maze[x][y]==1
    if(((x>=0&& x<row)&&(y>=0 && y<col)) && (visited[x][y]== false) && (maze[x][y]==1))
    {
        return true;
    }
    else
    {return false;}

}
void find(int maze[][3], int &row,int &col, int x,int y,  vector<vector<bool>>& visited, vector<string>& path,string output )
{
  //base
  if(x==row-1 && y== col-1)
  {
    // reached to destination
    path.push_back(output);
    return;
  }
  // procedure
  //down moment 
if(safe(x+1,y,row,col,visited,maze))
{
    visited[x+1][y]=true;
     find(maze,row,col,x+1,y,visited,path,output +'D');
     visited[x+1][y]=false;  // backtracking
}
  //right moment
if(safe(x,y+1,row,col,visited,maze))
{
    visited[x][y+1]=true;
     find(maze,row,col,x,y+1,visited,path,output +'R');
     visited[x][y+1]=false;  // backtracking
}
  // left moment
if(safe(x,y-1,row,col,visited,maze))
{
    visited[x][y-1]=true;
     find(maze,row,col,x,y-1,visited,path,output +'L');
     visited[x][y-1]=false;  // backtracking
}
  // up moment
  if(safe(x-1,y,row,col,visited,maze))
{
    visited[x-1][y]=true;
     find(maze,row,col,x-1,y,visited,path,output +'U');
     visited[x-1][y]=false;  // backtracking
}
}

int main()
{
    int maze[][3]= {{1,0,0},{1,1,0},{1,1,0}};
    // what if intitially no ways possible i.e maze[0][0]==0
    if(maze[0][0]==0)
    {
        cout<<" no solutions";
        return 0;
    }
    int row=3;
    int col=3;
    vector<vector<bool>> visited(row,vector<bool>(col,false)); // created an matrix that contain about which one visited
    visited[0][0]= true; // 1st marked as visted
    vector<string> path; // to store all poosible ways
    string output=""; // to store output that generated
    find(maze,row,col,0,0,visited,path,output);
    if(path.size()==0) // if no possble solution exist and if maze[row-1][col-1]==0
    {
        cout<<" again no solution";
        return 0;
    }
    cout<<"number of ways:"<<endl;
    for(auto i: path)
   {cout<<i<<" ";}
}