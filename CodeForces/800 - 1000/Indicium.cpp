#include <bits/stdc++.h>
using namespace std;

bool FillMatrix(int N, int K, int row, int col, vector<vector<int>>& lmatrix, vector<unordered_set<int>>& nums_in_row, vector<unordered_set<int>>& nums_in_col) {
    cout << "FillMatrix row=" << row << " col=" << col << endl;
    if (row == N) {
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            sum += lmatrix[i][i];
        }
        return sum == K;
    }

    for (int i = 1 ; i <= N; i++) {
        if (nums_in_row[row].find(i) == nums_in_row[row].end() &&
            nums_in_col[col].find(i) == nums_in_col[col].end()) {
            cout << "Trying out row=" << row << " col=" << col << " val=" << i << endl; 
            nums_in_row[row].emplace(i);
            nums_in_col[col].emplace(i);
            lmatrix[row][col] = i;
            int next_row, next_col;
            if (col+1 < N) {
                next_row = row;
                next_col = col+1;
            } else {
                next_row = row+1;
                next_col = 0;
            }
            if (FillMatrix(N, K, next_row, next_col, lmatrix, nums_in_row, nums_in_col)) {
                return true;
            } else {
                nums_in_row[row].erase(i);
                nums_in_col[col].erase(i);
            }
            
        }
    }
    return false;
}

int main() {
    int num_cases;
    scanf("%d", &num_cases);
    cout << "num of cases: " << num_cases << endl;
    for (int i = 0; i < num_cases; i++) {
        int N, K;
        scanf("%d %d", &N, &K);
        cout << "N=" << N << " " << "K=" << K << endl;
        vector<vector<int>> lmatrix;
        lmatrix.resize(N);
        vector<unordered_set<int>> nums_in_row;
        nums_in_row.resize(N);
        vector<unordered_set<int>> nums_in_col;
        nums_in_col.resize(N);
       
       for (int j = 0; j < N; j++) {
       		vector<int> v;
            v.resize(N);
            lmatrix[j] = v;
            unordered_set<int> s1;
            nums_in_row[j] = s1;
            unordered_set<int> s2;
            nums_in_col[j] = s2;
        }
        
        cout << "filling matrix" << endl;
        if (FillMatrix(N, K, 0, 0, lmatrix, nums_in_row, nums_in_col)) {
            cout << "Case #" << i+1 << ": POSSIBLE" << endl;
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N-1; k++) {
                    cout << lmatrix[j][k] << " ";
                }
                cout << lmatrix[j][N-1] << endl;
            }
        } else {
            cout << "Case #" << i+1 << ": IMPOSSIBLE" << endl;
        }
    }
}