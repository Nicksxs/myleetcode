int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
class Solution {
public:
    int dfs(int x, int y, const int &m, const int &n, vector<vector<int>>& matrix, vector<vector<int>>& dis){
        if(dis[x][y]) return dis[x][y];
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] > matrix[x][y]){
                dis[x][y] = max(dis[x][y], dfs(nx, ny, m, n, matrix, dis));
            }
        }
        return ++dis[x][y];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(!matrix.size()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > dis(m, vector<int>(n, 0));
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans, dfs(i, j, m, n, matrix, dis));
            }
        }
        return ans;
    }
};


// int dx[] = { 1 , -1, 0 , 0  };
// int dy[] = { 0 , 0 , 1 , -1 };
// class Solution {
// public:
// 	int dfs(int x, int y, const int &m,const int &n,vector<vector<int>>& matrix, vector<vector<int>>& dis) {
// 		if (dis[x][y]) return dis[x][y];
 
// 		for (int i = 0; i < 4; i++) {
// 			int nx = x + dx[i];
// 			int ny = y + dy[i];
// 			if (nx >= 0 && ny >= 0 && nx < m && ny < n && matrix[nx][ny] > matrix[x][y]) {
// 				dis[x][y] = max(dis[x][y], dfs(nx, ny, m, n, matrix, dis));
// 			}
// 		}
// 		return ++dis[x][y];
// 	}
 
// 	int longestIncreasingPath(vector<vector<int>>& matrix) {
// 		if (!matrix.size()) return 0;
// 		int m = matrix.size(), n = matrix[0].size();
// 		vector<vector<int> > dis(m, vector<int>(n, 0));
// 		int ans = 0;
// 		for (int i = 0; i < m; i++) {
// 			for (int j = 0; j < n; j++) {
// 				ans = max(ans, dfs( i, j, m, n, matrix, dis));
// 			}
// 		}
// 		return ans;
// 	}
// };