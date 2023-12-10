class Solution {

    double solve(string s,string d,unordered_map<string,vector<pair<string,double>>>&adj){
        
       
        queue<pair<double,string>>q;
        map<string,int>mp;
        q.push({1,s});
        mp[s]++;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            double temp=it.first;
            
            string node=it.second;
            cout<<node<<" ";
            if(node==d)return temp;
            
            for(auto i:adj[node]){
                double nt=i.second;
                string nnode=i.first;
                if(!mp.count(nnode)){
                    q.push({nt*temp,nnode});
                    mp[nnode]++;
                }
            }
            
        }
        return -1;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& values, vector<vector<string>>& q) {
        vector<double>ans;

        int n=e.size();

        unordered_map<string,vector<pair<string,double>>>adj;

        for(int i=0;i<n;i++){
            string n1=e[i][0],n2=e[i][1];
            adj[n1].push_back({n2,values[i]});
            adj[n2].push_back({n1,1/values[i]});
        }

        for(int i=0;i<q.size();i++){
            string s=q[i][0],d=q[i][1];
            if(!adj.count(s) || !adj.count(d))ans.push_back(-1);
            else{
            double temp=solve(s,d,adj);
            ans.push_back(temp);}
        }

        return ans;

    }
};