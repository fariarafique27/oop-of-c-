#include<iostream>

using namespace std;
template<class t>
class Array
{
	t *data;
	int size;
	
public:	
	Array()
	{
		size=5;
		data=new t[size];
	
		for(int i=0;i<size;i++)
		{
			data[i]=0;
		}
		
	}
	Array(int s)
	{
		size=s;
		data=new t[s];
			for(int i=0;i<s;i++)
		{
			data[i]=0;	
		}
	}
	Array(const Array& obj)
	{
		this->size=obj.size;
		data=new t[size];
			for(int i=0;i<size;i++)
		{
			data[i]=obj.data[i];
		}
		
	}
	~Array()
	{
		delete [] data;
	}
	int getSize()
	{
		return size;
	}
	void setElement(t k,int i)
	{
		if(i>=0 && i< size)
		{
			
			data[i]=k;
		}
		else
		{
			cout<<"Index is not in array ";
		}
	}
	int countElement(t k)
	{
		int c=0;
		for (int i = 0; i < size; i++)
		{
			if(data[i]==k)
			{
				c++;
			}
		}
		if(c==0)
		
			return -1;
		
			return c;
	}
	Array operator=(const Array &obj)
	{
		if(this!=&obj) 		//avoid self assignment 
		{
			if(this->size!=obj.size)
			{
				this->size=obj.size;
				delete [] data;
				data=new t[size];	
			}
			for (int i = 0; i < size; i++)
			{
				data[i]=obj.data[i];
			}
		}
		return *this;
	}
	Array subArray(int s,int e)
	{
		int size=((e-s)+1);
		Array <t>obj(size);
		for (int i = 0; i < size; i++)
		{
			obj.data[i]=this->data[s];
			s++;
		}
		return obj;
	}
	
	Array operator+( Array& obj) 
	{	
		//Array <t> objN(size+obj.size);
		int a=size;
		size=size+obj.size;
		
			//Array objN(size);
			for(int i=a,j=0;i<size,j<obj.size;i++,j++)
			{
			data[i]=obj.data[j];
			}
			
			return *this;
		
	}
	
	template<class t1>
	friend ostream& operator << (ostream& out, const Array<t1>& obj) ;

	
	template<class t1>
	friend istream& operator >> (istream& in, Array<t1> & obj) ;

	bool operator==(const Array& obj)
	{		
			if(size!=obj.size)
				return false;
			
			for(int i=0;i<size;i++)
			{
				if(this->data[i]!=obj.data[i])
				return false;
			}
		return true;
	}
	//for both
	t& operator[] (int index)
	{
		if (index >= 0 && index < size)		
		{
			return data[index];				
		}

		cout << " Out-of-Bound" << endl;

		exit(0);						
	}
	t operator[] (int index) const
	{
		if (index >= 0 && index < size)		
		{
			return data[index];			
		}

		cout << " Out-of-Bound" << endl;

		exit(0);
	}
	
};
	template<class t1>
	 ostream& operator << (ostream& out, const Array<t1>& obj) 
	{
		
		for(int i=0;i<obj.size;i++)
		{
			out<<obj.data[i]<<"\t";
		}
		out<<endl;
		return out;
	}
		template<class t1>
	istream& operator >> (istream& in,  Array<t1>& obj) 
	{
		for(int i=0;i<obj.size;i++)
		{
			cout<<"Enter elemet "<<i+1<<"   :"; in>>obj.data[i];
			
		}
		cout<<endl;
		return in;
	}
	
int main()
{
	Array <int> obj1(5);
	Array <char> obj2(4);
	Array <int> obj3(5);
	cout<<obj2;
	
	cout<<"\n*********SET ELEMENT 3 in 1***********\nbefore : "<<obj1<<"\n";
	obj1.setElement(3,1);
	cout<<"Atrer : "<<obj1;
	
	cout<<"\ncount key element 3\n";
	cout<<"total specified element is : "<<obj1.countElement(3)<<endl;
	cout<<"\n sub collection 0 to 2";
	cout<<"\nobj1 :"<<obj1;
	cout << "sub collection "<< obj1.subArray(0,2)<<endl;
	cout<<"\n == operator \n";
	if(obj1==obj3)
		cout<<"\nEqual \n";
	else
	 cout<<"\n not equal \n";
	 cout<<"\n + operator onj3+obj1\n obj3 : "<<obj3;
	cout<<endl<<"obj1 : "<<obj1<<endl;
	obj3+obj1;
	cout<<"obj3 after: "<<obj3;
	cout<<"\n[] for r value: "<<obj1[1];
	obj1[2]=8;
	cout<<"\n[] for both l r value "<<obj1[2];

return 0;
}

