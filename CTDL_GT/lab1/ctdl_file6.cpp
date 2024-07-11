#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#define MAX 100
using namespace std;


//functions
int getCurrentYear()
{
	time_t now = std::time(0);
	tm* timeconvert = std::localtime(&now);
	int year = timeconvert->tm_year + 1900;
	return year;
}

int isNamNhuan(int y)
{
	if (y % 4 == 0 && y % 100 != 0)
		return 1;
	if (y % 100 == 0 && y % 400 == 0)
		return 1;
	return 0;
}

int getDate(int m, int y)
{
	switch (m)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
	case 4: case 6: case 9: case 11:
		return 30;
	case 2:
		if (isNamNhuan(y))
			return 29;
		else
			return 28;
	}
}

//Struct NTN & functions
struct NTN
{
	int d, m, y; //date, month, year
	//methods
	void input();
	void print();
	int isValid();
};

void NTN::input()
{
	cin >> d >> m >> y;
}

void NTN::print()
{
	cout << d << '/' << m << '/' << y;
}

int NTN::isValid()
{
	if (y <= 0 || y > getCurrentYear())
		return 0;
	if (m < 1 || m > 12)
		return 0;
	if (d < 1 || d > getDate(m, y))
		return 0;
	return 1;
}

//Struct Lop & functions
struct Lop
{
	char malop[20];
	char tenlop[20];
	char tenkhoa[30];
	int soluong;
	NTN ngaykg;
	//methods
	void input();
	void print();
};

void Lop::input()
{
	cout << "Ma lop: "; cin >> malop;
	cin.ignore();
	cout << "Ten lop: "; cin.getline(tenlop, 20);
	cout << "Ten khoa: "; cin.getline(tenkhoa, 20);
	cout << "So sinh vien: "; cin >> soluong;
	cin.ignore();
	do
	{
		cout << "Ngay khai giang (dd/mm/yyyy): "; ngaykg.input();
		if (!ngaykg.isValid())
			cout << "Ngay thang nam khong hop le!\n";
	} while (!ngaykg.isValid());
}

void Lop::print()
{
	cout << "Ma lop: " << malop;
	cout << "\nTen lop: " << tenlop;
	cout << "\nTen khoa: " << tenkhoa;
	cout << "\nSo luong sinh vien: " << soluong;
	cout << "\nNgay khai giang: "; ngaykg.print();
	cout << endl;
}

//Struct DSLop & functions
struct DSLop
{
	Lop list[MAX];
	int n = 0;
	//methods
	void inputList();
	void printList();
	void inputListFile();
	void printListFile(char *tenkhoa);
	void delete_1_class();
	void deleteClasses(char *tenkhoa);
	
	int sumSoluong(char *tenkhoa);
	int countLop(char *tenkhoa);
};

void DSLop::inputList()
{
	int currentindex = 0;
	do
	{
		cout << "Nhap thong tin lop thu " << ++n << ":\n";
		list[currentindex++].input();
		cout << "Tiep tuc nhap? (1/0): ";
		int select;
		cin >> select;
		if (!select)
			break;
	} while (n != MAX);
}

void DSLop::printList()
{
	for (int i = 0; i < n; i++)
	{
		cout << "Lop thu " << i + 1 << endl;
		list[i].print();
	}
}

void DSLop::inputListFile()
{
	ifstream fin("DanhSachLop.txt");
	if (fin.is_open())
	{
		fin >> n;
		for (int i = 0; i < n; i++)
		{
			Lop tmp;
			fin.getline(tmp.malop, 20, '#');
			fin.getline(tmp.tenlop, 20, '#');
			fin.getline(tmp.tenkhoa, 30, '#');
			fin >> tmp.soluong;
			int date[3];
			char read_data[5];
			for (int k = 0; k < 3; k++)
			{
				fin.getline(read_data, 5, '/');
				date[k] = atoi(read_data);
			}
			tmp.ngaykg.d = date[0];
			tmp.ngaykg.m = date[1];
			tmp.ngaykg.y = date[2];
			list[i] = tmp;
		}
	}
	else
		cout << "Khong mo duoc file!\n";
}

