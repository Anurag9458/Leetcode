class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int>st;
        int n=arr.size();

        for(int i=0;i<n;i++){
            
            if(st.empty())
            st.push(arr[i]);
            else if(arr[i]<0 && st.top()>0){
                        if(abs(arr[i])<st.top())
                        continue;
                        else if(abs(arr[i])==st.top())st.pop();
                        else{
                            
                            st.pop();
                            // cout<<st.top()<<" ";
                            int flag=1;
                            while(!st.empty() && st.top()>0){
                              
                                if(st.top()<abs(arr[i]))
                                st.pop();
                                else if(st.top()==abs(arr[i])){
                                //    cout<<1<<" ";
                                    st.pop();
                                    flag=0;
                                    break;
                                }
                                else break;
                            }
                            if(flag)
                            if((st.empty() || st.top()<0))st.push(arr[i]);
                        }   
            }else
            st.push(arr[i]);

        }
        
        vector<int>ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(begin(ans),end(ans));

        return ans;
    }
};