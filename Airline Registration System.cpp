#include <bits/stdc++.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

void mainMenu();

struct customer{
	string ID;
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

void xoa_kh(string id, node &a)
{
    node tmp = a, pre = NULL;
    while(tmp != NULL)
    {
        if(tmp->data.ID == id)
        {
            if(tmp == a)
            {
                a = tmp->next;
                free(tmp);
            }else
            {
                pre->next = tmp->next;
                free(tmp);
            }
            cout << "Da xoa ID: " << id << "thanh cong!\n";
            return;
        }
        pre = tmp;
        tmp = tmp->next;
    }
    cout << "Khong tim thay ID!\n";
}

void prin(node a)
{
    ofstream file1("out.txt");
    node tmp = a;
    cout << setw(15) << "ID" << setw(15) << "Ten" << setw(15) << "Tuoi" <<setw(15) << "Dia chi" <<setw(15) << "Noi den"<<setw(15) << "Noi khoi hanh" <<setw(15)<< "Gioi tinh"
          <<setw(15) << "Ngay khoi hanh" << setw(15) << "Email" <<setw(30) << "So dien thoai"<< '\n';
    while(tmp != NULL) {
        cout << setw(15) << tmp->data.ID << setw(15) << tmp->data.name << setw(15) << tmp->data.age <<setw(15) << tmp->data.add <<setw(15) << tmp->data.arrival<<setw(15) << tmp->data.departure <<setw(15)<< tmp->data.sex
        <<setw(15) << tmp->data.date<<setw(15) << tmp->data.email<<setw(30) << tmp->data.mobile << '\n';
        tmp = tmp -> next;
    }
    tmp = a;
    while(tmp != NULL) {
        file1 << tmp->data.ID << setw(15) << tmp->data.name << setw(15) << tmp->data.age <<setw(15) << tmp->data.add <<setw(15) << tmp->data.arrival<<setw(15) << tmp->data.departure <<setw(15)<< tmp->data.sex
        <<setw(15) << tmp->data.date<<setw(15) << tmp->data.email<<setw(30) << tmp->data.mobile << '\n';
        tmp = tmp -> next;
    }
    file1 << endl;
    file1.close();
}
node cus_list = NULL;

void chinh_sua_thong_tin(string id, node &a)
{
    char name[20];
	char add[50];
	char email[50];
	long mobile;
	int age;
	char sex;
	char departure[25];	//noi den
	char arrival[25];
	char date[10];

	node tmp = a;
	while(tmp != NULL)
	{
	    if(tmp->data.ID == id) break;
	    tmp = tmp->next;
	}
    if(tmp == NULL) {
        cout << "\t\t-----------------------------\n";
        cout << "\t\t\tID khong co san!\n";
        return;
    }

    int i = 1;
    do
    {
        cout << "\n\tChon thong tin muon sua:\n";
        cout << "\t\t-----------------------------\n";
        cout << "\t1. Ten\n";
        cout << "\t2. Dia chi\n";
        cout << "\t3. email\n\t4. So dien thoai\n\t5. Tuoi\n\t6. Gioi tinh\n\t7. Noi den\n\t8. Noi di\n\t9. Ngay khoi hanh\n\t10. Thoat.\n";

        int choose;
        cin >> choose;
        cin.get();
        switch(choose)
        {
        case 1:
        {
            cout << "Nhap ten can sua:";
            cin.getline(name, 20);
            strcpy(tmp->data.name, name);
            break;
        }
        case 2:
        {
            cout << "Nhap dia chi can sua:";
            cin.getline(add, 50);;
            strcpy(tmp->data.add, add);
            break;
        }
        case 3:
        {
            cout << "Nhap email can sua:";
            cin.getline(email, 50);
            strcpy(tmp->data.email, email);
            break;
        }
        case 4:
        {
            cout << "Nhap so dien thoat can sua:";
            cin >> mobile;
            tmp->data.mobile = mobile;
            break;
        }
        case 5:
        {
            cout << "Nhap tuoi can sua:";
            cin >> age;
            tmp->data.age = age;
            break;
        }
        case 6:
        {
            cout << "Nhap gioi tinh can sua:";
            cin >> sex;
            tmp->data.sex = sex;
            break;
        }
        case 7:
        {
            cout << "Nhap noi den can sua:";
            cin.getline(departure, 25);
            strcpy(tmp->data.departure, departure);
            break;
        }
        case 8:
        {
            cout << "Nhap noi di can sua:";
            cin.getline(arrival, 25);
            strcpy(tmp->data.arrival, arrival);
            break;
        }
        case 9:
        {
            cout << "Nhap ngay khoi hanh can sua:";
            cin.getline(date, 10);
            strcpy(tmp->data.date, date);
            break;
        }
        case 10:
            --i;
            break;
        }
    }
    while(i);

}

class BOOKING
{
	public: string ID;
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
	void disInfo()
	{

		cout.setf(ios::left);
		cout << setw(15) << ID << setw(15) << name << setw(12) << date << setw(20) << add << setw(15) << mobile << setw(30) << email << setw(12) << departure << setw(12) << arrival << endl;
        strcpy(x.add, add);
        x.age = age;
        strcpy(x.arrival, arrival);
        x.ID = ID;
        strcpy(x.date , date);
        strcpy(x.departure , departure);
        strcpy(x.email , email);
        x.mobile = mobile;
        strcpy(x.name , name);
        x.sex = sex;
        add_kh(cus_list, x);
	}
};

void Thongtin()
{
    prin(cus_list);
}
void Xoa()
{
    cout << "Nhap ID can xoa:";
    string c; cin >> c;
    xoa_kh(c, cus_list);
}

void DangKi();
void TimKiem();

int main()
{
    string userName;
    string userPassword;
    int loginAttempt = 0;

    while (loginAttempt < 5)
    {
        cout << "user name: ";
        cin >> userName;
        cout << "user password: ";
        char tmp;
        while((tmp = getch()) != 13)
        {
        	userPassword += tmp;
        	printf("*");
		}
        cout <<endl;
        if (userName == "admin" && userPassword == "admin")
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
            int choice;
            do
            {
                cout << "\t\tVui long lua chon lua chon cua ban\n";
                cout << "--------------------------------------------------------------------\n";
                cout << "\t1. Dang ki chuyen bay.\t\t2. Thong tin chuyen bay.\n";
                cout << "\t3. Tim kiem chuyen bay.\t\t4. Sua doi thong tin chuyen bay.\n";
                cout << "\t5. Huy bo chuyen bay.\t\t";
                cout << "6. Thoat chuong trinh.\n";

                cout << "Vui long nhap lua chon cua ban: ";
                cin >> choice;
                if (choice < 1 || choice > 6)
                {
                    cout << "\nLua chon sai. Vui long quy khach nhap lai: \n";
                    continue;
                }
                switch (choice)
                {
                case 1:
                    DangKi();
                    break;
                case 2:
                    Thongtin();
                    break;
                case 3:
                    TimKiem();
                    break;

                case 4:
                {
                    cout << "\n\tNhap ID ban muon chinh sua:";
                    string id_tam;
                    cin >> id_tam;
                    chinh_sua_thong_tin(id_tam, cus_list);
                    break;
                }
                case 5:
                {
                    Xoa();
                    break;
                }
                case 6:
                {
                    exit(EXIT_FAILURE);
                }
            }
            }
            while (true);
        }
        else
        {
            cout << "Dang nhap sai, vui long dang nhap lai.\n" << '\n';
            loginAttempt++;
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

    do
    {
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
    }
    while (ch == 'Y' || ch == 'y');
    cout << "\n\t..........Dat Chuyen Bay Thanh Cong...............\n";

    char c1;
    cout << "\tNhan 'q' de ket thuc, nhan 'm' quay ve menu chinh.";
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
	cout << "Nhap ID can tim kiem:";
	string tmp_id; cin >> tmp_id;
	node tmp = cus_list;
	while(tmp != NULL)
    {
        if(tmp->data.ID == tmp_id)
        {
            cout << "ID hop le!\n";
            cout << setw(15) << tmp->data.ID << setw(15) << tmp->data.name << setw(15) << tmp->data.age <<setw(15) << tmp->data.add <<setw(15) << tmp->data.arrival<<setw(15) << tmp->data.departure <<setw(15)<< tmp->data.sex
                 <<setw(15) << tmp->data.date<<setw(15) << tmp->data.email<<setw(30) << tmp->data.mobile << '\n';
            return;
        }
        tmp = tmp->next;
    }
    cout << "ID khong tim thay!\n";
}