void DSLop::printListFile(char* tenkhoa)
{
	ofstream fout("DanhSachLopTheoKhoa.txt");
	vector<Lop> result;
	for (int i = 0; i < n; i++)
		if (strcmp(list[i].tenkhoa, tenkhoa) == 0)
			result.push_back(list[i]);
	fout << result.size();
	for (int i = 0; i < result.size(); i++)
	{
		Lop tmp = result[i];
		fout << tmp.malop << '#'
			<< tmp.tenlop << '#'
			<< tmp.tenkhoa << '#'
			<< tmp.soluong << '#'
			<< tmp.ngaykg.d << '/'
			<< tmp.ngaykg.m << '/'
			<< tmp.ngaykg.y;
	}
}

void DSLop::delete_1_class()
{
	if (n != 0)
	{
		int vitri;
		do
		{
			cout << "Nhap vi tri lop muon xoa tu 1 den " << n << ": ";
			cin >> vitri;
			if (vitri < 1 || vitri > n)
			{
				cout << "Vi tri khong hop le. Tiep tuc? (1/0): ";
				int iscont;
				cin >> iscont;
				if (!iscont)
					return;
			}
		} while (vitri < 1 || vitri > n);
		for (int i = --vitri; i < n - 1; i++)
			list[i] = list[i + 1];
		n--;
	}
}

void DSLop::deleteClasses(char* tenkhoa)
{
	if (n != 0)
	{
		for (int k = 0; k < n; k++)
			if (strcmp(list[k].tenkhoa, tenkhoa) == 0)
			{
				for (int i = k; i < n - 1; i++)
					list[i] = list[i + 1];
				k--;
				n--;
			}
	}
}

int DSLop::sumSoluong(char *tenkhoa)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		if (strcmp(list[i].tenkhoa, tenkhoa) == 0)
			sum += list[i].soluong;
	return sum;
}

int DSLop::countLop(char *tenkhoa)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (strcmp(list[i].tenkhoa, tenkhoa) == 0)
			count++;
	return count;
}

// Main & Menu
int menu()
{
	int choice;
	cout << "========================= QUAN LY LOP =========================\n";
	cout << " 1. Nhap DS Lop tu ban phim                                    \n";
	cout << " 2. Xuat DS Lop ra man hinh                                    \n";
	cout << " 3. Nhap DS Lop tu tap tin                                     \n";
	cout << " 4. Xuat DS Lop thuoc khoa 'Kinh te va quan ly cong' ra tap tin\n";
	cout << " 5. Tinh tong so luong sv khoa CNTT                            \n";
	cout << " 6. Tinh tong so lop khoa Ngoai ngu                            \n";
	cout << " 7. Xoa 1 lop theo vi tri                                      \n";
	cout << " 8. Xoa cac lop thuoc khoa 'Co ban'                            \n";
	cout << " 0. Thoat chuong trinh                                         \n";
	cout << "===============================================================\n";
	cout << "Lua chon cua ban: "; cin >> choice;
	return choice;
}

int main()
{
	DSLop ds;
	char tenkhoa[30];

	while (true)
	{
		system("cls");
		int x = menu();
		system("cls");
		switch (x)
		{
		case 1:
			ds.inputList();
			break;
		case 2:
			ds.printList();
			break;
		case 3:
			ds.inputListFile();
			cout << "DONE!\n";
			break;
		case 4:
			strcpy(tenkhoa, "Kinh te va quan ly cong");
			ds.printListFile(tenkhoa);
			break;
		case 5:
			strcpy(tenkhoa, "Cong nghe thong tin");
			cout << "So sinh vien khoa CNTT: " << ds.sumSoluong(tenkhoa);
			break;
		case 6:
			strcpy(tenkhoa, "Ngoai ngu");
			cout << "So lop thuoc khoa Ngoai ngu: " << ds.countLop(tenkhoa);
			break;
		case 7:
			ds.delete_1_class();
			cout << "DONE!\n";
			break;
		case 8:
			strcpy(tenkhoa, "Co ban");
			ds.deleteClasses(tenkhoa);
			cout << "DONE!\n";
			break;
		case 0:
			cout << "Ban da thoat chuong trinh\n";
			return 0;
		default:
			cout << "Lua chon khong hop le!\n";
			break;
		}
		int is_cont;
		cout << "\nTiep tuc chuong trinh? (1/0): "; cin >> is_cont;
		if (!is_cont)
		{
			system("cls");
			cout << "Ban da thoat chuong trinh\n";
			break;
		}
	}
	system("pause");
	return 0;
}