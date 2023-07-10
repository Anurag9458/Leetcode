class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> st;
        map<string,int> mp;
        
        int n = s.size(),i = 0, j = 0;
        string temp;
        while(j < 10){
            temp.push_back(s[j]);;
            j++;
        }
        mp[temp]++;
        while(j < n){
            temp = temp.substr(1);
            temp.push_back(s[j]);
            if(mp.count(temp)){
                st.insert(temp);
            }else{
                mp[temp]++;
            }
            j++;
        }
        vector<string> ans(begin(st),end(st));
        return ans;
    }

};