class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            int count=0,count1=0;
            for(int j=i;j<n;j++){
                if(s[j]=='0'){
                    count++;
                }else{
                    count1++;
                }
                 if(count1<=k || count<=k){
                ans++;
            }
            }
           
        }
        return ans;
    }
};