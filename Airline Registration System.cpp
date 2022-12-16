#include <bits/stdc++.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

void mainMenu();

struct customer{
	char ID[20];
	char name[20];
	char add[50];
	char email[50];
	long mobile;
	int age;
	char sex;
	char departure[25];	//noi den
	char arrival[25];
	char date[10];
};

struct Node{
    customer data;
    Node *next;
};
typedef struct Node *node;
node make_node(customer x)
{
    node tmp = new Node();
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}
void add_kh(node &a, customer x)
{
    node tmp = make_node(x);
    if(a == NULL) a = tmp;
    else
    {
        node p = a;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = tmp;
    }
}

void prin(node a)
{
    node tmp = a;
    while(tmp != NULL) {
        cout << tmp->data.ID << '\t' << tmp->data.name << '\t' << tmp->data.age << '\t' << tmp->data.add << '\t' << tmp->data.arrival<< '\t' << tmp->data.departure << '\t'<< tmp->data.sex
        << '\t' << tmp->data.date<< '\t' << tmp->data.email<< '\t' << tmp->data.mobile;
        tmp = tmp -> next;
    }
    cout << endl;
}
node cus_list = NULL;
class BOOKING
{
	public: char ID[20];
	char name[20];
	char add[50];
	char email[50];
	long mobile;
	int age;
	char sex;
	char departure[25];	//noi den
	char arrival[25];
	char date[10];


	public: void getInfo()
	{
		cout << "Nhap ho va ten: ";
		cin.get();
		cin.getline(name, 20);

		cout << "Nhap dia chi: ";
		cin.getline(add, 50);

		cout << "Nhap email: ";
		cin.getline(email, 50);

		cout << "Nhap SDT: ";
		cin >> mobile;

		cout << "Nhap so tuoi: ";
		cin >> age;

		cout << "Nhap gioi tinh(M(nam)/F(nu)): ";
		cin >> sex;

		cout << "Nhap IDname: ";
		cin >> ID;

		int n;
		int k = 0;
		do { 	cout << "\n\t\tLua chon diem bat dau: \n";
			cout << "\t\t-----------------------------\n";
			cout << "\t1. Ha Noi\n";
			cout << "\t2. Ho Chi Minh\n";
			cout << "\t3. Da Nang\n";
			cout << "\t4. Nha Trang\n";
			cout << "\t5. Can Tho\n";
			cout << "\t6. Da Lat\n";

			cout << "Moi quy khach nhap lua chon:  ";
			cin >> n;
			switch (n)
			{
				case 1:
					strcpy(departure, "HN");
					break;
				case 2:
					strcpy(departure, "HCM");
					break;
				case 3:
					strcpy(departure, "DN");
					break;
				case 4:
					strcpy(departure, "NT");
					break;
				case 5:
					strcpy(departure, "CT");
					break;
				case 6:
					strcpy(departure, "DL");
					break;
				default:
					cout << "Lua chon khong dung. Quy khach vui long nhap lai.\n";
					k++;
			}
		} while (k != 0);

		int p = 0;
		do { 	cout << "\n\t\tLua chon diem den cua ban\n";
			cout << "\t\t---------------------------\n";
			cout << "\t1. Ha Noi\n";
			cout << "\t2. Ho Chi Minh\n";
			cout << "\t3. Da Nang\n";
			cout << "\t4. Nha Trang\n";
			cout << "\t5. Can Tho\n";
			cout << "\t6. Da Lat\n";

			cout << "Moi quy khach nhap lua chon: ";
			cin >> n;

			switch (n)
			{
				case 1:
					strcpy(arrival, "HN");
					break;
				case 2:
					strcpy(arrival, "HCM");
					break;
				case 3:
					strcpy(arrival, "DN");
					break;
				case 4:
					strcpy(arrival, "NT");
					break;
				case 5:
					strcpy(arrival, "CT");
					break;
				case 6:
					strcpy(arrival, "DL");
					break;
				default:
					cout << "Lua chon khong dung. Quy khach vui long nhap lai.\n";
					p++;
			}
		} while (p != 0);

		cout << "Nhap ngay khoi hanh(DD/MM/YYYY) : ";
		cin >> date;
	}
    customer x;
	int disInfo()
	{

		cout.setf(ios::left);
		cout << setw(15) << ID << setw(15) << name << setw(12) << date << setw(20) << add << setw(15) << mobile << setw(30) << email << setw(12) << departure << setw(12) << arrival << endl;
        strcpy(x.add, add);
        x.age = age;
        strcpy(x.arrival, arrival);
        strcpy(x.ID , ID);
        strcpy(x.date , date);
        strcpy(x.departure , departure);
        strcpy(x.email , email);
        x.mobile = mobile;
        strcpy(x.name , name);
        x.sex = sex;
	}
};

