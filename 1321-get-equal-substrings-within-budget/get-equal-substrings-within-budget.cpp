class Solution {
public:
    int equalSubstring(string s, string t, int maxi) {
        vector<int>temp;
        int n=s.size();
        
        for(int i=0;i<n;i++){
            temp.push_back(abs(s[i]-t[i]));
        }

        int sum=0;
        int i=0,j=0;
        int ans=0;

        while(i<n){
            sum+=temp[i];
            while(sum>maxi){
                sum-=temp[j];
                j++;
            }
            ans=max(ans,i-j+1);
            i++;
        }
        
        return ans;

    }
};