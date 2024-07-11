#include <iostream>
#include <string>
using namespace std;

struct PhongBan
{
	string mapb;
	string tenpb;
};

void input(PhongBan &pb)
{
	cout << "Nhap ma phong ban: "; cin >> pb.mapb;
	cin.ignore();
	cout << "Nhap ten phong ban: "; getline(cin, pb.tenpb);
}

void print(PhongBan pb)
{
	cout << "Ma phong ban: " << pb.mapb << endl;
	cout << "Ten phong ban: " << pb.tenpb << endl;
}

int main()
{
	PhongBan phongban;
	cout << "Nhap thong tin 1 phong ban:\n";
	input(phongban);
	cout << "Thong tin phong ban:\n";
	print(phongban);

	system("pause");
	return 0;
}