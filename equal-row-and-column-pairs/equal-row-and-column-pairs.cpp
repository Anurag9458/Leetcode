#include<bits/stdc++.h>
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector<vector<int>>temp=grid;
        int n=grid.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            if(i>j)
            swap(temp[i][j],temp[j][i]);
        }
        unordered_map<string,int>mp;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            string temp="";
            for(int a:grid[i])
            temp+=to_string(a+1);
            cout<<temp<<" ";
            mp[temp]++;
        }
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            string temp1="";
            for(int a:temp[i])
            temp1+=to_string(a+1);
            cout<<temp1<<" ";
            if(mp.count(temp1))ans+=mp[temp1];
        }
        return ans;
    }
};