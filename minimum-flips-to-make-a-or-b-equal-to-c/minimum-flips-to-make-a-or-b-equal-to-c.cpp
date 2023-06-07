class Solution {

    void solve(vector<int>&temp,int a)
    {
        while(a)
        {
            if(a%2)temp.push_back(1);
            else temp.push_back(0);
            a/=2;
        }
    }

public:
    int minFlips(int a, int b, int c) {
        vector<int>temp1,temp2,temp3;
        solve(temp1,a);
        solve(temp2,b);
        solve(temp3,c);
        int maxi=0;
        // reverse(temp1.begin(),end(temp1));
        // reverse(temp2.begin(),end(temp2));
        // reverse(temp3.begin(),end(temp3));
        maxi=max(temp1.size(),max(size(temp2),size(temp3)));
        if(temp1.size()<maxi)
        while(temp1.size()!=maxi)temp1.push_back(0);
        if(temp2.size()<maxi)
        while(temp2.size()!=maxi)temp2.push_back(0);
        if(temp3.size()<maxi)
        while(temp3.size()!=maxi)temp3.push_back(0);
        int ans=0;
        for(int i=0;i<maxi;i++)
        {
            if(temp3[i]==0 )
            {
                if(temp1[i]==1 && temp2[i]==1)ans+=2;
                else if(temp1[i]==0 && temp2[i]==0)ans=ans;
                else ans++;
            }
            else
            {
                if(temp1[i]==0 && temp2[i]==0)ans++;
            }
        }
        return ans;
    }
};