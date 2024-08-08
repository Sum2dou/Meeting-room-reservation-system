#include"orderfile.h"
#include<fstream>
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(BOOKING_FILE, ios::in);

	string date;      // ����
	string interval;  // ʱ���
	string devId;     // ���
	string devName;   // ����
	string roomId;    // �����ұ��
	string status;    // ԤԼ״̬


	this->m_Size = 0;  // ԤԼ��¼����

	while (ifs >> date && ifs >> interval && ifs >> devId && ifs >> devName && ifs >> roomId && ifs >> status)
	{
		

		string key;
		string value;
		map<string, string> m;

		int pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = devId.find(":");
		if (pos != -1)
		{
			key = devId.substr(0, pos);
			value = devId.substr(pos + 1, devId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = devName.find(":");
		if (pos != -1)
		{
			key = devName.substr(0, pos);
			value = devName.substr(pos + 1, devName.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = roomId.find(":");
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}


		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}

	

	ifs.close();
}
void OrderFile::updateOrder()
{
	if (this->m_Size == 0)
	{
		return;
	}

	ofstream ofs(BOOKING_FILE, ios::out | ios::trunc);
	for (int i = 0; i < m_Size; i++)
	{
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["devId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["devName"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}
	ofs.close();
}

