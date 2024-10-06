#include <iostream>
#include <vector>

using namespace std;

int ackermann_non_recursive(int m, int n, vector<vector<int>>& dp_v) {
    // 處理 m == 2 的特殊情況
    if (m == 2) {
        return n * 2 + 3;
    }

    // 如果還沒有計算過這些結果，進行計算
    if (dp_v[m - 3].size() <= n) {
        int start_j = dp_v[m - 3].size();  // 紀錄目前的大小
        dp_v[m - 3].resize(n + 1);  // 將大小調整為需要的大小
        for (int j = start_j; j <= n; j++) {
            // 計算 Ackermann 函數的值，並存入 dp_v 表中
            dp_v[m - 3][j] = ackermann_non_recursive(m - 1, dp_v[m - 3][j - 1], dp_v);
        }
    }

    return dp_v[m - 3][n];  // 返回已經計算好的結果
}

int main() {
    int m, n;
    cin >> m >> n;

    // 處理 m < 2 和 m == 2 的特殊情況，直接輸出結果
    if (m < 2) {
        cout << n + 1 + m << endl;
        return 0;
    } else if (m == 2) {
        cout << n * 2 + 3 << endl;
        return 0;
    }

    // 初始化動態規劃表，大小為 m-2 行
    vector<vector<int>> dp_v(m - 2);

    // 從 m = 3 開始進行計算，並填充 dp_v 表
    for (int i = 3; i <= m; i++) {
        dp_v[i - 3].resize(n + 1);  // 對每一行進行動態調整
        for (int j = 0; j <= n; j++) {
            if (j == 0) {
                // 當 j == 0 時，計算 A(i-1, 1) 並存入 dp_v
                dp_v[i - 3][j] = ackermann_non_recursive(i - 1, 1, dp_v);
            } else {
                // 否則計算 A(i-1, dp_v[i-3][j-1])，並存入 dp_v
                dp_v[i - 3][j] = ackermann_non_recursive(i - 1, dp_v[i - 3][j - 1], dp_v);
            }
        }
    }

    // 輸出最終結果
    cout << dp_v[m - 3][n] << endl;

    return 0;
}
