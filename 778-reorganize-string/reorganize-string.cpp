class Solution {
public:
    string reorganizeString(string s) {

     string ans;
     map<char,int>mp;
     for(char c:s)mp[c]++;

     priority_queue<pair<int,char>>pq;

     for(auto it:mp){
         pq.push({it.second,it.first});
     }

    pair<int,char>prev={0,'#'};

     while(!pq.empty()){
         auto it=pq.top();
         pq.pop();
         if(prev.first>0){
             pq.push(prev);
         }

         ans+=it.second;
         it.first--;

         prev=it;

     }
     if(prev.first>0)return "";
     return ans;

    }
};