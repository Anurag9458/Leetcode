class Solution {


    int cal(int i,int j,char c){
        if(c=='+')return i+j;
        if(c=='-')return i-j;
        if(c=='*')return i*j;
        return 0;
    }

public:
    vector<int> diffWaysToCompute(string exp) {
        int n=exp.size();
        bool num=1;
        vector<int>ans;

        for(int i=0;i<n;i++){
            if(!isdigit(exp[i])){
                num=0;
                vector<int>left=diffWaysToCompute(exp.substr(0,i));
                vector<int>right=diffWaysToCompute(exp.substr(i+1));

               
                for(int k:left){
                    for(int j:right){
                        int temp=cal(k,j,exp[i]);
                        ans.push_back(temp);
                    }
                }
                
            }
        }
        if(num)ans.push_back(stoi(exp));
        return ans;
    }
};