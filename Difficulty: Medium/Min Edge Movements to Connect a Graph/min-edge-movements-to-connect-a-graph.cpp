class dsu{
   public:
    
        vector<int>parent,rank;
        
        dsu(int n){
            parent.resize(n);
            rank.resize(n,0);
        
        
            for(int i=0;i<n;i++)parent[i]=i;
        
        }
        
        int finduparent(int node){
            if(node==parent[node])return node;
            
            return parent[node]=finduparent(parent[node]);
        }
        
        void unionfind(int x,int y){
            int p=finduparent(x);
            int q=finduparent(y);
            
            if(p==q)return;
            
            if(rank[p]<rank[q]){
                parent[p]=q;
                rank[q]++;
            }
            
            else{
                parent[q]=p;
                rank[p]++;
            }
            
        }
};

        


class Solution {
  public:
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        // code here
        
        dsu dsu(n);
        int ans=0;
        
        int cnt=0;
        for(auto it:edges){
            if(dsu.finduparent(it[0])==dsu.finduparent(it[1])){
                
                cnt++;
            }
            else{
                dsu.unionfind(it[0],it[1]);
            }
        }
        
        int nc=0;
        for(int i=0;i<n;i++){
            if(dsu.parent[i]==i){
                nc++;
            }
        }
        
        ans=nc-1;
        if(cnt>=ans){
            
            return ans;
        }
        
        
        
        return -1;
    }
};