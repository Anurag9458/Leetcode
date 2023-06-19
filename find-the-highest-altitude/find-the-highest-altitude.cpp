class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int>temp;
        temp.push_back(0);
        int a=gain[0];
        for(int i=1;i<gain.size();i++)
        {
            a+=gain[i];
            temp.push_back(a);
        }
        int ans=*max_element(begin(temp),end(temp));
        if(gain[0]>0)
        ans=max(gain[0],ans);
        return ans;
    }
};