#include <iostream>
#include <math.h>
using namespace std;

struct PhanSo
{
	//properties
	int tuso;
	int mauso;
	//methods
	void input();
	void print();
	PhanSo tong(PhanSo ps2);
	PhanSo hieu(PhanSo ps2);
	PhanSo tich(PhanSo ps2);
	PhanSo thuong(PhanSo ps2);
	PhanSo rutgon();
};

void PhanSo::input()
{
	cout << "Nhap tu so: "; cin >> tuso;
	do
	{
		cout << "Nhap mau so: "; cin >> mauso;
		if (mauso == 0)
			cout << "Mau so phai khac 0. Nhap lai!\n";
	} while (mauso == 0);
}

void PhanSo::print()
{
	if (mauso == 0)
		return;
	if (tuso == 0)
		cout << 0;
	else if(tuso == mauso)
		cout << 1;
	else
		cout << tuso << '/' << mauso;
}

PhanSo PhanSo::tong(PhanSo ps2)
{
	PhanSo kq;
	if (mauso == ps2.mauso)
	{
		kq.mauso = mauso;
		kq.tuso = tuso + ps2.tuso;
	}
	else
	{
		kq.mauso = mauso * ps2.mauso;
		kq.tuso = tuso * ps2.mauso + ps2.tuso * mauso;
	}
	return kq.rutgon();
}

PhanSo PhanSo::hieu(PhanSo ps2)
{
	PhanSo kq;
	if (mauso == ps2.mauso)
	{
		kq.mauso = mauso;
		kq.tuso = tuso - ps2.tuso;
	}
	else
	{
		kq.mauso = mauso * ps2.mauso;
		kq.tuso = tuso * ps2.mauso - ps2.tuso * mauso;
	}
	return kq.rutgon();
}

PhanSo PhanSo::tich(PhanSo ps2)
{
	PhanSo kq;
	kq.tuso = tuso * ps2.tuso;
	kq.mauso = mauso * ps2.mauso;
	return kq.rutgon();
}

PhanSo PhanSo::thuong(PhanSo ps2)
{
	PhanSo kq;
	if (ps2.tuso != 0)
	{
		kq.tuso = tuso * ps2.mauso;
		kq.mauso = mauso * ps2.tuso;
		return kq.rutgon();
	}
	else cout << "Error! Phan so chia bang 0\n";
	kq.tuso = 0;
	kq.mauso = 0;
	return kq.rutgon();
}

PhanSo PhanSo::rutgon()
{
	PhanSo kq;
	kq.tuso = this->tuso;
	kq.mauso = this->mauso;
	int a = abs(tuso);
	int b = abs(mauso);
	if (a != 0)
	{
		while (a != b)
		{
			if (a > b)
				a = a - b;
			else
				b = b - a;
		}
		kq.tuso = tuso / a;
		kq.mauso = mauso / a;
	}
	return kq;
}

int main()
{
	PhanSo ps1, ps2, tong, hieu, tich, thuong;
	cout << "Nhap phan so thu 1:\n"; ps1.input();
	cout << "Nhap phan so thu 2:\n"; ps2.input();
	cout << "\nTong 2 phan so: "; 
	tong = ps1.tong(ps2);
	tong.print();
	cout << "\nHieu 2 phan so: "; 
	hieu = ps1.hieu(ps2);
	hieu.print();
	cout << "\nTich 2 phan so: "; 
	tich = ps1.tich(ps2);
	tich.print();
	cout << "\nThuong 2 phan so: "; 
	thuong = ps1.thuong(ps2);
	thuong.print();
	cout << endl;
	system("pause");
	return 0;
}