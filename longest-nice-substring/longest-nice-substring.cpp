class Solution {
public:
    string longestNiceSubstring(string s) {
        if(s.size()<2)return "";
        int n = s.size();
        unordered_set<char> st;
        for(char c : s)st.insert(c);

        for(int i = 0; i < n; i++){
            if(st.count(toupper(s[i])) && st.count(tolower(s[i])))
            continue;

            string prev = longestNiceSubstring(s.substr(0,i));
            cout<<prev<<" ";
            string next = longestNiceSubstring(s.substr(i+1,n));
            cout<<next<<" ";
            return prev.size() >= next.size() ? prev : next;
        }
        return s;
    }
};