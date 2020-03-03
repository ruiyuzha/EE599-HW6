#include "solution.h"
using namespace std;

//Question 5
//O(1)
bool Solution::isSafe(vector<vector <int> > maze, int x, int y) 
{ 
    // if (x, y outside maze) return false 
    if (x >= 0 && x < maze.size() && y >= 0 && y < maze.size() && maze[x][y] == 1) 
        return true; 
  
    return false; 
} 

//O(n^2)
bool Solution::solveMaze(vector<vector <int> > maze, pair<int, int> start_pts, pair<int, int> end_pts){
    int size_vector=maze.size();
    bool res=0;
    vector<vector <int> > visited(size_vector, vector<int>(size_vector,0));

    if (solveMazeUtil(maze, start_pts.first, start_pts.second, end_pts, visited) == false) {  
        return false; 
    } 
    return true;
}

//O(n^2)
bool Solution::solveMazeUtil(vector<vector <int> > maze, int x, int y, pair<int, int> end_pts, vector<vector <int> > visited) 
{ 
    int size_vector=maze.size();
    // if (x, y is goal) return true 
    if (x == end_pts.first && y == end_pts.second) { 
        visited[x][y] = 1; 
        return true; 
    } 
  
    // Check if maze[x][y] is valid 
    if (isSafe(maze, x, y) == true) { 
        // mark x, y as part of solution path 
        visited[x][y] = 1; 
  
        /* Move forward in x direction */
        if (solveMazeUtil(maze, x + 1, y, end_pts, visited) == true) 
            return true; 
  
        /* If moving in x direction doesn't give solution then 
           Move down in y direction  */
        if (solveMazeUtil(maze, x, y + 1, end_pts, visited) == true) 
            return true; 
  
        /* If none of the above movements work then BACKTRACK:  
            unmark x, y as part of solution path */
        visited[x][y] = 0; 
        return false; 
    } 
  
    return false; 
} 

//Question 6
//O(logn)
void Solution::partition (vector<int>& v, int i, int low, int high)
{
  swap(v[i],v[high-1]);
  int pivot = v[high-1]; // pivot
  int k = (low - 1); // Index of smaller element
  for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (v[j] < pivot)
        {
            k++; // increment index of smaller element
            swap(v[k], v[j]);
        }
    }
    swap(v[k + 1], v[high-1]);
}

//O(n)
void Solution::print_vector(vector<int> v){
    if(v.size()>0){
        cout<<"{";
        for(int i=0;i<int(v.size());i++){
            cout<<v[i]<<",";  
        }
        cout<<"\b}";
    }
    else{
        cout<<"{}";
    }
    cout<<endl;
}