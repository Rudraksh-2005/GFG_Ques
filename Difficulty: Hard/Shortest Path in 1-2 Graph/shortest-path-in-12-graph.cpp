class Solution {
  public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V);
        
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
            
        }
        
        vector<int>dis(V,INT_MAX);
        
        dis[src]=0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push({0,src});
        
        
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            
            int dist=it.first;
            int node=it.second;
            
            for(auto mp:adj[node]){
                if(mp.second + dist <dis[mp.first]){
                    dis[mp.first]=mp.second +dist;
                    pq.push({dis[mp.first],mp.first});
                }
            }
        }
        
        if(dis[dest]==INT_MAX)return -1;
        
        
        return dis[dest];
    }
};
