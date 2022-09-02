//Bank Managment system
#include<bits/stdc++.h>
using namespace std;

class Bank
{
	long int acNo;
	char acName[50];
	long int acAmt;
	int pin;

public:
		void getData()
		{
				cout<<"Enter Account no ";
				cin>>acNo;
				cout<<"Enter Account Holder's Name ";
				scanf(" %[^\n]s",acName);
				cout<<"Enter the Amount ";
				cin>>acAmt;
				cout<<"Enter the pin ";
				cin>>pin;
		}


		void depAmt(long int amt)
		{
				acAmt+=amt;
		}


		void withAmt(long int amt)
		{
				acAmt-=amt;
		}
	

		long int getAcNo()
		{
				return acNo;
		}

		
		string getAcName()
		{
				return acName;
		}

		
		long int getAmt()
		{
				return acAmt;
		}

		
		int getPin()
		{
				return pin;
		}

		void displayAccount()
		{
				cout<<"***********************************************************************\n";
				cout<<"Account Number:"<<setw(5)<<acNo<<" "<<"    Account Name:"<<setw(10)<<acName<<" "<<"    Amount"<<setw(10)<<acAmt<<"\n";
				cout<<"***********************************************************************\n";
		}

};



int main()
{
	int opt;
	long int no,amt,deposit,withDraw;
	char name[50];
	int pin;

	Bank obj,obj1;
	----
	
	fstream f; 
	f.open("info1.dat",ios::in|ios::out|ios::app|ios::ate|ios::binary);
	f.close();

	while(1)
	{
		cout<<"\n.....................PROJECT ON BANK MANAGEMENT SYSTEM......................\n";
		
		cout<<"\n1.Add an Account \n2.Display all acounts \n3.View Details of Account \n4.Update an Account \n5.Deposit \n6.Withdraw \n";
		
		cin>>opt;
		
		switch(opt)
		{
			case 1: 
					
					f.open("info1.dat",ios::out | ios::app | ios::binary);
					obj.getData();
					f.write((char *)&obj,sizeof(obj));
					f.close();
					break;

			case 2:
					
					f.open("info1.dat",ios::in | ios::binary);
					f.seekg(0,ios::beg);
					
					while(f.read((char *) & obj,sizeof (obj)))
						{
							obj.displayAccount();
						}
					f.close();
					break;
		
			case 3:
					
					f.open("info1.dat",ios::in | ios::binary);
					f.seekg(0,ios::beg);
					cout<<"Enter the Account no of which you need Details: ";
					cin>>no;
					
					while(f.read((char *) & obj,sizeof (obj)))
						{
							cout<<obj.getAcNo()<<"\n";
							
							if(obj.getAcNo()==no)
								{
								obj.displayAccount();
								break;
								}
						}
					f.close();
					break;

			case 4:
					
					f.open("info1.dat",ios::in|ios::out|ios::ate|ios::binary);
					f.seekg(0,ios::beg);
					
					cout<<"Enter the account no of account you need to update: ";
					cin>>no;
					while(f.read((char*)&obj,sizeof(obj)))
						{
							if(obj.getAcNo()==no)
								{
								obj.getData();	
								f.seekp(-sizeof(obj),ios::cur);
								f.write((char *) & obj,sizeof (obj));
								break;
								}
						}
					
					f.close();
					break;


			case 5:
					f.open("info1.dat",ios::in|ios::out|ios::ate|ios::binary);
					f.seekg(0,ios::beg);
					cout<<"Enter the account no : ";
					cin>>no;
					cout<<"Enter the amount to deposit in account: ";
					cin>>deposit;
					
					while(f.read((char*)&obj,sizeof(obj)))
						{
						if(obj.getAcNo()==no)
							{
							obj.depAmt(deposit);
							f.seekp(-sizeof(obj),ios::cur);
							f.write((char *) & obj,sizeof (obj));
							break;
							}
						}
					
					f.close();
					break;

			case 6:
					f.open("info1.dat",ios::in|ios::out|ios::ate|ios::binary);
					f.seekg(0,ios::beg);
					cout<<"Enter the account no : ";
					cin>>no;
					cout<<"Enter the amount to withdraw from account : ";
					cin>>withDraw;
					
					while(f.read((char*)&obj,sizeof(obj)))
						{
							if(obj.getAcNo()==no)
							{	
								if(obj.getAmt()>=withDraw)
								{
								obj.withAmt(withDraw);
								f.seekp(-sizeof(obj),ios::cur);
								f.write((char *) & obj,sizeof (obj));
								break;
								}
								
								else
								{
								cout<<"Insufficient Balance\n";
								break;
								}

							}
						}
					
					f.close();
					break;					

			}


		}
	return 0;
}
