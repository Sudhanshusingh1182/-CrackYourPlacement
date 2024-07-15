int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int dx[] = {1, 2, 1, 2, -1, -2, -1, -2};
        int dy[] = {2, 1, -2, -1, 2, 1, -2, -1};

        queue<pair<int , pair<int, int>>> q;
        vector<vector<int>> vis(N + 1, vector<int>(N + 1, 0));

        q.push({0,{KnightPos[0], KnightPos[1]}});
        vis[KnightPos[0]][KnightPos[1]] = 0;

        while (!q.empty()) {
            int row = q.front().second.first;
            int col = q.front().second.second;
            int dist = q.front().first;
            
            q.pop();

            if (row == TargetPos[0] && col == TargetPos[1]) {
                return dist;
            }

            for (int i = 0; i < 8; i++) {
                int newr = row + dx[i];
                int newc = col + dy[i];

                if (newr >= 1 && newr <= N && newc >= 1 && newc <= N && !vis[newr][newc]) {
                    vis[newr][newc]=1;
                    q.push({dist + 1,{newr, newc}});
                }
            }
        }

        // Target position is unreachable
        return -1;
	}