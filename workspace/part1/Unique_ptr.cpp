/*
* unique_ptr: �ϳ��� ����Ʈ �����͸��� Ư���� ��ü�� ó���ϵ��� �Ѵ�.
* Ư���� ��ü�� �������� ������ ���� ���� �Ҹ��ڰ� ��ü�� ������ �� �ִ�.
*/
#include <iostream>

using namespace std;

void main1(void) { // ������ ������ �޸� �Ҵ� ����
	unique_ptr<int> p1(new int(10));
	unique_ptr<int> p2;
	cout << "����Ʈ ������ 1: " << p1 << endl;
	cout << "����Ʈ ������ 2: " << p2 << endl;
	cout << "---������ ����---" << endl;
	p2 = move(p1);
	cout << "����Ʈ ������ 1: " << p1 << endl;
	cout << "����Ʈ ������ 2: " << p2 << endl;
	cout << "---�޸� �Ҵ� ����---" << endl;
	p2.reset();
	cout << "����Ʈ ������ 1: " << p1 << endl;
	cout << "����Ʈ ������ 2: " << p2 << endl;
	system("pause");
}

void main2(void) { // ��ü�� �����ϱ�
	unique_ptr<int> p1(new int(10));
	cout << *p1 << endl; // �����ϰ� �ִ� ��ü ��ȯ
	system("pause");
}

void main3(void) { // �޸� ���� ���Ŀ� ��ü ����
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