#include "Developer.h"
#include <fstream>
#include <iostream>
#include <Algorithm>
#include"GlobalFile.h"
#include"MeetingRoom.h"
#include"orderfile.h"
// 默认构造
Developer::Developer()
{
}

// 有参构造(研发工号、姓名、密码)
Developer::Developer(int id, string name, string pwd)
{
	// 初始化属性
	this->m_DevId = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

// 菜单界面
void Developer::openMenu()
{
		cout << "欢迎研发人员：" << this->m_Name << "登录！" << endl;
		cout << "\t\t ----------------------------------\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|          1.申请预约              |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|          2.查看我的预约          |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|          3.查看所有预约          |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|          4.取消预约              |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|          0.注销登录              |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t ----------------------------------\n";
		cout << "请选择您的操作： " << endl;


}

void Developer::infoMeetingRoom()
{
	// 获取会议室信息
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


// 查看会议室信息
void Developer::showMeetingRoom()
{

	cout << "会议室信息如下： " << endl;
	infoMeetingRoom();
	for (vector<MeetingRoom>::iterator it = vMee.begin(); it != vMee.end(); it++)
	{
		cout << "会议室编号：" << it->m_MeeId << " 会议室名称： " << it->m_Name << " 会议室最大容量： " << it->m_MaxNum << " 该会议室当前容量： " << it->curnum << " 是否需要预约： " << it->m_NeedValid << endl;
	}
	cout << "当前会议室数量为： " << vMee.size() << endl;


}



// 申请预约
void Developer::applyBooking()
{
	cout << "会议室开放时间为周一至周五！" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;
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
		cout << "输入有误，请重新输入" << endl;
	}


	cout << "请输入申请预约的时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	
	cout << "当前会议室信息为：" << endl;
	showMeetingRoom();
	cout << "请选择会议室：" << endl;
	
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
			cout << "输入有误，请重新输入/该会议已被预约完" << endl;
		}
		
	}
	cout << "预约成功！正在审核中" << endl;

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

// 查看我的预约
void Developer::showMyBooking()
{
		OrderFile of;
		if (of.m_Size == 0)
		{
			cout << "无预约记录" << endl;
			system("pause");
			system("cls");
			return;
		}
		for (int i = 0; i < of.m_Size; i++)
		{
			if (atoi(of.m_orderData[i]["devId"].c_str()) == this->m_DevId)
			{
				cout << "预约日期： 周" << of.m_orderData[i]["date"];
				cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
				cout << " 机房：" << of.m_orderData[i]["roomId"];
				string status = " 状态： ";  // 0 取消的预约   1 审核中   2 已预约 -1 预约失败
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "预约成功";
				}
				else if (of.m_orderData[i]["status"] == "-1")
				{
					status += "审核未通过，预约失败";
				}
				else
				{
					status += "预约已取消";
				}
				cout << status << endl;

			}
		}

		system("pause");
		system("cls");
}



// 查看所有预约
void Developer::showAllBooking()
{
		OrderFile of;
		if (of.m_Size == 0)
		{
			cout << "无预约记录" << endl;
			system("pause");
			system("cls");
			return;
		}

		for (int i = 0; i < of.m_Size; i++)
		{
			cout << i + 1 << "、 ";

			cout << "预约日期： 周" << of.m_orderData[i]["date"];
			cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 工号：" << of.m_orderData[i]["devId"];
			cout << " 姓名：" << of.m_orderData[i]["devName"];
			cout << " 会议室：" << of.m_orderData[i]["roomId"];
			string status = " 状态： ";  // 0 取消的预约   1 审核中   2 已预约 -1 预约失败
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "审核未通过，预约失败";
			}
			else
			{
				status += "预约已取消";
			}
			cout << status << endl;
		}

		system("pause");
		system("cls");


}

// 取消预约
void Developer::cancelBooking()
{
		OrderFile of;
		if (of.m_Size == 0)
		{
			cout << "无预约记录" << endl;
			system("pause");
			system("cls");
			return;
		}
		cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;

		vector<int>v;
		int index = 1;
		for (int i = 0; i < of.m_Size; i++)
		{
			if (atoi(of.m_orderData[i]["devId"].c_str()) == this->m_DevId)
			{
				if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
				{
					v.push_back(i);
					cout << index++ << "、 ";
					cout << "预约日期： 周" << of.m_orderData[i]["date"];
					cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
					cout << " 机房：" << of.m_orderData[i]["roomId"];
					string status = " 状态： ";  // 0 取消的预约   1 审核中   2 已预约  -1 预约失败
					if (of.m_orderData[i]["status"] == "1")
					{
						status += "审核中";
					}
					else if (of.m_orderData[i]["status"] == "2")
					{
						status += "预约成功";
					}
					cout << status << endl;

				}
			}
		}
		cout << "请输入取消的记录,0代表返回" << endl;
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
					//	cout << "记录所在位置： " << v[select - 1] << endl;
					of.m_orderData[v[select - 1]]["status"] = "0";
					of.updateOrder();
					cout << "已取消预约" << endl;
					break;
				}

			}
			cout << "输入有误，请重新输入" << endl;
		}

		system("pause");
		system("cls");
	}


