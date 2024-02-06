class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<int>>mp;
        vector<pair<string,int>>temp;
        int i=0;
        for(string s:strs){
            sort(begin(s),end(s));
            temp.push_back({s,i});
            i++;
        }
        sort(begin(temp),end(temp));
        for(auto it:temp){
            mp[it.first].push_back(it.second);
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