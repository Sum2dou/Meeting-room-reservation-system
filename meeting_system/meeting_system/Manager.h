#pragma once
#include<iostream>
using namespace std;
#include "identity.h"
#include <vector>
#include"Developer.h"
#include"AdminStaff.h"

class Manager :public Identity
{
public:

	// 默认构造
	Manager();

	// 有参构造  管理员姓名，密码
	Manager(string name, string pwd);

	// 选择菜单
	virtual void openMenu();

	// 添加账号  
	void addPerson();

	// 查看账号
	void showPerson();

	// 查看会议室信息
	void infoMeetingRoom();
	void showMeetingRoom();


	// 清空预约记录
	void cleanFile();
	// 初始化容器
	void initVector();

	// 研发人员容器
	vector<Developer> vDev;

	// 行政人员容器
	vector<AdminStaff> vAdmsta;

	// 会议室容器
	vector<MeetingRoom> vMee;


	
	int safe = 1;

	// 检测重复 参数:(传入id，传入类型) 返回值：(true 代表有重复，false代表没有重复)
	bool checkRepeat(int id, int type);


};
