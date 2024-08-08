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
        std::cout << endl << "请选择你的身份：" << endl;
        std::cout << "\t\t -------------------------------\n";
        std::cout << "\t\t|                               |\n";
        std::cout << "\t\t|          1.研发人员           |\n";
        std::cout << "\t\t|                               |\n";
        std::cout << "\t\t|          2.行政人员           |\n";
        std::cout << "\t\t|                               |\n";
        std::cout << "\t\t|          3.系统管理员         |\n";
        std::cout << "\t\t|                               |\n";
        std::cout << "\t\t|          0.退    出           |\n";
        std::cout << "\t\t|                               |\n";
        std::cout << "\t\t -------------------------------\n";
        std::cout << "输入您的选择: ";

        cin >> select;  // 接受用户选择

        switch (select)
        {
        case 1:  //  1.研发人员
            LoginIn(DEVELOPER_FILE,1);
            break;
        case 2:  //  2.行政人员
            LoginIn(ADMINSTAFF_FILE, 2);
            break;
        case 3:  // 管理员身份
            LoginIn(MANAGER_FILE, 3);
            break;
        case 0:  // 退出系统
            cout << "欢迎下一次使用系统" << endl;
            system("pause");
            return 0;
            break;
        default:
            std::cout << "输入有误，请重新选择！" << endl;
            std::system("pause");
            std::system("cls");
            break;
        }

    }
    system("pause");
    return 0;
}
