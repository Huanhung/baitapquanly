#include<iostream>
#include<string.h> 
#include<conio.h> 
#include<iomanip> 
using namespace std;
class sinhvien
{
	public:
		char hoten[20], gioitinh[20];
		char namsinh[20], diachi[30];
		char masv[10], lop[10];
		float tin1, tin2, tin3, tin4, anh1, anh2, DTB;
		
			void nhap();
			void hienthi();
};
// xay dung phuong thuc nhap
void sinhvien::nhap()
{
	cin.ignore(1); // xoa bo nho dem
	cout<<"\n Nhap ho ten:";cin.getline(hoten,20);fflush(stdin);
	cout<<"\n Nhap gioi tinh:";cin.getline(gioitinh,20);fflush(stdin);
	cout<<"\n Nhap nam sinh:";cin.getline(namsinh,20);fflush(stdin);
	cout<<"\n Nhap dia chi:";cin.getline(diachi,30);fflush(stdin);
	cout<<"\n Nhap ma sinh vien:";cin.getline(masv,10);fflush(stdin);
	cout<<"\n Nhap lop:";cin.getline(lop,10);fflush(stdin);
	cout<<"\n Nhap diem tin 1:";
	cin>>tin1;
	cout<<"\n Nhap diem tin 2:";
	cin>>tin2;
	cout<<"\n Nhap diem tin 3:";
	cin>>tin3;
	cout<<"\n Nhap diem tin 4:";
	cin>>tin4;
	cout<<"\n Nhap diem anh 1:";
	cin>>anh1;
	cout<<"\n Nhap diem anh 2:";
	cin>>anh2;
	cout<<endl;
}
// xay dung phuong thuc hien thi
void sinhvien::hienthi()
{
	cout<<""<<setw(10)<<hoten<<setw(8)<<gioitinh<<setw(10)<<namsinh;
	cout<<""<<setw(11)<<diachi<<setw(11)<<masv<<setw(11)<<lop;
	
	cout<<""<<setw(10)<<tin1<<setw(10)<<tin2<<setw(10)<<tin3<<setw(10)<<tin4;
	cout<<""<<setw(10)<<anh1<<setw(10)<<anh2;
	
	DTB=(tin1+tin2+tin3+tin4+anh1+anh2)/6;
	cout<<""<<setw(12)<<DTB;
	cout<<""<<setw(10)<<setprecision(2)<<DTB; //tinh diem tb lam tron
	// xep loai hoc luc sinh vien
	if(DTB>=8)
	{
		cout<<" Xep loai gioi";
	}
	else if(DTB>=7)
	{
		cout<<" Xep loai kha";
	}
	else if(DTB>=5)
	{
		cout<<" Xep loai trung binh";
	}
	else if(DTB<5)
	{
		cout<<" Xep loai yeu";
	}
}
// xay dung lop ke thua
class quanlysv: public sinhvien
{
	public:
		//double DTB;
		sinhvien sv[100]; // khai bao mang sinh vien
		int n;
		  
		  void nhap();
		  void hienthi();
		  void xeploaiHL();
		  void timkiemsv();
		
};
// xay dung phuong thuc nhap
void quanlysv::nhap()
{
	cout<<"Nhap so luong sinh vien:";cin>>n; // n=2
	for(int i=0;i<n;i++)
	{
		cout<<"\n sinh vien thu:"<<i+1<<"";
		sv[i].nhap(); // Goi phuong thuc nhap o lop sinh vien
	}
}
// xay dung phuong thuc hien thi
void quanlysv::hienthi()
{
	cout<<"\n Ho Ten"<<setw(12)<<"Gioi Tinh"<<setw(11)<<"Nam Sinh"<<setw(12);
	cout<<"Dia Chi"<<setw(14)<<"Ma Sinh Vien"<<setw(12)<<"Lop"<<setw(10);
	
	cout<<"Tin1"<<setw(10)<<"Tin2"<<setw(10)<<"Tin3"<<setw(10)<<"Tin4"<<setw(10);
	cout<<"Anh1"<<setw(10)<<"Anh2"<<setw(9)<<"DTB"<<setw(14)<<"DTB Lam Tron"<<setw(10);
	for(int i=0;i<n;i++)
	{
		sv[i].hienthi(); // Goi phuong thuc hien thi lop sinh vien o tren
	}
}
// xep loai hoc luc sinh vien
void quanlysv::xeploaiHL()
{
	cout<<"\n";
	cout<<"---\n Sinh vien xep loai hoc luc gioi---"<<endl;
	for(int i=0;i<n;i++)
	{
		if(sv[i].DTB>=8)
		{
			sv[i].hienthi();
		}
	}
	cout<<"\n";
	cout<<"\n--- Sinh vien xep loai hoc luc yeu---"<<endl;
	for(int i=0;i<n;i++)
	{
		if(sv[i].DTB<5)
		{
			sv[i].hienthi();
		}
	}
}

