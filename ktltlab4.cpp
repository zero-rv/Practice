//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//#include <conio.h>
//
//using namespace std;
//
//void b5();
//
//int main()
//{
//back:
//	cout << "Switch: ";
//	int x;
//	cin >> x;
//	switch (x)
//	{
//	case 5:
//		b5();
//		goto back;
//	case 0:
//		break;
//	default:
//		goto back;
//	}
//	return 0;
//}
//
//void b5()
//{
//	int incorrect_count = 1;
//	retype:
//	string password = "";
//	char ps_char;
//	cout << "Nhap mat khau: ";
//	do
//	{
//		ps_char = _getch();
//		if (ps_char == '\r') { break; }
//		if (ps_char == '\b')
//		{
//			cout << "\b \b";
//			password.pop_back();
//		}
//		else
//		{
//			password += ps_char;
//			cout << "*";
//		}
//	} while (true);
//
//	if (password != "SinhVienCQ")
//	{
//		incorrect_count++;
//		if (incorrect_count <= 3)
//		{
//			cout << endl << "Nhap sai! Nhap lai!" << endl;
//			goto retype;
//		}
//		cout << endl << "Nhap sai mat khau 3 lan ----------> Pay acc!" << endl;
//	}
//	else cout << endl << "Dang nhap thanh cong" << endl;
//}
