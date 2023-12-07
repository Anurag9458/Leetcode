class Solution {
public:
    string mergeAlternately(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        int mini=min(n,m);
        string ans;
        for(int i=0;i<mini;i++){
            ans.push_back(s1[i]);
            ans.push_back(s2[i]);
        }

        if(n==mini){
            while(mini<m)
            ans.push_back(s2[mini++]);
        }
        if(m==mini){
            while(mini<n)
            ans.push_back(s1[mini++]);
        }

        return ans;
    }
};