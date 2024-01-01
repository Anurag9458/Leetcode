class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size(),m=s.size();
        sort(begin(s),end(s));
        int count=0;
        for(int i=0;i<n;i++){
            int it=lower_bound(begin(s),end(s),g[i])-begin(s);
            if(it!=s.size()){
            count++;
            s.erase(begin(s)+it);}
        }
        return count;
    }
};