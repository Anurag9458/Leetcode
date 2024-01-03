class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& a) {
        map<string,vector<int>>mp;

        
        set<string>st;

        for(auto it:a){
            mp[it[0]].push_back(stoi(it[1]));
        }

        for(auto it:mp){
            // cout<<it.second.size()<<" ";
            if(it.second.size()<3)continue;
            vector<int>temp=it.second;
            sort(begin(temp),end(temp));
            for(int i=0;i<temp.size();i++){
                int a=temp[i]+100;
                a--;
                // cout<<a<<" ";
                int count=0;
                for(int j=i;j<temp.size();j++){
                    if(temp[j]<=a)count++;
                    else break;
                }
                if(count>=3)st.insert(it.first);
                // cout<<endl;
            }

        }

        vector<string>ans(begin(st),end(st));
        return ans;
    }
};