void DangKi();
void TimKiem();

int main()
{
	cout << "\t\t\tWelcome Admin!\n";
	start:
		cout << "*****************************************************************\n";
	cout << "............<<<Chao Mung Den Voi Dich Vu NTU Airline>>>........\n";
	cout << "\n";
	cout << "---111--------111-----1111111111111111111---------1111-------1111\n";
	cout << "---111-11-----111-------------1111----------------1111-------1111\n";
	cout << "---111--11----111-------------1111----------------1111-------1111\n";
	cout << "---111---11---111-------------1111----------------1111-------1111\n";
	cout << "---111----11--111-------------1111----------------1111-------1111\n";
	cout << "---111----11--111-------------1111----------------1111-------1111\n";
	cout << "---111-----11-111-------------1111----------------1111-------1111\n";
	cout << "---111--------111-------------1111----------------111111111111111\n";
	cout << "*****************************************************************\n";
	int k = 0;
	int choice;
	do {
		cout << "\t\tVui long lua chon lua chon cua ban\n";
		cout << "--------------------------------------------------------------------\n";
		cout << "\t1. Dang ki chuyen bay\t\t2. Thong tin chuyen bay\n";
		cout << "\t3. Tim kiem chuyen bay\t\t4. Sua doi thong tin chuyen bay\n";
		cout << "\t5. Huy bo chuyen bay\t\t6. Thong tin hanh khach\n";
		cout << "\t\t\t7. Thoat chuong trinh.\n";

		cout << "Vui long nhap lua chon cua ban: ";
		cin >> choice;
		if (choice < 1 || choice > 7)
		{
			cout << "\nLua chon sai. Vui long quy khach nhap lai: \n";
			k++;
		}
	} while (k != 0);

	switch (choice)
	{
		case 1:
			DangKi();
			break;
		case 3:
			TimKiem();
			break;
		case 7:
			{
				exit(EXIT_FAILURE);
			}
	}
}

void DangKi()
{

	BOOKING b;
	char ch;
	int book_id = 1;

	cout << endl;
	cout << "-----------Chao mung den voi dich vu dat ve------------------\n";
	cout << endl;
	cout << "---111--------111-----1111111111111111111-----1111-------1111\n";
	cout << "---111-11-----111-------------1111------------1111-------1111\n";
	cout << "---111--11----111-------------1111------------1111-------1111\n";
	cout << "---111---11---111-------------1111------------1111-------1111\n";
	cout << "---111----11--111-------------1111------------1111-------1111\n";
	cout << "---111----11--111-------------1111------------1111-------1111\n";
	cout << "---111-----11-111-------------1111------------1111-------1111\n";
	cout << "---111--------111-------------1111------------111111111111111\n";
	cout << "-------------------------------------------------------------\n";

	do {
		b.getInfo();

		cout << "\n\t\tChi tiet dat ve\n";
		cout << "\t\t-----------------------------\n";
		cout.setf(ios::left);
		cout << setw(15) << "ID" << setw(15) << "Ho va Ten" << setw(12) << "Ngay di" << setw(20) << "Dia chi" << setw(15) << "SDT" << setw(30) << "Email" << setw(12) << "Noi den" << setw(12) << "Noi di" << endl;
		cout << setw(15) << "----" << setw(15) << "----" << setw(12) << "----" << setw(20) << "-------" << setw(15) << "------" << setw(30) << "-----" << setw(12) << "-------" << setw(12) << "-------" << endl;
		b.disInfo();

		cout << "\nQuy khach co muon dang ki lai?\n";
		cout << "(Y la co,N la khong): ";
		cin >> ch;
	} while (ch == 'Y' || ch == 'y');
	cout << "\n\t..........Dat Chuyen Bay Thanh Cong...............\n";

	char c1;
	cout << "\tNhan 'q' de ket thuc, nhan 'm' quay ve menu chinh ";
	cin >> c1;
	if (c1 == 'q' || c1 == 'Q')
		exit(EXIT_FAILURE);
	else if (c1 == 'm' || c1 == 'M')
	{
		main();
	}
}

