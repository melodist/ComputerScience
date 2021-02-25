/*
* weak_ptr: shared_ptr 객체가 참조하고 있는 객체에 접근할 수 있지만 
* 해당 객체의 소유자 수에는 포함되지 않는 스마트 포인터
* shared_ptr에 의한 순환 참조(Circular Reference) 현상을 제거하기 위하여 사용
*/
#include <iostream>

using namespace std;

int main(void) {
	int* arr = new int(1);
	shared_ptr<int> sp1(arr);
	weak_ptr<int> wp = sp1; // wp는 참조 횟수 계산에서 제외
	cout << sp1.use_count() << endl;
	cout << wp.use_count() << endl; // 결과는 1로 동일
	if (true) {
		shared_ptr<int> sp2 = wp.lock(); // wp가 참조하고 있는 shared_ptr 포인터 반환
		cout << sp1.use_count() << endl; // sp1, sp2가 arr을 참조하고 있으므로 2를 반환
		cout << wp.use_count() << endl; // wp에 의한 참조는 포함되지 않음
	}
	// Scope를 벗어나므로 sp2가 해제됨
	cout << sp1.use_count() << endl; // sp1이 arr을 참조하고 있으므로 2를 반환
	cout << wp.use_count() << endl; // wp에 의한 참조는 포함되지 않음
	system("pause");
}