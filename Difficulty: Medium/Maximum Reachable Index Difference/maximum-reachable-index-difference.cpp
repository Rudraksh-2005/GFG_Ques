class Solution {
  public:
    int maxIndexDifference(string &s) {
        // code here
           int n=s.size();
        unordered_map<char,deque<int>>mpp;
        for(int i=0;i<n;i++)
        {
            mpp[s[i]].push_back(i);
        }
        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>>pq;//{dis,char
        if(mpp.find('a')==mpp.end())
        {
            return -1;
        }
        int ind=mpp['a'][0];
        pq.push({ind,'a'});
        int max_diff=0;
        while(!pq.empty())
        {
            int ch=pq.top().second;
            int idx=pq.top().first;
            pq.pop();
            max_diff=max(max_diff,idx-ind);
            if(mpp.find(char(ch+1))!=mpp.end())
            {
                deque<int> dq=mpp[char(ch+1)];
                while(!dq.empty())
                {
                    if(dq.front()>idx)
                    {
                        pq.push({dq.front(),char(ch+1)});
                    }
                    dq.pop_front();
                    if(dq.size()==0)
                    {
                        mpp.erase(char(ch+1));
                    }
                }
            }
        }
        return max_diff;
    }
};
