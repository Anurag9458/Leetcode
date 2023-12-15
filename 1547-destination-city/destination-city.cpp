class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        
        int n=paths.size()+1;
        vector<int>adj[n];
        set<string>st;
        for(auto it:paths){
            st.insert(it[0]);
            st.insert(it[1]);
        }

        vector<string>v(begin(st),end(st));

        map<string,int>mp;
        for(int i=0;i<n;i++){
            mp[v[i]]=i;
        }

        for(auto it:paths){
            adj[mp[it[1]]].push_back(mp[it[0]]);
        }

        vector<int>outdegree(n,0);
        for(int i=0;i<n;i++){
            for(int a:adj[i])
            outdegree[a]++;
        }

        int ans=0;
        for(int i=0;i<n;i++){
            cout<<outdegree[i]<<" ";
            if(outdegree[i]==0){
                ans=i;
            }
        }

        return v[ans];

    }
};