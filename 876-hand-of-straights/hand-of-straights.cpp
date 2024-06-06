class Solution {
public:
    bool isNStraightHand(vector<int>& arr, int n) {
        map<int,int>mp;

        if(arr.size()%n){
            return 0;
        }

        for(int i:arr){
            mp[i]++;
        }

        int flag=0;

        while(true){
            vector<int>v;

            if(!mp.size()){
                break;
            }

            for(auto it:mp){
                int a=it.first;
                v.push_back(it.first);
                // cout<<it.first<<" ";
                 mp[a]--;
                 if(mp[a]==0){
                    mp.erase(a);
                 }
                

                if(v.size()==n){
                    break;
                }
                
            }
            // cout<<endl;
            if(v.size()!=n){
                return 0;
            }
            for(int i=1;i<v.size();i++){
                if(v[i-1]!=v[i]-1){
                    return 0;
                }
            }
            
        }
        return 1;
    }
};