~//BOOKSHOP INVENTORY SYSTEM PROJECT

#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

class book	
{
private:
	char *author,*title,*publisher;
	float *price;
	int *stock;
public:	
	book()
	{
	author= new char[30];
	title=new char[50];
	publisher=new char[20];
	price= new float;
	stock=new int;
	}
	void enterdata();
	void editdata();
	void showdata();
	int search(char[],char[]);
	void buybook();
	
};

void book :: enterdata()	
{
	cin.ignore();
	cout<<"\nEnter Title Name: ";       
	cin.getline(title,50);
	cout<<"Enter Author Name: ";
	cin.getline(author,30);
	cout<<"Enter Publisher Name: ";   
	cin.getline(publisher,20);
	cout<<"Enter Price: ";            
	cin>>*price;
	cout<<"Enter Stock Number: ";   
	cin>>*stock;   
	
}

void book :: editdata()	
{
	cout<<"\nEnter Title Name: ";       
	cin.getline(title, 50);
	cout<<"Enter Author Name: ";      
	cin.getline(author,30);
	cout<<"Enter Publisher Name: ";   
	cin.getline(publisher,20);
	cout<<"Enter Price: ";            
	cin>>*price;
	cout<<"Enter Stock Number: ";   
	cin>>*stock;   
	
}

void book :: showdata()
{
	cout<<"\nAuthor Name: "<<author;
	cout<<"\nTitle Name: "<<title;
	cout<<"\nPublisher Name: "<<publisher;
	cout<<"\nPrice: "<<*price;
	cout<<"\nStock Number: "<<*stock;   
	
}

int book :: search(char tbuy[20],char abuy[20] )
{
	if(strcmp(tbuy,title)==0 && strcmp(abuy,author)==0)
		return 1;
	else 
		return 0;
		
}

void book :: buybook()	
{
	int count;
	cout<<"\nEnter Number Of Books to buy: ";
	cin>>count;
	if(count<=*stock)	
	{
		*stock=*stock-count;
		cout<<"\nBooks Bought Sucessfully";
		cout<<"\nAmount: Rs. "<<(*price)*count;
	}
	else
		cout<<"\nRequired Copies Out of Stock";
}

int main()
{
	book *B[20];
	int i=0,r,t,choice;
	char title[20],author[20];
	while(1)	
	{
		cout<<"\nMENU"
		<<"\n1. Entry of New Book"
		<<"\n2. Buy Book"
		<<"\n3. Search For Book"
		<<"\n4. Edit Details Of Book"
		<<"\n5. Exit"
		<<"\n\nEnter your Choice: ";
		cin>>choice;
		
		switch(choice)	
		{
			case 1:	
			B[i] = new book; //class name is book and the array of pointers in pointing to a new object of the class
				B[i]->enterdata();
				i++;	
				break;
				
			case 2:
			 cin.ignore();
				cout<<"\nEnter Title Of Book: "; 
				cin.getline(title,20);
				cout<<"Enter Author Of Book: ";  
				cin.getline(author,20);
				for(t=0;t<i;t++)	
				{
					if(B[t]->search(title,author))	
					{
						B[t]->buybook();
						break;
					}
				}
				if(t==1)
				cout<<"\nThis Book is Out of Stock";
				break;

			case 3: 
			cin.ignore();
				cout<<"\nEnter Title Of Book: "; 
				cin.getline(title,20);
				cout<<"Enter Author Of Book: ";  
				cin.getline(author,20);
				
				for(t=0;t<i;t++)	
				{
					if(B[t]->search(title,author))	
					{
						cout<<"\nBook Found Successfully";
						B[t]->showdata();
						break;
					}
				}
				if(t==i)
				cout<<"\nThis Book is Out of Stock";
				break;
			
			case 4: 
			cin.ignore();
				cout<<"\nEnter Title Of Book: "; 
				cin.getline(title,20);
				cout<<"Enter Author Of Book: ";  
				cin.getline(author,20);
				
				for(t=0;t<i;t++)	
				{
					if(B[t]->search(title,author))	
					{
						cout<<"\nBook Found Successfully";
						B[t]->editdata();
						break;
					}
				}
				if(t==i)
				cout<<"\nThis Book is Out of Stock";
				break;
			
			case 5: 
			exit(0);

			default: 
			cout<<"\nInvalid Choice Entered";
			
		}
	}
	return 0;
}
