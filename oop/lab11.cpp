 #include<iostream>
#include<string.h>
#include<math.h>

using namespace std;

class FeetInches
{
private:
	int feet;			// To hold a number of feet
	int inches;			// To hold a number of inches

	void simplify()
	{
		if (inches >= 12)
		{
			feet += (inches / 12);
			inches = inches % 12;
		}
		else if (inches < 0)
		{
			feet -= ((abs(inches) / 12) + 1);
			inches = 12 - (abs(inches) % 12);
		}
	}

public:
	// Constructor
	FeetInches(int f = 0, int i = 0)
	{
		feet = f;
		inches = i;
		simplify();
		cout<<" D\n";
	}

	FeetInches(const FeetInches& right)
	{
		feet = right.feet;
		inches = right.inches;
		simplify();
		cout<<" copy\n";
	}

	// Mutator functions
	void setFeet(int f)
	{
		feet = f;
	}

	void setInches(int i)
	{
		inches = i;
		simplify();
	}

	// Accessor functions
	int getFeet() const
	{
		return feet;
	}

	int getInches() const
	{
		return inches;
	}

	FeetInches operator + (const FeetInches& right)
	{
		FeetInches temp;

		temp.inches = inches + right.inches;
		temp.feet = feet + right.feet;
		temp.simplify();

		return temp;
	}

	FeetInches operator - (const FeetInches& right)
	{
		FeetInches temp;

		temp.inches = inches - right.inches;
		temp.feet = feet - right.feet;
		temp.simplify();

		return temp;
	}

	FeetInches operator * (const FeetInches& right)
	{
		FeetInches temp;

		temp.inches = inches * right.inches;
		temp.feet = feet * right.feet;
		temp.simplify();

		return temp;
	}

	FeetInches operator ++ ()
	{
		++inches;
		simplify();

		return *this;
	}

	FeetInches operator ++ (int)
	{
		FeetInches temp(feet, inches);

		inches++;
		simplify();

		return temp;
	}

	FeetInches operator -- ()
	{
		--inches;
		simplify();

		return *this;
	}

	FeetInches operator -- (int)
	{
		FeetInches temp(feet, inches);

		inches--;
		simplify();

		return temp;
	}

	bool operator > (const FeetInches& right)
	{
		bool status;

		if (feet > right.feet)
			status = true;
		else if (feet == right.feet && inches > right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	bool operator < (const FeetInches& right)
	{
		return !(*this > right);
	}

	bool operator >= (const FeetInches& right)
	{
		bool status;

		if (feet >= right.feet)
			status = true;
		else if (feet == right.feet && inches >= right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	bool operator <= (const FeetInches& right)
	{
		return !(*this >= right);
	}

	bool operator == (const FeetInches& right)
	{
		bool status;

		if (feet == right.feet && inches == right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	bool operator != (const FeetInches& right)
	{
		return !(*this == right);
	}

	friend ostream& operator << (ostream&, const FeetInches&);
	friend istream& operator >> (istream&, FeetInches&);
};

ostream& operator << (ostream& out, const FeetInches& obj)
{
	out << "Feet = " << obj.feet << "\tInches = " << obj.inches << endl;

	return out;
}

istream& operator >> (istream& in, FeetInches& obj)
{
	cout << "Enter Feet:\t";
	in >> obj.feet;

	cout << "Enter Inches:\t";
	in >> obj.inches;

	return in;
}
class  RoomDimension
{
	FeetInches length, width;
	public:
		void setL(FeetInches obj)
		{
			length.setFeet(obj.getFeet());
			length.setInches(obj.getInches());
		}
		void setF(FeetInches obj)
		{
			width.setFeet(obj.getFeet());
			width.setInches(obj.getInches());
		}
		FeetInches getL()
		{
			return length;
		}
		FeetInches getW()
		{
			return width;
		}
		RoomDimension( FeetInches l ,FeetInches w ) : length(l), width(w)
		{
//			length.setFeet(l.getFeet());
//			length.setInches(l.getInches());
//			width.setFeet(w.getFeet());
//			width.setInches(w.getInches()); 
			cout<<" room \n";
		}
		FeetInches area()
		{
			FeetInches a=length*width;
			return a;
		}
		void print()
		{
			cout<< length;
			cout<<width;
			
		}
		
};
class RoomCarpet
{
	 RoomDimension roomsize;
	 float costPerSquareFoot;
	 
	 public:
	 	void setC(float c)
	 	{
	 		costPerSquareFoot=c;
		 }
		void setSize(RoomDimension r) 
		{
			roomsize.setL(r.getL());
			roomsize.setF(r.getW());

		}
		RoomCarpet(RoomDimension r , float c ) : roomsize(r.getL(),r.getW())
		{
			costPerSquareFoot=c;
		}
		double totalCost()
		{
		//	double a = roomsize.area.getFeet()+(roomsize.area().getInches()/12);
			double a= (roomsize.area().getFeet()+(roomsize.area().getInches()/12)) *costPerSquareFoot;
			if(a>0)
			return a;
			else
			return 0;
		}
		void printt()
		{
			//cout<<" room size length  "<<roomsize.getL().getFeet()<<" feet "<< roomsize.getL().getInches() << " inches ";
			//cout<<" room size width "<<roomsize.getW().getFeet()<<" feet "<< roomsize.getW().getInches() << " inches ";
			roomsize.print();
			cout<<" cost "<<costPerSquareFoot;

			
		}
};
int main()
{	
	FeetInches o(1,2),p(3,4);
	cin>>o;
	cin>>p;
	RoomDimension obj1(o,p);
//	FeetInches a=obj1.area();
//		cout<<obj1.getL().getFeet();
//	cout<<obj1.getL().getInches();
//	obj1.print();
	
	float c; cout<<" enter cost : "; cin>>c;
	
	RoomCarpet cost(obj1, c);
	cost.printt();
	cout<<" $ "<<cost.totalCost();
	return 0;
}
