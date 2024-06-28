class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        using ll=long long;
        vector<int>v[n];

        for(auto it:roads){
            v[it[0]].push_back(it[1]);
            v[it[1]].push_back(it[0]);
        }

        vector<pair<int,int>>temp;

        for(int i=0;i<n;i++){
            temp.push_back({v[i].size(),i});
            // cout<<v[i].size()<<" ";
        }
        // cout<<endl;

        sort(begin(temp),end(temp),greater<pair<int,int>>());

        map<int,int>mp;
        int a=n;
        for(auto it:temp){
            mp[it.second]=n;
            // cout<<it.second<<" "<<n<<endl;
            n--;
        }

        ll ans=0;


        for(auto it:roads){
            ans+=(mp[it[0]]+mp[it[1]]);
        }

        return ans;
    }
};