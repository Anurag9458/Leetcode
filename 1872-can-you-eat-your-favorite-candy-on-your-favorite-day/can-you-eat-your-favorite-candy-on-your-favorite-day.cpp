class Solution {
public:
    vector<bool> canEat(vector<int>& cand, vector<vector<int>>& q) {
        int n=cand.size();
        vector<long long >pre;
        long long int sum=0;
        pre.push_back(0);
        for(int i:cand){
            sum+=i;
            pre.push_back(sum);
        }

        vector<bool>ans;

        for(auto it:q){
            long long int t=it[0],d=it[1],c=it[2];
            long int maxi=pre[t+1]-1;
            long int mini=pre[t]/c;

            if(d>=mini && d<=maxi){
                ans.push_back(1);
            }else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};