/*
* shared_ptr: �ϳ��� Ư���� ��ü�� �����ϴ� ����Ʈ �������� ������ �� �������� ����.
* Ư���� ��ü�� ���ο� ����Ʈ �����Ͱ� ������ ������ Reference Count�� 1�� �����ϸ�
* �� ����Ʈ �������� ������ ���� ������ 1�� ����. Reference Count�� 0�� �Ǹ� delete
* Ű���带 �̿��� �޸𸮿��� �����͸� �ڵ����� �Ҵ� ����
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