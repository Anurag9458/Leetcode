class Solution {
public:
    bool closeStrings(string s1, string s2) {
        
        map<char,int>mp1,mp2;
        for(char c:s1)mp1[c]++;
        for(char c:s2)mp2[c]++;

        vector<int>st1,st2;

        for(char c:s1)if(!mp2.count(c))return 0;
        for(char c:s2)if(!mp1.count(c))return 0;
        
        for(auto it:mp1)st1.push_back(it.second);
        for(auto it:mp2)st2.push_back(it.second);

        sort(begin(st1),end(st1));
        sort(begin(st2),end(st2));

        return st1==st2;

    }
};