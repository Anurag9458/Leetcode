class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if(x<y){
            swap(x,y);
             reverse(begin(s),end(s));
        }
       
        int acount=0,bcount=0,ans=0;

         for (int i = 0; i < s.size(); ++i) {
            char currentChar = s[i];

            if (currentChar == 'a') {
                ++acount;
            } else if (currentChar == 'b') {
                if (acount > 0) {
                    --acount;
                    ans += x;
                } else {
                    ++bcount;
                }
            } else {
                ans += min(bcount, acount) * y;
                acount = bcount = 0;
            }
        }

        ans+=min(bcount,acount)*y;

        return ans;

    }
};