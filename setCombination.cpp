#include <iostream>
using namespace std;

// ���j��ƨӥͦ�����
void powerset_recursive(char set[], char subset[], int set_size, int index, int subset_size) {
    // ���F���X�����ɡA��X��e���l��
    if (index == set_size) {
        cout << "{ ";
        for (int i = 0; i < subset_size; i++) {
            cout << subset[i] << " ";
        }
        cout << "}" << endl;
        return;
    }

    // ���]�t��e���������p
    powerset_recursive(set, subset, set_size, index + 1, subset_size);

    // �]�t��e���������p
    subset[subset_size] = set[index];  // �N��e�����[�J�l��
    powerset_recursive(set, subset, set_size, index + 1, subset_size + 1);  // �l���j�p�W�[
}

int main() {
    // �ϥέ�Ͱ}�C�Ӧs�x���X
    char set[] = {'a', 'b', 'c'};
    int set_size = sizeof(set) / sizeof(set[0]);


    // �ϥΤ@�Ӱ}�C�Ӧs�x��e�l���A�̤j�j�p�P���X�j�p�ۦP
    char subset[set_size];

    // �p��ÿ�X����
    powerset_recursive(set, subset, set_size, 0, 0);

    return 0;
}
