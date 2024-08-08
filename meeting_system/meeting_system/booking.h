#include "globalFile.h"
#include "identity.h"
#include <fstream>
#include <string>
#include "Developer.h"
#include "AdminStaff.h"
#include "Manager.h"
#include<memory>


// ����Ա�Ӳ˵�
void managerMenu(Identity*& manager)
{
	while (true)
	{
		// ����Ա�˵�
		manager->openMenu();

		Manager* man = (Manager*)manager;
		int select = 0;

		cin >> select;

		if (select == 1)   // ����˺�
		{
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2)  // �鿴�˺�
		{
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3)  // �鿴������
		{
			cout << "�鿴������" << endl;
			man->showMeetingRoom();
		}
		else if (select == 4)  // ���ԤԼ
		{
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


// �з���Ա�Ӳ˵�
void developerMenu(Identity*& developer)
{
	while (true)
	{
		// �з���Ա�˵�
		developer->openMenu();

		Developer* dev = (Developer*)developer;
		int select = 0;

		cin >> select;

		if (select == 1)  // ����ԤԼ
		{
			dev->applyBooking();
		}
		else if (select == 2)  // �鿴����ԤԼ
		{
			dev->showMyBooking();
		}
		else if (select == 3)  // �鿴����ԤԼ
		{
			dev->showAllBooking();
		}
		else if (select == 4)  // ȡ��ԤԼ
		{
			dev->cancelBooking();
		}
		else
		{
			delete developer;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


// ������Ա�˵�
void adminstaffMenu(Identity*& adminstaff)
{
	while (true)
	{
		// ��ʦ�˵�
		adminstaff->openMenu();

		AdminStaff* adm = (AdminStaff*)adminstaff;
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			// �鿴����ԤԼ
			adm->showAllBooking();
		}
		else if (select == 2)
		{
			// ���ԤԼ
			adm->validBooking();
		}
		else
		{
			delete adminstaff;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}



// ��¼����
void LoginIn(string fileName, int type)
{

	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	// �ļ����������
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1)	// �з���Ա��¼
	{
		cout << "����������з�����" << endl;
		cin >> id;
	}
	else if (type == 2)  // ������Ա��¼
	{
		cout << "�����������������" << endl;
		cin >> id;
	}

	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺 " << endl;
	cin >> pwd;


	if (type == 1)
	{
		// �з���Ա��¼��֤
		int fId;
		string fUserName;
		string fPwd;
		while (ifs >> fId && ifs >> fUserName && ifs >> fPwd)
		{
			if (id == fId && name == fUserName && pwd == fPwd)
			{
				cout << "�з���Ա��֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				//std::shared_ptr<Developer> person(new Developer(id, name, pwd));
				person = new Developer(id, name, pwd);
				developerMenu(person);
				return;
			}
		}

	}
	else if (type == 2)
	{
		// ������Ա��¼��֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "������Ա��֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				//std::shared_ptr<AdminStaff> person(new AdminStaff(id, name, pwd));
				person = new AdminStaff(id, name, pwd);
				//���������Ӳ˵�
				adminstaffMenu(person);
				return;
			}
		}

	}
	else if (type == 3)
	{
		// ����Ա��¼��֤
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "��֤��¼�ɹ�!" << endl;
				// ��¼�ɹ��󣬰�������������Ա����
				system("pause");
				system("cls");
				// ��������Ա����
				//std::shared_ptr<Manager> person(new Manager(name, pwd));
				person = new Manager(name, pwd);
				// �������Ա�Ӳ˵�
				managerMenu(person);
				return;
			}
		}

	}
	cout << "��֤��¼ʧ��!" << endl;

	system("pause");
	system("cls");
	return;
}



