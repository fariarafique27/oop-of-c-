#include<iostream>

using namespace std;
class Item 
{
	int id;
	string name;
	int quantity;
	float cost;
	
	public:
		void setID(int i)
		{
			if(i>0)
				id=i;
			else
				id=0;
		}
		void setName(string n)
		{
			name=n;
		}
		void setQ(int q)
		{
			if(q>0)
				quantity=q;
			else
				quantity=0;
		}
		void setCost(float c)
		{
			if(c>0)
				cost=c;
			else
				cost=0;
		}
		int getID()
		{
			return id;
		}
		string getName()
		{
			return name;
		}
		int getQ()
		{
			return quantity;
		}
		float getCost()
		{
			return cost;
		}
		
		Item (int i ,string n,int q,float c)
		{
			setID(i);
			setName(n);
			setQ(q);
			setCost(c);
		}
		Item (int i ,string n,int q)
		{
			setID(i);
			setName(n);
			setQ(q);
			cost=0;	
		}
		Item (int i ,string n,float c)
		{
			setID(i);
			setName(n);
			setCost(c);
			quantity=0;
		}
		Item (const Item &obj)		//copy 
		{
			id=obj.id;
			name=obj.name;
			quantity=obj.quantity;
			cost=obj.cost;
		}
		~Item ()							//destructor 
		{
			cout<<"\ndestructor executed.... ";
		}
		
		void setItem (int i ,string n,int q,float c)
		{
			setID(i);
			setName(n);
			setQ(q);
			setCost(c);
		}
		void getItem()
		{
			cout<<"Enter ID of item : "; cin>>id; 	setID(id); cin.ignore();
			cout<<"Enter name of item : "; getline(cin,name); setName(name);
			cout<<"Enter quantity of item :"; cin>>quantity; setQ(quantity);
			cout<<"Enter cost per item : Rs "; cin >>cost;  setCost(cost);
		}
		void putItem()
		{
			cout<<"\nID : "<<getID()<<" \tName :"<<name<<"\tQuantity :"<<quantity<<"\tCost : Rs "<<cost;
		}
		double getTotalCost()
		{
			if(quantity>0)
				return cost*quantity;
			else 
				return 0;
		}
		bool isEqual(const Item &obj)
		{
			if(id==obj.id&&name==obj.name&&quantity==obj.quantity&&cost==obj.cost)
				return true;
			else
				false;
		}
		void updateName(Item a[],const int size)
		{
			for(int i=0;i<size;i++)
			{
				if (id == a[i].id)		 
				//	this->name=a[i].name;
				a[i].name=name;
			}
		}
		static Item getMinimumCost(const Item a[],const int size)
		{	
			Item c(1,"aa",1,1);
			c.cost=a[0].cost;
			for(int i=0;i<size;i++)
			{
				if (a[i].cost<c.cost)		 
					{
						c=a[i];
					}
			}
			return c;
		}
		void getAveragePrice(const Item a[],const int size)
		{
			float s=0;
			for(int i=0;i<size;i++)
			{
				s=s+a[i].cost;
			}
			cost=s/size;
		
		}
};

int main()
{
	Item i1(1,"aroob",4,6),i2(2,"ahmad",3.9f),i3(3,"akbar",7.9f),i4(i1),i5(4,"ayza",6,6.8);
	Item ar[3]={Item(44,"juice",1,3),Item(1,"laptop",1,2),Item(44,"apple",1,5)};
	i5.getItem();
	i1.putItem();
	i2.putItem();
	i3.putItem();
	i4.putItem();
	i5.putItem();
	cout<<"\n------------------------------";
	cout<<"\nTotal Cost of item 1 is : Rs  ";
	cout<<i1.getTotalCost();
	cout<<"\n------------------------------";
	if(i1.isEqual(i4))
	{
		cout<<"\nitem 1 and 4 are in equal state! ";
	}
	else
	{
		cout<<"\nitem 1 and 4 are not in equal state!";
	}
	cout<<"\n------------------------------";
	cout<<"\nName of items before update :\n";
	cout<<i1.getName()<<"\n";
	//cin.ignore();
	cout<<ar[1].getName();
	cout<<"\nName of items after update :\n";
	i1.updateName(ar,3);
	cout<<i1.getName()<<"\n";
	//ar[].getName();
	cout<<ar[1].getName();
	cout<<"\n------------------------------";
	cout<<"\nMinimun Cost in array " ;
	Item i6=i1.getMinimumCost(ar,3);
	i6.putItem();
	cout<<"\n------------------------------";
	i2.getAveragePrice(ar,3);
	cout<<"\nAverage of cost of objects in array : "<<i2.getCost();
	
	return 0;
}
