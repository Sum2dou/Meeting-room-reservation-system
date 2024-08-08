#pragma once
#include<iostream>
using namespace std;
#include "identity.h"
#include"MeetingRoom.h"
#include<vector>

// 研发人员类
class Developer :public Identity
{
public:
	// 默认构造
	Developer();

	// 有参构造(工号、姓名、密码)
	Developer(int id, string name, string pwd);

	// 菜单界面
	virtual void openMenu();
	void infoMeetingRoom();
	void showMeetingRoom();
	// 申请预约
	void applyBooking();

	// 查看我的预约
	void showMyBooking();

	// 查看所有预约
	void showAllBooking();

	// 取消预约
	void cancelBooking();

	// 研发人员工号
	int m_DevId;
	
	// 会议室容器
	vector<MeetingRoom> vMee;
	int safe=0;//保证会议室信息不会随着文件读取而改变

};
#pragma once
#pragma once
