#include "globalFile.h"
#include "identity.h"
#include <fstream>
#include <string>
#include "Developer.h"
#include "AdminStaff.h"
#include "Manager.h"
#include<memory>


// 管理员子菜单
void managerMenu(Identity*& manager)
{
	while (true)
	{
		// 管理员菜单
		manager->openMenu();

		Manager* man = (Manager*)manager;
		int select = 0;

		cin >> select;

		if (select == 1)   // 添加账号
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2)  // 查看账号
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3)  // 查看会议室
		{
			cout << "查看会议室" << endl;
			man->showMeetingRoom();
		}
		else if (select == 4)  // 清空预约
		{
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


// 研发人员子菜单
void developerMenu(Identity*& developer)
{
	while (true)
	{
		// 研发人员菜单
		developer->openMenu();

		Developer* dev = (Developer*)developer;
		int select = 0;

		cin >> select;

		if (select == 1)  // 申请预约
		{
			dev->applyBooking();
		}
		else if (select == 2)  // 查看自身预约
		{
			dev->showMyBooking();
		}
		else if (select == 3)  // 查看所有预约
		{
			dev->showAllBooking();
		}
		else if (select == 4)  // 取消预约
		{
			dev->cancelBooking();
		}
		else
		{
			delete developer;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


// 行政人员菜单
void adminstaffMenu(Identity*& adminstaff)
{
	while (true)
	{
		// 教师菜单
		adminstaff->openMenu();

		AdminStaff* adm = (AdminStaff*)adminstaff;
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			// 查看所有预约
			adm->showAllBooking();
		}
		else if (select == 2)
		{
			// 审核预约
			adm->validBooking();
		}
		else
		{
			delete adminstaff;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}



// 登录功能
void LoginIn(string fileName, int type)
{

	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	// 文件不存在情况
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1)	// 研发人员登录
	{
		cout << "请输入你的研发工号" << endl;
		cin >> id;
	}
	else if (type == 2)  // 行政人员登录
	{
		cout << "请输入你的行政工号" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码： " << endl;
	cin >> pwd;


	if (type == 1)
	{
		// 研发人员登录验证
		int fId;
		string fUserName;
		string fPwd;
		while (ifs >> fId && ifs >> fUserName && ifs >> fPwd)
		{
			if (id == fId && name == fUserName && pwd == fPwd)
			{
				cout << "研发人员验证登录成功!" << endl;
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
		// 行政人员登录验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "行政人员验证登录成功!" << endl;
				system("pause");
				system("cls");
				//std::shared_ptr<AdminStaff> person(new AdminStaff(id, name, pwd));
				person = new AdminStaff(id, name, pwd);
				//进入行政子菜单
				adminstaffMenu(person);
				return;
			}
		}

	}
	else if (type == 3)
	{
		// 管理员登录验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "验证登录成功!" << endl;
				// 登录成功后，按任意键进入管理员界面
				system("pause");
				system("cls");
				// 创建管理员对象
				//std::shared_ptr<Manager> person(new Manager(name, pwd));
				person = new Manager(name, pwd);
				// 进入管理员子菜单
				managerMenu(person);
				return;
			}
		}

	}
	cout << "验证登录失败!" << endl;

	system("pause");
	system("cls");
	return;
}



