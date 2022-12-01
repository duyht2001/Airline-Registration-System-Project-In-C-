#include<iostream>
#include<fstream>
#include<iomanip>
#include <cstring>
#include <cstdlib>

using namespace std;

void mainMenu();

class BOOKING
{
    public :
        char name[20];
        char add[50];
        char email[50];
        long mobile;
        int age;
        char sex;
        char departure[25];//noi den
        char arrival[25];
        char date[10];
    public :
        int getInfo()
        {
            cout << "Nhap ho va ten: ";
            cin.get();
            cin.getline(name,20);

            cout << "Nhap dia chi: ";
            cin.getline(add,50);

            cout << "Nhap email: ";
            cin.getline(email,50);

            cout << "Nhap SDT: ";
            cin >> mobile;

            cout << "Nhap so tuoi: ";
            cin >> age;

            cout <<"Nhap gioi tinh(M(nam)/F(nu)): ";
            cin >> sex;



            int n;
            int k = 0;
            do
            {
                cout << "\n\t\tLua chon diem bat dau: \n";
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
            }while(k != 0);

            int p = 0;
            do
            {
                cout << "\n\t\tLua chon diem den cua ban\n";
                cout << "\t\t---------------------------\n";
                cout << "\t1. Ha Noi\n";
                cout << "\t2. Ho Chi Minh\n";
                cout << "\t3. Da Nang\n";
                cout << "\t4. Nha Trang\n";
                cout << "\t5. Can Tho\n";
                cout << "\t6. Da Lat\n";

                cout << "Moi quy khach nhap lua chon: ";
                cin >>n;

                switch(n)
                {
                    case 1:
                        strcpy(arrival,"HN");
                        break;
                    case 2:
                        strcpy(arrival,"HCM");
                        break;
                    case 3:
                        strcpy(arrival,"DN");
                        break;
                    case 4:
                        strcpy(arrival,"NT");
                        break;
                    case 5:
                        strcpy(arrival,"CT");
                        break;
                    case 6:
                        strcpy(arrival,"DL");
                        break;
                   default:
                        cout << "Lua chon khong dung. Quy khach vui long nhap lai.\n";
                        p++;
                }
            }while(p != 0);

            cout << "Nhap ngay khoi hanh( DD/MM/YYYY ) :- ";
            cin >> date;
        }

        int disInfo()
        {
            cout.setf(ios::left);
            cout <<setw(15)<< name <<setw(12)<< date <<setw(20)<< add <<setw(15)<< mobile <<setw(30)<<email<<setw(12)<< departure <<setw(12)<< arrival<<endl;
        }

};

int main()
{
start :
    cout << "*********************************************************************\n";
    cout <<"..............Chao Mung Den Voi Dich Vu NTU Airline ............\n";
    cout << "*********************************************************************\n";
    int k = 0;
    int choice;
    do
    {
        cout << "\tVui long lua chon lua chon cua ban\n";
        cout << "--------------------------------------------------------------------\n";
        cout << "\t1. Dang ki chuyen bay\t\t2. Thong tin chuyen bay\n";
        cout << "\t3. Tim kiem chuyen bay\t\t4. Sua doi thong tin chuyen bay\n";
        cout << "\t5. Huy bo chuyen bay\t\t6. Thong tin hanh khach\n";

        cout << "Vui long nhap lua chon cua ban : ";
        cin >> choice;
        if(choice<1 || choice >6)
        {
            cout << "\nLua chon sai. Vui long quy khach nhap lai: \n";
            k++;
        }
    }while (k != 0);
    switch (choice)
    {
        case 1:
            {
                BOOKING b;
                fstream f1;
                char ch;
                int book_id = 1;
                f1.open("booking.dat",ios::in|ios::out|ios::app|ios::binary);
                cout << "\t\tChao mung den voi dich vu dat ve\n";
                cout << "\t\t---------------------------\n";

                do
                {
                    b.getInfo();
                    f1.write((char *)&b , sizeof(b));

                    cout << "\n\t\tChi tiet dat ve\n";
                    cout << "\t\t-----------------------------\n";
                    cout.setf(ios::left);
                    cout <<setw(15)<<"Ho va Ten"<<setw(12)<<"Ngay di"<<setw(20)<<"Dia chi"<<setw(15)<<"SDT"<<setw(30)<<"Email"<<setw(12)<<"Noi den"<<setw(12)<<"Noi di"<<endl;
                    cout <<setw(15)<<"----"<<setw(12)<<"----"<<setw(20)<<"-------"<<setw(15)<<"------"<<setw(30)<<"-----"<<setw(12)<<"-------"<<setw(12)<<"-------"<<endl;
                    b.disInfo();
                    cout << "\nQuy khach co muon dang ki lai ?\n";
                    cout << "(Y la co,N la khong)";
                    cin >> ch;
                }while (ch == 'Y'|| ch == 'y');
                cout << "\n\t..........Dat Chuyen Bay Thanh Cong...............\n";

                char c1;
                cout << "\tNhan 'q' de ket thuc hoac bat ki phim nao khac de quay lai Man hinh chinh :- ";
                cin >>c1;
                if(c1 == 'q' || c1 == 'Q')
                    exit(EXIT_FAILURE);
                else
                    goto start;
                f1.close();
            }
            break;
	
}
}


