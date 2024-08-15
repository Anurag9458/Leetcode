class Solution {
public:
    bool lemonadeChange(vector<int>& arr) {
        map<int,int>mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]==5){
                mp[5]++;
            }else if(arr[i]==10){
                mp[10]++;
                if(mp[5]<=0){
                    return 0;
                }else{
                    mp[5]--;
                }
            }else{
                if(mp[10]>0 && mp[5]>0){
                    mp[10]--;
                    mp[5]--;
                }else if(mp[5]>=3){
                    mp[5]-=3;
                }else{
                    return 0;
                }
            }
        }
        return 1;
    }
};