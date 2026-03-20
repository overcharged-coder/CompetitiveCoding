#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<bool>>& board, int q_row, int q_col, int kw_row, int kw_col, int i, int j, bool& can_escape, int n){
    if (can_escape) return;
    if (i < 1 || i > n || j < 1 || j > n) return;
    if (board[i - 1][j - 1]) return;
    if (i == q_row || j == q_col || abs(i - q_row) == abs(j - q_col)) return;
    board[i - 1][j - 1] = true;
    if (i == kw_row && j == kw_col) {
        can_escape = true;
        return;
    }
    board[i - 1][j - 1] = true;
    dfs(board, q_row, q_col, kw_row, kw_col, i + 1, j, can_escape, n);
    dfs(board, q_row, q_col, kw_row, kw_col, i - 1, j, can_escape, n);
    dfs(board, q_row, q_col, kw_row, kw_col, i, j + 1, can_escape, n);
    dfs(board, q_row, q_col, kw_row, kw_col, i, j - 1, can_escape, n);
    dfs(board, q_row, q_col, kw_row, kw_col, i + 1, j + 1, can_escape, n);
    dfs(board, q_row, q_col, kw_row, kw_col, i - 1, j + 1, can_escape, n);
    dfs(board, q_row, q_col, kw_row, kw_col, i + 1, j - 1, can_escape, n);
    dfs(board, q_row, q_col, kw_row, kw_col, i - 1, j - 1, can_escape, n);
}


int main() {
    int n, queen_row, queen_col, king_row, king_col, king_wanted_row, king_wanted_col; cin >> n >> queen_row >> queen_col >> king_row >> king_col >> king_wanted_row >> king_wanted_col;
    bool can_escape = false;
    vector<vector<bool>> board(n, vector<bool>(n, false));
    dfs(board, queen_row, queen_col, king_wanted_row, king_wanted_col, king_row, king_col, can_escape, n);
    if (can_escape) cout << "YES" << endl;
    else cout << "NO" << endl;
}