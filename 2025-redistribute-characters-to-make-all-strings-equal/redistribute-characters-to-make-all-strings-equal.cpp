class Solution {
public:
    bool makeEqual(vector<string>& words) {

        int n=words.size();
        if(n==1){
            return 1;
        }

        map<char,int>mp;
        for(string s:words){
            for(char c:s){
                mp[c]++;
            }
        }

        for(auto it:mp){
            if(it.second%n){
                return 0;
            }
        }

        return 1;
    }
};