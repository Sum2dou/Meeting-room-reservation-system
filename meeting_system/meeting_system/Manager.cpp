#include "Manager.h"
#include "Developer.h"
#include "AdminStaff.h"
#include <fstream>
#include <iostream>
#include <Algorithm>
#include"GlobalFile.h"
#include <vector>
#include"MeetingRoom.h"

// Ĭ�Ϲ���
Manager::Manager()
{
}

// �вι���
Manager::Manager(string name, string pwd)
{
		this->m_Name = name;
		this->m_Pwd = pwd;
		// ��ʼ������
		this->initVector();
}

// ѡ��˵�
void Manager::openMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴��������Ϣ      |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

// ����˺�  
void Manager::addPerson()
{

		cout << "����������˺ŵ�����" << endl;
		cout << "1������з���Ա" << endl;
		cout << "2�����������Ա" << endl;
		string errorTip;  // �ظ�������ʾ
		string fileName;
		string tip;
		ofstream ofs;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			fileName = DEVELOPER_FILE;
			tip = "�������з���ţ� ";
			errorTip = "�з�����ظ�������������";
		}
		else
		{
			fileName = ADMINSTAFF_FILE;
			tip = "������������ţ�";
			errorTip = "ְ�����ظ�������������";
		}

		ofs.open(fileName, ios::out | ios::app);
		int id;
		string name;
		string username;
		string pwd;
		cout << tip << endl;
		while (true)
		{
			cin >> id;

			bool ret = this->checkRepeat(id, 1);

			if (ret)  // ���ظ�
			{
				cout << errorTip << endl;
			}
			else
			{
				break;
			}
		}

		cout << "������������ " << endl;
		cin >> name;

		cout << "�������û����� " << endl;
		cin >> name;

		cout << "���������룺 " << endl;
		cin >> pwd;
		

		ofs << id << " " << name << " " << username<<" "<< " " << pwd << " " << endl;
		cout << "��ӳɹ�" << endl;
		// ��ʼ������
		this->initVector();

		system("pause");
		system("cls");

		ofs.close();

}
void printDeveloper(Developer& s)
{
	cout << "�з����ţ� " << s.m_DevId << " ������ " << s.m_Name << " ���룺" << s.m_Pwd << endl;
}
void printAdminStaff(AdminStaff& t)
{
	cout << "�������ţ� " << t.m_AdmId << " ������ " << t.m_Name << " ���룺" << t.m_Pwd << endl;
}
// �鿴�˺�
void Manager::showPerson()
{
		cout << "��ѡ��鿴���ݣ�" << endl;
		cout << "1���鿴�����з���Ա" << endl;
		cout << "2���鿴����������Ա" << endl;

		int select = 0;

		cin >> select;

		if (select == 1)
		{
			cout << "�����з���Ա����Ϣ���£� " << endl;
			for_each(vDev.begin(), vDev.end(), printDeveloper);
		}
		else
		{
			cout << "����������Ա����Ϣ���£� " << endl;
			for_each(vAdmsta.begin(), vAdmsta.end(), printAdminStaff);
		}
		system("pause");
		system("cls");
	

}

void Manager::infoMeetingRoom()
{
	// ��ȡ��������Ϣ
	ifstream ifs;
	if (safe == 1)
	{
		safe++;
		ifs.open(MEETINGROOM_FILE, ios::in);

		MeetingRoom c;
		while (ifs >> c.m_MeeId&& ifs >> c.m_Name&& ifs >> c.m_MaxNum&& ifs >> c.m_NeedValid)
		{
			vMee.push_back(c);
		}
		cout << "��ǰ����������Ϊ�� " << vMee.size() << endl;

		ifs.close();
	}
	
}


// �鿴��������Ϣ
void Manager::showMeetingRoom()
{

	cout << "��������Ϣ���£� " << endl;
	infoMeetingRoom();
	for (vector<MeetingRoom>::iterator it = vMee.begin(); it != vMee.end(); it++)
	{
		cout << "�����ұ�ţ�" << it->m_MeeId << " ���������ƣ� " << it->m_Name << " ��������������� " << it->m_MaxNum << " �Ƿ���ҪԤԼ�� " << it->m_NeedValid << endl;
	}
	system("pause");
	system("cls");


}

// ���ԤԼ��¼
void Manager::cleanFile()
{
		ofstream ofs(BOOKING_FILE, ios::trunc);
		ofs.close();

		cout << "��ճɹ���" << endl;
		system("pause");
		system("cls");
	
}


void Manager::initVector()
{
	// ��ȡ�з���Ա�ļ�����Ϣ
	ifstream ifs;
	ifs.open(DEVELOPER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	vDev.clear();
	vAdmsta.clear();

	Developer s;
	while (ifs >> s.m_DevId && ifs >> s.m_Name&& ifs >> s.m_Pwd)
	{
		vDev.push_back(s);
	}
	cout << "��ǰ�з���Ա����Ϊ�� " << vDev.size() << endl;
	ifs.close(); //�з���Ա��ʼ��

	// ��ȡ������Ա�ļ���Ϣ
	ifs.open(ADMINSTAFF_FILE, ios::in);

	AdminStaff t;
	while (ifs >> t.m_AdmId&& ifs >> t.m_Name&& ifs >> t.m_Pwd)
	{
		vAdmsta.push_back(t);
	}
	cout << "��ǰ������Ա����Ϊ�� " << vAdmsta.size() << endl;

	ifs.close();
}


bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Developer>::const_iterator it = vDev.begin(); it != vDev.end(); it++)
		{
			if (id == it->m_DevId)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<AdminStaff>::const_iterator it = vAdmsta.begin(); it != vAdmsta.end(); it++)
		{
			if (id == it->m_AdmId)
			{
				return true;
			}
		}
	}
	return false;
}
