#include "graph.h"
using namespace std;

//O(V+E)
void Graph::dfs_nonrecursive(int u, vector<bool>& visited, vector<int>& res){
    stack<int> s;
    s.push(u);
    while(!s.empty()){
        int i = s.top();
        s.pop();
        if(visited[i]){
            continue;
        }
        visited[i]=true;
        res.push_back(i);
        //Return reverse iterator to reverse end
        for(auto rit=v_.at(i).rbegin();rit!=v_.at(i).rend();rit++){
            if(!visited[*rit]){
                s.push(*rit);
            }
        }
    }
}

//O(n(V+E))
vector<int> Graph ::DFS_ALL()
{
  int root = v_.begin()->first;
  vector<bool> visited(v_.size(), false);
  vector<int> res;
  vector<int> res1;
  dfs_nonrecursive(root,visited,res);
  for(auto it = v_.begin(); it != v_.end(); ++it){
    std::vector<int>::iterator it1 = find(res.begin(), res.end(), it->first);
    if(it1 == res.end()){
      dfs_nonrecursive(it->first,visited,res1);
      res.insert(res.end(), res1.begin(), res1.end());
    }
  }
  return res;
}
