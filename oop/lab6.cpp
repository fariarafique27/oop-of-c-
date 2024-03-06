#include<iostream>

using namespace std;

class Student 
{
	int regNo;
	string firstName;
	string lastName;
	string program;
	float cgpa;
public:	
	void setRegNo(int r)
	{
		if(r>=501&&r<=506)
			regNo=r;
		else
			regNo=0;
	}
	int getReg()
	{
		return regNo;
	}
	
	void setFirst(string firstName)	
	{
		this->firstName=firstName;
	}
	string getFirst()
	{
		return firstName;
	}
	
	void setLast(string lastName)
	{
		this->lastName=lastName;
	}
	string getLast()
	{
		return lastName;
	}
	
	void setProgram(string program)
	{
		this->program=program;
	}
	string getProgram()
	{
		return program;
	}
	
	void setCgpa(float g)
	{
		if(g>=0&&g<=4.00)
			cgpa=g;
		else
			cgpa=-1;
	}
	float getCgpa()
	{
		return cgpa;
	}
	
	Student(int r,string f,string l,string p)
	{
		setRegNo(r);
		setFirst(f);
		setLast(l);
		setProgram(p);
		cgpa=-1;
	}
	Student(int r,string f,string p)
	{
		setRegNo(r);
		setFirst(f);
		setProgram(p);
		lastName="";
		cgpa=-1;
	}
	Student(int r,string f,string l,string p,float g)
	{
		setRegNo(r);
		setFirst(f);
		setLast(l);
		setProgram(p);
		setCgpa(g);
	}
	Student(const Student& s)
	{
		regNo=s.regNo;
		firstName=s.firstName;
		lastName=s.lastName;
		program=s.program;
		cgpa=s.cgpa;
	}
	~Student ()							//destructor 
	{
		cout<<"\ndestructor executed.... ";
	}
	
	void set(int r,string f,string l,string p,float g)
	{
		setRegNo(r);
		setFirst(f);
		setLast(l);
		setProgram(p);
		setCgpa(g);
	}
	void read()
	{
		cout<<"Enter Reg no : "; cin>>regNo; setRegNo(regNo);
		cout<<"Enter First name : ";cin>>firstName; setFirst(firstName); 
		cout<<"Enter last name : ";cin>>lastName; setFirst(lastName); 
		cin.ignore();
		cout<<"Enter program name : ";getline(cin,program); setFirst(program); 
		cout<<"Enter CGPA : "; cin>>cgpa; setCgpa(cgpa);
	}	
	void write()
	{
	cout<<"\nRegNo : "<<this->regNo<<"\tfirstName : "<<this->firstName<<"\tlastName : "<<this->lastName<<"\tProgram : "<<this->program<<"\tCGPA : "<<this->cgpa;
	}
	
	bool isfirstsemester()
	{
		if(cgpa==-1)
			return true;
		else
		 return false;
	}
	double getPercent()
	{	
		if(cgpa>=0.00)
		 	{
		 		return (cgpa/4)*100;	
			}
		else 
			return -1;
	}
	bool getPromoted()
	{
		if(cgpa>2.00)
			return true;
		else
			return false;
	}
	
};

int main()
{
	Student s(1,"AHMAD","ANWAR","SE"),s1(1,"AROOB","HAMID","SE",-1),s2(1,"amna","IT"),s3(s1),s4(1,"Aqba","HAMID","SE",3);
	
	s2.set(2,"AYZA","HAMID","CS",5);
	s1.read();
	cout<<"\nData of s: \n ";
	s.write();
	cout<<"\nData of s1: \n ";
	s1.write();
	cout<<"\nData of s2: \n ";
	s2.write();
	cout<<"\nData of s3: \n ";
	s3.write();
	cout<<"\nData of s4: \n ";
	s4.write();
	cout<<"\n--------------------\n";
	
	if(s3.isfirstsemester())
		cout<<"\nS3 is in 1ST semester ";
	else 
		cout<<"Not in 1st semester ";
	cout<<"\n--------------------\n";
	
	cout<<"Percentage of S4 is : "<<s4.getPercent();
	cout<<"\n--------------------\n";
	
	if(s3.getPromoted())
		cout<<"S3 is promoted ";
	else 
		cout<<"Not promoted ";
	cout<<"\n--------------------\n";
	
	
	return 0;
}
