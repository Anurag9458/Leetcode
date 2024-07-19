class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& arr) {
        vector<int>ans;
        int n=arr.size(),m=arr[0].size();
        vector<int>col(m,0);
        vector<int>row(n,1e9);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                col[i]=max(col[i],arr[j][i]);
                row[j]=min(row[j],arr[j][i]);
            }
        }
        unordered_map<int,int>mp;

        for(int i:row){
            mp[i]++;
        }

        for(int i:col){
            if(mp.count(i)){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};