class KthLargest {
public:
    int n,k;
    multiset<int>st;
    KthLargest(int k, vector<int>& nums) {
        
        for(int i:nums){
            st.insert(i);
        }
        this->k=k;
        n=nums.size();
    }
    
    int add(int val) {
        st.insert(val);
        n++;
        int count=0;
        for(auto it:st){
            if(count==n-k){
                return it;
            }
            count++;
        }
        return 0;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */