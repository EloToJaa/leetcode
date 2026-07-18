// Category: algorithms
// Level: Medium
// Percent: 51.75706%

// There are a total of numCourses courses you have to take, labeled from 0 to
// numCourses - 1. You are given an array prerequisites where prerequisites[i] =
// [ai, bi] indicates that you must take course bi first if you want to take
// course ai.
//
//
// 	For example, the pair [0, 1], indicates that to take course 0 you have
// to first take course 1.
//
//
// Return true if you can finish all courses. Otherwise, return false.
//
//  
// Example 1:
//
// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take.
// To take course 1 you should have finished course 0. So it is possible.
//
//
// Example 2:
//
// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take.
// To take course 1 you should have finished course 0, and to take course 0 you
// should also have finished course 1. So it is impossible.
//
//
//  
// Constraints:
//
//
// 	1 <= numCourses <= 2000
// 	0 <= prerequisites.length <= 5000
// 	prerequisites[i].length == 2
// 	0 <= ai, bi < numCourses
// 	All the pairs prerequisites[i] are unique.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 private:
  enum class VisitState {
    kUnvisited,
    kVisiting,
    kVisited,
  };

  vector<VisitState> visited;
  vector<int> topo;
  vector<vector<int>> graph;
  bool dfs(int v) {
    visited[v] = VisitState::kVisiting;
    for (const int& u : graph[v]) {
      if (visited[u] == VisitState::kVisited) continue;
      if (visited[u] == VisitState::kVisiting) return true;
      if (dfs(u)) return true;
    }
    visited[v] = VisitState::kVisited;
    return false;
  }

 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    graph = vector<vector<int>>(numCourses, vector<int>());
    visited = vector<VisitState>(numCourses, VisitState::kUnvisited);
    for (const auto& r : prerequisites) {
      graph[r[1]].push_back(r[0]);
    }
    for (int v = 0; v < numCourses; v++) {
      if (visited[v] == VisitState::kUnvisited && dfs(v)) return false;
    }
    return true;
  }
};
