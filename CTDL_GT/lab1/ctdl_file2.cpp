#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin("BT1.txt");
	if (fin.is_open())
	{
		int m;
		fin >> m;
		if (!fin.fail())
			cout << "Ket qua m = " << m << endl;
		else
			cout << "Khong co ket qua!\n";
		fin.close();
	}
	else
		cout << "Khong mo duoc file!\n";

	system("pause");
	return 0;
}