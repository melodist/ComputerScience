#include <iostream>
#define NUMBER 7

using namespace std;

int a[] = { 7, 1, 9, 5, 6, 4, 1 };
int tree[4 * NUMBER]; // 4를 곱하면 모든 범위를 커버 가능

// 구간 합 트리 생성하기
// start: 시작 인덱스, end: 끝 인덱스
int init(int start, int end, int node) {
	if (start == end) return tree[node] = a[start];
	int mid = (start + end) / 2;
	// 재귀적으로 두 부분으로 나눈 뒤에 그 합을 자기 자신으로 한다.
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

// 구간 합 계산하기
// start: 시작 인덱스, end: 끝 인덱스
// left, right: 구간 합을 구하고자 하는 범위
int sum(int start, int end, int node, int left, int right) {
	// 범위 밖에 있는 경우
	if (left > end || right < start) return 0;
	// 범위 안에 있는 경우
	if (left <= start && end <= right) return tree[node];
	// 그렇지 않다면 두 부분으로 나누어 합을 구하기
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

// 구간 합 수정하기
// start: 시작 인덱스, end: 끝 인덱스
// index: 구간 합을 수정하고자 하는 노드
// dif: 수정할 값
void update(int start, int end, int node, int index, int dif) {
	// 범위 밖에 있는 경우
	if (index < start || index > end) return;
	// 범위 안에 있으면 내려가며 다른 원소도 갱신
	tree[node] += dif;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, dif);
	update(mid + 1, end, node * 2 + 1, index, dif);
}

// Segment Tree
int main(void) {
	// 구간 합 트리 생성
	init(0, NUMBER - 1, 1);
	// 구간 합 구하기
	cout << "0부터 6까지의 구간 합: " << sum(0, NUMBER - 1, 1, 0, 6) << endl;
	// 구간 합 갱신하기
	cout << "인덱스 5의 원소를 +3만큼 수정" << endl;
	update(0, NUMBER - 1, 1, 5, 3);
	// 구간 합 다시 구하기
	cout << "3부터 6까지의 구간 합: " << sum(0, NUMBER - 1, 1, 3, 6) << endl;
	system("pause");
}