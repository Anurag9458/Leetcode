#define ll long long 

class Solution {

    long long solve(ll s,ll d,vector<pair<ll,ll>>adj[]){

      set<pair<ll,ll>>st;
      st.insert({0,s});
      vector<ll>dis(27,1e9);
      dis[s]=0;

      while(!st.empty()){
          auto it=*st.begin();
          st.erase(it);
          ll t=it.first,node=it.second;
        //   cout<<node<<" ";
          if(node==d){
              return t;
          }

        for(auto i:adj[node]){
            ll nnode=i.first,cost=i.second;
            if(t+cost<dis[nnode]){
                dis[nnode]=t+cost;
                st.insert({dis[nnode],nnode});
            }
        }
            
      }
        return -1;
    }

public:
    long long minimumCost(string s, string d, vector<char>& o, vector<char>& c, vector<int>& cost) {
        ll n2=o.size();
        
        set<char>st;
        for(char c:s)st.insert(c);
        for(char c:d)st.insert(c);
        ll n=st.size();
        vector<pair<ll,ll>>adj[27];

        for(ll i=0;i<n2;i++){
            adj[o[i]-'a'].push_back({c[i]-'a',cost[i]});
        }

        long long ans=0;
        ll n1=s.size();
        map<pair<int,int>,int>mp;
        for(ll i=0;i<n1;i++){
            pair<int,int>p={s[i]-'a',d[i]-'a'};
            if(mp.count(p)){
                ans+=mp[p];
            }
            else if(s[i]!=d[i]){
                long long temp=solve(s[i]-'a',d[i]-'a',adj);
                // cout<<temp<<" ";
                mp[{s[i]-'a',d[i]-'a'}]=temp;
                if(temp<0)return -1;
                ans+=temp;
            }
        }
        return ans;
    }
};