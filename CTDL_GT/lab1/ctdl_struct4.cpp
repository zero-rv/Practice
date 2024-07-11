#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <math.h>
#define MAX 45
using namespace std;

// Struct SinhVien & functions
struct SinhVien
{
	string mssv;
	string hoten;
	string diachi;
	int namsinh;
	double diem[3];// Toan | Van | Ngoai Ngu
	//methods
	void input();
	void print();
	double calDTB();
	string setRanking();
};

void SinhVien::input()
{
	cout << "Mssv: "; cin >> mssv;
	cin.ignore();
	cout << "Ho ten: "; getline(cin, hoten);
	cout << "Dia chi: "; getline(cin, diachi);
	cout << "Nam sinh: "; cin >> namsinh;
	cout << "Diem (Toan Van N.N): ";
	for (int i = 0; i < 3; i++)
		cin >> diem[i];
}

void SinhVien::print()
{
	cout << "Mssv: " << mssv;
	cout << "\nHo ten: " << hoten;
	cout << "\nDia chi: " << diachi;
	cout << "\nNam sinh: " << namsinh;
	cout << "\nDiem (Toan Van N.N): ";
	for (int i = 0; i < 3; i++)
		cout << diem[i] << " ";
	cout << endl;
}

double SinhVien::calDTB()
{
	double sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum += diem[i];
		if (i == 1)
			sum *= 2;
	}
	return round((sum / 5) * 10) / 10;
}

string SinhVien::setRanking()
{
	double result = calDTB();
	if (result >= 8)
		return "Gioi";
	if (result >= 6.5)
		return "Kha";
	if (result >= 5)
		return "TB";
	return "Duoi TB";
}
// Struct DSSV & functions
struct DSSV
{
	SinhVien dssv[MAX];
	int n = 0;
	//methods
	void inputdssv();
	void printdssv();
	void print1sv();
};

void DSSV::inputdssv()
{
	int currentindex = 0;
	do
	{
		cout << "Nhap thong tin sv thu " << ++n <<":\n";
		dssv[currentindex++].input();
		cout << "Tiep tuc? (1/0): ";
		int select;
		cin >> select;
		if (!select)
			break;
	} while (n != MAX);
}

void DSSV::printdssv()
{
	for (int i = 0; i < n; i++)
	{
		cout << "Sinh vien thu " << i + 1 << endl;
		dssv[i].print();
	}
}

void DSSV::print1sv()
{
	int select;
	do
	{
		cout << "Nhap so thu tu cua sinh vien muon xuat thong tin (1 - " << n << "): ";
		cin >> select;
		if (select <= 0 || select > n)
			cout << "Khong hop le, nhap lai!\n";
	} while (select <= 0 || select > n);
	cout << "Thong tin sinh vien thu " << select << endl;
	dssv[--select].print();
}


int main()
{
	DSSV lop;
	cout << "----------Nhap thong tin sinh vien---------------------\n";
	lop.inputdssv();
	//Xuat thong tin do nguoi dung nhap
	lop.print1sv();
	//Xuat dssv gom mssv, hoten, dtb
	cout << "----------DSSV va xep loai cua tung sinh vien----------\n";
	lop.printdssv();
	system("pause");
	return 0;
}