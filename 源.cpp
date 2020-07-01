#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<utility>
#include <iterator>
using namespace std;
class StudentCourse {
private:
	string course_;
	float credits_;
	int score_;
public:
	StudentCourse(string course, float credits, int score) :
		course_(course), credits_(credits), score_(score) {}
	string getcourse_()const { return course_; }
	float getcredits_()const { return credits_; }
	int getscore_()const { return score_; }
	void show() {
		cout << getcourse_() << " "
			<< getcredits_() << " " << getscore_();
	}
};
//把所有数据全部封装起来，方便排序时所用
class StudentCourse2 {
private:
	int id_2;
	string course_2;
	float credits_2;
	int score_2;
public:
	StudentCourse2(int id, string course, float credits, int score) :
		id_2(id), course_2(course), credits_2(credits), score_2(score) {}
	int getid_()const { return id_2; }
	string getcourse_()const { return course_2; }
	float getcredits_()const { return credits_2; }
	int getscore_()const { return score_2; }
	void show() {
		cout << getcourse_() << " "
			<< getcredits_() << " " << getscore_();
	}
};
class StudentInfo {
private:
	string name_;
	string sex_;
	string birthday_;
	int school_year_;
	string birthplace_;
public:
	StudentInfo(string name, string sex, string birthday,
		int school_year, string birthplace) :
		name_(name), sex_(sex), birthday_(birthday),
		school_year_(school_year), birthplace_(birthplace) {}
	string getname()const { return name_; }
	string getsex()const { return sex_; }
	string getbirthday()const { return birthday_; }
	int getschool_year()const { return school_year_; }
	string getbirthplace()const { return birthplace_; }
	void display() {
		cout << getname() << " " << getsex() << " " << getbirthday() << " "
			<< getschool_year() << " " << getbirthplace();
	}
};
//为了方便排序，将全部数据封装起来
class StudentInfo2 {
private:
	int id2;
	string name2;
	string sex2;
	string birthday2;
	int school_year2;
	string birthplace2;
public:
	StudentInfo2(int id, string name, string sex, string birthday,
		int school_year, string birthplace) :id2(id),
		name2(name), sex2(sex), birthday2(birthday),
		school_year2(school_year), birthplace2(birthplace) {}
	int getid()const { return id2; }
	string getname()const { return name2; }
	string getsex()const { return sex2; }
	string getbirthday()const { return birthday2; }
	int getschool_year()const { return school_year2; }
	string getbirthplace()const { return birthplace2; }
	void display() {
		cout << getid() << " " << getname() << " " << getsex() << " " << getbirthday() << " "
			<< getschool_year() << " " << getbirthplace();
	}
};
//根据各个字段排序
void SortByName(multimap<int, StudentInfo2>s)//根据姓名排序
{
	vector<StudentInfo2>n;
	multimap<string, StudentInfo2>n1;
	for (multimap<int, StudentInfo2>::iterator iter = s.begin();iter != s.end();++iter)
		n1.insert(make_pair(((iter->second).getname()), iter->second));
	for (multimap<string, StudentInfo2>::iterator iter2 = n1.begin();iter2 != n1.end();++iter2)
		n.push_back(iter2->second);
	for (vector<StudentInfo2>::iterator iter3 = n.begin();iter3 != n.end();++iter3)
	{
		(*iter3).display();
		cout << endl;
	}
}
void SortBySex(multimap<int, StudentInfo2>s)//根据性别排序
{
	vector<StudentInfo2>n;
	multimap<string, StudentInfo2>n1;
	for (multimap<int, StudentInfo2>::iterator iter = s.begin();iter != s.end();++iter)
		n1.insert(make_pair(((iter->second).getsex()), iter->second));
	for (multimap<string, StudentInfo2>::iterator iter2 = n1.begin();iter2 != n1.end();++iter2)
		n.push_back(iter2->second);
	for (vector<StudentInfo2>::iterator iter3 = n.begin();iter3 != n.end();++iter3)
	{
		(*iter3).display();
		cout << endl;
	}
};
void SortByBirthday(multimap<int, StudentInfo2>s)//根据生日排序
{
	vector<StudentInfo2>n;
	multimap<string, StudentInfo2>n1;
	for (multimap<int, StudentInfo2>::iterator iter = s.begin();iter != s.end();++iter)
		n1.insert(make_pair(((iter->second).getbirthday()), iter->second));
	for (multimap<string, StudentInfo2>::iterator iter2 = n1.begin();iter2 != n1.end();++iter2)
		n.push_back(iter2->second);
	for (vector<StudentInfo2>::iterator iter3 = n.begin();iter3 != n.end();++iter3)
	{
		(*iter3).display();
		cout << endl;
	}
};
void SortBySchool_year(multimap<int, StudentInfo2>s)//根据学年排序
{
	vector<StudentInfo2>n;
	multimap<int, StudentInfo2>n1;
	for (multimap<int, StudentInfo2>::iterator iter = s.begin();iter != s.end();++iter)
		n1.insert(make_pair(((iter->second).getschool_year()), iter->second));
	for (multimap<int, StudentInfo2>::iterator iter2 = n1.begin();iter2 != n1.end();++iter2)
		n.push_back(iter2->second);
	for (vector<StudentInfo2>::iterator iter3 = n.begin();iter3 != n.end();++iter3)
	{
		(*iter3).display();
		cout << endl;
	}
};
void SortByBirthplace(multimap<int, StudentInfo2>s)//根据出生地排序
{
	vector<StudentInfo2>n;
	multimap<string, StudentInfo2>n1;
	for (multimap<int, StudentInfo2>::iterator iter = s.begin();iter != s.end();++iter)
		n1.insert(make_pair(((iter->second).getbirthplace()), iter->second));
	for (multimap<string, StudentInfo2>::iterator iter2 = n1.begin();iter2 != n1.end();++iter2)
		n.push_back(iter2->second);
	for (vector<StudentInfo2>::iterator iter3 = n.begin();iter3 != n.end();++iter3)
	{
		(*iter3).display();
		cout << endl;
	}
};
void SortByScore(multimap<int, StudentCourse2>ss1) //按分数排序
{
	vector<StudentCourse2>p;
	multimap<int, StudentCourse2>ss;
	for (multimap<int, StudentCourse2>::iterator iter = ss1.begin();iter != ss1.end();++iter)
	{
		ss.insert(make_pair((iter->second).getscore_(), iter->second));
	}
	for (multimap<int, StudentCourse2>::iterator iter2 = ss.begin();iter2 != ss.end();++iter2)
	{
		p.push_back(iter2->second);
	}
	for (vector<StudentCourse2>::iterator iter3 = p.begin();iter3 != p.end();++iter3)
	{
		(*iter3).show();
		cout << endl;
	}
};
//查询和删除操作
void Checkcourse(multimap<int, StudentCourse>s1)//查询并删除某一课程
{
	string course;
	cout << "输入你想要删除的课程:";
	cin >> course;
	cout << "查询结果为:" << endl;
	for (multimap<int, StudentCourse>::iterator iter = s1.begin();iter != s1.end();++iter)
	{
		if (((iter->second).getcourse_()) == course)
		{
			cout << iter->first << " ";
			(iter->second).show();
			cout << endl;
		}
	}
	cout << "删除后:" << endl;
	for (multimap<int, StudentCourse>::iterator iter1 = s1.begin();iter1 != s1.end();++iter1)
	{
		if ((iter1->second).getcourse_() == course)
		{
			;
		}
		else {
			cout << iter1->first << " ";
			(iter1->second).show();
			cout << endl;
		}
	}
};
void Checkscore(multimap<int, StudentCourse>s1) //查询并删除不及格的成绩
{
	cout << "查询结果:" << endl;
	for (multimap<int, StudentCourse>::iterator iter = s1.begin();iter != s1.end();++iter)
	{
		if ((iter->second).getscore_() < 60)
		{
			cout << iter->first << " ";
			(iter->second).show();
			cout << endl;
		}
	}
	cout << "删除后:" << endl;
	for (multimap<int, StudentCourse>::iterator iter1 = s1.begin();iter1 != s1.end();++iter1)
	{
		if (((iter1->second).getscore_()) < 60)
		{
			;
		}
		else {
			cout << iter1->first << " ";
			(iter1->second).show();
			cout << endl;
		}
	}
};
void Checkid(multimap<int, StudentCourse>s1, map<int, StudentInfo>s2)//查询并删除某一学生
{
	int count;
	cout << "请输入你想要查询并删除的学生id:";
	cin >> count;
	cout << "查询结果为:" << endl;
	for (map<int, StudentInfo>::iterator iter = s2.begin();iter != s2.end();++iter)
	{
		if (iter->first == count)
		{
			cout << iter->first << " ";
			(iter->second).display();
			cout << endl;
		}
	}
	for (multimap<int, StudentCourse>::iterator iter1 = s1.begin();iter1 != s1.end();++iter1)
	{
		if (iter1->first == count)
		{
			cout << iter1->first << " ";
			(iter1->second).show();
			cout << endl;
		}
	}
	cout << "删除后:" << endl;
	for (multimap<int, StudentCourse>::iterator iter2 = s1.begin();iter2 != s1.end();++iter2)
	{
		if (iter2->first == count)
		{
			;
		}
		else {
			cout << iter2->first << " ";
			(iter2->second).show();
			cout << endl;
		}
	}
	for (multimap<int, StudentInfo>::iterator iter3 = s2.begin();iter3 != s2.end();++iter3)
	{
		if (iter3->first == count)
		{
			;
		}
		else {
			cout << iter3->first << " ";
			(iter3->second).display();
			cout << endl;
		}
	}
};
void Check(multimap<int, StudentCourse>s1, map<int, StudentInfo>s2)//多条件删除
{
	cout << "查询性别男，学年为2018级或者分数少于80的学生" << endl;
	cout << "查询结果为:" << endl;
	for (map<int, StudentInfo>::iterator iter = s2.begin();iter != s2.end();++iter)
	{
		if ((iter->second).getsex() == "male")
		{
			for (multimap<int, StudentCourse>::iterator iter1 = s1.begin();iter1 != s1.end();++iter1)
			{
				if (((iter->second).getschool_year() == 2018) || (((iter1->second).getscore_()) < 80))
				{
					cout << iter->first << " ";
					(iter->second).display();
					cout << endl;
					cout << iter1->first << " ";
					(iter1->second).show();
					cout << endl;
				}
			}
		}
	}
};
//打印相关的信息到文件result.txt中
void Test(multimap<int, StudentCourse>s1, map<int, StudentInfo>s2)
{
	string filename;
	int t = 0;
	cout << "Enter name for new file:";
	cin >> filename;
	ofstream fout(filename.c_str());
	fout << "2018级选修C语言且成绩小于60分的学生:" << endl;
	for (multimap<int, StudentCourse>::iterator iter1 = s1.begin();iter1 != s1.end();++iter1)
		if (((iter1->second).getscore_() < 60) && ((iter1->second).getcourse_() == "CProgrammingLanguage"))
		{
			for (map<int, StudentInfo>::iterator iter2 = s2.begin();iter2 != s2.end();++iter2)
				if (((iter2->first) == (iter1->first)) &&
					((iter2->second).getschool_year() == 2018))
				{
					fout << iter2->first << " " << (iter2->second).getname() << " "
						<< (iter2->second).getsex() << " " << (iter2->second).getbirthday()
						<< " " << (iter2->second).getschool_year() << " " << (iter2->second).getbirthplace();
					fout << endl;
					fout << iter1->first << " " << (iter1->second).getcourse_() << " "
						<< (iter1->second).getcredits_() << " " << (iter1->second).getscore_();
					fout << endl;
					t = 1;
				}
		}
	if (t == 0)
		fout << "没有满足要求的学生" << endl;
	fout << "课程平均分大于80的学生个人信息:" << endl;
	typedef multimap<int, StudentCourse>::iterator ScoreIter;
	int count;
	double m;//记录总分
	double n;//记录平均分
	for (map<int, StudentInfo>::iterator iter2 = s2.begin();iter2 != s2.end();++iter2)
	{
		m = 0;n = 0;
		count = s1.count(iter2->first);
		pair<ScoreIter, ScoreIter>rang = s1.equal_range(iter2->first);
		for (ScoreIter iter = rang.first;iter != rang.second;++iter)
		{
			m += (iter->second).getscore_();
		}
		n = m / count;
		if (n >= 80)
			fout << iter2->first << " " << (iter2->second).getname() << " "
			<< (iter2->second).getsex() << " " << (iter2->second).getbirthday()
			<< " " << (iter2->second).getschool_year() << " " << (iter2->second).getbirthplace() << endl;

	}
	fout << "查询每个学生是否修满10/15/20学分" << endl;
	for (map<int, StudentInfo>::iterator iter2 = s2.begin();iter2 != s2.end();++iter2)
	{
		m = 0;
		fout << iter2->first << " " << (iter2->second).getname() << " "
			<< (iter2->second).getsex() << " " << (iter2->second).getbirthday()
			<< " " << (iter2->second).getschool_year() << " " << (iter2->second).getbirthplace();
		pair<ScoreIter, ScoreIter>rang = s1.equal_range(iter2->first);
		for (ScoreIter iter = rang.first;iter != rang.second;++iter)
		{
			if ((iter->second).getscore_() > 60)
			{
				m += (iter->second).getcredits_();
			}
		}
		fout << endl;
		fout << "学分:" << m << endl;
		if (m >= 10)
			fout << "已修满10学分;" << endl;
		else fout << "未修满10学分;" << endl;
		if (m >= 15)
			fout << "已修满15学分;" << endl;
		else fout << "未修满15学分;" << endl;
		if (m >= 20)
			fout << "已修满20学分;" << endl;
		else fout << "未修满20学分;" << endl;
	}
}
int main()
{
	multimap<int, StudentCourse>s1;//存储StudentCourse.txt里面的信息
	map<int, StudentInfo>s2;//存储StudentInfo.txt里面的信息
	multimap<int, StudentInfo2>m1;//方便排序时所用
	multimap<int, StudentCourse2>ss1;
	ifstream fin1;
	ifstream fin2;
	fin1.open("StudentCourse.txt");
	fin2.open("StudentInfo.txt");
	int id;
	string course;
	float credits;
	int score;
	int id_;
	string name;
	string sex;
	string birthday;
	int school_year;
	string birthplace;
	while (fin1.good())
	{
		fin1 >> id;
		fin1 >> course;
		fin1 >> credits;
		fin1 >> score;
		StudentCourse s(course, credits, score);
		StudentCourse2 p(id, course, credits, score);
		s1.insert(make_pair(id, s));
		ss1.insert(make_pair(id, p));
	}
	while (fin2.good())
	{
		fin2 >> id_;
		fin2 >> name;
		fin2 >> sex;
		fin2 >> birthday;
		fin2 >> school_year;
		fin2 >> birthplace;
		StudentInfo ss(name, sex, birthday, school_year, birthplace);
		StudentInfo2 mm(id_, name, sex, birthday, school_year, birthplace);
		s2.insert(make_pair(id_, ss));
		m1.insert(make_pair(id_, mm));
	}
	//打印两表的信息
	for (multimap<int, StudentCourse>::iterator iter1 = s1.begin();iter1 != s1.end();++iter1)
	{
		cout << iter1->first << " ";
		(iter1->second).show();
		cout << endl;
	}
	for (multimap<int, StudentInfo>::iterator iter2 = s2.begin();iter2 != s2.end();++iter2)
	{
		cout << iter2->first << " ";
		(iter2->second).display();
		cout << endl;
	}
	fin1.close();
	fin2.close();
	cout << "按姓名排序:" << endl;
	SortByName(m1);
	cout << "按性别排序:" << endl;
	SortBySex(m1);
	cout << "按生日排序:" << endl;
	SortByBirthday(m1);
	cout << "按出生地排序:" << endl;
	SortByBirthplace(m1);
	Checkcourse(s1);
	Checkid(s1, s2);
	Test(s1, s2);
	return 0;
}