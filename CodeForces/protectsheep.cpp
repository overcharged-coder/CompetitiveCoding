#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c; cin >> r >> c;
    vector<vector<char>> meadow(r, vector<char>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> meadow[i][j];
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (meadow[i][j] == 'S') {
                if (i > 0 && meadow[i - 1][j] == 'W') {
                    cout << "No" << endl;
                    return 0;
                }
                if (i < r - 1 && meadow[i + 1][j] == 'W') {
                    cout << "No" << endl;
                    return 0;
                }
                if (j > 0 && meadow[i][j - 1] == 'W') {
                    cout << "No" << endl;
                    return 0;
                }
                if (j < c - 1 && meadow[i][j + 1] == 'W') {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (meadow[i][j] == '.'){
                meadow[i][j] = 'D';
            }
            cout << meadow[i][j];
        }
        cout << endl;
    }
}