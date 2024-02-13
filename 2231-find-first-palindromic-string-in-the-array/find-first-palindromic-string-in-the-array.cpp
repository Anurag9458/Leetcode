class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string s:words){
            string temp=s;
            reverse(begin(temp),end(temp));
            if(s==temp){
                return s;
            }
        }
        return "";
    }
};