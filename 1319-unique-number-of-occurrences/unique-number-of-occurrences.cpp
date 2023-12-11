class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp1,mp2;
        for(int i:arr)mp1[i]++;
        for(auto it:mp1){
            if(mp2.count(it.second))return 0;
            mp2[it.second]++;
        }
        return 1;
    }
};