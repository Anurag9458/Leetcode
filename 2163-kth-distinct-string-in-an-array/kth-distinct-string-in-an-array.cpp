class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int>mp;
        for(string it:arr){
            mp[it]++;
        }
        int ans=0;
        int count=0;
        for(string it:arr){
            if(mp[it]==1){
                count++;
                if(count==k){
                    return it;
                }
            }
        }

        return "";
    }
};