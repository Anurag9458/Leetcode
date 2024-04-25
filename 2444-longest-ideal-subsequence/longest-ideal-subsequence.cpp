class Solution {

   

public:
    int longestIdealString(string s, int k) {
       
        int n=s.length();

        vector<int>t(26,0);
        int ans=0;
        for(int i=0;i<n;i++){
            int curr=s[i]-'a';
            int left=max(0,curr-k);
            int right=min(25,curr+k);

            int maxi=0;

            for(int j=left;j<=right;j++){
                maxi=max(maxi,t[j]);
            }        
            t[curr]=max(t[curr],maxi+1);
            ans=max(ans,t[curr]);
        }
        return ans;
    }
};