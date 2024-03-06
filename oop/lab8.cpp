#include<iostream>

using namespace std;

class Date
{
	int day;
	int month;
	int year;
	
	void setD(int d)
	{
		if(d>=1&&d<=31)	
			day=d;
		else 
			day=1;
	}
	void setM(int m)
	{
		if(m>=1&&m<=12)	
			month=m;
		else 
			month=1;
	}
	void setY(int y)
	{
		if(y>=1900)	
			year=y;
		else 
			year=1900;
	}
	int getD()
	{ 
		return day;
	}
	int getM()
	{ 
		return month;
	}
	int getY()
	{ 
		return year;
	}
	public:
	
	Date(int d,int m ,int y)
	{
		setD(d);
		setM(m);
		setY(y);
	}
	Date(int m ,int y)
	{
		day=1;
		setM(m);
		setY(y);
	}
	Date()
	{
		day=1;
		month=1;
		year=1900;
	}
	
	friend ostream& operator<<(ostream &out, Date &obj)
	{
		string m[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
		int a=(obj.month)-1;
		out<<"\n"<<m[a]<<"  "<<obj.day<<","<<obj.year;
		return out;
	}
	friend istream& operator>>(istream&in, Date &obj)
	{	
		cout<<"\nEnter date :";  in>> obj.day; obj.setD(obj.day);
		cout<<"Enter month :";  in>>obj.month; obj.setM(obj.month);
		cout<<"Enter year :"; in>>obj.year; obj.setY(obj.year);
		return in;
	}
	Date operator++()
	{
		++day;
	 	if(day==31&&month==12)
		{
			day=1;
			month=1;
			year=year+1;
		}
		if(day==31)
		{
			day=1;
			month=month+1;
		}
		
		return *this;
	}
	Date operator++(int)
	{
		Date oldState(*this);
		day++;
			if(day==31&&month==12)
		{
			day=1;
			month=1;
			year=year+1;
		}
		if(day==31)
		{
			day=1;
			month=month+1;
		}
		return oldState;
	}
	Date operator--()
	{
		--day;
		
		if(day==0&&month==1)
		{
			day=30;
			month=12;
			year=year-1;
			setY(year);
		}
		if(day==0)
		{
			day=30;
			month=month-1;
		}
		return *this;
	}
	Date operator--(int)
	{
		Date oldState(*this);
		day--;
		if(day==0&&month==1)
		{
			day=31;
			month=12;
			year=year-1;
			setY(year);
		}
		if(day==0)
		{
			day=30;
			month=month-1;
		}
		return oldState;
	}
	int operator-(const Date&obj)
	{
		int a=year-(obj.year);
		if(a<0)
		{
			a=a*(-1);
		}
		int b=month-( obj.month);
		if(b<0)
		{
			b=b*(-1);
		}
		int c=day-(obj.day);
		if(c<0)
		{
			c=c*(-1);
		}
		return (c+(b*30)+(a*365));
	}
	bool operator+()
	{
		if((day==5&&month==2)||(day==23&&month==3)||(day==1&&month==5))
			return true;
	
		return		false;
	}
};

int main()
{
	Date d(5,2,2021),d1,d2(5,2,2020),d3(30,2,2020),d4(30,12,2020),d6(1,6,1900),d8(1,1,1900);
	cout<<d;
	cout<<"\n-------------------------";
	
	cin>>d1;
	cout<<d1;
	cout<<"\n-------------------------";
	
	cout<<"\nNumber of days "<<d-d1;
	cout<<"\n-------------------------";
	
	if(+d2)
		cout<<"\nPublic holiday ";
	else
		cout<<"\nNOT public holiday";
	cout<<"\n-------------------------";
	cout<<"\nPre increment on 30-2-2020 ";
	++d3;
	cout<<"\n"<<d3;
	cout<<"\nPre increment on 30-12-2020 ";
	++d4;
	cout<<"\n"<<d4;
	cout<<"\n-------------------------";
	
	cout<<"\nPost increment on 5-2-2021 ";
	Date d7=d++;
	cout<<d7;
	cout<<d;
	cout<<"\nPre decrement on 1-6-1900 ";
	--d6;
	cout<<"\n"<<d6;
	cout<<"\n-------------------------";
	cout<<"\nPre decrement on 1-1-1900 ";
	--d8;
	cout<<"\n"<<d8;
	cout<<"\n-------------------------";
	cout<<"\nPost decrement on 1-1-1900 ";
	Date d9=d8--;
	cout<<"\n"<<d9;
	cout<<"\n"<<d8;
	cout<<"\n-------------------------";
	
	return 0;
}
