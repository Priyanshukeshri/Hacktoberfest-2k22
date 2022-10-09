
class Solution {
public:
    void solve(int col,vector<string> &board,vector<vector<string>> &ans,int n, vector<bool>&left_upper, vector<bool>&left_lower, vector<bool>&left_row)
    {
      if(col>=n)
      {
          ans.push_back(board);
          return ;
      }
    
    for(int row=0;row<n;row++)
    {
         if( left_upper[n-1+col-row]==0 && left_lower[row+col]==0 && left_row[row]==0 )
         {
            board[row][col]='Q';
             left_upper[n-1+col-row]=1;  left_lower[row+col]=1 ; left_row[row]=1;
            solve(col+1,board,ans,n,left_upper,left_lower,left_row);
              left_upper[n-1+col-row]=0;  left_lower[row+col]=0 ; left_row[row]=0;
             board[row][col]='.';  
         }
        
    }

    }
    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>>ans;
        string s(n,'.');
     vector<string> board(n);
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        
        vector<bool>left_upper(2*n-1,0),left_lower(2*n-1,0),left_row(n,0);
        solve(0,board,ans,n,left_upper,left_lower,left_row);
  return ans;
    }
};
