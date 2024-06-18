class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        vector<pair<int,int>>v;
        int n=d.size();
        v.push_back({0,0});
        for(int i=0;i<n;i++){
            v.push_back({d[i],p[i]});
        }

        sort(begin(v),end(v));

        for(int i=0;i<v.size()-1;i++){
            v[i+1].second=max(v[i].second,v[i+1].second);
        }



        

        int ans=0;
        int m=w.size();
        for(int i:w){
            int lo=0,hi=v.size()-1,temp=0;

            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(v[mid].first<=i){
                    temp=max(temp,v[mid].second);
                    lo=mid+1;
                }else{
                    hi=mid-1;
                }

            }
            ans+=temp;
        }

        return ans;
    }
};