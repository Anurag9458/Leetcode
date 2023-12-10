class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int>pre;
        pre.push_back(0);
        
        int n=gain.size();

        for(int i=0;i<n;i++){
            pre.push_back(pre.back()+gain[i]);
        }

        return *max_element(begin(pre),end(pre));
    }
};