void TimKiem()
{
	BOOKING s;
	int choice;
	fstream f3;
	char sName[20];
	char sEmail[20];
	long sMobile;
	char sID[20];
	f3.open("booking.txt", ios:: in | ios::out | ios::binary);
	cout << "*****************Chon tieu chi de Tim Kiem*******************\n";
	cout << "---111--------111-----1111111111111111111-----1111-------1111\n";
	cout << "---111-11-----111-------------1111------------1111-------1111\n";
	cout << "---111--11----111-------------1111------------1111-------1111\n";
	cout << "---111---11---111-------------1111------------1111-------1111\n";
	cout << "---111----11--111-------------1111------------1111-------1111\n";
	cout << "---111----11--111-------------1111------------1111-------1111\n";
	cout << "---111-----11-111-------------1111------------1111-------1111\n";
	cout << "---111--------111-------------1111------------111111111111111\n";
	cout << "\t\t---------------------------------------------------------\n";
	cout << "\n";
	cout << "\t1. Theo Ten\n\t2. Theo Email\n";
	cout << "\t3. Theo ID(Khuyen nghi)\n\t4. Theo SDT\n";

	cout << "Vui long nhap lua chon cua ban: ";
	cin >> choice;

	switch (choice)
	{
		case 1:
			{
				int flag = 0;
				cout << "Nhap ten ma ban muon tim kiem: ";
				cin >> sName;
				f3.seekg(0, ios::beg);
				f3.read((char*) &s, sizeof(s));
				cout.setf(ios::left);
				cout << setw(15) << "ID" << setw(15) << "Ho va Ten" << setw(12) << "Ngay di" << setw(20) << "Dia chi" << setw(15) << "SDT" << setw(30) << "Email" << setw(12) << "Noi den" << setw(12) << "Noi di" << endl;
				cout << setw(15) << "----" << setw(15) << "----" << setw(12) << "----" << setw(20) << "-------" << setw(15) << "------" << setw(30) << "-----" << setw(12) << "-------" << setw(12) << "-------" << endl;
				while (f3.eof() != 1)
				{
					if (strcmp(sName, s.name) == 0)
					{
						s.disInfo();
						flag = 1;
					}

					f3.read((char*) &s, sizeof(s));
				}

				if (flag == 0)
					cout << "\t!!!!!!Khong tim thay ket qua!!!!!!!!\n";
				f3.close();

				char c3_1;
				cout << "Nhan 'q' de quay lai Menu Tim Kiem nhan 'm' de quay lai Menu Chinh\n";
				cin >> c3_1;

				if (c3_1 == 'q' || c3_1 == 'Q')
					TimKiem();
				else if (c3_1 == 'm' || c3_1 == 'M')
				{
					main();
				}
			}

			break;

		case 2:
			{
				int flag = 0;
				cout << "Nhap Email ma ban muon tim kiem:- ";
				cin >> sEmail;

				f3.seekg(0, ios::beg);
				f3.read((char*) &s, sizeof(s));

				cout.setf(ios::left);
				cout << setw(15) << "ID" << setw(15) << "Ho va Ten" << setw(12) << "Ngay di" << setw(20) << "Dia chi" << setw(15) << "SDT" << setw(30) << "Email" << setw(12) << "Noi den" << setw(12) << "Noi di" << endl;
				cout << setw(15) << "----" << setw(15) << "----" << setw(12) << "----" << setw(20) << "-------" << setw(15) << "------" << setw(30) << "-----" << setw(12) << "-------" << setw(12) << "-------" << endl;
				while (f3.eof() != 1)
				{
					if (strcmp(sEmail, s.email) == 0)
					{
						s.disInfo();
						flag = 1;
					}

					f3.read((char*) &s, sizeof(s));
				}

				if (flag == 0)
					cout << "\t\tKhong tim thay ket qua!!\n";

				char c3_2;
				cout << "Nhan 'q' de quay lai Menu Tim Kiem nhan 'm' de quay lai Menu Chinh\n";
				cin >> c3_2;

				if (c3_2 == 'q' || c3_2 == 'Q')
					TimKiem();
				else if (c3_2 == 'm' || c3_2 == 'M')
				{
					main();
				}
			}

			break;

		case 3:
			{
				int flag = 0;
				cout << "Nhap ID ma ban muon tim kiem: ";
				cin >> sID;

				f3.seekg(0, ios::beg);
				f3.read((char*) &s, sizeof(s));

				cout.setf(ios::left);
				cout << setw(15) << "ID" << setw(15) << "Ho va Ten" << setw(12) << "Ngay di" << setw(20) << "Dia chi" << setw(15) << "SDT" << setw(30) << "Email" << setw(12) << "Noi den" << setw(12) << "Noi di" << endl;
				cout << setw(15) << "----" << setw(15) << "----" << setw(12) << "----" << setw(20) << "-------" << setw(15) << "------" << setw(30) << "-----" << setw(12) << "-------" << setw(12) << "-------" << endl;

				while (f3.eof() != 1)
				{
					if (sID == s.ID)
					{
						s.disInfo();
						flag = 1;
					}
				}

				if (flag == 0)
					cout << "\t\tKhong co ket qua!!!!\n";

				char c3_3;
				cout << "Nhan 'q' de quay lai Menu Tim Kiem nhan 'm' de quay lai Menu Chinh\n";
				cin >> c3_3;

				if (c3_3 == 'q' || c3_3 == 'Q')
					TimKiem();
				else if (c3_3 == 'm' || c3_3 == 'M')
				{
					main();
				}
			}

			break;

		case 4:
			{
				int flag = 0;
				cout << "Nhap SDT ma ban muon tim kiem: ";
				cin >> sMobile;

				f3.seekg(0, ios::beg);
				f3.read((char*) &s, sizeof(s));

				cout.setf(ios::left);
				cout << setw(15) << "ID" << setw(15) << "Ho va Ten" << setw(12) << "Ngay di" << setw(20) << "Dia chi" << setw(15) << "SDT" << setw(30) << "Email" << setw(12) << "Noi den" << setw(12) << "Noi di" << endl;
				cout << setw(15) << "----" << setw(15) << "----" << setw(12) << "----" << setw(20) << "-------" << setw(15) << "------" << setw(30) << "-----" << setw(12) << "-------" << setw(12) << "-------" << endl;
				while (f3.eof() != 0)
				{
					if (sMobile, s.mobile)
					{
						s.disInfo();
						flag = 1;
					}
				}

				if (flag == 0)
					cout << "\tKhong tim thay ket qua!!!!!!!!\n";

				char c3_4;
				cout << "Nhan 'q' de quay lai Menu Tim Kiem nhan 'm' de quay lai Menu Chinh\n";
				cin >> c3_4;

				if (c3_4 == 'q' || c3_4 == 'Q')
					TimKiem();
				else if (c3_4 == 'm' || c3_4 == 'M')
				{
					main();
				}
			}
	}
}
