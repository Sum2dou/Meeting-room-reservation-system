#pragma once
#include<iostream>
using namespace std;
#include "identity.h"
#include"MeetingRoom.h"
#include<vector>

// �з���Ա��
class Developer :public Identity
{
public:
	// Ĭ�Ϲ���
	Developer();

	// �вι���(���š�����������)
	Developer(int id, string name, string pwd);

	// �˵�����
	virtual void openMenu();
	void infoMeetingRoom();
	void showMeetingRoom();
	// ����ԤԼ
	void applyBooking();

	// �鿴�ҵ�ԤԼ
	void showMyBooking();

	// �鿴����ԤԼ
	void showAllBooking();

	// ȡ��ԤԼ
	void cancelBooking();

	// �з���Ա����
	int m_DevId;
	
	// ����������
	vector<MeetingRoom> vMee;
	int safe=0;//��֤��������Ϣ���������ļ���ȡ���ı�

};
#pragma once
#pragma once
