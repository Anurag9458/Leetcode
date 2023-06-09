class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char tar) {
        char ans='z'+1;
        for(int i=0;i<letters.size();i++)
        {
            if(letters[i]>tar && letters[i]!=tar && letters[i]<ans)ans=letters[i];
        }
        if(ans=='z'+1)return letters[0];
        return ans;
    }
};