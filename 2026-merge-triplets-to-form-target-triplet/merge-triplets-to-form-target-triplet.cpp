class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& arr, vector<int>& tar) {
        sort(begin(arr),end(arr));
        vector<int>v(3,0);

        for(auto it:arr){
            if(v==tar)return 1;
            // for(int i:v){
            //     cout<<i<<" ";
            // }
            // cout<<endl;
            if(it[0]<=tar[0] && it[1]<=tar[1] && it[2]<=tar[2]){
                v[0]=max(v[0],it[0]);
                v[1]=max(v[1],it[1]);
                v[2]=max(v[2],it[2]);
            }
        }
        if(v==tar)return 1;
        return 0;
    }   
};