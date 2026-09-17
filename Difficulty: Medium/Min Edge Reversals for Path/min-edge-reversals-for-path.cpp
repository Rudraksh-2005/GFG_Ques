class Solution {
  public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
        // code here  
        vector<vector<pair<int,int>>> adj(n+1);  // node, cost
               for(auto ele : edges){
                   int u = ele[0], v = ele[1];
                   adj[u].push_back({v,0});
                   adj[v].push_back({u,1});
               }
               vector<int> dist(n+1,1e8);
               queue<pair<int,int>> q;
               q.push({src,0});
               dist[src] = 0;
               while(!q.empty()){
                   auto it = q.front(); q.pop();
                   int node = it.first, cost = it.second;
                   for(auto ele : adj[node]){
                       int adjNode = ele.first, adjCost = ele.second;
                       if(adjCost + cost < dist[adjNode]){
                           dist[adjNode] = adjCost + cost;
                           q.push({adjNode,adjCost+cost});
                       }
                   }
               }
               if(dist[dst]==1e8) return -1;
               return dist[dst];
           
    }
};