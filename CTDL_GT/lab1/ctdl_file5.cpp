#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int count = 0;
	char chuoi;
	ifstream fin("BT4.txt");
	if (fin.is_open())
	{
		while (fin.get(chuoi))
			count++;
		cout << "Tong so ky tu trong file: " << count << endl;
		fin.close();
	}
	else
		cout << "Khong mo duoc file!\n";
	system("pause");
	return 0;
}