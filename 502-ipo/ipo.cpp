class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        vector<pair<int,int>>v;
        int n=p.size();
        for(int i=0;i<n;i++){
            v.push_back({c[i],p[i]});
        }

        sort(begin(v),end(v));

        int ans=0;
        priority_queue<int>pq;
        int i=0;
        while(k--){
            while(i<n && v[i].first<=w){
                pq.push(v[i].second);
                i++;
            }
            if(pq.empty()){
                break;
            }
            w+=pq.top();
            pq.pop();
        }

        return w;

    }
};