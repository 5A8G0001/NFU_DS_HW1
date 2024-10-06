#include <iostream>

using namespace std;

// �۩w�q��ƨӼ��� vector::resize() �欰
long long* resize_array(long long* old_array, int old_size, int new_size) {
    // �ʺA���t�s�}�C
    long long* new_array = new long long[new_size];

    // �N�°}�C���e������s�}�C
    for (int i = 0; i < old_size; i++) {
        new_array[i] = old_array[i];
    }

    // �N�Ѿl������l�Ƭ� -1�]��ܩ|���p��^
    for (int i = old_size; i < new_size; i++) {
        new_array[i] = -1;
    }

    // �����°}�C�O����
    delete[] old_array;

    return new_array;  // ��^�s�}�C�����w
}

long long ackermann_non_recursive(int m, int n, long long** dp_v, int* sizes) {
    // �B�z m == 2 ���S���p
    if (m == 2) {
        return n * 2 + 3;
    }

    // �ˬd�O�_�ݭn�X�R�}�C�A���e�T�O�j�p����
    if (n + 1 > sizes[m - 3]) {
        dp_v[m - 3] = resize_array(dp_v[m - 3], sizes[m - 3], n + 1);
        sizes[m - 3] = n + 1;  // ��s�檺�j�p
    }

    // �p�G�ݭn�p��ȡA�h�i�滼�j�p��(���^�d��)
    if (n > 0) {
        for (int j = 1; j <= n; j++) {
            if (dp_v[m - 3][j] == -1) {
                cout << "recursive!" << endl;
                dp_v[m - 3][j] = ackermann_non_recursive(m - 1, dp_v[m - 3][j - 1], dp_v, sizes);
            }
        }
    } else {
        if (dp_v[m - 3][n] == -1) {
            dp_v[m - 3][n] = ackermann_non_recursive(m - 1, 1, dp_v, sizes);
        }
    }

    return dp_v[m - 3][n];  // ��^�w�g�p��n�����G
}

int main()
{
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

    // �ʺA���t�G���}�C dp_v�A��l�j�p n+1
    long long** dp_v = new long long*[m - 2];  // ���t m-2 ��
    int* sizes = new int[m - 2];  // �O���C�@�檺�j�p
    for (int i = 0; i < m - 2; i++) {
        dp_v[i] = new long long[n + 1];  // �C���l���t n+1 �Ӥ���
        sizes[i] = n + 1;  // ��l�Ƥj�p�� n + 1
        for (int j = 0; j <= n; j++) {
            dp_v[i][j] = -1;  // ��l�Ƭ� -1�A��ܩ|���p��
        }
    }


    if (!dp_v) {
        cerr << "Memory allocation failed!" << endl;
        return -1;
    }

    // �q m = 3 �}�l�i��p��A�ö�R dp_v ��
    for (int i = 3; i <= m; i++) {
        // ��C�@��A�T�O�j�p�����A�i��p��
        if (n + 1 > sizes[i - 3]) {
            dp_v[i - 3] = resize_array(dp_v[i - 3], sizes[i - 3], n + 1);
            sizes[i - 3] = n + 1;  // ��s�檺�j�p
        }
        for (int j = 0; j <= n; j++) {
            if (j == 0) {
                // �� j == 0 �ɡA�p�� A(i-1, 1) �æs�J dp_v
                dp_v[i - 3][j] = ackermann_non_recursive(i - 1, 1, dp_v, sizes);
            } else {
                // �_�h�p�� A(i-1, dp_v[i-3][j-1])�A�æs�J dp_v
                dp_v[i - 3][j] = ackermann_non_recursive(i - 1, dp_v[i - 3][j - 1], dp_v, sizes);
            }
        }
    }

    // ��X�̲׵��G
    cout << dp_v[m - 3][n] << endl;

    // ����ʺA���t���O����
    for (int i = 0; i < m - 2; i++) {
        delete[] dp_v[i];  // ����C�@��
    }
    delete[] dp_v;  // �����ӰʺA�}�C
    delete[] sizes; // ���� sizes �}�C

    return 0;
}
