class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> indegree;

        for (int i=0; i < numCourses; i++) {
          indegree[i] = 0;
        }

        // graph se cho minh biet co nhung node nao phu thuoc vo node i
        // nhung khong cho minh biet node i co phu thuoc vo node nao hay khong ????? -> can indegree map
        for(auto p : prerequisites){
          graph[p[1]].emplace_back(p[0]);
          indegree[p[0]]++;
        }
        

        /*
        su dung BFS, cai queue cua minh chi chua nhung node nao co indegree = 0
        */
        int count = 0;
        queue<int> q;
        for(int i =0; i < numCourses; i++){
          if (indegree[i] == 0) {
            q.push(i);
          }
        }
        
        while(!q.empty()){
          int curr = q.front();
          q.pop();
          count++;
          for(auto p : graph[curr]){
            indegree[p]--;
            if (indegree[p] == 0){
              q.push(p);             
            }
          }
        }
        return count == numCourses;
    }
};