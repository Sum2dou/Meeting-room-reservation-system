#include "Manager.h"
#include "Developer.h"
#include "AdminStaff.h"
#include <fstream>
#include <iostream>
#include <Algorithm>
#include"GlobalFile.h"
#include <vector>
#include"MeetingRoom.h"

// 默认构造
Manager::Manager()
{
}

// 有参构造
Manager::Manager(string name, string pwd)
{
		this->m_Name = name;
		this->m_Pwd = pwd;
		// 初始化容器
		this->initVector();
}

// 选择菜单
void Manager::openMenu()
{
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看会议室信息      |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

// 添加账号  
void Manager::addPerson()
{

		cout << "请输入添加账号的类型" << endl;
		cout << "1、添加研发人员" << endl;
		cout << "2、添加行政人员" << endl;
		string errorTip;  // 重复错误提示
		string fileName;
		string tip;
		ofstream ofs;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			fileName = DEVELOPER_FILE;
			tip = "请输入研发编号： ";
			errorTip = "研发编号重复，请重新输入";
		}
		else
		{
			fileName = ADMINSTAFF_FILE;
			tip = "请输入行政编号：";
			errorTip = "职工号重复，请重新输入";
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

			if (ret)  // 有重复
			{
				cout << errorTip << endl;
			}
			else
			{
				break;
			}
		}

		cout << "请输入姓名： " << endl;
		cin >> name;

		cout << "请输入用户名： " << endl;
		cin >> name;

		cout << "请输入密码： " << endl;
		cin >> pwd;
		

		ofs << id << " " << name << " " << username<<" "<< " " << pwd << " " << endl;
		cout << "添加成功" << endl;
		// 初始化容器
		this->initVector();

		system("pause");
		system("cls");

		ofs.close();

}
void printDeveloper(Developer& s)
{
	cout << "研发工号： " << s.m_DevId << " 姓名： " << s.m_Name << " 密码：" << s.m_Pwd << endl;
}
void printAdminStaff(AdminStaff& t)
{
	cout << "行政工号： " << t.m_AdmId << " 姓名： " << t.m_Name << " 密码：" << t.m_Pwd << endl;
}
// 查看账号
void Manager::showPerson()
{
		cout << "请选择查看内容：" << endl;
		cout << "1、查看所有研发人员" << endl;
		cout << "2、查看所有行政人员" << endl;

		int select = 0;

		cin >> select;

		if (select == 1)
		{
			cout << "所有研发人员的信息如下： " << endl;
			for_each(vDev.begin(), vDev.end(), printDeveloper);
		}
		else
		{
			cout << "所有行政人员的信息如下： " << endl;
			for_each(vAdmsta.begin(), vAdmsta.end(), printAdminStaff);
		}
		system("pause");
		system("cls");
	

}

void Manager::infoMeetingRoom()
{
	// 获取会议室信息
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
		cout << "当前会议室数量为： " << vMee.size() << endl;

		ifs.close();
	}
	
}


// 查看会议室信息
void Manager::showMeetingRoom()
{

	cout << "会议室信息如下： " << endl;
	infoMeetingRoom();
	for (vector<MeetingRoom>::iterator it = vMee.begin(); it != vMee.end(); it++)
	{
		cout << "会议室编号：" << it->m_MeeId << " 会议室名称： " << it->m_Name << " 会议室最大容量： " << it->m_MaxNum << " 是否需要预约： " << it->m_NeedValid << endl;
	}
	system("pause");
	system("cls");


}

// 清空预约记录
void Manager::cleanFile()
{
		ofstream ofs(BOOKING_FILE, ios::trunc);
		ofs.close();

		cout << "清空成功！" << endl;
		system("pause");
		system("cls");
	
}


void Manager::initVector()
{
	// 读取研发人员文件中信息
	ifstream ifs;
	ifs.open(DEVELOPER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	vDev.clear();
	vAdmsta.clear();

	Developer s;
	while (ifs >> s.m_DevId && ifs >> s.m_Name&& ifs >> s.m_Pwd)
	{
		vDev.push_back(s);
	}
	cout << "当前研发人员数量为： " << vDev.size() << endl;
	ifs.close(); //研发人员初始化

	// 读取行政人员文件信息
	ifs.open(ADMINSTAFF_FILE, ios::in);

	AdminStaff t;
	while (ifs >> t.m_AdmId&& ifs >> t.m_Name&& ifs >> t.m_Pwd)
	{
		vAdmsta.push_back(t);
	}
	cout << "当前行政人员数量为： " << vAdmsta.size() << endl;

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
