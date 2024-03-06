#include<iostream>

using namespace std;
class Collection
{
	int *data;
	int size;
	
public:	
	Collection(int s)
	{
		size=s;
		data=new int[s];
	
		for(int i=0;i<s;i++)
		{
			data[i]=0;
		}
		
	}
	Collection(int a[], int s)
	{
		size=s;
		data=new int[s];
			for(int i=0;i<s;i++)
		{
			data[i]=a[i];
			if(	data[i]>0)
			{
					data[i]=0;
			}
		}
	
	}
	Collection(const Collection& obj)
	{
		this->size=obj.size;
		data=new int[size];
			for(int i=0;i<size;i++)
		{
			data[i]=obj.data[i];
				if(	data[i]>0)
			{
					data[i]=0;
			}
		}
		
	}
	~Collection()
	{
		delete [] data;
	}
	
	int getSize()
	{
		return size;
	}
	void setElement(int k,int i)
	{
		if(i>=0 && i< size)
		{
			if(k>0)
			{
				data[i]=k;
			}
			else
				data[i]=0;
		
		}
		else
		{
			cout<<"Index is not in array ";
		}
	}
	//member function to display ar
	void putData() const
	{
		for (int i = 0; i < size; i++)
		{
			cout << data[i] << "\t";
		}

		cout << endl;
	}
	int countElement(int k)
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
		{
			return -1;
		}
		else
		{
			return c;
		}
	}
	
	Collection operator=(const Collection &obj)
	{
		if(this!=&obj)
		{
			if(this->size!=obj.size)
			{
				this->size=obj.size;
				delete [] data;
				data=new int[size];	
			}
			for (int i = 0; i < size; i++)
			{
				data[i]=obj.data[i];
			}
		}
		return *this;
	}
	Collection subCollection(int s,int e)
	{
		int size=((e-s)+1);
		Collection obj(size);
		for (int i = 0; i < size; i++)
		{
			obj.data[i]=this->data[s];
			s++;
		}
		return obj;
	}
	friend ostream& operator << (ostream& out, const Collection& obj) 
	{
		
		for(int i=0;i<obj.size;i++)
		{
			out<<obj.data[i]<<"\t";
		}
		out<<endl;
		return out;
	}
	friend istream& operator >> (istream& in,  Collection& obj) 
	{
		
		for(int i=0;i<obj.size;i++)
		{
			cout<<"Enter elemet "<<i+1<<"   :"; in>>obj.data[i];
				if(	obj.data[i]>0)
			{
					obj.data[i]=0;
			}
		}
		cout<<endl;
		return in;
	}
	Collection operator+(const Collection& obj) const
	{	
		Collection objN(size);
		if(size==obj.size)
		{
			//Collection objN(size);
			for(int i=0;i<size;i++)
			{
			objN.data[i]=data[i]+obj.data[i];
			}
			return objN;
		}
		else 
		  return objN;
	}
	
	bool operator==(const Collection& obj)
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
	int& operator[] (int index)
	{
		if (index >= 0 && index < size)		
		{
			return data[index];				
		}

		cout << " Out-of-Bound" << endl;

		exit(0);						
	}
	int operator[] (int index) const
	{
		if (index >= 0 && index < size)		
		{
			return data[index];			
		}

		cout << " Out-of-Bound" << endl;

		exit(0);
	}
	bool operator-()
	{
		for(int i=0;i<size;i++)
		{
			if(data[i]==0)
			{
				return false;
			}
		}
		
		 return true;
		
	}

	
};
int main()
{
	Collection obj1(5);
	obj1.putData();
	obj1.setElement(3,1);
	cout<<" obj1\n"<<obj1;
	int a[4]={-1,-2,-3,-4};
	cout<<"\nAdditonal construtor \n";
	Collection obj2(a,4);
	obj2.putData();
	cout<<"\n count jey element \n";
	cout<<obj1.countElement(4);
	cout<<"\n = operator\n ";
	obj2=obj1;
	obj2.putData();
	cout<<"\n sub collection\n";
	cout << obj2.subCollection(0,2);
	Collection obj3(3);
	cout<<obj3;
	cin>>obj3;
	cout<<obj3;
	if(obj1==obj2)
		cout<<"\nEqual \n";
	else
	 cout<<"\n not \n";
	if(-obj1)
	 cout<<"non";
	 else
	 cout<<"zero exist ";
	 cout<<endl;
	 cout<<obj1[1];


	return 0;
}
