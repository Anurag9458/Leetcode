class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>mp;
        int ans=0;
        for(char c:s){
            mp[c]++;
        }
        for(char c:t){
            if(mp.count(c)){
                mp[c]--;
                if(mp[c]==0)
                mp.erase(c);
            }else{
                ans++;
            }
        }
        return ans;
    }
};