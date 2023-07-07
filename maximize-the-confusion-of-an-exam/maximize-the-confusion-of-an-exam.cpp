class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int countf = 0, countt = 0;
        int i = 0, j = 0, n = answerKey.size();
        for(char c : answerKey){
            if(c == 'T')countt++;
            else countf++;
        }
        if(min(countt, countf) <= k){
            return n;
        }
        countt = 0; countf = 0;
        int ans = 0;
        while(j < n){
            if(answerKey[j] == 'T')countt++;
            else countf++;

            while(min(countt, countf) > k){
                if(answerKey[i] == 'T')countt--;
                else countf--;
                i++;
            }

            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};