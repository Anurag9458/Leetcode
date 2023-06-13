#include<bits/stdc++.h>
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector<vector<int>>temp=grid;
        int n=grid.size();

        //Here we transpose a matrix
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            if(i>j)
            swap(temp[i][j],temp[j][i]);
        }

        //here we take map to store vector in form of string in map to reduce time complexity
        unordered_map<string,int>mp;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            string temp="";
            for(int a:grid[i])
            //here we store element+1 to avoid testcases like [[11,1],[1,11]]
            temp+=to_string(a+1);
            mp[temp]++;
        }

        //checking for same row
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