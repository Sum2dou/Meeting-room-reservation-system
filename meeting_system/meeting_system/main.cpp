#include <iostream>
#include <unordered_map>
#include <memory>
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include"booking.h"
using namespace std;
int main() 
{

    int select = 0;

    while (true)
    {
        std::cout << endl << "��ѡ�������ݣ�" << endl;
        std::cout << "\t\t -------------------------------\n";
        std::cout << "\t\t|                               |\n";
        std::cout << "\t\t|          1.�з���Ա           |\n";
        std::cout << "\t\t|                               |\n";
        std::cout << "\t\t|          2.������Ա           |\n";
        std::cout << "\t\t|                               |\n";
        std::cout << "\t\t|          3.ϵͳ����Ա         |\n";
        std::cout << "\t\t|                               |\n";
        std::cout << "\t\t|          0.��    ��           |\n";
        std::cout << "\t\t|                               |\n";
        std::cout << "\t\t -------------------------------\n";
        std::cout << "��������ѡ��: ";

        cin >> select;  // �����û�ѡ��

        switch (select)
        {
        case 1:  //  1.�з���Ա
            LoginIn(DEVELOPER_FILE,1);
            break;
        case 2:  //  2.������Ա
            LoginIn(ADMINSTAFF_FILE, 2);
            break;
        case 3:  // ����Ա���
            LoginIn(MANAGER_FILE, 3);
            break;
        case 0:  // �˳�ϵͳ
            cout << "��ӭ��һ��ʹ��ϵͳ" << endl;
            system("pause");
            return 0;
            break;
        default:
            std::cout << "��������������ѡ��" << endl;
            std::system("pause");
            std::system("cls");
            break;
        }

    }
    system("pause");
    return 0;
}
