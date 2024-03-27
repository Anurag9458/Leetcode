class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int ans=0;
        int i=0,j=0;
        map<char,int>mp;

        while(i<n){
            mp[s[i]]++;
            while(mp[s[i]]==3){
                mp[s[j]]--;
                j++;
            }
            ans=max(ans,i-j+1);
            i++;
        }

        return ans;
    }
};