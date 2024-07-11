#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct NhanVien
{
	string manv;
	string hotennv;
	int namvao;
	int namsinh;
	//methods
	void input();
	void print();
	int getCurrentYear();
	int calAge();
	int calThamnien();
};

void NhanVien::input()
{
	cout << "Nhap ma nv: "; cin >> manv;
	cin.ignore();
	cout << "Nhap ho ten nv: "; getline(cin, hotennv);
	cout << "Nhap nam vao: "; cin >> namvao;
	cout << "Nhap nam sinh: "; cin >> namsinh;
}

void NhanVien::print()
{
	cout << "Ma nv: " << manv << endl;
	cout << "Ho ten nv: " << hotennv << endl;
	cout << "Nam vao: " << namvao << endl;
	cout << "Nam sinh: " << namsinh << endl;
}

int NhanVien::getCurrentYear()
{
	time_t now = std::time(0);
	tm* timeconvert = std::localtime(&now);
	int year = timeconvert->tm_year + 1900;
	return year;
}

int NhanVien::calAge()
{
	return getCurrentYear() - namsinh;
}

int NhanVien::calThamnien()
{
	return getCurrentYear() - namvao;
}

int main()
{
	NhanVien nv;
	cout << "Nhap thong tin nhan vien:\n"; nv.input();
	cout << "Thong tin nhan vien:\n"; nv.print();
	cout << "Tuoi: " << nv.calAge() << endl;
	cout << "Tham niem lam viec: " << nv.calThamnien() << " nam" << endl;

	system("pause");
	return 0;
}