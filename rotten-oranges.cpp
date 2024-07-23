//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int m = grid.size(), n = grid[0].size(), time = -1, nFresh = 0,
            nRotten = 0;
        queue<pair<int, int>> q;
        vector<pair<int, int>> neighbours = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                    nFresh++;
                else if (grid[i][j] == 2) {
                    nRotten++;
                    q.push({i, j});
                }
        if (!nRotten && !nFresh)
            return 0;
        if (!nRotten && nFresh)
            return -1;
        while (!q.empty()) {
            time++;
            int size = q.size();
            while (size--) {
                int x = q.front().first;
                int y = q.front().second;
                for (auto p : neighbours) {
                    int X = x + p.first;
                    int Y = y + p.second;
                    if (X >= 0 && X < m && Y >= 0 && Y < n &&
                        grid[X][Y] == 1) {
                        q.push({X, Y});
                        grid[X][Y] = 2;
                        nFresh--;
                    }
                }
                q.pop();
            }
        }
        return nFresh ? -1 : time;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
