class Solution {
    vector<vector<string>>ans;

    bool ispalindrome(int lo,int hi,string &s){
        while(lo<=hi){
            if(s[lo++]!=s[hi--])return 0;
        }
        return 1;
    }

    void solve(int i,int n,string &s,vector<string>&temp){
        if(i==n){
            ans.push_back(temp);
            return;
        }

        for(int j=i;j<n;j++){
            if(ispalindrome(i,j,s)){
                temp.push_back(s.substr(i,j-i+1));
                solve(j+1,n,s,temp);
                temp.pop_back();
            }
        }

    }

public:
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<string>temp;
        solve(0,n,s,temp);
        return ans;
    }
};