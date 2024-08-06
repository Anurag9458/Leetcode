class Solution {
public:
    int minimumPushes(string word) {
        
        map<char,int>mp;
        for(char c:word)mp[c]++;
        
        vector<pair<int,char>>v;
        
        for(auto it:mp){
            v.push_back({it.second,it.first});
        }
        
        sort(begin(v),end(v),greater<pair<int,char>>());
        
        string temp;
        
        for(auto it:v){
            // cout<<it.first<<" "<<it.second<<endl;
            temp.push_back(it.second);
        }
        
        int n=temp.size();
        
        long long ans=0;
        
        for(int i=0;i<n;i++){
            if(i+1<=8){
                ans+=mp[temp[i]];
            }else if(i+1<=16){
                ans+=(mp[temp[i]]*2);
            }else if(i+1<=24){
                ans+=(mp[temp[i]]*3);
            }else {
                ans+=(mp[temp[i]]*4);
            }
        }
        return ans;
    }
};