#pragma once
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "identity.h"

class AdminStaff :public Identity
{
public:

	// 默认构造
	AdminStaff();

	// 有参构造 (职工编号，姓名，密码)
	AdminStaff(int empId, string name, string pwd);

	// 菜单界面
	virtual void openMenu();

	// 查看所有预约
	void showAllBooking();

	// 审核预约
	void validBooking();

	int m_AdmId;  // 编号

};
