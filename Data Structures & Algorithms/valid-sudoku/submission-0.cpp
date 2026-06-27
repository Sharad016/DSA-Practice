class Solution {
    bool all_row(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> st;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (st.find(board[i][j]) != st.end()) return false;
                    st.insert(board[i][j]);
                }
            }
        }
        return true;
    }
    bool all_col(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> st;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    if (st.find(board[j][i]) != st.end()) return false;
                    st.insert(board[j][i]);
                }
            }
        }
        return true;
    }
    bool squares(vector<vector<char>>& board) {
        unordered_map<int, set<char>> mp;
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                int sq = (r / 3) * 3 + c / 3;
                if (board[r][c] != '.') {
                    if (mp[sq].find(board[r][c]) != mp[sq].end()) return false;
                    mp[sq].insert(board[r][c]);
                }
            }
        }
        return true;
    }

   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return (all_row(board) && all_col(board) && squares(board));
    }
};
