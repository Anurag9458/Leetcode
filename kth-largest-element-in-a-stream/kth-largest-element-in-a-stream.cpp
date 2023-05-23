class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>q;
    int mk;
    KthLargest(int k, vector<int>& nums) {
        mk=k;
        for(int x:nums)add(x);
    }
    
    int add(int val) {
        if(q.size()<mk)q.push(val);
        else
        {
            if(val>q.top())
            {
                q.pop();
                q.push(val);
            }
        }
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */