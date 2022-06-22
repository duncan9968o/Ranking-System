#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <conio.h>
#include <ctime> 

#pragma warning( disable : 4996 )

#define KEY_LEFT  75
#define KEY_RIGHT 77
#define KEY_UP    72 
#define KEY_DOWN  80
#define C         67
#define ESC       27

using namespace std;

class Rank
{
private:
	int rank[50] = { 0 };
	char title[5] = "排名";
public:
	char* getTitle()
	{
		return title;
	}
	void setrank(int index)
	{
		rank[index] = rank[index] + 1;
	}
	int getrank(int index)
	{
		return rank[index];
	}
};

class studentID
{
private:
	int ID[50] = {0};
	char title[10] = "學號";
public:
	char* getTitle()
	{
		return title;
	}
	void setid(int Number_of_people)
	{
		for (int i = 0; i < Number_of_people; i++)
		{
			ID[i] = i + 1;
		}
	}
	int getid(int j)
	{
		return ID[j];
	}
};


class score
{
private:
	int Score[50];
	int sum=0;
public:
	
	void setscore(int Number_of_people)
	{
		for (int j = 0; j < Number_of_people; j++)
		{
			Score[j] = rand() % 100;
		}
	}
	void setsum(int index)
	{
		sum = sum + Score[index];
	}
	void resetscore(int index, int score)
	{
		if (index != -1)
		{
		Score[index] = score;
		}
	}

	int returnscore(int j)
	{
		return Score[j];
	}

	float average(int numofpeople)
	{
		return (float)sum / numofpeople;
	}

};


class engscore :public score
{
private:
	int TheEngHighest = 0;
	char title[5] = "英文";
	float High_standard = 0;
	float Low_standard = 0;
public:
	Rank EngRank;
	engscore() {}
	char* getTitle()
	{
		return title;
	}
	void SetEngHightest(int numofpeople)
	{
		for (int i = 0; i < numofpeople; i++)
		{
			if (TheEngHighest < returnscore(i))
			{
				TheEngHighest = returnscore(i);
			}
		}
	}
	int GetEngHighest()
	{
		return TheEngHighest;
	}
	void SetEngHigh_standard(float number)
	{
		High_standard = number;
	}
	float GetEngHigh_standard()
	{
		return High_standard;
	}
	void SetEngLow_standard(float number)
	{
		Low_standard = number;
	}
	float GetEngLow_standard()
	{
		return Low_standard;
	}
};

class mathscore :public score
{
private:
	int TheMathHighest = 0;
	char title[5] = "數學";
	float High_standard = 0;
	float Low_standard = 0;
public:
	Rank MathRank;
	mathscore() {}
	char* getTitle()
	{
		return title;
	}
	void SetMathHightest(int numofpeople)
	{
		for (int i = 0; i < numofpeople; i++)
		{
			if (TheMathHighest < returnscore(i))
			{
				TheMathHighest = returnscore(i);
			}
		}
	}
	int GetEngHighest()
	{
		return TheMathHighest;
	}
	void SetMathHigh_standard(float number)
	{
		High_standard = number;
	}
	float GetMathHigh_standard()
	{
		return High_standard;
	}
	void SetMathLow_standard(float number)
	{
		Low_standard = number;
	}
	float GetMathLow_standard()
	{
		return Low_standard;
	}
};

class numberOfPeople
{
private:
	int Number_of_people;
public:
	void setNumber()
	{
		while (1)
		{
			cout << "輸入學生人數(10~50人) : ";
			cin >> Number_of_people;
			if (cin.fail())
			{
				system("cls");
				cin.clear();
				cin.ignore();
				cout << "請輸入有效人數\n";
				continue;
			}
			if (Number_of_people >= 10 and Number_of_people <= 50)
			{
				break;
			}
			else
			{
				system("cls");
				cout << "請輸入有效人數\n";
			}
		}
	}
	int getNumber()
	{
		return Number_of_people;
	}

};

class studentName
{
private:
	char NameElement[30][4] = { "吳","林","蔡","李","程","陳","張","周","朱","胡",    "子","志","毓","學","　","科","明","君","慧","敏",       "均","觀","銘","嘉","真","欽","翔","芬","恩","文" };
	char Name[50][8] = { 0 };
	char title[10] = "姓　名";
public:
	char* getTitle()
	{
		return title;
	}
	void setname(int NumberOfPeople)
	{
		for (int i = 0; i < NumberOfPeople; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				strcat(Name[i], NameElement[rand() % 10 + j * 10]);
			}
		}
	}
	char* GetName(int i)
	{
		return Name[i];
	}
};



