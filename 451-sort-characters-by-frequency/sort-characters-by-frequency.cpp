class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }
        string ans;
        priority_queue<pair<int,char>>pq;
        for(auto it:mp){
           pq.push({it.second,it.first});
        }
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            while(it.first--){
                ans.push_back(it.second);
            }
        }
        
        return ans;
    }
};