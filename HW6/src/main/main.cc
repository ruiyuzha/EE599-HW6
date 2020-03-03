#include "src/lib/solution.h"
#include "src/lib/graph.h"
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  Solution solution;
  //Question 3
  map<int, set<int>> vertices{
    {0, {1,2,5}},
    {1, {0,2,3}},
    {2, {0,1,3}},
    {3, {1,2,4,6}},
    {4, {3}},
    {5, {0}},
    {6, {3}}
  };
  Graph g(vertices);
  int n=vertices.size();
  vector<int> output;
  vector<bool> visited(n, false);
  g.dfs_nonrecursive(0,visited,output);
  cout<<"Question 3: Non-recursive version of DFS"<<endl;
  cout<<"Output: ";
  solution.print_vector(output);
  cout<<endl;

  //Question 4
  map<int, set<int>> vertices1{
    {0, {1}},
    {1, {2,3}},
    {2, {0}},
    {3, {2,4,6}},
    {4, {}},
    {5, {6}},
    {6, {}}
  };
  Graph g1(vertices1);
  cout<<"Question 4: "<<endl;
  vector<int> res1=g1.DFS_ALL();
  solution.print_vector(res1);
  cout<<endl;

  //Question 5
  vector<vector <int>> maze={
    {1,1,0,0,0},
    {1,0,1,1,1},
    {1,1,0,0,1},
    {1,1,0,0,0},
    {1,1,1,1,1}
  };
  pair<int, int> start_pts(0,0);
  pair<int, int> end_pts(4,4);
  cout<<"Question 5: "<<endl;
  cout<<"Input: 2*2 maze, start=("<<start_pts.first<<","<<start_pts.second<<"), end=("<<end_pts.first<<","<<end_pts.second<<")"<<endl;
  cout<<"Output: ";
  if(solution.solveMaze(maze,start_pts,end_pts)){
    cout<<"true"<<endl;
  }
  else{
    cout<<"false"<<endl;
  }
  cout<<endl;
  
  //Question 6
  vector<int> v={9,7,5,11,12,2,14,3,10,6};
  int i =9;
  int low = 0;
  int high = v.size();

  cout<<"Question 6: Rearrange the vector: "<<endl;
  cout<<"Input: ";
  solution.print_vector(v);
  solution.partition(v,i,low,high);
  cout<<"Output: ";
  solution.print_vector(v);


  return EXIT_SUCCESS;
}