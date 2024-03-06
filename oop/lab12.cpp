# include<iostream>
# include<string.h>
using namespace std;

class Employee
{
	string firstN, lastN,SSN;
	public : 
	Employee(string f=" ", string l=" ", string s=" ")
	{
		firstN=f;
		lastN=l;
		SSN=s;
	}
	void setF(string f)
	{
		firstN=f;
	}
	void setL(string l)
	{
		lastN=l;
	}
	void setS(string s)
	{
		SSN=s;
	}
	string getF()
	{
		return firstN;
	}
	string getl()
	{
		return lastN;
	}
	string gets()
	{
		return SSN;
	}
	virtual void display()
	{
		cout<<endl<<firstN+lastN<<endl<<SSN<<endl;
	}
	virtual double earning()=0;
};
class SalariedEmployee : public Employee
{
	double weeklySalary;
	public :
		SalariedEmployee(double w=0,string f ="",string l="" ,string s="") : Employee(f,l,s)
		{
			weeklySalary=w;
		}
		double getSalray()
		{
			return weeklySalary;
		}
		void setSalary(double s)
		{
			weeklySalary=s;
		}
		void display()
		{
			Employee::display();
			cout<<"weeklySalary : "<<weeklySalary<<endl;
		}
		double earning()
		{
			return weeklySalary*4;
		}
};
class HourlyEmployee : public Employee
{
	double wage, hours;
	public :
		HourlyEmployee(double w=0, double h=0,string f=" " ,string l=" " ,string s=" ")	: Employee(f,l,s)
		{
			wage=w;
			hours=h;
		}
		void setW(double w)
		{
			wage=w;
		}
		void setH(double h)
		{
			hours=h;
		}
		double getW()
		{
			return wage;
		}
		double getH()
		{
			return hours;
		}
		void display()
		{
			Employee::display();
			cout<<"wage : "<<wage<<endl<<"hours : "<<hours<<endl;
		}
		double earning()
		{
			return hours*wage;
		}
};
class CommissionEmployee  : public Employee
{
	double grossSales , commissionRate;
	public :
		CommissionEmployee(double g=0,double c=0,string f=" " ,string l=" " ,string s=" ")  : Employee(f,l,s)
		{
			grossSales=g;
			commissionRate=c;
		}
		void setG(double g)
		{
			grossSales=g;
		}
		void setC(double c)
		{
			commissionRate=c;
		}
		double getG()
		{
			return grossSales;
		}
		double getC()
		{
			return commissionRate ;
		}
		void display()
		{
			Employee::display();
			cout<<"GrossSales : "<<grossSales<<endl<<"commissionRate : "<<commissionRate<<endl;
		}
		double earning()
		{
			return grossSales*commissionRate;
		}
};
class BasePlusCommissionEmployee : public CommissionEmployee
{
	double baseSalary;
	public:
		BasePlusCommissionEmployee(double b=0,double g=0 ,double c=0,string f=" ",string l=" ",string s= " ") : CommissionEmployee(g,c,f,l,s)
		{
			baseSalary=b;
		}
		void setB(double b)
		{
			baseSalary=b;
		}
		double getB()
		{
			return baseSalary;
		}
		void display()
		{
			CommissionEmployee::display();
			cout<<" base salary : "<<baseSalary;
		}
		double earning()
		{
			 
			double a =CommissionEmployee::earning() ;
			return a+ (baseSalary);
		}
};

int main ()
{
	Employee *p[4];
	SalariedEmployee s(1,"aroob "," hamid ","12q");
	//SalariedEmployee s;
	s.display();
	cout<<s.earning()<<" Rs "<<endl;
	HourlyEmployee h(2,4,"aroob "," hamid ","13e");
	h.display();
	cout<<h.earning()<<" Rs "<<endl;
	CommissionEmployee c(2,5,"aroob "," hamid ","13e");
	c.display();
	cout<<c.earning()<<" Rs "<<endl; 
	BasePlusCommissionEmployee b(10 ,2,2 ,"aroob "," hamid ","13e");
	b.display();
	cout<<endl<<b.earning()<<" Rs "<<endl;
	p[0]=&s;p[1]=&h;p[2]=&c;p[3]=&b;
	for(int i=0;i<4;i++)
	{
		p[i]->display(); 
		cout<<endl;
		
		cout<<p[i]->earning(); 
	}
}