// xay dung ham tim kiem sinh vien theo ma or hoten
void quanlysv::timkiemsv()
{
	string msv;
	int count=0;
	cout<<"\n Nhap ma sinh vien can tim:";fflush(stdin);getline(cin,msv);
	cout<<"\n---Thong tin sinh vien khi nhap xong la---";
	cout<<"\n Ho Ten"<<setw(12)<<"Gioi Tinh"<<setw(11)<<"Nam Sinh"<<setw(12);
	cout<<"Dia Chi"<<setw(14)<<"Ma Sinh Vien"<<setw(12)<<"Lop"<<setw(10);
	cout<<"Tin1"<<setw(10)<<"Tin2"<<setw(10)<<"Tin3"<<setw(10)<<"Tin4"<<setw(10);
	cout<<"Anh1"<<setw(10)<<"Anh2"<<setw(9)<<"DTB"<<setw(14)<<"DTB Lam Tron"<<setw(10);
	for(int i=0;i<n;i++)
	{
		if(sv[i].masv == msv)
		{
			sv[i].hienthi();
			count++;
		}
	}
	if(count == 0)
	{
		cout<<"\n Khong tim thay thong tin sinh vien";
	}
}
int main()
{
	int luachon,n;
	quanlysv QLSV;
	cout<<"---DAY LA CHUONG TRINH QUAN LY SINH VIEN---\n";
	cout<<"Xin moi ban nhap mot so > 0 de tiep tuc: ";cin>>n;
	while(n>0)
	{
	cout<<"\n=================MENU====================";
	cout<<"\n===== Chuong Trinh Quan Ly Sinh Vien =====";
	cout<<"\n=== Moi Ban Nhap Trong Cac Chon Lua Sau ===";
	cout<<"\n1: Nhap thong tin sinh vien.";
	cout<<"\n2: Hien thi thong tin sinh vien.";
	cout<<"\n3: Xep loai hoc luc sinh vien.";
	cout<<"\n4: Tim kiem sinh vien theo ma sinh vien or ho ten.";
	cout<<"\n5: Exit.";
	cout<<"\n *Xin Moi Nhap Lua Chon Cua Ban: ";cin>>luachon;
	switch(luachon)
	{
		case 1:
		
			QLSV.nhap();
		cout<<"bam phim bat ki de tiep tuc\n";
				system("pause");
		break;
	case 2:
		
			QLSV.hienthi();
			cout<<"bam phim bat ki de tiep tuc\n";
				system("pause");
		break;
	case 3:
		
			QLSV.xeploaiHL();
			cout<<"bam phim bat ki de tiep tuc\n";
				system("pause");
		break;
	
	case 4:
		
			QLSV.timkiemsv();
			cout<<"bam phim bat ki de tiep tuc\n";
				system("pause");
			break;
	case 5:
		cout<<endl;
		break;
		default:
		cout<<"\nKhong tim thay du lieu ban nhap. Xin moi nhap lai, Thanks.";
		cout<<"\nbam phim bat ki de tiep tuc\n";
				system("pause");
	}
	}	
//	QLSV.nhap();
//	QLSV.hienthi();
//	QLSV.xeploaiHL();
//	QLSV.timkiemsv();
//	getch();
	return 0;
}
