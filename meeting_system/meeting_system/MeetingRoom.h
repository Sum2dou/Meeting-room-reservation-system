#pragma once
#include<iostream>
using namespace std;
// 会议室类
class MeetingRoom
{
public:

	int m_MeeId;  // 会议室id号
	string m_Name;//会议室名称
	int m_MaxNum;  // 会议室最大容量
	string m_NeedValid;//是否需要预约
	int curnum=0;//会议室当前容量
		


};
#pragma once
