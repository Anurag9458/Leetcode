class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(string s:details){
            string temp;
            temp.push_back(s[11]);
            temp.push_back(s[12]);
            if(stoi(temp)>60){
                ans++;
            }
        }


        return ans;
    }
};