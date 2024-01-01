class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size(),m=s.size();
        sort(begin(s),end(s));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[j]>=g[i]){
                    s[j]=0;
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};