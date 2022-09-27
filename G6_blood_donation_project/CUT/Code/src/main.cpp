/********************************************************************************************************************
 ** FUNCTION NAME     :    main.c
 **
 ** DESCRIPTION       :    This file defines the function which send external message to refer 
 **
 **
 ** REVISION HISTORY  :
 ** DATE                      NAME                              REASON
 ** ---------------------------------------------------------------------------------------------------------------
 ** 18 SEPTEMBER 2022         MUSKAN YADAV                      To make main file and include all function in it
 ** 21 SEPTEMBER 2022         SNEHAL BAGUL                      To make changes in header of a file 
 ********************************************************************************************************************/

#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <sstream>
#include <fstream>
#include <string>
#include <list>
#include <thread>
#include "header.hpp"

using namespace std;

int main()
{
	
	fstream fl1,fl2;
	fl1.open("Donor_database",ios::in | ios::binary);
	if(fl1)	
	{
		fl1.close();
		donor_file_to_list();
	}
	fl2.open("Transaction_database",ios::in|ios::binary);
	if(fl2)
	{
		fl2.close();
		transaction_file_to_list();
	}
	string choice1="";
	system("clear");
	while(choice1!="4")
	{
	
		cout<<endl<<"*****************************************************************************"<<endl;
		cout<<endl<<"                  WELCOME TO BLOOD DONATION SYSTEM"<<endl;
		cout<<endl<<"*****************************************************************************"<<endl;
		cout<<"1.Donor registration."<<endl;
		cout<<"2.Receiver Enquiry and Registration."<<endl;
		cout<<"3.The Employee Corner."<<endl;
		cout<<"4.Exit."<<endl;
		cout<<endl<<"*****************************************************************************"<<endl;
		cout<<endl<<"Enter your choice-";
		cin>>choice1;
		try
		{
			if(!isdigit(choice1[0]))
				throw choice1;
		}
		catch(string b)
		{
			cout<<endl<<"Choice should only be in digits(1,2,3,4)."<<endl;
			system("read a");
			system("clear");
			continue;
		}
		try
		{
			if(choice1.length()!=1)
				throw choice1;
		}
		catch(string a)
		{
			cout<<endl<<"Choice should be of only one digit(1,2,3,4)."<<endl;
			system("read a");
			system("clear");
			continue;
		}

		if(choice1=="1")
			donor_registration();
		else if(choice1=="2")
		{
			thread t1(receiver_registration);
			t1.join();
		}
		else if(choice1=="3") 
		{
			if(submenu()==false)
				continue;
		}
		else if(choice1=="4")	
		{
			break;
		}
		else
		{
			cout<<"Invalid choice!!!";
			system("read a");
			system("clear");
			continue;
		}
		system("read a");
		system("clear");
	}
	list_to_donor_file();
	list_to_transaction_file();
	return EXIT_SUCCESS;
}

