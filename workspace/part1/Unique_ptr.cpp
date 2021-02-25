/*
* unique_ptr: 하나의 스마트 포인터만이 특정한 객체를 처리하도록 한다.
* 특정한 객체의 소유권을 가지고 있을 때만 소멸자가 객체를 삭제할 수 있다.
*/
#include <iostream>

using namespace std;

void main1(void) { // 소유권 이전과 메모리 할당 해제
	unique_ptr<int> p1(new int(10));
	unique_ptr<int> p2;
	cout << "스마트 포인터 1: " << p1 << endl;
	cout << "스마트 포인터 2: " << p2 << endl;
	cout << "---소유권 이전---" << endl;
	p2 = move(p1);
	cout << "스마트 포인터 1: " << p1 << endl;
	cout << "스마트 포인터 2: " << p2 << endl;
	cout << "---메모리 할당 해제---" << endl;
	p2.reset();
	cout << "스마트 포인터 1: " << p1 << endl;
	cout << "스마트 포인터 2: " << p2 << endl;
	system("pause");
}

void main2(void) { // 객체에 접근하기
	unique_ptr<int> p1(new int(10));
	cout << *p1 << endl; // 관리하고 있는 객체 반환
	system("pause");
}

void main3(void) { // 메모리 해제 이후에 객체 접근
	int* arr = new int[10];
	unique_ptr<int> p1(arr);
	for (int i = 0; i < 10; i++) {
		arr[i] = i;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	}
	p1.reset();
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	}
	system("pause");
}

int main(void) {
	main1();
	main2();
	main3();
}