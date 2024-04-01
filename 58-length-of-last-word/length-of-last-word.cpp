class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=1;
        int n=s.size();
        while(n--){
            if(s[n]==' '){
                continue;
            }else{
                break;
            }
        }
        while(n-- && s[n]!=' '){
            ans++;
        }
        return ans;
    }
};