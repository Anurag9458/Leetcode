class Solution {
public:
    bool isIsomorphic(string s, string t) {
       int n=s.size();
       map<char,char>mp1,mp2;


        for(int i=0;i<n;i++){
            if((mp1.count(t[i]) && s[i]!=mp1[t[i]]) || (mp2.count(s[i]) && t[i]!=mp2[s[i]]) ){
                return 0;
            }
            mp1[t[i]]=s[i];
            mp2[s[i]]=t[i];
        }

        return 1;

    }
};