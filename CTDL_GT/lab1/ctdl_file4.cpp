#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
	char chuoi[21];
	cout << "Nhap mot chuoi bat ky, toi da 20 ky tu: ";
	cin.getline(chuoi, 20);
	ofstream fout("BT4.txt");
	for (int i = 0; i < strlen(chuoi); i++)
		fout << (char)toupper(chuoi[i]);
	fout.close();

	system("pause");
	return 0;

}