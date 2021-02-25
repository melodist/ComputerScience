/*
* shared_ptr: 하나의 특정한 객체를 참조하는 스마트 포인터의 개수가 몇 개인지를 참조.
* 특정한 객체를 새로운 스마트 포인터가 참조할 때마다 Reference Count가 1씩 증가하며
* 각 스마트 포인터의 수명이 다할 때마다 1씩 감소. Reference Count가 0이 되면 delete
* 키워드를 이용해 메모리에서 데이터를 자동으로 할당 해제
*/
#include <iostream>

using namespace std;

int main(void) {
	int* arr = new int[10];
	shared_ptr<int> p1(arr);
	arr[7] = 100;
	cout << p1.use_count() << endl;
	shared_ptr<int> p2(p1);
	cout << p1.use_count() << endl;
	shared_ptr<int> p3(p2);
	cout << p1.use_count() << endl;
	p1.reset();
	p2.reset();
	cout << "arr[7]: " << arr[7] << endl;
	p3.reset();
	cout << p1.use_count() << endl;
	cout << "arr[7]: " << arr[7] << endl;
	system("pause");
}