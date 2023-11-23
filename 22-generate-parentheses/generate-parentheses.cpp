class Solution {

    void solve(int open,int close,string temp, vector<string>&ans){
        if(!open && !close){
            ans.push_back(temp);
            return;
        }
        if(open){
            solve(open-1,close,temp+"(",ans);
        }
        if(close>open){
            solve(open,close-1,temp+")",ans);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
       vector<string>ans;
       solve(n,n,"",ans);
       return ans; 
    }
};