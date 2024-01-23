class Solution {

    bool check(string s){
        
        set<char>st;
        for(char c:s)st.insert(c);
        bool ans=st.size()==s.size();
        // cout<<s<<" "<<ans<<endl;
        return ans;
    }

    void solve(int i,vector<string>&arr,string temp,vector<string>&v){
        if(i==arr.size()){
            return;
        }
        
        if(check(temp+arr[i])){
            v.push_back(temp+arr[i]);
            solve(i+1,arr,temp+arr[i],v);
        }
        solve(i+1,arr,temp,v);
        
    }

public:
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        vector<string>v;
        solve(0,arr,"",v);
        int ans=0;
        for(string s:v){
            if(check(s)){
                int temp=s.size();
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};