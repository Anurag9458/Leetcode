class Solution {
public:
    int hIndex(vector<int>& arr) {
      
        sort(begin(arr),end(arr));
        int n=arr.size(),ans=0;
        for(int i=0;i<n;i++){
            if(arr[i]>=n-i){
                ans=max(ans,n-i);
            }
        }
        return ans;
    }
};