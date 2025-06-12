class Solution
{
public:
  bool exists(vector<vector<char>> &board, int i, int j, string &word, int idx, int m, int n)
  {
    if (idx == word.size())
      return true;
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx])
      return false;

    char ch = board[i][j];
    board[i][j] = '$';
    bool res = exists(board, i + 1, j, word, idx + 1, m, n) ||
               exists(board, i - 1, j, word, idx + 1, m, n) ||
               exists(board, i, j + 1, word, idx + 1, m, n) ||
               exists(board, i, j - 1, word, idx + 1, m, n);

    board[i][j] = ch;

    return res;
  }

  bool exist(vector<vector<char>> &board, string word)
  {
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (board[i][j] == word[0] && exists(board, i, j, word, 0, m, n))
        {
          return true;
        }
      }
    }
    return false;
  }
};