#include "Developer.h"
#include <fstream>
#include <iostream>
#include <Algorithm>
#include"GlobalFile.h"
#include"MeetingRoom.h"
#include"orderfile.h"
// Ĭ�Ϲ���
Developer::Developer()
{
}

// �вι���(�з����š�����������)
Developer::Developer(int id, string name, string pwd)
{
	// ��ʼ������
	this->m_DevId = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

// �˵�����
void Developer::openMenu()
{
		cout << "��ӭ�з���Ա��" << this->m_Name << "��¼��" << endl;
		cout << "\t\t ----------------------------------\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|          1.����ԤԼ              |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|          3.�鿴����ԤԼ          |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|          4.ȡ��ԤԼ              |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|          0.ע����¼              |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t ----------------------------------\n";
		cout << "��ѡ�����Ĳ����� " << endl;


}

void Developer::infoMeetingRoom()
{
	// ��ȡ��������Ϣ
	if (safe == 0)
	{
		ifstream ifs;

		ifs.open(MEETINGROOM_FILE, ios::in);

		MeetingRoom c;
		while (ifs >> c.m_MeeId&& ifs >> c.m_Name&& ifs >> c.m_MaxNum&& ifs >> c.m_NeedValid)
		{
			vMee.push_back(c);
		}
		ifs.close();
		safe = safe + 1;

	}
	
	



}


// �鿴��������Ϣ
void Developer::showMeetingRoom()
{

	cout << "��������Ϣ���£� " << endl;
	infoMeetingRoom();
	for (vector<MeetingRoom>::iterator it = vMee.begin(); it != vMee.end(); it++)
	{
		cout << "�����ұ�ţ�" << it->m_MeeId << " ���������ƣ� " << it->m_Name << " ��������������� " << it->m_MaxNum << " �û����ҵ�ǰ������ " << it->curnum << " �Ƿ���ҪԤԼ�� " << it->m_NeedValid << endl;
	}
	cout << "��ǰ����������Ϊ�� " << vMee.size() << endl;


}



// ����ԤԼ
void Developer::applyBooking()
{
	cout << "�����ҿ���ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	int date = 0;
	int interval = 0;
	int room = 0;
	MeetingRoom m;
	
	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "������������������" << endl;
	}


	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	
	cout << "��ǰ��������ϢΪ��" << endl;
	showMeetingRoom();
	cout << "��ѡ������ң�" << endl;
	
	while (true)
	{
		cin >> room;
		room = room - 1;
		vMee[room].curnum++;
		if (room >= 1 && room <= vMee.size()&&vMee[room].curnum<= vMee[room].m_MaxNum)
		{
			break;
		}
		else
		{
			cout << "������������������/�û����ѱ�ԤԼ��" << endl;
		}
		
	}
	cout << "ԤԼ�ɹ������������" << endl;

	ofstream ofs(BOOKING_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "devId:" << this->m_DevId << " ";
	ofs << "devName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	system("pause");
	system("cls");

}

// �鿴�ҵ�ԤԼ
void Developer::showMyBooking()
{
		OrderFile of;
		if (of.m_Size == 0)
		{
			cout << "��ԤԼ��¼" << endl;
			system("pause");
			system("cls");
			return;
		}
		for (int i = 0; i < of.m_Size; i++)
		{
			if (atoi(of.m_orderData[i]["devId"].c_str()) == this->m_DevId)
			{
				cout << "ԤԼ���ڣ� ��" << of.m_orderData[i]["date"];
				cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
				cout << " ������" << of.m_orderData[i]["roomId"];
				string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				else if (of.m_orderData[i]["status"] == "-1")
				{
					status += "���δͨ����ԤԼʧ��";
				}
				else
				{
					status += "ԤԼ��ȡ��";
				}
				cout << status << endl;

			}
		}

		system("pause");
		system("cls");
}



// �鿴����ԤԼ
void Developer::showAllBooking()
{
		OrderFile of;
		if (of.m_Size == 0)
		{
			cout << "��ԤԼ��¼" << endl;
			system("pause");
			system("cls");
			return;
		}

		for (int i = 0; i < of.m_Size; i++)
		{
			cout << i + 1 << "�� ";

			cout << "ԤԼ���ڣ� ��" << of.m_orderData[i]["date"];
			cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << " ���ţ�" << of.m_orderData[i]["devId"];
			cout << " ������" << of.m_orderData[i]["devName"];
			cout << " �����ң�" << of.m_orderData[i]["roomId"];
			string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "���δͨ����ԤԼʧ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}

		system("pause");
		system("cls");


}

// ȡ��ԤԼ
void Developer::cancelBooking()
{
		OrderFile of;
		if (of.m_Size == 0)
		{
			cout << "��ԤԼ��¼" << endl;
			system("pause");
			system("cls");
			return;
		}
		cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;

		vector<int>v;
		int index = 1;
		for (int i = 0; i < of.m_Size; i++)
		{
			if (atoi(of.m_orderData[i]["devId"].c_str()) == this->m_DevId)
			{
				if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
				{
					v.push_back(i);
					cout << index++ << "�� ";
					cout << "ԤԼ���ڣ� ��" << of.m_orderData[i]["date"];
					cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
					cout << " ������" << of.m_orderData[i]["roomId"];
					string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ  -1 ԤԼʧ��
					if (of.m_orderData[i]["status"] == "1")
					{
						status += "�����";
					}
					else if (of.m_orderData[i]["status"] == "2")
					{
						status += "ԤԼ�ɹ�";
					}
					cout << status << endl;

				}
			}
		}
		cout << "������ȡ���ļ�¼,0������" << endl;
		int select = 0;
		while (true)
		{
			cin >> select;
			if (select >= 0 && select <= v.size())
			{
				if (select == 0)
				{
					break;
				}
				else
				{
					//	cout << "��¼����λ�ã� " << v[select - 1] << endl;
					of.m_orderData[v[select - 1]]["status"] = "0";
					of.updateOrder();
					cout << "��ȡ��ԤԼ" << endl;
					break;
				}

			}
			cout << "������������������" << endl;
		}

		system("pause");
		system("cls");
	}


