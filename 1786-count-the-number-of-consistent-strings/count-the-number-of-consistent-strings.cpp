class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        int ans=0;
        int n=words.size();
        int res=0;

        for(char c:allowed){
            res|=1<<(c-'a');
        }

        for(int i=0;i<n;i++){
            string temp=words[i];
            int count=0;
            for(char c:temp){
                if(res&(1<<(c-'a'))){
                    count++;
                }
                
            }
            if(count==temp.size()){
                ans++;
            }
        }
        return ans;
    }
};