class personalsum
{
private:
	int sum[50];
	char title[5] = "總分";
public:
	char* getTitle()
	{
		return title;
	}
	void setsum(int index, int score1, int score2)
	{
		sum[index] = score1 + score2;
	}
	int getpersonalsum(int index)
	{
		return sum[index];
	}
};


class student
{
public:
	engscore English;
	mathscore Math;
	numberOfPeople NumberOfPeople;
	studentName studentName;
	studentID ID;
	personalsum sum;
	Rank studentrank;
};
void print_avg(float num1, float num2)
{
	cout << "平均\t" << "\t   " << setprecision(3) << num1 << "\t  " << setprecision(3) << num2 << "\t"
		<< "\t" << endl;
}
void print_high_stadard(float num1, float num2)
{
	cout << "高標\t" << "\t   " << setprecision(3) << num1 << "\t  " << setprecision(3) << num2 << "\t"
		<< "\t" << endl;
}
void print_title(char* ID, char* Name, char* subject1, char* subject2, char* sum, char* rank)
{
	cout << ID << "\t" << Name << "\t   " << subject1 << "\t  " << subject2 << "\t" << sum << "\t" << rank << endl;
}
void print_low_stadard(float num1, float num2)
{
	cout << "低標\t" << "\t   " << setprecision(3) << num1 << "\t  " << setprecision(3) << num2 << "\t"
		<< "\t" << endl;
}

