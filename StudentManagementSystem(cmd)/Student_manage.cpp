#include"manage.h"
#include<iostream>
using namespace std;
int main() {
	int l, g;
	Manage ma;
	cout << endl;
	cout << "********************************ѧ���ɼ�����ϵͳ********************************" << endl;
	ma.InFile();
	do {
		cout << "                              ��������ѡ�����š�                              " << endl;
		cout << "1������ѧ����¼" <<
			endl << "2��ɾ��ѧ����¼" <<
			endl << "3���ɼ��޸�    " <<
			endl << "4�����˳ɼ��鿴    " <<
			endl << "5������ɼ�����    " << endl;

		do {
			cin >> l;
			switch (l) {
			case 1:
				ma.AddRecord(); break;
			case 2:
				ma.DeleRecord(); break;
			case 3:
				ma.ChangeRecord(); break;
			case 4:
				ma.Search(); break;
			case 5:
				ma.Analyse(); break;
			default:cout << "�����������������" << endl; break;
			}
		} while (l != 1 && l != 2 && l != 3 && l != 4 && l != 5);
		cout << "1.�������гɼ�����" << endl;
		cout << "2.�˳�����ϵͳ" << endl;
		cin >> g;
	} while (g == 1);
	cout << "                            ��лʹ�ñ�ϵͳ��" << endl;
	return 0;
}