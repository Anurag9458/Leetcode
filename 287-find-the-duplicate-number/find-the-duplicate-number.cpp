class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        map<int,int>mp;
        for(int i:nums){
            if(mp.count(i)){
                return i;}
                mp[i]++;
        }
        return 0;
    }
};