int main()
{
	//
	srand(time(NULL));
	student student;
	student.NumberOfPeople.setNumber();
	student.ID.setid(student.NumberOfPeople.getNumber());
	student.studentName.setname(student.NumberOfPeople.getNumber());
	student.English.setscore(student.NumberOfPeople.getNumber()); 
	student.English.SetEngHightest(student.NumberOfPeople.getNumber());
	student.Math.setscore(student.NumberOfPeople.getNumber()); 
	student.Math.SetMathHightest(student.NumberOfPeople.getNumber());
	
	system("cls");
	//計算總合
	for (int i = 0; i < student.NumberOfPeople.getNumber(); i++)
	{
		student.sum.setsum(i, student.English.returnscore(i), student.Math.returnscore(i));
	}
	//學號排序

	cout << student.ID.getTitle() << "\t" << student.studentName.getTitle() << "\t   " << student.English.getTitle() << "\t  " << student.Math.getTitle() << "\t" << student.sum.getTitle() << endl;
	for (int j = 0; j < student.NumberOfPeople.getNumber(); j++)
	{
		cout << student.ID.getid(j) << "\t" << student.studentName.GetName(j) << "\t   " << student.English.returnscore(j) << "\t  " << student.Math.returnscore(j) << "\t"
			<< student.sum.getpersonalsum(j) << endl;
	}
	cout << endl << "按下左鍵修改英文成績，右鍵修改數學成績，上鍵確認輸出，確認後不可再做修改";
	int Key = 0;
	while (1)
	{
		if (Key == KEY_UP)
		{
			system("cls");
			break;
		}
		
		if (_kbhit())
		{
			Key = _getch();
			if (Key == KEY_RIGHT)
			{
				while (1)
				{
					int index = 0, mathscore = 0;
					cout << "\n\n輸入欲更改者之學號及數學成績\n";
					cout << "例 : 修改二號的數學成績修改為88，則在學號處輸入2，成績輸入88\n";
					cout << "學號處輸入0即可退出修改\n\n";
					
					cout << "輸入學號 : ";
					cin >> index;
					if (index < 0 or index > student.NumberOfPeople.getNumber())
					{
						cout << "請輸入有效數字";
						continue;
					}
					else if (cin.fail())
					{
						system("cls");
						cin.clear();
						cin.ignore();
						cout << "請輸入有效數字\n";
						continue;
					}
					else if (index != 0)
					{
						cout << "輸入成績 : ";
						cin >> mathscore;
						if (mathscore < 0 or mathscore > 100)
						{
							cout << "請輸入有效數字";
							continue;
						}
						if (cin.fail())
						{
							system("cls");
							cin.clear();
							cin.ignore();
							cout << "請輸入有效數字\n";
							continue;
						}
						student.Math.resetscore(index - 1, mathscore);
					}
					if (index == 0)
					{
						
							system("cls");
							//計算總合
							for (int i = 0; i < student.NumberOfPeople.getNumber(); i++)
							{
								student.sum.setsum(i, student.English.returnscore(i), student.Math.returnscore(i));
							}
							

							//學號排序
							cout << student.ID.getTitle() << "\t" << student.studentName.getTitle() << "\t   " << student.English.getTitle() << "\t  " << student.Math.getTitle() << "\t" << student.sum.getTitle() << endl;
							for (int j = 0; j < student.NumberOfPeople.getNumber(); j++)
							{
								cout << student.ID.getid(j) << "\t" << student.studentName.GetName(j) << "\t   " << student.English.returnscore(j) << "\t  " << student.Math.returnscore(j) << "\t"
									<< student.sum.getpersonalsum(j) << endl;
							}
							cout << endl << "按下左鍵修改英文成績，右鍵修改數學成績，上鍵確認輸出，確認後不可再做修改";
							break;
					}
				}
			}
			if (Key == KEY_LEFT)
			{
				while (1)
				{
					int index = 0, englishcore = 0;
					cout << "\n\n輸入欲更改者之學號及英文成績\n";
					cout << "例 : 修改二號的英文成績修改為88，則在學號處輸入2，成績輸入88\n";
					cout << "學號處輸入0即可退出修改\n\n";

					cout << "輸入學號 : ";
					cin >> index;
					if (index < 0 or index > student.NumberOfPeople.getNumber())
					{
						cout << "請輸入有效數字";
						continue;
					}
					else if (cin.fail())
					{
						system("cls");
						cin.clear();
						cin.ignore();
						cout << "請輸入有效數字\n";
						continue;
					}
					else if (index != 0)
					{
						cout << "輸入成績 : ";
						cin >> englishcore;
						if (englishcore < 0 or englishcore > 100)
						{
							cout << "請輸入有效數字";
							continue;
						}
						if (cin.fail())
						{
							system("cls");
							cin.clear();
							cin.ignore();
							cout << "請輸入有效數字\n";
							continue;
						}
						student.English.resetscore(index - 1, englishcore);
					}
					if (index == 0)
					{

						system("cls");
						//計算總合
						for (int i = 0; i < student.NumberOfPeople.getNumber(); i++)
						{
							student.sum.setsum(i, student.English.returnscore(i), student.Math.returnscore(i));
						}
						//學號排序
						cout << student.ID.getTitle() << "\t" << student.studentName.getTitle() << "\t   " << student.English.getTitle() << "\t  " << student.Math.getTitle() << "\t" << student.sum.getTitle() << endl;
						for (int j = 0; j < student.NumberOfPeople.getNumber(); j++)
						{
							cout << student.ID.getid(j) << "\t" << student.studentName.GetName(j) << "\t   " << student.English.returnscore(j) << "\t  " << student.Math.returnscore(j) << "\t"
								<< student.sum.getpersonalsum(j) << endl;
						}
						cout << endl << "按下左鍵修改英文成績，右鍵修改數學成績，上鍵確認輸出，確認後不可再做修改";
						break;

					}
				}
			}
			if (Key == KEY_UP)
			{
				system("cls");
				break;
			}
		}
	}
	system("cls");
	//計算單科總分
	for (int i = 0; i < student.NumberOfPeople.getNumber(); i++)
	{
		student.English.setsum(i);
		student.Math.setsum(i);
	}

	//計算排名
	for (int i = 0; i < student.NumberOfPeople.getNumber(); i++)
	{
		student.studentrank.setrank(i);
		for (int j = 0; j < student.NumberOfPeople.getNumber(); j++)
		{
			if (student.sum.getpersonalsum(j) < student.sum.getpersonalsum(i))
			{
				student.studentrank.setrank(j);
			}
			if (student.English.returnscore(j) < student.English.returnscore(i))
			{
				student.English.EngRank.setrank(j);
			}
			if (student.Math.returnscore(j) < student.Math.returnscore(i))
			{
				student.Math.MathRank.setrank(j);
			}
		}
	}
	//計算高標
	float a = 0, b = 0;
	for (int i = 1; i <= student.NumberOfPeople.getNumber() / 4; i++)
	{
		for (int j = 0; j < student.NumberOfPeople.getNumber(); j++)
		{
			if (i == student.English.EngRank.getrank(j))
			{
				a = a + student.English.returnscore(j);
			}
			if (i == student.Math.MathRank.getrank(j))
			{
				b = b + student.Math.returnscore(j);
			}
		}
		if (i == student.NumberOfPeople.getNumber() / 4)
		{
			student.English.SetEngHigh_standard(a / (student.NumberOfPeople.getNumber() / 4));
			student.Math.SetMathHigh_standard(b / (student.NumberOfPeople.getNumber() / 4));
		}
	}
	//計算底標
	a = 0, b = 0;
	for (int i = student.NumberOfPeople.getNumber(); i >= student.NumberOfPeople.getNumber() - student.NumberOfPeople.getNumber() / 4; i--)
	{
		for (int j = student.NumberOfPeople.getNumber(); j > 0; j--)
		{
			if (i == student.English.EngRank.getrank(j))
			{
				a = a + student.English.returnscore(j);
			}
			if (i == student.Math.MathRank.getrank(j))
			{
				b = b + student.Math.returnscore(j);
			}
		}
		if (i == student.NumberOfPeople.getNumber() - student.NumberOfPeople.getNumber() / 4)
		{
			student.English.SetEngLow_standard(a / (student.NumberOfPeople.getNumber() / 4));
			student.Math.SetMathLow_standard(b / (student.NumberOfPeople.getNumber() / 4));
		}
	}

	//學號排序
	print_title(student.ID.getTitle(), student.studentName.getTitle(), student.English.getTitle(), student.Math.getTitle(), student.sum.getTitle(), student.studentrank.getTitle());
	for (int j = 0; j < student.NumberOfPeople.getNumber(); j++)
	{
		cout << student.ID.getid(j) << "\t" << student.studentName.GetName(j) << "\t   " << student.English.returnscore(j) << "\t  " << student.Math.returnscore(j) << "\t"
			<< student.sum.getpersonalsum(j) << "\t" << student.studentrank.getrank(j) << endl;
	}
	print_avg(student.English.average(student.NumberOfPeople.getNumber()), student.Math.average(student.NumberOfPeople.getNumber()));
	print_high_stadard(student.English.GetEngHigh_standard(), student.Math.GetMathHigh_standard());
	print_low_stadard(student.English.GetEngLow_standard(), student.Math.GetMathLow_standard());
	cout << endl << "按下右鍵可切換至排名排序，按下上鍵結束程式";

	while (1)
	{
		int Key;
		if (_kbhit())
		{
			Key = _getch();
			if (Key == KEY_LEFT)
			{
				system("cls");
				//學號排序
				print_title(student.ID.getTitle(), student.studentName.getTitle(), student.English.getTitle(), student.Math.getTitle(), student.sum.getTitle(), student.studentrank.getTitle());
				for (int j = 0; j < student.NumberOfPeople.getNumber(); j++)
				{
					cout << student.ID.getid(j) << "\t" << student.studentName.GetName(j) << "\t   " << student.English.returnscore(j) << "\t  " << student.Math.returnscore(j) << "\t"
						<< student.sum.getpersonalsum(j) << "\t" << student.studentrank.getrank(j) << endl;
				}
				print_avg(student.English.average(student.NumberOfPeople.getNumber()), student.Math.average(student.NumberOfPeople.getNumber()));
				print_high_stadard(student.English.GetEngHigh_standard(), student.Math.GetMathHigh_standard());
				print_low_stadard(student.English.GetEngLow_standard(), student.Math.GetMathLow_standard());
				cout << endl << "按下右鍵可切換至排名排序，按下上鍵結束程式";
			}
			if (Key == KEY_RIGHT)
			{
				system("cls");
				//排名排序//
				print_title(student.ID.getTitle(), student.studentName.getTitle(), student.English.getTitle(), student.Math.getTitle(), student.sum.getTitle(), student.studentrank.getTitle());
				for (int i = 1; i <= student.NumberOfPeople.getNumber(); i++)
				{
					for (int j = 0; j < student.NumberOfPeople.getNumber(); j++)
					{
						if (i == student.studentrank.getrank(j))
						{
							cout << student.ID.getid(j) << "\t" << student.studentName.GetName(j) << "\t   " << student.English.returnscore(j) << "\t  " << student.Math.returnscore(j) << "\t"
								<< student.sum.getpersonalsum(j) << "\t" << student.studentrank.getrank(j) << endl;
						}
					}
				}
				print_avg(student.English.average(student.NumberOfPeople.getNumber()), student.Math.average(student.NumberOfPeople.getNumber()));
				print_high_stadard(student.English.GetEngHigh_standard(), student.Math.GetMathHigh_standard());
				print_low_stadard(student.English.GetEngLow_standard(), student.Math.GetMathLow_standard());
				cout << endl << "按下左鍵可切換至座號排序，按下上鍵結束程式";
			}
			if (Key == KEY_UP)
			{
				break;
			}
		}
	}
	return 0;
}