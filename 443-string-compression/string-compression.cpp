class Solution {
public:
    int compress(vector<char>& chars) {
        
        vector<char>ans;

        int n=chars.size();

        if(n==1)return n;

        int i=0;

        for(i=i;i<n;i++){
            if(i+1<n && chars[i+1]!=chars[i])
            ans.push_back(chars[i]);
            else {
                ans.push_back(chars[i]);
                int temp=1;
                while(i+1<n && chars[i+1]==chars[i]){
                    temp++;
                    i++;
                }
                string a=to_string(temp);
                for(char c:a)
                ans.push_back(c);
            }
        }
        if(chars[n-1]!=chars[n-2])ans.pop_back();
        chars=ans;
        return ans.size();
    }
};