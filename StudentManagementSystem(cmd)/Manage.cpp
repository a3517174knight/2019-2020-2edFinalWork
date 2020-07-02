#include"manage.h"
#include<conio.h>

int m, e, p;
string i, n;
//---------------------------------------------------���ӳɼ�
void Manage::AddRecord() {
	int k(0), t;
	do {
		do {
			cout << "---------------------------------------------------" << endl;
			cout << "�밴˳������ѧ����ѧ�� ���� ��ѧ Ӣ�� ����" << endl;
			cin >> i >> n >> m >> e >> p;
			for (t = 0; t < stu.size(); t++) {
				if (i == stu[t].GetId() || n == stu[t].GetName()) {
					cout << "���и����ɼ���" << endl;
					k = 1;
				}
			}
			if (m > 100 || m < 0 || e>100 || e < 0 || p>100 || p < 0) {
				cout << "����ɼ���ΧΪ0-100" << endl;
				k = 1;
			}
		} while (k == 1);
		Student s(i, n, m, e, p);
		s.Show();
		cout << "---------------------------------------------------" << endl;
		cout << "�Ƿ񱣴�:" << endl << "1.��  2.��" << endl;
		cin >> k;
		if (k == 1) {
			stu.push_back(s);
			OutFile();
		}
		cout << "---------------------------------------------------" << endl;
		cout << "�Ƿ�������" << endl;
		cout << "1.�� 2.��" << endl;
		cin >> k;
	} while (k == 1);
}
//---------------------------------------------------���ҳɼ�
int Manage::Search() {
	int k, t;
	do {
		cout << "��ѡ����ҷ�ʽ��" << endl;
		cout << "-----------------------------------------------------------" << endl;
		cout << "1.ѧ��" << '\t' << '\t' << "2.����" << endl;
		cin >> k;//������switch��䣿
		if (k == 1) t = SearchId();
		else if (k == 2) t = SearchName();
		else cout << "�������!!" << endl;
		cout << "-----------------------------------------------------------" << endl;
		cout << "�Ƿ����²���?" << endl;
		do {
			cout << "1.��" << '\t' << '\t' << "2.��" << endl;
			cin >> k;
		} while (k != 1 && k != 2);
	} while (k == 1);
	return t;
	//http://www.todo.net.cn/tech/article.asp?id=530 vector����������ɾ��
}
//----------------------------------------------------ѧ�Ų���
int Manage::SearchId() {
	int t;
	string id;
	do {
		cout << "������ȷ��ѧ�ţ�" << endl;
		cin >> id;
		for (t = 0; t < stu.size(); ) {
			if (id == stu[t].GetId())  break;
			else t++;
		}
	} while (t == stu.size());//problem  t++
	cout << "ѧ��" << '\t' << '\t' << "����" << '\t' << "��ѧ" << '\t' << "Ӣ��" << '\t' << "����" << endl;
	stu[t].Show();
	return t;
}
//----------------------------------------------------��������
int Manage::SearchName() {
	string name;
	int t;
	do {

		cout << "������ȷ��������" << endl;
		cin >> name;
		for (t = 0; t < stu.size();) {
			if (name == stu[t].GetName()) break;
			else t++;
		}
	} while (t == stu.size());
	cout << "ѧ��" << '\t' << '\t' << "����" << '\t' << "��ѧ" << '\t' << "Ӣ��" << '\t' << "����" << endl;
	stu[t].Show();
	return t;
}
//----------------------------------------------------�����β���
void Manage::SearchScore() {
	int k, max, min, t, temp;
	do {
		do {
			cout << "������ҿ�Ŀ:" << endl;
			cout << "-----------------------------------------------------------" << endl;
			cout << "1.��ѧ" << '\t' << '\t' << "2.Ӣ��" << '\t' << '\t' << "3.����" << endl;
			cin >> k;
			if (k != 1 && k != 2 && k != 3) {
				cout << "����������������룡" << endl;
			}
		} while (k != 1 && k != 2 && k != 3);

		cout << "����������޺�����:" << endl;
		do {
			cin >> max >> min;
			if (max < min || max>100 || min < 0)cout << "�����������������:" << endl;
		} while (max < min || max>100 || min < 0);
		cout << "-----------------------------------------------------------" << endl;
		cout << "��ѯ���Ϊ:" << endl;
		switch (k) {
		case 1:
			for (t = 0; t < stu.size(); t++) {
				temp = stu[t].GetMath();
				if (temp <= max && temp >= min)
					stu[t].Show();
			};
			break;
		case 2:
			for (t = 0; t < stu.size(); t++) {
				temp = stu[t].GetEng();
				if (temp <= max && temp >= min)
					stu[t].Show();
			};
			break;
		case 3:
			for (t = 0; t < stu.size(); t++) {
				temp = stu[t].GetPhy();
				if (temp <= max && temp >= min)
					stu[t].Show();
			};
			break;
		default:cout << "�������!!" << endl; break;
		}
		cout << "-----------------------------------------------------------" << endl;
		cout << "�Ƿ�����������β�ѯ" << endl;
		cout << "1.�� 2.��" << endl;
		cin >> k;
	} while (k == 1);
}
//----------------------------------------------------��ƽ��ֵ
void Manage::Average() {
	int t, k;
	double average, add(0);
	do {
		cout << "��������ƽ��ֵ�Ŀ�Ŀ:" << endl;
		cout << "-----------------------------------------------------------" << endl;
		do {
			cout << "1.��ѧ" << '\t' << "2.Ӣ��" << '\t' << "3.����" << '\t' << "4.�ܷ�" << endl;
			cin >> k;
			if (k != 1 && k != 2 && k != 3 && k != 4) {
				cout << "����������������룡" << endl;
			}
		} while (k != 1 && k != 2 && k != 3 && k != 4);
		switch (k) {
		case 1:
			for (t = 0; t < stu.size(); t++) {
				add += stu[t].GetMath();
			}
			average = add / stu.size();
			cout << "��ѧ��ƽ�����ǣ�" << average << endl;
			break;
		case 2:
			for (t = 0; t < stu.size(); t++) {
				add += stu[t].GetEng();
			}
			average = add / stu.size();
			cout << "Ӣ���ƽ�����ǣ�" << average << endl;
			break;
		case 3:
			for (t = 0; t < stu.size(); t++) {
				add += stu[t].GetPhy();
			}
			average = add / stu.size();
			cout << "�����ƽ�����ǣ�" << average << endl;
			break;
		case 4:
			for (t = 0; t < stu.size(); t++) {
				add += stu[t].Sum();
			}
			average = add / stu.size();
			cout << "�ֵܷ�ƽ�����ǣ�" << average << endl;
			break;
		}
		cout << "-----------------------------------------------------------" << endl;
		cout << "�Ƿ������ƽ��ֵ��" << endl;
		cout << "1.��   2.��" << endl;
		cin >> k;
	} while (k == 1);
}
//------------------------------------------------------------���׼��
void Manage::Standard() {
	int t, k;
	double standardadd(0), standard, add(0), average;
	do {
		cout << "���������׼��Ŀ�Ŀ:" << endl;
		cout << "-----------------------------------------------------------" << endl;
		do {
			cout << "1.��ѧ" << '\t' << "2.Ӣ��" << '\t' << "3.����" << '\t' << "4.�ܷ�" << endl;
			cin >> k;
			if (k != 1 && k != 2 && k != 3 && k != 4) {
				cout << "����������������룡" << endl;
			}
		} while (k != 1 && k != 2 && k != 3 && k != 4);
		switch (k) {
		case 1:
			for (t = 0; t < stu.size(); t++) {
				add += stu[t].GetMath();
			}
			average = add / stu.size();
			for (t = 0; t < stu.size(); t++) {
				standardadd += (stu[t].GetMath() - average) * (stu[t].GetMath() - average);
			}
			standard = sqrt(standardadd / stu.size());
			cout << "��ѧ�ı�׼���ǣ�" << standard << endl;
			break;
		case 2:
			for (t = 0; t < stu.size(); t++) {
				add += stu[t].GetEng();
			}
			average = add / stu.size();
			for (t = 0; t < stu.size(); t++) {
				standardadd += (stu[t].GetEng() - average) * (stu[t].GetEng() - average);
			}
			standard = sqrt(standardadd / stu.size());
			cout << "Ӣ��ı�׼���ǣ�" << standard << endl;
			break;
		case 3:
			for (t = 0; t < stu.size(); t++) {
				add += stu[t].GetPhy();
			}
			average = add / stu.size();
			for (t = 0; t < stu.size(); t++) {
				standardadd += (stu[t].GetPhy() - average) * (stu[t].GetPhy() - average);
			}
			standard = sqrt(standardadd / stu.size());
			cout << "����ı�׼���ǣ�" << standard << endl;
			break;
		case 4:
			for (t = 0; t < stu.size(); t++) {
				add += stu[t].Sum();
			}
			average = add / stu.size();
			for (t = 0; t < stu.size(); t++) {
				standardadd += (stu[t].Sum() - average) * (stu[t].Sum() - average);
			}
			standard = sqrt(standardadd / stu.size());
			cout << "�ֵܷı�׼���ǣ�" << standard << endl;
			break;
		default:
			cout << "�������" << endl;
			break;
		}
		cout << "-----------------------------------------------------------" << endl;
		cout << "�Ƿ�������׼�" << endl;
		cout << "1.��   2.��" << endl;
		cin >> k;
	} while (k == 1);
}
//------------------------------------------------------------------------------------�󼰸���
void Manage::Pass() {
	int k, t;
	int temp;
	double pass, pa(0);
	do {
		cout << "�������󼰸��ʵĿ�Ŀ:" << endl;
		cout << "-----------------------------------------------------------" << endl;
		do {
			cout << "1.��ѧ" << '\t' << '\t' << "2.Ӣ��" << '\t' << '\t' << "3.����" << endl;
			cin >> k;
			if (k != 1 && k != 2 && k != 3) {
				cout << "����������������룡" << endl;
			}
		} while (k != 1 && k != 2 && k != 3);
		switch (k) {
		case 1:
			for (t = 0; t < stu.size(); t++) {
				temp = stu[t].GetMath();
				if (temp >= 60) pa++;
			}
			pass = pa / stu.size();
			cout << "��ѧ�ļ������ǣ�" << pass << endl;
			pa = 0;
			break;
		case 2:
			for (t = 0; t < stu.size(); t++) {
				temp = stu[t].GetEng();
				if (temp >= 60) pa++;
			}
			pass = pa / stu.size();
			cout << "Ӣ��ļ������ǣ�" << pass << endl;
			pa = 0;
			break;
		case 3:
			for (t = 0; t < stu.size(); t++) {
				temp = stu[t].GetPhy();
				if (temp >= 60) pa++;
			}
			pass = pa / stu.size();
			cout << "����ļ������ǣ�" << pass << endl;
			pa = 0;
			break;
		default:cout << "������󣡣�" << endl;
		}
		cout << "-----------------------------------------------------------" << endl;
		cout << "�Ƿ�����󼰸��ʣ�" << endl;
		cout << "1.��   2.��" << endl;
		cin >> k;
	} while (k == 1);
}
//--------------------------------------------------------------------------�ļ�����
void Manage::InFile() {
	int t, k;
	ifstream ifile;
	ifile.open("D:/data.txt");
	if (!ifile) cout << "Error!" << endl;
	do {
		ifile >> i >> n >> m >> e >> p;
		Student s(i, n, m, e, p);
		stu.push_back(s);
	} while (!ifile.eof());
}
//---------------------------------------------------------------------------�ɼ�����ѡ��
void Manage::Analyse() {
	int k;
	do {
		cout << "                              ��������ѡ�����š�                              " << endl;
		cout << "1.��ʾȫ��ɼ�" << endl;
		cout << "2.ƽ����" << endl;
		cout << "3.�ϸ���" << endl;
		cout << "4.��׼��" << endl;
		cout << "5.�鿴����ĳ�����ε�ͬѧ" << endl;
		cout << "6.�Գɼ���������" << endl;
		cin >> k;
		switch (k) {
		case 1:Display(); break;
		case 2:Average(); break;
		case 3:Pass(); break;
		case 4:Standard(); break;
		case 5:SearchScore(); break;
		case 6:Sort(); break;
		default:cout << "�������" << endl; break;
		}
		cout << "-----------------------------------------------------------" << endl;
		cout << "1.������������ɼ�����" << endl;
		cout << "2.�����ϲ�" << endl;
		cin >> k;
	} while (k == 1);
}//-------------------------------------------------------------------------------------�ɼ�����
void Manage::Sort() {
	int q, p, k;
	for (q = 0; q < stu.size(); q++)
		for (p = 0; p < stu.size(); p++)
		{
			if (stu[q].Sum() > stu[p].Sum())			//�Ȱ����ܳɼ�����
			{
				Student s = stu[p];
				stu[p] = stu[q];
				stu[q] = s;
			}
		}

	for (q = 0; q < stu.size(); q++)
		for (p = 0; p < stu.size(); p++) {
			if (stu[q].Sum() == stu[p].Sum() && stu[q].GetMath() > stu[p].GetMath())	//�ܳɼ���ͬ������ѧ�ɼ���
			{
				Student s = stu[p];
				stu[p] = stu[q];
				stu[q] = s;
			}
		}
	for (q = 0; q < stu.size(); q++)
		for (p = 0; p < stu.size(); p++) {
			if (stu[q].Sum() == stu[p].Sum() && stu[q].GetMath() == stu[p].GetMath() && stu[q].GetPhy() > stu[p].GetPhy())	//��ѧ�ɼ�Ҳ��ͬ��������ɼ���
			{
				Student s = stu[p];
				stu[p] = stu[q];
				stu[q] = s;
			}
		}
	for (q = 0; q < stu.size(); q++)
		for (p = 0; p < stu.size(); p++) {
			if (stu[q].Sum() == stu[p].Sum() && stu[q].GetMath() == stu[p].GetMath() && stu[q].GetPhy() == stu[p].GetPhy() && stu[q].GetEng() > stu[p].GetEng())	//������ɼ�Ҳ��ͬ����Ӣ��ɼ���
			{
				Student s = stu[p];
				stu[p] = stu[q];
				stu[q] = s;
			}
		}
	for (q = 0; q < stu.size(); q++)
		for (p = 0; p < stu.size(); p++) {
			if (stu[q].Sum() == stu[p].Sum() && stu[q].GetMath() == stu[p].GetMath() && stu[q].GetPhy() == stu[p].GetPhy() && stu[q].GetEng() == stu[p].GetEng() && stu[q].GetId() > stu[p].GetId())		//�����Ƴɼ���һ������ѧ������
			{
				Student s = stu[p];
				stu[p] = stu[q];
				stu[q] = s;
			}
		}
	Display();
	cout << "-----------------------------------------------------------" << endl;
	cout << "�Ƿ���������ı���" << endl;
	cout << "1.��     2.��" << endl;
	cin >> k;
	if (k == 1) OutFile();

}
//-----------------------------------------------------------------------------------------------------------------���ĳɼ�
void Manage::ChangeRecord() {
	int t;
	t = Search();
	int k, temp;
	do {
		do {
			cout << "��ѡ���޸���Ŀ" << endl;
			cout << "-----------------------------------------------------------" << endl;
			cout << "1.��ѧ" << '\t' << '\t' << "2.Ӣ��" << '\t' << '\t' << "3.����" << endl;
			cin >> k;
			if (k != 1 && k != 2 && k != 3) {
				cout << "����������������룡" << endl;
			}
		} while (k != 1 && k != 2 && k != 3);
		do {
			cout << "�������޸�ֵ��" << endl;
			cin >> temp;
			if (temp > 100 || temp < 0) {
				cout << "����ֵ���Ϸ�!" << endl;
			}
		} while (temp > 100 || temp < 0);
		i = stu[t].GetId();
		n = stu[t].GetName();
		m = stu[t].GetMath();
		e = stu[t].GetEng();
		p = stu[t].GetPhy();
		switch (k) {
		case 1:
			m = temp; break;
		case 2:
			e = temp; break;
		case 3:
			p = temp; break;
		default:; break;
		}
		cout << "��ȷ���Ƿ��޸ģ�" << endl;
		cout << "1.�� 2.��" << endl;
		cin >> k;
		if (k == 1) {
			Student s(i, n, m, e, p);
			stu[t] = s;
			OutFile();
		}
		else cout << "���δ����" << endl;
		cout << "-----------------------------------------------------------" << endl;
		cout << "�Ƿ�����޸�" << endl;
		cout << "1.��  2.��" << endl;
		cin >> k;
	} while (k == 1);
}
//---------------------------------------------------------------------------------------------�ļ����
void Manage::OutFile() {
	int t;
	ofstream ofile;
	ofile.open("D:/data.txt");
	ofile << "ѧ��" << '\t' << '\t' << "����" << '\t' << "��ѧ" << '\t' << "Ӣ��" << '\t' << "����" << endl;
	for (t = 0; t < stu.size(); t++) {
		ofile << stu[t].GetId() << '\t' << stu[t].GetName() << '\t' << stu[t].GetMath() << '\t' << stu[t].GetEng() << '\t' << stu[t].GetPhy() << endl;
	}
	ofile.close();
	cout << "����ɹ���" << endl;
}
//-----------------------------------------------------------------------------------------------------ɾ����¼
void Manage::DeleRecord() {
	int k, x, t;
	Student temp;
	do {
		t = Search();
		cout << "-----------------------------------------------------------" << endl;
		cout << "ȷ��ɾ���˼�¼��" << endl;
		cout << "1.��" << endl;
		cout << "2.��" << endl;
		cin >> k;
		if (k == 1) {
			for (x = t; x < stu.size() - 1; x++) {
				temp = stu[x];
				stu[x] = stu[x + 1];
				stu[x + 1] = temp;
			}
			stu.pop_back();
			cout << "ɾ���ɹ�!" << endl;
			OutFile();
		}
		cout << "-----------------------------------------------------------" << endl;
		cout << "�Ƿ����ɾ����" << endl;
		cout << "1.��" << endl;
		cout << "2.��" << endl;
		cin >> k;
	} while (k == 1);
}
//-------------------------------------------------------------------------------------------------��ʾ���гɼ�
void Manage::Display() {
	int t;
	for (t = 0; t < stu.size(); t++) {
		stu[t].Show();
	}
}
