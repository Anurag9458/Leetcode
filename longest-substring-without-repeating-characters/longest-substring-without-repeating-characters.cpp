class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,n=size(s);
        if(n==0)return 0;
        int ans=0;
        map<char,int>mp;
        while(r<n)
        {
            if(mp.count(s[r]) && l<=r)
            {
                while(mp.count(s[r])){
                if(mp[s[l]]==1)mp.erase(s[l]);
                else mp[s[l]]--;
                l++;
                }
            }
            mp[s[r]]++;
            r++;
            ans=max(ans,r-l+1);
        }
        return ans-1;
    }
};