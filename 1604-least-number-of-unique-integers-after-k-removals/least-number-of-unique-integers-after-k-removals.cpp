class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>mp;

        for(int i:arr){
            mp[i]++;
        }

        multiset<pair<int,int>>st;

        for(auto it:mp){
            st.insert({it.second,it.first});
        }

        while(k--){
            auto it=*st.begin();
            st.erase(it);
            if(it.first==1){
                continue;
            }else{
                it.first--;
                st.insert(it);
            }
        }


        return st.size();
    }
};