class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

     int mod=1e9+7;
     long long  ans=0;
     int n=arr.size();
     vector<int>left(n),right(n);
     stack<int>st;

     for(int i=0;i<n;i++){
         
         if(st.empty()){
             left[i]=-1;
         }else{
             while(!st.empty() && arr[st.top()]>arr[i]){
             st.pop();
            }
             left[i]=st.empty()?-1:st.top();    
         }
          st.push(i);
     }

     while(!st.empty()){
         st.pop();
     }

     for(int i=n-1;i>=0;i--){
         if(st.empty()){
             right[i]=n;  
         }else{
             while(!st.empty() && arr[st.top()]>=arr[i]){
             st.pop();
             }
             right[i]=st.empty()?n:st.top();
         }
         st.push(i);
     }

     for(int i=0;i<n;i++){
         long long int temp=(i-left[i])*(right[i]-i);
         temp%=mod;
         temp=(temp*arr[i]);
         ans=(ans+temp)%mod;
     }

    // for(int i:left)cout<<i<<" ";cout<<endl;for(int i:right)cout<<i<<" ";

     return ans;


    }
};