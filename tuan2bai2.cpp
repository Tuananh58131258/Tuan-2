#include<string>
#include<fstream>
#include<iostream>
#include<vector>
using namespace std;
struct NhanVien
{//khai bao struct luu tru nhan vien
	int MaNV, Tuoi, LuongCB;
	string Hoten;
};
void NhapNV(NhanVien &NV)
{//ham nhap vao thong tin nhan vien.
	cout <<"Nhap Ma nhan vien: ";
	cin>>NV.MaNV;
	cout <<"Nhap ho ten nhan vien: ";
	cin.ignore();
	getline(cin,NV.Hoten);
	cout <<"Nhap tuoi nhan vien: ";
	cin>>NV.Tuoi;
	cout <<"Nhap luong co ban nhan vien: ";
	cin>>NV.LuongCB;
}
void XuatNV(NhanVien NV)
{
	//Xuat thong tin nhan vien theo thu tu ma nhan vien, ten, tuoi, luong co ban
	cout <<NV.MaNV<<"\t"<<NV.Hoten<<"\t\t"<<NV.Tuoi<<"\t"<<NV.LuongCB<<endl;
}
void Ghifile(ofstream &outfile,NhanVien &NV)
{
	//ghi vao file du lieu 1 nhan vien
	outfile<<NV.MaNV<<endl;
	outfile<<NV.Hoten<<endl;
	outfile<<NV.Tuoi<<endl;
	outfile<<NV.LuongCB<<endl;
}
void Docfile(ifstream &infile,NhanVien &NV)
{
	//doc tu file du lieu 1 nhan vien
	infile>>NV.MaNV;
	string temp;
	getline(infile,temp);
	getline(infile,NV.Hoten);
	infile>>NV.Tuoi;
	infile>>NV.LuongCB;
}
void DocDS(ifstream &f,vector<NhanVien> &list)
{
	//doc tu file danh sach nhan vien.
	int n;
	f>>n;
	list.resize(n);
	for(int i = 0; i< list.size(); i++)
	{
		Docfile(f,list[i]);
	}
}
void GhiDS(ofstream &f,vector<NhanVien> &list)
{
	//ghi vao file danh sach nhan vien
	f << list.size()<<endl;
	for(int i = 0; i<list.size();i++)
	{
		Ghifile(f,list[i]);
	}
}
void NhapDS(vector<NhanVien> &DSNV)
{
	int n;
	cout <<"nhap vao so luong nhan vien: ";
	cin >> n;
	DSNV.resize(n);//xac dinh kich thuoc cua danh sach
	for(int i = 0; i< DSNV.size();i++)
	{
		cout <<"nhap thong tin nhan vien thu "<<i+1<<endl;
		NhapNV(DSNV[i]);//goi ham nhap nhan vien de nhap danh sach nhan vien
	}
}
void XuatDS(vector<NhanVien> &DSNV)
{
	//duyet vong lap tu 0 den cuoi danh sach. DSNV.size() tra ve so luong phan tu danh sach
	for(int i = 0; i< DSNV.size();i++)
	{
		XuatNV(DSNV[i]);
		//goi ham xuat nhan vien de xuat danh sach nhan vien
	}
}
int Kiemtra(vector<NhanVien> DSNV,int manv)
{
	//ham nay nham muc dich kiem tra xem da co ma nhan vien trong danh sach hay chua,
	//neu co roi se tra ve vi tri cua nhan vien do trong danh sach
	//neu chua se tra ve -1
	for(int i = 0; i<DSNV.size();i++)
	{
		if(DSNV[i].MaNV == manv)
		return i;
	}
	return -1;
}
void ThemNV(vector<NhanVien> &DSNV)
{
	NhanVien NV;
	do
	{
		cout <<"Nhap vao ma nhan vien, ma nhan vien phai khac voi cac nhan vien da co trong danh sach: ";
		cin >> NV.MaNV;	
	}while(Kiemtra(DSNV,NV.MaNV)!=-1);//vong lap do while kiem tra xem ma nhan vien moi co bi trung voi ma nhan vien cu hay khong.
	//nhap cac thong tin khac cua nhan vien
	cout <<"Nhap ten nhan vien: ";cin.ignore();
	getline(cin,NV.Hoten);
	cout <<"Nhap tuoi nhan vien: ";
	cin>> NV.Tuoi;
	cout <<"Nhap luong co ban cua nhan vien: ";
	cin>>NV.LuongCB;
	DSNV.push_back(NV);//them nhan vien vao cuoi vector
	cout<<"Da them nhan vien."<<endl;
}
void XoaNV(vector<NhanVien> &DSNV)
{
	int manv;
	cout <<"nhap vao ma nhan vien can xoa: ";
	cin >> manv;
	if(Kiemtra(DSNV,manv)!=-1)//dung ham kiem tra de kiem tra xem co ma nhan vien can xoa hay khong
	{
		DSNV.erase(DSNV.begin()+Kiemtra(DSNV,manv));//neu co se tien hanh xoa nhan vien
		cout<<"Da xoa nhan vien."<<endl;
	}	
	else
	cout <<"Khong tim thay nhan vien."<<endl;// thong bao neu khong tim thay
}
void TimNV(vector<NhanVien> &DSNV)
{
	int manv;
	cout <<"nhap vao ma nhan vien can tim: ";
	cin >> manv;
	if(Kiemtra(DSNV,manv)!=-1)//kiem tra xem thu co ton tai nhan vien hay khong
	{
		cout <<"Thong tin nhan vien co ma: "<<manv<<endl;
		cout <<"MaNV\tHoten\t\t\tTuoi\tLuongCB"<<endl;
		XuatNV(DSNV[Kiemtra(DSNV,manv)]);//neu tim thay thi xuat ra thong tin nhan vien
	}
	else
	cout <<"Khong tim thay nhan vien."<<endl;//thong bao neu khong tim thay nhan vien
}
void SuaNV(vector<NhanVien> &DSNV)
{
	NhanVien NV;
	int manv;
	cout <<"Nhap ma nhan vien can sua:";
	cin >> manv;
	//kiem tra xem nhan vien can sua co ton tai hay khong
	int temp = Kiemtra(DSNV,manv);
	if(temp!=-1)
	{
		cout <<"Nhap vao thong tin can sua, Nhap vao 0 neu khong co thay doi."<<endl;
		cout <<"Nhap ho ten:";cin.ignore();
		getline(cin,NV.Hoten);
		cout <<"Nhap tuoi: ";
		cin>> NV.Tuoi;
		cout <<"Nhap luong co ban: ";
		cin>>NV.LuongCB;
		if(NV.Hoten.compare("0")!=0)
		DSNV[temp].Hoten = NV.Hoten;
		if(NV.Tuoi!=0)
		DSNV[temp].Tuoi = NV.Tuoi;
		if(NV.LuongCB!=0)
		DSNV[temp].LuongCB = NV.LuongCB;
		cout <<"Da sua thong tin nhan vien."<<endl;
	}
	else
	cout <<"Khong tim thay nhan vien!"<<endl;
}
void Menu()
{
	cout << "Cac chuc nang cua chuong trinh:" << endl;
	cout << "1: Them 1 nhan vien." << endl;
	cout << "2: Xoa 1 nhan vien theo ma nhan vien." << endl;
	cout << "3: Sua 1 nhan vien theo ma nhan vien." << endl;
	cout << "4: Tim kiem thong tin 1 nhan vien theo ma." << endl;
	cout << "5: In danh sach nhan vien." << endl;
	cout << "6: Ghi danh sach vao file."<<endl;
	cout << "7: Thoat chuong trinh."<<endl;
}
int Chonchucnang()
{
	int chon; 
	cout << "Nhap chuc nang muon thuc hien: ";
	cin >> chon;
	if (chon >0 && chon < 8)
		return chon;
	else return Chonchucnang();
}
void Xulychucnang(vector<NhanVien> &list,ofstream &f)
{
	Menu();
	int chucnang = Chonchucnang();
	switch (chucnang)
	{
	case 1:
		system("cls");
		ThemNV(list);
		system("pause");
		break;
	case 2:
		system("cls");
		XoaNV(list);
		system("pause");
		break;
	case 3:
		system("cls");
		SuaNV(list);
		system("pause");
		break;
	case 4:
		system("cls");
		TimNV(list);
		system("pause");
		break;
	case 5:
		system("cls");
		XuatDS(list);
		system("pause");
		break;
	case 6:
		system("cls");
		GhiDS(f,list);
		cout <<"Da ghi vao file output2.txt."<<endl;
		system("pause");
		break;
	case 7:
		cout <<"Cam on ban da su chung chuong trinh"<<endl;
		exit(1);
		break;
	}
}
int main()
{
	vector<NhanVien> list;
	ifstream infile;
	ofstream outfile;
	outfile.open("output2.txt");
	infile.open("input2.txt");
	DocDS(infile,list);
	while (1)
	{
		system("cls");
		Xulychucnang(list,outfile);
	}
	system("pause");
}
