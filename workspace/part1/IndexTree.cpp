#include <iostream>
#define NUMBER 7

using namespace std;

int tree[NUMBER];

// 1부터 i까지의 구간 합 구하기
int sum(int i) {
	int res = 0;
	while (i > 0) {
		res += tree[i];
		// 마지막 비트만큼 빼면서 앞으로 이동
		i -= (i & -i);
	}
	return res;
}

// 특정 인덱스 수정하기
void update(int i, int dif) {
	while (i <= NUMBER) {
		tree[i] += dif;
		// 마지막 비트만큼 더하면서 뒤로 이동
		i += (i & i);
	}
}

// 구간 합 계산 함수 구현하기
int getSelection(int start, int end) {
	return sum(end) - sum(start - 1);
}

// Index Tree
// tree[i] : i의 마지막 비트가 tree[i]가 저장하고 있는 값들의 개수
// ex. i = 7 -> 111(2)이므로 1개, i = 8 -> 1000(2)이므로 8개
int main(void) {
	update(1, 7);
	update(2, 1);
	update(3, 9);
	update(4, 5);
	update(5, 6);
	update(6, 4);
	update(7, 1);
	cout << "1부터 7까지의 구간 합: " << getSelection(1, 7) << endl;
	cout << "인덱스 6의 원소를 +3만큼 수정"<< endl;
	update(6, 3);
	cout << "4부터 7까지의 구간 합: " << getSelection(1, 7) << endl;
	system("pause");
}