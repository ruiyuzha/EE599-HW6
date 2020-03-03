#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
using namespace std;

class Graph{
  public:
    Graph(map<int, set<int> > &vertices):v_(vertices) {}
    map<int, set<int> > v_;
    void dfs_nonrecursive(int u, vector<bool>& visited, vector<int>& res);
    vector<int> DFS_ALL();
};