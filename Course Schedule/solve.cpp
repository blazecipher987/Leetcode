#include <bits/stdc++.h>
using namespace std;
#include<vector>


class Solution {
public:
    vector<bool> visited;
    vector<bool> foundInPath;
    vector<int> ans;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> graph[numCourses];
        visited.resize(numCourses, false);
        foundInPath.resize(numCourses, false);

        for(int i=0; i< prerequisites.size(); i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i]) {
                if (dfsTraversal(i, graph)) {
                    return false;  // Cycle detected
                }
            }
        }


    }

    bool dfsTraversal(int v, vector<int> graph[]){

        visited[v]= true;
        foundInPath[v]= true;

        for(auto u: graph[v]){

            if(visited[u]==false){

                if(dfsTraversal(u, graph)==true){
                    return true;
                }
            }

            else if(foundInPath[u]==true){
                return true;
            }
        }

        foundInPath[v]=false;
        ans.push_back(v);
        return false;

    }
};