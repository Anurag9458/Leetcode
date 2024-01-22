class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n1=arr1.size(),n2=arr2.size(),ans=0;
        for(int i=0;i<n1;i++){
            int flag=0;
            for(int j=0;j<n2;j++){
                if(abs(arr1[i]-arr2[j])<=d)flag=1;
            }
            if(!flag)ans++;
        }
        return ans;
    }
};