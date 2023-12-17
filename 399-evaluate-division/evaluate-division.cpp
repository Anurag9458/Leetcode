class Solution {
    
    double solve(string s,string d,unordered_map<string,vector<pair<string,double>>>&adj){
        queue<pair<double,string>>q;
        q.push({1,s});
        map<string,int>mp;
        mp[s]++;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            string node=it.second;
            double temp=it.first;
            if(node==d)return temp;
            for(auto i:adj[node]){
                double ntemp=i.second;
                string nnode=i.first;
                if(!mp.count(nnode)){
                    mp[nnode]++;
                    q.push({ntemp*temp,nnode});
                }
            }
        }
        return -1;
    }


public:
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& queries) {

        vector<double>ans;
        unordered_map<string,vector<pair<string,double>>>adj;
        int n=eq.size();
        for(int i=0;i<n;i++){
            string s=eq[i][0],d=eq[i][1];
            adj[s].push_back({d,values[i]});
            adj[d].push_back({s,1/values[i]});
        }

        for(auto it:queries){
            string s=it[0],d=it[1];
            if(!adj.count(s) || !adj.count(d))ans.push_back(-1);
            else{
                double temp=solve(s,d,adj);
                ans.push_back(temp);
            }
        }

        return ans;
    }
};