class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n,0);
        bool skip=0;
        sort(begin(arr),end(arr));

        if(n<=2){
            return arr;
        }
        int i=0,j=0;

        while(i<n){
            
            if(!ans[j]){
                if(!skip){
                    ans[j]=arr[i];
                    i++;
                }
                skip=!skip;
            }
            j=(j+1)%n;
            
        }


        return ans;

    }
};