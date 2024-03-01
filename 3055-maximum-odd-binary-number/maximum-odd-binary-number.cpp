class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(begin(s),end(s),greater<char>());
        int n=s.size();
        for(int i=0;i<n;i++){
            if(i+1<n && s[i+1]=='0'){
                swap(s[i],s[n-1]);
                break;
            }
        }
        return s;
    }
};