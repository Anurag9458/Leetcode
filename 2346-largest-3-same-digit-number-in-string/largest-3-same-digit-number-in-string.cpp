class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.size();
        char a='0'-1;
        for(int i=0;i<n-2;i++)
        if(num[i]==num[i+1] && num[i+1]==num[i+2])
        a=max(a,num[i]);

        if(a=='0'-1)
        return "";
        string ans;
        ans+=a;
        ans+=a;
        ans+=a;
        return ans;
    }
};