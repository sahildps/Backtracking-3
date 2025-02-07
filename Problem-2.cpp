// TC : O(m*n)*3^n --size of the string
// SC : O(N)
class Solution
{
public:
    int m, n;
    vector<vector<int>> dirs;
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.size() == 0 || board.empty())
        {
            return false;
        }

        m = board.size();
        n = board[0].size();
        dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // U D L R

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (backtrack(board, word, i, j, 0))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool backtrack(vector<vector<char>> &board, string word, int row, int col, int index)
    {
        // base
        if (index == word.size())
        {
            return true;
        }

        if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] == '#')
        {
            return false;
        }

        // logic
        if (board[row][col] == word[index])
        {
            char temp = board[row][col];
            // action
            board[row][col] = '#';
            for (int i = 0; i < dirs.size(); i++)
            {
                int nr = row + dirs[i][0];
                int nc = col + dirs[i][1];
                // recurse
                if (backtrack(board, word, nr, nc, index + 1))
                {
                    return true;
                }
            }
            // backtrack
            board[row][col] = temp;
        }

        return false;
    }
};