class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& arr1, vector<int>& arr2) {
        
        int n=arr1.size();
        vector<int>ans;
        
        map<int,int>mp;
        
        for(int i=0;i<n;i++){
            mp[arr1[i]]++;
            int count=0;
            for(int j=0;j<=i;j++){
                if(mp.count(arr2[j])){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};