class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int a:rooms[i]){
                adj[i].push_back(a);
            }
        }

        queue<int>q;
        q.push(0);
        vector<int>visited(n,0);
        visited[0]=1;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(int i:adj[node]){
                if(!visited[i]){
                    visited[i]=1;
                    q.push(i);
                }
            }
        }

        for(int i:visited)
        if(!i)return 0;
        return 1;
    }
};