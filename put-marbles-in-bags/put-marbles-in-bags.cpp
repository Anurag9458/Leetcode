class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long> temp;
        int n = weights.size();
        if(n == 1)return 0;
        for(int i = 0; i < n-1; i++){
            temp.push_back((weights[i] + weights[i+1]));
            //  cout<<temp.back()<<" ";
        }
        long long sum1 = 0, sum2 = 0;
        sort(temp.begin(),end(temp));
        int a = k-1;
        cout<<temp[0];
        int i = 0;
        while(a--){
            sum1 += temp[i];
            i++;
        }
        a = k - 1;
        i = temp.size()-1;
        
        while(a--){
            sum2 += temp[i];
            i--;
        }

        
        return (sum2 - sum1);
    }
};