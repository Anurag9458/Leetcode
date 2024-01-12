class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        string temp;
        map<string,int>mp;
        temp=s.substr(0,10);
        int n=s.size();
        mp[temp]++;
        for(int i=10;i<n;i++){
            temp.push_back(s[i]);
            temp=temp.substr(1);
            mp[temp]++;
        }

        vector<string>ans;
        for(auto it:mp)if(it.second>1)ans.push_back(it.first);
        return ans;
    }
};