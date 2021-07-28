#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class book
{
	public:
		char *author,*title,*publisher;
		float *price;
		int *stock;
		
	public:
		book()
		{
			author=new char[20];
			title=new char[20];
			publisher=new char[20];
			price=new float;
			stock=new int;
		}
		
		void feed();
		void edit();
		void show();
		int search(char[],char[]);
		void buy();
};

void book::feed()
{
	cin.ignore();
	cout<<"\nEnter the name of the author: "<<endl;
	cin.getline(author,20);
	cout<<"Enter Title name: "<<endl;
	cin.getline(title,20);
	cout<<"Enter name of the publisher: "<<endl;
	cin.getline(publisher,20);
	cout<<"Enter price: "<<endl;
	cin>>*price;
	cout<<"Enter stock position: "<<endl;
	cin>>*stock; 
}

void book::edit()
{
	cout<<"\nEnter author name: "<<endl;
	cin.getline(author,20);
	cout<<"Enter Title name: "<<endl;
	cin.getline(title,20);
	cout<<"Enter name of the publisher: "<<endl;
	cin.getline(publisher,20);
	cout<<"Enter price: "<<endl;
	cin>>*price;
	cout<<"Enter stock position: "<<endl;
	cin>>*stock; 
}

void book::show()
{
	cout<<"\nAuthor: "<<author<<endl;
	cout<<"\nTitle: "<<title<<endl;
	cout<<"\nPublisher: "<<publisher<<endl;
	cout<<"\nPrice: "<<*price<<endl;
	cout<<"\nStock position: "<<*stock<<endl;
}

int book::search(char tbuy[20],char abuy[20])
{
	if(strcmp(tbuy,title)==0 && strcmp(abuy,author)==0)
		return 1;
	else 
		return 0;
}

void book::buy()
{
	int count;
	cout<<"\nEnter number of books to buy: "<<endl;
	cin>>count;
	if(count<=*stock)
	{
		*stock=*stock-1;
		cout<<"\nBooks bought successfully !"<<endl;
		cout<<"\nAmount: Rs "<<(*price)*count<<endl;
	}
	else
		cout<<"\nRequired copies not in stock."<<endl;
}


int main()
{
	book *b[20];
	int i=0,r,t,choice;
	char titlebuy[20],authorbuy[20];
	while(1)
	{
		cout<<"\n\n\t\tMENU"<<endl;
		cout<<"\t\t1. Entry of new book"<<endl;
		cout<<"\t\t2. Buy book"<<endl;
		cout<<"\t\t3. Search for a book"<<endl;
		cout<<"\t\t4. Edit details of book"<<endl;
		cout<<"\t\t5. Exit"<<endl;
		cout<<"\n\t\t Enter your choice"<<endl;
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				b[i]=new book();
				b[i]->feed();
				i++;
				break;
			
			case 2:
				cin.ignore();
				cout<<"\nEnter title of the book"<<endl;
				cin.getline(titlebuy,20);
				cout<<"\nEnter the name of the author"<<endl;
				cin.getline(authorbuy,20);
				for(t=0;t<i;i++)
				{
					if(b[t]->search(titlebuy,authorbuy))
					{
						b[t]->buy();
						break;
					}
				}
				if(t==1)
				{
					cout<<"\nThis book is not in stock"<<endl;
				}
				break;
				
			case 3:
				cin.ignore();
					cout<<"\nEnter title of the book"<<endl;
				cin.getline(titlebuy,20);
				cout<<"\nEnter the name of the author"<<endl;
				cin.getline(authorbuy,20);
				for(t=0;t<i;i++)
				{
					if(b[t]->search(titlebuy,authorbuy))
					{
						cout<<"\nBook found successfully"<<endl;
						b[t]->show();
					}
				}
				if(t==i)
				cout<<"\nThis book is not in stock"<<endl;
				break;
			
			case 4:
				cin.ignore();
					cout<<"\nEnter title of the book"<<endl;
				cin.getline(titlebuy,20);
				cout<<"\nEnter the name of the author"<<endl;
				cin.getline(authorbuy,20);
				for(t=0;t<i;i++)
				{
					if(b[t]->search(titlebuy,authorbuy))
					{
						cout<<"\nBook found successfully"<<endl;
						b[t]->edit();
						break;
					}
				}
				if(t==i)
				cout<<"\nThis book is not in stock"<<endl;
			    break;
			    
			case 5:
				exit(0);
			
			default:
				cout<<"\nInvalid choice"<<endl;
				
		}
		
	}
	return 0;
}
