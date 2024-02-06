class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<int>>mp;
        
        int i=0;
        for(string s:strs){
            sort(begin(s),end(s));
            mp[s].push_back(i);
            i++;
        }

        vector<vector<string>>ans;

        for(auto it:mp){
            vector<string>v;
            for(int i:it.second){
                v.push_back(strs[i]);
            }
            ans.push_back(v);
        }

        return ans;

    }
};