class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }
        string ans;
        for(char c:order){
            if(mp.count(c)){
                while(mp[c]>0){
                    ans.push_back(c);
                    mp[c]--;
                }
                mp.erase(c);
            }
        }

        for(auto it:mp){
            while(it.second--){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};