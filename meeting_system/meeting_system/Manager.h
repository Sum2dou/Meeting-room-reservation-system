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

	// Ĭ�Ϲ���
	Manager();

	// �вι���  ����Ա����������
	Manager(string name, string pwd);

	// ѡ��˵�
	virtual void openMenu();

	// ����˺�  
	void addPerson();

	// �鿴�˺�
	void showPerson();

	// �鿴��������Ϣ
	void infoMeetingRoom();
	void showMeetingRoom();


	// ���ԤԼ��¼
	void cleanFile();
	// ��ʼ������
	void initVector();

	// �з���Ա����
	vector<Developer> vDev;

	// ������Ա����
	vector<AdminStaff> vAdmsta;

	// ����������
	vector<MeetingRoom> vMee;


	
	int safe = 1;

	// ����ظ� ����:(����id����������) ����ֵ��(true �������ظ���false����û���ظ�)
	bool checkRepeat(int id, int type);


};
