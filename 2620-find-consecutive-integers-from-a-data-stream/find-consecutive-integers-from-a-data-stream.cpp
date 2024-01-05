class DataStream {
    vector<int>v;
    map<int,int>mp;
    int k,val;
    int j=0;
public:
    DataStream(int value, int k) {
        this->k=k;
        this->val=value;
        mp.clear();
        v.clear();
        j=0;
    }
    
    bool consec(int num) {
        if(v.size()<k){
            v.push_back(num);
            mp[num]++;
            if(mp[val]==k){
                return 1;
            }
            return 0;
        }
        v.push_back(num);
        mp[num]++;
        
        mp[v[j]]--;
        
        if(mp[v[j]]==0){
            mp.erase(v[j]);
        }
        j++;
        
        if(mp[val]==k){
            return 1;
        }
        return 0;

    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */