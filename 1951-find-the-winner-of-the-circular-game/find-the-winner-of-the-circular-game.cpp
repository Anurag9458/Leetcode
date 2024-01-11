class Solution {
    int solve(int i,int k,vector<int>&v,int n){
        if(n==1)return v[0];
        int temp=(i+k)%n;
        v.erase(begin(v)+temp);
        return solve(temp,k,v,v.size());
    }
public:
    int findTheWinner(int n, int k) {
        vector<int>v(n);
        for(int i=0;i<n;i++)v[i]=i+1;
        k--;
        return solve(0,k,v,n);
    }
};