class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();

        for(auto &it:grid){
            int a=it[0];
            if(a){
                continue;
            }else{
                for(int &i:it){
                    i=!i;
                }
            }
        }

        vector<int>temp;
        for(int i=0;i<m;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(grid[j][i])count++;
            }
            temp.push_back(count);
            
        }

        for(int i=0;i<m;i++){
           
            int a=n-temp[i];
            //  cout<<temp[i]<<" "<<a<<" ";
            if(a>temp[i]){
            for(int j=0;j<n;j++){
                // cout<<grid[j][i]<<" ";
                grid[j][i]=!grid[j][i];
            }
            }
        }

        int ans=0;

        for(auto it:grid){
            for(int i:it){
                cout<<i<<" ";
            }
            cout<<endl;
        }

        for(int i=0;i<n;i++){
            int sum=0,a=2;
            if(grid[i][m-1])sum++;
            for(int j=m-2;j>=0;j--){
                if(grid[i][j]){
                    sum+=a;
                }
                a*=2;
            }
            // cout<<sum<<" ";
            ans+=sum;
        }

        return ans;

    }
};