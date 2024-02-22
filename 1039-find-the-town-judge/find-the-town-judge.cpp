class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int n1=trust.size();
        if(n==1){
            return 1;
        }
        map<int,vector<int>>mp;
        map<int,int>mp1; 
        for(int i=0;i<n1;i++){
            mp1[trust[i][0]]++;
            mp[trust[i][1]].push_back(trust[i][0]);
        }
        for(auto it:mp){
            if(it.second.size()==n-1 && !mp1.count(it.first))return it.first;
        }
        return -1;
    }
};