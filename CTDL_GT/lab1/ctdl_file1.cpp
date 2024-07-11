#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int a, b;
	cout << "Nhap 2 so nguyen a va b: ";
	cin >> a >> b;
	ofstream fout("BT1.txt");
	fout << a + b;
	fout.close();
	cout << "DONE!\n";

	system("pause");
	return 0;
}