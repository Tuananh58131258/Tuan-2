#include<string>
#include<fstream>
#include<iostream>
#include<vector>
using namespace std;
struct NhanVien
{
	int MaNV, Tuoi, LuongCB;
	string Hoten;
};
void NhapNV(NhanVien &NV)
{
	cout <<"Nhap Ma nhan vien: ";
	cin>>NV.MaNV;
	cout <<"Nhap ho ten nhan vien: ";
	cin.ignore();
	getline(cin,NV.Hoten);
//	cout <<"Nhap tuoi nhan vien: ";
//	cin>>NV.Tuoi;
//	cout <<"Nhap luong co ban nhan vien: ";
//	cin>>NV.LuongCB;
}
void XuatNV(NhanVien NV)
{
	cout <<NV.MaNV<<"\t"<<NV.Hoten<<endl;//<<"\t"<<NV.Tuoi<<"\t"<<NV.LuongCB<<endl;
}
void NhapDS(vector<NhanVien> &DSNV)
{
	int n;
	cout <<"nhap vao so luong nhan vien: ";
	cin >> n;
	DSNV.resize(n);//kich thuoc cua danh sach
	for(int i = 0; i< DSNV.size();i++)
	{
		cout <<"nhap thong tin nhan vien thu "<<i+1<<endl;
		NhapNV(DSNV[i]);
	}
}
void XuatDS(vector<NhanVien> DSNV)
{
	for(int i = 0; i< DSNV.size();i++)
	{
		XuatNV(DSNV[i]);
	}
}
int Kiemtra(vector<NhanVien> DSNV,int manv)
{
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
		cout <<"Nhap vao ma nhan vien muon xoa, ma nhan vien phai nam trong danh sach nhan vien da co."<<endl;
		NhapNV(NV);	
	}while(Kiemtra(DSNV,NV.MaNV)!=-1);
	DSNV.push_back(NV);
}
void XoaNV(vector<NhanVien> &DSNV)
{
	int manv;
	cout <<"nhap vao ma nhan vien can xoa: ";
	cin >> manv;
	if(Kiemtra(DSNV,manv)!=-1)
	DSNV.erase(DSNV.begin()+Kiemtra(DSNV,manv));
	else
	cout <<"Khong tim thay nhan vien."<<endl;
}
void TimNV(vector<NhanVien> &DSNV)
{
	int manv;
	cout <<"nhap vao ma nhan vien can tim: ";
	cin >> manv;
	if(Kiemtra(DSNV,manv)!=-1)
	XuatNV(DSNV[Kiemtra(DSNV,manv)]);
	else
	cout <<"Khong tim thay nhan vien."<<endl;
}
void SuaNV(vector<NhanVien> &DSNV)
{
	NhanVien NV;
	int manv;
	do
	{
		cout <<"Nhap ma nhan vien can sua:";
		cin >> manv;
	}while(Kiemtra(DSNV,manv)==-1);
	int temp = Kiemtra(DSNV,manv);
	cout <<"Nhap vao thong tin can sua, Nhap vao 0 neu khong co thay doi.";
	cout <<"Nhap ho ten:";cin.ignore();
	getline(cin,NV.Hoten);
//	cout <<"Nhap tuoi: ";
//	cin>> NV.Tuoi;
//	cout <<"Nhap luong co ban: ";
//	cin>>NV.LuongCB;
	if(NV.Hoten.compare("0")!=0)
	DSNV[temp].Hoten = NV.Hoten;
//	if(NV.Tuoi!=0)
//	DSNV[temp].Hoten = NV.Tuoi;
//	if(NV.LuongCB!=0)
//	DSNV[temp].Hoten = NV.LuongCB;
}
int main()
{
	vector<NhanVien> list;
	NhanVien NV;
	NhapDS(list);
	cout <<"thong tin nhan vien"<<endl;
	XuatDS(list);
	cout <<"-----------------------"<<endl;
	//ThemNV(list);
	//XoaNV(list);
	//TimNV(list);
	SuaNV(list);
	cout <<"thong tin nhan vien"<<endl;
	XuatDS(list);
}
