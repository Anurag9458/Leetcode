class Solution {
public:
    int minimumDeletions(string s) {
        
        
        int n=s.size();
        vector<int>counta(n,0),countb(n,0);
        int count=0;
        int ans=n;
        for(int i=0;i<n;i++){
            countb[i]=count;
            if(s[i]=='b')count++;
        }

        count=0;

        for(int i=n-1;i>=0;i--){
            counta[i]=count;
            if(s[i]=='a')count++;
        }

        for(int i=0;i<n;i++){
            ans=min(ans,counta[i]+countb[i]);
        }
        
        return ans;
    }
};