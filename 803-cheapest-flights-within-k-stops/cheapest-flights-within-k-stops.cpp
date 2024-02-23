class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int s, int d, int k) {
         vector<pair<int,int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        set<pair<int,pair<int,int>>>st;
        st.insert({0,{s,0}});
        vector<int>price(n,1e9);
        price[s]=0;
        while(!st.empty()){
            auto it=*st.begin();
            st.erase(it);
            int step=it.first,node=it.second.first,p=it.second.second;
            if(step>k)break;
            for(auto i:adj[node]){
                if(p+i.second<price[i.first]){
                    price[i.first]=p+i.second;
                    st.insert({step+1,{i.first,price[i.first]}});
                }
            }
        }
        if(price[d]==1e9)price[d]=-1;
        return price[d];
    }
};