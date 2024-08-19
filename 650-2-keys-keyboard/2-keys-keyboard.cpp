class Solution {

    int solve(int i,int j,int n){
        if(i==n){
            return 0;
        }
        if(i>n){
            return 1e9;
        }
        int ca=2+solve(i+i,i,n);
        int p=1+solve(i+j,j,n);

        return min(ca,p);
    }

public:
    int minSteps(int n) {
        if(n==1){
            return 0;
        }

        return 1+solve(1,1,n);
    }
};