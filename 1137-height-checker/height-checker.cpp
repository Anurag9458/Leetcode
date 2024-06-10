class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>v=heights;
        int n=v.size();
        int ans=0;
        sort(begin(v),end(v));
        for(int i=0;i<n;i++){
            if(heights[i]!=v[i]){
                ans++;
            }
        }

        return ans;
    }
};