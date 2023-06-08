class Solution {
    int ans=0;

    void solve(vector<int>&temp)
    {
        int lo=0,hi=temp.size()-1,res=-1;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(temp[mid]<0){res=mid;hi=mid-1;}
            else if(temp[mid]>=0)lo=mid+1;
        }
        cout<<res<<endl;
        if(res==-1)return;
        ans+=(temp.size()-res);
    }

public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int i=0;i<n;i++)
        solve(grid[i]);
        return ans;
    }
};