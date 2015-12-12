class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        int lives = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++){
                lives = 0;
                if(i > 0 && j > 0){
                    lives += board[i - 1][j - 1] == 1 || board[i - 1][j - 1] == 2 ? 1 : 0;
                } //左上角
                if(i > 0){
                    lives += board[i - 1][j] == 1 || board[i - 1][j] == 2 ? 1 : 0;
                } //上
                if(i > 0 && j < n - 1){
                    lives += board[i - 1][j + 1] == 1 || board[i - 1][j + 1] == 2 ? 1 : 0;
                } //右上角
                if(j < n - 1){
                    lives += board[i][j + 1] == 1 || board[i][j + 1] == 2 ? 1 : 0;
                } //右
                if(i < m - 1 && j < n - 1){
                    lives += board[i + 1][j + 1] == 1 || board[i + 1][j + 1] == 2 ? 1 : 0;
                } //右下
                if(i < m - 1){
                    lives += board[i + 1][j] == 1 || board[i + 1][j] == 2 ? 1 : 0;
                } //下
                if(i < m - 1 && j > 0){
                    lives += board[i + 1][j - 1] == 1 || board[i + 1][j - 1] == 2 ? 1 : 0;
                } //左下
                if(j > 0){
                    lives += board[i][j - 1] == 1 || board[i][j - 1] == 2 ? 1 : 0;
                } //左
                if(board[i][j] == 1){
                    if(lives > 3 || lives < 2)
                        board[i][j] = 2;
                }else{
                    if(lives == 3)
                        board[i][j] = 3;
                }
                
            }
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                {
                    board[i][j] = board[i][j] % 2;
                }
    }
};