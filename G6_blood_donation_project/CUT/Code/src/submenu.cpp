/***************************************************************************************************************
 ** FUNCTION NAME    :    submenu
 **
 ** DESCRIPTION      :    This file defines the function which send external message for refer and 
                          this file is included in main file
 **
 **
 ** REVISION HISTORY :
 **  DATE                              NAME                                 REASON
 ** ------------------------------------------------------------------------------------------------------------
 **  19 SEPTEMBER 2022                 DOLLY SALUJA                         To make submenu file 
 **  21 SEPTEMBER 2022                 NIDHI DUBEY                          To make changes in header of the file
 ***************************************************************************************************************/
#include<iostream>
#include<iomanip>
#include<thread>
//#include "class.hpp"
//#include "receiver_related_operations.cpp"
#include "manage_donor_data.cpp"
//#include "employee_validation.cpp"
//#include "Validation.cpp"
//#include "report.cpp"
#include "header.hpp"
using namespace std;

donor *dr=&d;
receiver *rc=&r;

//function call through pointer to a function...

int (donor::*p1[5])()={&donor::edit_donor_data,&donor::remove_donor_data,&donor::view_donor_data,&donor::view_all_donor_data,&donor::five_highest_donor_report};

int (receiver::*p2[3])()={&receiver::view_receiver_queue,&receiver::remove_daily_transaction_file,&receiver::daily_donation_report};

receiver *rec;

string choice1="",choice2="";


//EMPLOYEE CORNER SUBMENU FUNCTION...

bool submenu()
{

	choice1="";
	if(employee_validation()!=0)
	{
		cout<<"Invalid password!!!"<<endl;
		//system("clear");
		return false;
	}
	while(choice1!="6")
	{
		system("clear");
		cout<<endl<<"*****************************************************************************"<<endl;
		cout<<endl<<"                         THE EMPLOYEE CORNER"<<endl;
		cout<<endl<<"*****************************************************************************"<<endl;
		cout<<"1.Manage donor database "<<endl;
		cout<<"2.Report Corner"<<endl;
		cout<<"3.View Reciever's Queue."<<endl;
		cout<<"4.Empty daily transaction file."<<endl;
		cout<<"5.Carry out donation"<<endl;
		cout<<"6.Go Back"<<endl;
		cout<<endl<<"*****************************************************************************"<<endl;
		cout<<endl<<"Enter your choice-";
		cin>>choice1;
		
		try
		{
			for(int i=0;i<choice1.length();i++)
			{
				if(!isdigit(choice1[i]))
					throw choice1;
			}
		}
		catch(string a)
		{
			cout<<endl<<"Please enter only digits in choice.";
			continue;
		}
		try
		{
			if(stoi(choice1)<1 || stoi(choice1)>6)
				throw choice1;
		}
		catch(string a)
		{
			cout<<endl<<"Please enter choice between 1-6";
			continue;
		}

		if(choice1=="1")
		{
			manage_donor_menu();
			continue;
		}
		if(choice1=="2")
		{
			report_corner_menu();

		}
		else if(stoi(choice1)>2 && stoi(choice1)<5)
		{
			(rc->*p2[stoi(choice1)-3])();
		}
		else if(choice1=="5")
		{
			thread t2(&receiver::carry_out_donation,receiver());
			t2.join();
		}
		else
			break;

		system("read a");
		system("clear");
	}
	return true;
}

/*_______________________________________________________________________________________________*/
/************************************************************************************************/
//MANAGE DONOR DATA MENU...

int manage_donor_menu()
{

	choice1="",choice2="";

	while(choice1!="4")
	{
		system("clear");
		cout<<endl<<"*****************************************************************************"<<endl;
		cout<<endl<<"                          MANAGING DONOR DATABASE"<<endl;
		cout<<endl<<"*****************************************************************************"<<endl;
		cout<<"1.Edit"<<endl;
		cout<<"2.Remove"<<endl;
		cout<<"3.View"<<endl;
		cout<<"4.Go Back"<<endl;
		cout<<endl<<"*****************************************************************************"<<endl;
		cout<<endl<<"Enter your choice-";

		cin>>choice1;


		try
		{
			for(int i=0;i<choice1.length();i++)
			{
				if(!isdigit(choice1[i]))
					throw choice1;
			}
		}
		catch(string a)
		{
			cout<<endl<<"Please enter only digits in choice.";
			continue;
		}

		try
		{
			if(stoi(choice1)<1 || stoi(choice1)>4)
				throw choice1;
		}
		catch(string a)
		{
			cout<<endl<<"Please enter choice between 1-6";
			continue;
		}

		if(stoi(choice1)>0 && stoi(choice1)<3)
		{
			(dr->*p1[stoi(choice1)-1])();
		}
		else if(choice1=="3")
		{
			while(choice2!="3")
			{
				system("clear");

				cout<<endl<<"*****************************************************************************"<<endl;
				cout<<endl<<"                                 VIEW DONOR DATA"<<endl;

				cout<<endl<<"*****************************************************************************"<<endl;
				cout<<"View donor records-"<<endl;
				cout<<"1.Based on Aadhar number."<<endl;
				cout<<"2.All donor records."<<endl;
				cout<<"3.Go back."<<endl;
				cout<<endl<<"*****************************************************************************"<<endl;
				cout<<endl<<"Enter your choice-";
				cin>>choice2;

				try
				{
					for(int i=0;i<choice2.length();i++)
					{
						if(!isdigit(choice2[i]))
						throw choice2;
					}
				}
				catch(string a)
				{
					cout<<endl<<"Please enter only digits in choice.";
					continue;
				}
				try
				{
					if(stoi(choice2)<1 || stoi(choice2)>3)
						throw choice2;
				}
				catch(string a)
				{
					cout<<endl<<"Please enter choice between 1-3";
					continue;
				}

				if(stoi(choice2)>0 && stoi(choice2)<3)
				{
					(dr->*p1[stoi(choice2)+1])();
			        }
				else
					break;

				system("read a");
				system("clear");

			}
		}
		else
			 break;

		system("read a");
		system("clear");
	}
		return EXIT_SUCCESS;
}


/*____________________________________________________________________________________________________*/
/******************************************************************************************************/

//REPORT CORNER SUBMENU FUNCTION...

int report_corner_menu()
{
		choice1="";
		while(choice1!="3")
		{
			system("clear");

			cout<<endl<<"*****************************************************************************"<<endl;
			cout<<endl<<"                      WELCOME TO REPORT CORNER SECTION"<<endl;

			cout<<endl<<"*****************************************************************************"<<endl;
			cout<<"1.Daily Donation Report."<<endl;
			cout<<"2.Five Highest Donor Report."<<endl;
			cout<<"3.Go Back."<<endl;
			cout<<endl<<"*****************************************************************************"<<endl;
			cout<<endl<<"Enter your choice-";
			cin>>choice1;


			try
			{
				for(int i=0;i<choice1.length();i++)
				{
					if(!isdigit(choice1[i]))
						throw choice1;
				}
			}
			catch(string a)
			{
				cout<<endl<<"Please enter only digits in choice.";
				continue;
			}
			try
			{
				if(stoi(choice1)<1 || stoi(choice1)>3)
					throw choice1;
			}
			catch(string a)
			{
				cout<<endl<<"Please enter choice from 1-3";
			}

			if(choice1=="1")
				(rc->*p2[2])();
			else if(choice1=="2")
				(dr->*p1[stoi(choice1)+2])();
			else
				break;

			system("read a");
			system("clear");
		}
		return 0;
}

/*_______________________________________________________________________________________________________*/
/*********************************************************************************************************/
