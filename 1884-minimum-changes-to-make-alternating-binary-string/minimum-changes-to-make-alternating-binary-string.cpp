class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int ans1=0,ans2=0;
        string temp1,temp2;
        int i=0;
        while(i<n){
            if(i%2==0){
            temp1.push_back('1');
            temp2.push_back('0');}
            else{
                temp1.push_back('0');
                temp2.push_back('1');
            }
            i++;
        }

        for(int i=0;i<n;i++){
            if(s[i]!=temp1[i])ans1++;
            if(s[i]!=temp2[i])ans2++;
        }
        

        return min(ans1,ans2);
    }
};