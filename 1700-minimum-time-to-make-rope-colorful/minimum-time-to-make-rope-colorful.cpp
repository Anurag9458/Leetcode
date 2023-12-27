class Solution {
public:
    int minCost(string s, vector<int>& t) {
        int ans=0,n=s.size();
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
            int maxi=0,sum=0;
            while(i+1<n && s[i]==s[i+1]){
                maxi=max(maxi,t[i]);
                sum+=t[i];
                i++;
            }
            if(i<n){
                maxi=max(maxi,t[i]);
                sum+=t[i];
            }
            int temp=sum-maxi;
            ans+=temp;
            }
        }
        return ans;
    }
};