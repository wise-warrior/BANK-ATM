//ATM Program....(inheritance)
/*acc(name, no, bal)----->current(cheque book,no interest)---->savings(ci,withrawal,no cheque book)
members--->1)deposit amt and update bal
		   2)display acc details
		   3)compute and deposit int;
		   4)withdraw amt for costumer after checking bal and update the bal;
		   5)check for min balance (current acc) and impose penalty (if any) and
		   update the bal */
#include<iostream>
#include<math.h>
#include<process.h>
using namespace std;
class account
{
	protected :
		char name[50];
		long acc;
		float bal;
	public :
		void get_details()
		{
			cout<<"Enter Name : "; cin>>ws;
			cin.getline(name,50);
			cout<<"Enter A/c No : "; cin>>acc;
			cout<<"Enter Opening Balance : Rs "; cin>>bal;
		}
		void put_details()
		{
			cout<<"NAME : "; puts(name);
			cout<<"A/C No : "<<acc<<endl
				<<"BALANCE : Rs "<<bal<<endl;
		}
};
class savings : public account
{
	protected :
		float ci,amt,r,with_amt,n,prin;
		char ans;
	public :
		void interest();
		void withdrawal();
		void read()
		{
			cout<<"Enter The Amt You Want : "; cin>>prin;
			cout<<"Enter No. of years : "; cin>>n;
		}
};
void savings :: interest ()
{
	read();
	amt = prin * pow((1 + (6.7/100)),n);
	ci = amt - prin;
	cout<<"\nYOUR COMPOUND INTEREST (@ 6.7 per annum) : Rs "<<ci<<endl
		<<"AMOUNT TO BE PROVIDED AS LOAN : Rs "<<prin<<endl;
	cout<<"\nDo You Want The Interest ? (y/n) : "; cin>>ans;
	if(ans=='y')
	{
		bal += prin;
		cout<<"\nUPDATED BALANCE : Rs "<<bal<<endl
			<<"\nYou have to pay Rs "<<ci<<" as "<<endl
			<<"COMPOUND INTEREST (per annum) ...and "<<endl
			<<"Rs "<<amt<<" After "<<n<<" years "<<endl;
	}
	else
	{
		cout<<"OK...!!!"<<endl;
	}
}
void savings :: withdrawal ()
{
	cout<<"Enter Amt to be Withdrawan : Rs "; cin>>with_amt;
	if(with_amt < bal)
	{
		bal -= with_amt;
		cout<<"YOU HAVE WITHDRAWAN : Rs "<<with_amt<<endl
			<<"UPDATED BALANCE : Rs "<<bal<<endl;
	}
	else
	{
		cout<<"You Don't have Sufficient Balance...!!!"<<endl;
	}
}
class current : public account
{
	protected :
		float dep_amt,min_bal,penalty;
		char cheque[30],add[100]; int query;
	public :
		void deposit();
		void balcheck();
		void address()
		{
			cout<<"Enter Address : "; cin>>ws;
			cin.getline(add,100);	
		}		
};
void current :: deposit ()
{
	cout<<"Wanna pay by Cash (1) / cheque (2) : "; cin>>query;
	if(query==2)
	{
		cout<<"Enter Cheque No : ";
		cin>>cheque;
	}
	else 
		cout<<"Proceed With Cash payment-->"<<endl;
	cout<<"Enter Amount To Be Deposited : Rs "; cin>>dep_amt;
	bal += dep_amt;
	cout<<"\nYOU HAVE DEPOSITED : Rs "<<dep_amt<<endl
		<<"UPDATED BALANCE :Rs "<<bal<<endl; 
}
void current :: balcheck ()
{
	min_bal = 1000;
	penalty = 100;
	if(bal < min_bal)
	{
		bal -= penalty;
		cout<<"\nYOU DON'T HAVE SUFFICIENT MIN BALANCE...!!!"<<endl
			<<penalty<<" HAS BEEN DEDUCTED FROM YOUR ACC...!!!"<<endl
			<<"UPDATED BALANCE : Rs "<<bal<<endl;
	}
	else
	{
		cout<<"\nYou Have SUFFICIENT BALANCE...NO PENALTY imposed..!!!"<<endl;
	}
}
int main ()
{
	current c; savings s;
	int ch,pages,pages2; char choice,type; int wish;
	do{
	cout<<"================================================="<<endl;
	cout<<"Enter Your A/c type (Savings (S) / current(C)): "; cin>>type;
	if(type=='S') 
	{
		s.get_details();
		do {
		cout<<"\n=============== MENU ==============="<<endl
		<<"1)Display Acc Details (Savings)"<<endl
		<<"2)Compound Interest "<<endl
		<<"3)Withdrawal "<<endl
		<<"4)EXIT "<<endl;
		cout<<"===================================="<<endl;
		cout<<"\nEnter Your Choice : "; cin>>ch;
		switch(ch)
		{
			case 1 :
				cout<<"===================================="<<endl;
				s.put_details();
				cout<<"===================================="<<endl;
				break;
			case 2 :
				s.interest();
				break;
			case 3 :
				s.withdrawal();
				break;
			case 4:
				cout<<"Exiting...!!!"<<endl;
				exit(0);
			default :
				cout<<"WRONG choice...!!!"<<endl;
		}	
		cout<<"\nWant to Continue (Y/N) ? : "; cin>>choice;
		} while(choice=='Y');
	}
	else if(type=='C')
	{
		c.get_details();
		do {
		cout<<"\n=============== MENU ==============="<<endl
		<<"1)Display Acc Details (Current) "<<endl
		<<"2)Deposit "<<endl
		<<"3)Min Balance Check "<<endl
		<<"4)Cheque Book "<<endl<<"5)EXIT "<<endl;
		cout<<"===================================="<<endl;
		cout<<"\nEnter Your Choice : "; cin>>ch;
		switch(ch)
		{
			case 1 :
				cout<<"===================================="<<endl;
				c.put_details();
				cout<<"===================================="<<endl;
				break;
			case 2 :
				c.deposit();
				break;
			case 3 :
				c.balcheck();
				break;
			case 4 :
cout<<"Enter No. of pages of your previous Cheque Book  : "; cin>>pages;
				cout<<"Enter No. of pages Used : "; cin>>pages2;
				if(pages2==pages)
				{
					c.address();
					cout<<"\nYOUR CHEQUE BOOK WILL BE SHORTLY "<<endl
						<<"DELIVERED AT YOUR ADDRESS..."<<endl;
				}
				else
				{
					cout<<"\nYOU HAVEN'T USED UP ALL THE PAGES...!!"<<endl
						<<"NEW CHEQUE BOOK CAN'T BE ISSUED...!!!"<<endl;
				}
				break;
			case 5 :
				cout<<"Exiting...!!!"<<endl;
				exit(0);
			default :
				cout<<"WRONG choice...!!!"<<endl;
		}
		cout<<"\n Want to Continue (Y/N) ? : "; cin>>choice;
		}while(choice=='Y');
	}
	cout<<endl<<"======= THANKS FOR BANKING WITH US... ==========="<<endl;
	cout<<"================================================="<<endl;
	cout<<"\nWanna Continue further banking : 1(yes)/2(No) : "; cin>>wish;
	} while (wish==1);
	return 0;
}

