class Solution {
public:
    int maxScore(string s) {
        vector<int>v1,v2;
        int count=0,n=s.size();
        for(char c:s){
            if(c=='0')count++;
            v1.push_back(count);
        }
        count=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1')count++;
            v2.push_back(count);
        }
        reverse(begin(v2),end(v2));
        int maxi=0;
        for(int i=0;i<n-1;i++){
            maxi=max(maxi,v1[i]+v2[i+1]);
        }
        return maxi;
    }
};