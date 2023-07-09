class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        if(n < 3)return 0;
        int i = 0, j = 0;
        map<char,int> mp;
        while(j < 3){
            mp[s[j]]++;
            j++;
        }
        int ans = 0;
        if(mp.size() == 3)ans++;
        while(j < n){
            mp[s[i]]--;
           
            if(mp[s[i]] == 0){
                mp.erase(s[i]);
            }
            i++;
            mp[s[j]]++;
            if(mp.size() == 3)ans++;
            j++;
        }
        return ans;
    }
};