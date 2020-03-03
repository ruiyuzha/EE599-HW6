#include "src/lib/solution.h"
#include "src/lib/graph.h"
#include "gtest/gtest.h"
#include <vector>

TEST(DFS, ReturnDFS) {
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
  vector<int> actual;
  vector<bool> visited(n, false);
  g.dfs_nonrecursive(0,visited,actual);
  vector<int> expected={0,1,2,3,4,6,5};
  EXPECT_EQ(expected, actual);
}

TEST(DFSALL, ReturnDFSALL) {
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
  vector<int> actual=g1.DFS_ALL();
  vector<int> expected={0,1,2,3,4,6,5};
  EXPECT_EQ(expected, actual);
}

TEST(Maze1, ReturnMaze1) {
  Solution solution;
  vector<vector <int>> maze={
    {1,1,0,0,0},
    {1,0,1,1,1},
    {1,1,0,0,1},
    {1,1,0,0,0},
    {1,1,1,1,1}
  };
  pair<int, int> start_pts(0,0);
  pair<int, int> end_pts(4,4);
  bool actual=solution.solveMaze(maze,start_pts,end_pts);
  EXPECT_EQ(1, actual);
}

TEST(Maze2, ReturnMaze2) {
  Solution solution;
  vector<vector <int>> maze={
    {1,1,0,0,0},
    {1,1,1,1,1},
    {0,1,0,0,1},
    {1,0,0,0,0},
    {1,1,1,1,1}
  };
  pair<int, int> start_pts(1,2);
  pair<int, int> end_pts(4,4);
  bool actual=solution.solveMaze(maze,start_pts,end_pts);
  EXPECT_EQ(0, actual);
}

TEST(Rearrange, ReturnRearrange){
  Solution solution;
  vector<int> v={9,7,5,11,12,2,14,3,10,6};
  int i =9;
  int low = 0;
  int high = v.size();
  solution.partition(v,i,low,high);
  vector <int> expected={5,2,3,6,12,7,14,9,10,11};
  EXPECT_EQ(expected, v);
}