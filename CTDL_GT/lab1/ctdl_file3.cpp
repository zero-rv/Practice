#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
	//Xuat du lieu ra file
	int a, b, c;
	cout << "Nhap 3 so nguyen a, b, c: ";
	cin >> a >> b >> c;
	ofstream fout("BT3.txt");
	fout << a << '#' << b << '#' << c;
	fout.close();
	system("pause");
	//Doc file, tinh trung binh cong
	char digit[20];
	double sum = 0;
	ifstream fin("BT3.txt");
	if (fin.is_open())
	{
		while(fin.getline(digit, 20, '#'))
		{
			double num = atof(digit);
			sum += num;
		}
		cout << "Ket qua trung binh cong = " << sum / 3 << endl;
		fin.close();
	}
	else
		cout << "Khong mo duoc file!\n";

	system("pause");
	return 0;
}