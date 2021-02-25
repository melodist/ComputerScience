#include <iostream>
#define NUMBER 7

using namespace std;

int tree[NUMBER];

// 1���� i������ ���� �� ���ϱ�
int sum(int i) {
	int res = 0;
	while (i > 0) {
		res += tree[i];
		// ������ ��Ʈ��ŭ ���鼭 ������ �̵�
		i -= (i & -i);
	}
	return res;
}

// Ư�� �ε��� �����ϱ�
void update(int i, int dif) {
	while (i <= NUMBER) {
		tree[i] += dif;
		// ������ ��Ʈ��ŭ ���ϸ鼭 �ڷ� �̵�
		i += (i & i);
	}
}

// ���� �� ��� �Լ� �����ϱ�
int getSelection(int start, int end) {
	return sum(end) - sum(start - 1);
}

// Index Tree
// tree[i] : i�� ������ ��Ʈ�� tree[i]�� �����ϰ� �ִ� ������ ����
// ex. i = 7 -> 111(2)�̹Ƿ� 1��, i = 8 -> 1000(2)�̹Ƿ� 8��
int main(void) {
	update(1, 7);
	update(2, 1);
	update(3, 9);
	update(4, 5);
	update(5, 6);
	update(6, 4);
	update(7, 1);
	cout << "1���� 7������ ���� ��: " << getSelection(1, 7) << endl;
	cout << "�ε��� 6�� ���Ҹ� +3��ŭ ����"<< endl;
	update(6, 3);
	cout << "4���� 7������ ���� ��: " << getSelection(1, 7) << endl;
	system("pause");
}