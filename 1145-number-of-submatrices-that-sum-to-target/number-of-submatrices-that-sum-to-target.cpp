class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int t) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>pre;

        for(int i=0;i<n;i++){
            int sum=0;
            vector<int>temp;
            for(int j=0;j<m;j++){
                sum+=mat[i][j];
                temp.push_back(sum);
            }
            pre.push_back(temp);
        }


        int ans=0;

        for(int k=0;k<m;k++){
        for(int i=k;i<m;i++){
            unordered_map<int,int>mp;
            mp[0]=1;
            int sum=0;
            for(int j=0;j<n;j++){
               sum+=pre[j][i]-(k>0?pre[j][k-1]:0);
               if(mp.count(sum-t)){
                   ans+=mp[sum-t];
               }
               mp[sum]++;
            }
        }
        }

        return ans;

    }
};