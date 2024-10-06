#include <iostream>
#include <vector>

using namespace std;

int ackermann_non_recursive(int m, int n, vector<vector<int>>& dp_v) {
    // �B�z m == 2 ���S���p
    if (m == 2) {
        return n * 2 + 3;
    }

    // �p�G�٨S���p��L�o�ǵ��G�A�i��p��
    if (dp_v[m - 3].size() <= n) {
        int start_j = dp_v[m - 3].size();  // �����ثe���j�p
        dp_v[m - 3].resize(n + 1);  // �N�j�p�վ㬰�ݭn���j�p
        for (int j = start_j; j <= n; j++) {
            // �p�� Ackermann ��ƪ��ȡA�æs�J dp_v ��
            dp_v[m - 3][j] = ackermann_non_recursive(m - 1, dp_v[m - 3][j - 1], dp_v);
        }
    }

    return dp_v[m - 3][n];  // ��^�w�g�p��n�����G
}

int main() {
    int m, n;
    cin >> m >> n;

    // �B�z m < 2 �M m == 2 ���S���p�A������X���G
    if (m < 2) {
        cout << n + 1 + m << endl;
        return 0;
    } else if (m == 2) {
        cout << n * 2 + 3 << endl;
        return 0;
    }

    // ��l�ưʺA�W����A�j�p�� m-2 ��
    vector<vector<int>> dp_v(m - 2);

    // �q m = 3 �}�l�i��p��A�ö�R dp_v ��
    for (int i = 3; i <= m; i++) {
        dp_v[i - 3].resize(n + 1);  // ��C�@��i��ʺA�վ�
        for (int j = 0; j <= n; j++) {
            if (j == 0) {
                // �� j == 0 �ɡA�p�� A(i-1, 1) �æs�J dp_v
                dp_v[i - 3][j] = ackermann_non_recursive(i - 1, 1, dp_v);
            } else {
                // �_�h�p�� A(i-1, dp_v[i-3][j-1])�A�æs�J dp_v
                dp_v[i - 3][j] = ackermann_non_recursive(i - 1, dp_v[i - 3][j - 1], dp_v);
            }
        }
    }

    // ��X�̲׵��G
    cout << dp_v[m - 3][n] << endl;

    return 0;
}
