/*
* weak_ptr: shared_ptr ��ü�� �����ϰ� �ִ� ��ü�� ������ �� ������ 
* �ش� ��ü�� ������ ������ ���Ե��� �ʴ� ����Ʈ ������
* shared_ptr�� ���� ��ȯ ����(Circular Reference) ������ �����ϱ� ���Ͽ� ���
*/
#include <iostream>

using namespace std;

int main(void) {
	int* arr = new int(1);
	shared_ptr<int> sp1(arr);
	weak_ptr<int> wp = sp1; // wp�� ���� Ƚ�� ��꿡�� ����
	cout << sp1.use_count() << endl;
	cout << wp.use_count() << endl; // ����� 1�� ����
	if (true) {
		shared_ptr<int> sp2 = wp.lock(); // wp�� �����ϰ� �ִ� shared_ptr ������ ��ȯ
		cout << sp1.use_count() << endl; // sp1, sp2�� arr�� �����ϰ� �����Ƿ� 2�� ��ȯ
		cout << wp.use_count() << endl; // wp�� ���� ������ ���Ե��� ����
	}
	// Scope�� ����Ƿ� sp2�� ������
	cout << sp1.use_count() << endl; // sp1�� arr�� �����ϰ� �����Ƿ� 2�� ��ȯ
	cout << wp.use_count() << endl; // wp�� ���� ������ ���Ե��� ����
	system("pause");
}