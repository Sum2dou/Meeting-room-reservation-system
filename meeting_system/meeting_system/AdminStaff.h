#pragma once
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "identity.h"

class AdminStaff :public Identity
{
public:

	// Ĭ�Ϲ���
	AdminStaff();

	// �вι��� (ְ����ţ�����������)
	AdminStaff(int empId, string name, string pwd);

	// �˵�����
	virtual void openMenu();

	// �鿴����ԤԼ
	void showAllBooking();

	// ���ԤԼ
	void validBooking();

	int m_AdmId;  // ���

};
