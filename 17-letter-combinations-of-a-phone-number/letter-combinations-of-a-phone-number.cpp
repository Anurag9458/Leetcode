class Solution {

    void solve(int i,int n,string &dig,map<char,string>&mp,vector<string>&ans){
        if(i==n){
            return;
        }
        char c=dig[i];
        string temp=mp[c];
        cout<<temp<<" ";
        if(ans.size()==0){
            for(int j=0;j<temp.size();j++){
                string s;
                s.push_back(temp[j]);
                ans.push_back(s);
            }
        }
        else{
            vector<string>v;
            for(int j=0;j<ans.size();j++){
                string s=ans[j];
                for(int k=0;k<temp.size();k++){
                    v.push_back(s+temp[k]);
                }
            }
            ans=v;
        }
        solve(i+1,n,dig,mp,ans);
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        map<char,string>mp;
        mp['2']="abc";mp['3']="def";mp['4']="ghi";mp['5']="jkl";mp['6']="mno";
        mp['7']="pqrs";mp['8']="tuv";mp['9']="wxyz";
        int n=digits.size();
        if(n==0){
            return ans;
        }
        solve(0,n,digits,mp,ans);
        return ans;
    }
};