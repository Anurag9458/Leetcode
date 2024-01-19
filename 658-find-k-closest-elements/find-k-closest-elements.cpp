class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>q;
        for(int i:arr){
            
            q.push({abs(i-x),i});
            if(q.size()>k){
                while(q.size()>k)
                q.pop();
            }
        }
        vector<int>ans;
        while(!q.empty()){
            auto it=q.top();
            ans.push_back(it.second);
            q.pop();
        }
        sort(begin(ans),end(ans));
        return ans;
    }
};