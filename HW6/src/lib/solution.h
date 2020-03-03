#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
  //Question 5
  bool isSafe(vector<vector <int> > maze, int x, int y);
  bool solveMaze(vector<vector <int> > maze, pair<int, int> start_pts, pair<int, int> end_pts);
  bool solveMazeUtil(vector<vector <int> > maze, int x, int y, pair<int, int> end_pts, vector<vector <int> > visited);
  //Question 6
  void partition (vector<int>& v, int i, int low, int high);
  void print_vector(vector<int> v);
};

#endif