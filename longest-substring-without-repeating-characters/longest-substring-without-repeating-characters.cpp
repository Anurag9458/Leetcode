class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, n =s.size();
        int i = 0, j = 0;
        map<char,int>mp;
        while(j < n){
            mp[s[j]]++;
            while(mp[s[j]] > 1){
                mp[s[i]]--;
                i++;
            }
            cout<<j<<" "<<i<<endl;
            ans = max(ans, j-i+1);
            j++;
        }
        return ans ;
    }
};