#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
struct Question
{
	string quest, choise[4], correctAnswer;
	//struc cau hoi
};
struct player
{
	int scores;
	string playername,bode;
	//struct nguoi choi
};
void SavePlayerScore(vector<player> &listP, player &p)
{
	listP.push_back(p);
	// ham them nguoi choi vao cuoi danh sach 
}
void printplayer(player &p)
{
	cout << p.playername << "\t" << p.scores << "\t" << p.bode << endl;
}
void printlistplayer(vector<player> &listP)
{
	for (int i = 0; i < listP.size(); i++)
	{
		printplayer(listP[i]);
	}
}
void Docfile(ifstream &f, Question &q)
{
	getline(f, q.quest);
	for (int i = 0; i< 4; i++)
	{
		getline(f, q.choise[i]);
	}
	getline(f, q.correctAnswer);
}
void DocDS(ifstream &f, vector<Question> &listquest)
{
	int n;
	f >> n;
	listquest.resize(n);
	string temp;
	getline(f, temp);
	for (int i = 0; i < listquest.size(); i++)
	{
		Docfile(f, listquest[i]);
	}
}
bool checkanswer(Question q)
{
	string temp;
	cin.ignore();
	cout << "Nhap dap an: ";
	cin >> temp;
	if (temp[0]>96)
		temp[0] = temp[0] - 32;
	if (temp == q.correctAnswer)
	{
		cout << "Dap an dung!" << endl;
		return true;
	}
	else
	{
		cout << "Ban da tra loi sai, dap an dung la: " << q.correctAnswer << endl;
		return false;
	}
}
void printQ(Question q)
{
	cout << q.quest << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << q.choise[i] << endl;
	}
}
void printquestion(vector<Question> &listQ, int &dem)
{
	for (int i = 0; i < listQ.size(); i++)
	{
		printQ(listQ[i]);
		if (checkanswer(listQ[i]))
			dem++;
	}
	cout << "ban da tra loi dung: " << dem << " cau." << endl;
}
void Menu()
{
	cout << "Chon bo de trac nghiem." << endl;
	cout << "1: Bo de 1." << endl;
	cout << "2: Bo de 2." << endl;
	cout << "3: Bo de 3." << endl;
	cout << "4: Xem ket qua nguoi choi." << endl;
	cout << "5: Thoat chuong trinh." << endl;
}
int chonde()
{
	int chon;
	cout << "Moi chon bo de: ";
	cin >> chon;
	if (chon >0 && chon< 6)
		return chon;
	else return chonde();
}
void Xulymenu(vector<Question> &list, ifstream &f,vector<player> &listP, int &dem)
{
	player p;
	int KQ;
	Menu();
	int de = chonde();
		switch (de)
		{
		case 1:
		{
			system("cls");
			f.open("de1.txt");
			DocDS(f, list);
			printquestion(list, dem);
			KQ = dem;
			cout << "Moi nhap ten nguoi choi: "; cin.ignore();
			getline(cin, p.playername);
			p.bode = "de 1";
			p.scores = KQ;
			SavePlayerScore(listP, p);
			f.close();
			system("pause");
			break;
		}
		case 2:
		{	
			system("cls");
			f.open("de2.txt");
			DocDS(f, list);
			printquestion(list, dem);
			KQ = dem;
			cout << "Moi nhap ten nguoi choi: "; cin.ignore();
			getline(cin, p.playername);
			p.bode = "de 2";
			p.scores = KQ;
			SavePlayerScore(listP, p);
			f.close();
			system("pause");
			break;
		}
		case 3:
			{
				system("cls");
				f.open("de3.txt");
				DocDS(f, list);
				printquestion(list, dem);
				KQ = dem;
				cout << "Moi nhap ten nguoi choi: "; cin.ignore();
				getline(cin, p.playername);
				p.bode = "de 3";
				p.scores = KQ;
				SavePlayerScore(listP, p);
				f.close();
				system("pause");
				break;
			}
		case 4:
		{
			system("cls");
			cout << "Diem so:" << endl;
			cout << "Ten\tDiem\tDe so" << endl;
			printlistplayer(listP);
			system("pause");
			break;
		}
		case 5:
			{
				cout << "Cam on ban da su dung chuong trinh!" << endl;
				exit(1);
				break;
			}
		}
}
int main()
{
	int dem = 0;
	ifstream infile;
	vector<Question> list;
	vector<player> listP;
	while (1)
	{
		system("cls");
		Xulymenu(list, infile,listP,dem);
	}
	//	infile.open("de1.txt");
	//	DocDS(infile,list);
	//	printquestion(list,dem);
}
