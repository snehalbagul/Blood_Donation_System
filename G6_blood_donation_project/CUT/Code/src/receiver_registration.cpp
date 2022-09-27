/***************************************************************************************************************
 ** FUNCTION NAME   :    receiver_registration
 **
 **
 ** DESCRIPTION     :    In this file registration of receiver is performed 
 **
 **
 ** RETURNS         :    EXIT_SUCCESS or EXIT_FAILURE
 **
 **
 **************************************************************************************************************/

#include<iostream>
#include<iomanip>
#include<set>
#include<list>
#include<deque>
#include<string.h>
#include<string>
#include<stdlib.h>
#include "header.hpp"
using namespace std;

 
/*************************************RECEIVER CLASS**********************************************************/

class receiver:public blood_donation //Inheriting from blood donation
{
	private:
		char donor_aadhar_num[15];
	public:
		int view_receiver_queue();
		int carry_out_donation();
		int daily_donation_report();
		int remove_daily_transaction_file();
		int get_receiver_data();
		char* get_aadhar_num()
		{
			return this->aadhar_num;
		}
		char* get_name()
		{
			return this->name;
		}
		char* get_blood_group()
		{
			return this->blood_group;
		}
		char* get_donor_aadhar_num()
		{
			return this->donor_aadhar_num;
		}
		char* get_address()
		{
			return this->address;
		}
		char* get_age()
		{
			return this->age;
		}
		
		void put_aadhar_num()
		{
			strcpy(this->aadhar_num,aadhar_num);
		}
		void put_name()
		{
			strcpy(this->name,name);
		}
		void put_address()
		{
			strcpy(this->address,address);
		}
		void put_age()
		{
			strcpy(this->age,age);
		}
		void put_blood_group()
		{
			strcpy(this->blood_group,blood_group);
		}
		void put_donor_aadhar_num()
		{
			strcpy(this->donor_aadhar_num,donor_aadhar_num);
		}

};

deque<receiver> q;
list<receiver> rl;
receiver r;

/*_________________________________________________________________________________________________________*/
/***********************************************************************************************************/

//get receiver data function to get all receiver details...

int receiver::get_receiver_data()
{
	system("clear");
	//....Aadhar validation...........
	while(1)
	{
		cout<<endl<<"Enter your Aadhar number-";
		cin>>aadhar_num;
		if(aadhar_validation(aadhar_num)==true)
		{
			flag=0;
			for(auto it:l)
			{
				if(strcmp(it.get_aadhar_num(),aadhar_num)==0)
				{
					cout<<"Aadhar number should not be duplicate."<<endl;
					flag=1;
					break;
				}
			}
			if(flag==1)
				continue;
			else
				break;
		}
		else
			continue;
	}

	//....Name validation.............
	while(1)
	{
		cout<<endl<<"Enter your name-";
		cin>>name;
		if(name_validation(name)==true)
			break;
		else
			continue;
	}

	//....Address validation..........
	while(1)
	{
		cout<<endl<<"Enter your address-";
		cin>>address;
		if(address_validation(address)==true)
			break;
		else
			continue;
	}

	//....Age validation...............
	while(1)
	{
		cout<<endl<<"Enter your age-";
		cin>>age;
		if(age_validation(age)==true)
			break;
		else
			continue;
	}

	//....Blood group validation........
              char ch[2];
			while(1)
			{
				cout<<endl<<"Blood Groups -";
				cout<<endl<<"1.A+	5.O+";	
				cout<<endl<<"2.A-	6.O-";	
				cout<<endl<<"3.B+	7.AB+";
				cout<<endl<<"4.B-	8.AB-";
			        	
				cout<<endl<<"Enter your choice(1-8) for blood group from above  data-";
				cin>>ch;
				
				if(blood_group_validation(ch)==true)
					break;
				else
					continue;
			}
			char bg[8][4]={"A+","A-","B+","B-","O+","O-","AB+","AB-"};
			strcpy(blood_group,bg[atoi(ch)-1]);
	int units;
	while(1)
	{
		cout<<endl<<"Enter units of blood-";
		cin>>units;
		if(units>3 || units<1)
		{
			cout<<endl<<"Please enter units between 1-3";
			continue;
		}
		else
			break;
	}
	system("clear");

	//displaying list of donor having the blood group entered by the user...
	
	cout<<endl<<"____________________________________________________________________________________________"<<endl;
	cout<<endl<<"********************************************************************************************"<<endl;

	cout<<endl<<"----------------------LIST OF DONOR---(BLOOD_GROUP)---"<<blood_group<<"---------------------"<<endl;

	cout<<endl<<"********************************************************************************************"<<endl;

	cout<<endl<<setw(10)<<"AADHAR_NO."<<setw(12)<<"NAME"<<setw(12)<<"AGE"<<setw(12)<<"ADDRESS"<<setw(15)<<"BLOOD_GROUP"<<setw(18)<<endl;
	flag=0;
	string str;
	int flag1=0;

	if(q.empty())
	{

		for(auto it:l)
		{
			if(strcmp(it.get_blood_group(),blood_group)==0)
			{
				flag=1;
				flag1=1;
				cout<<setw(10)<<it.get_aadhar_num()<<setw(12)<<it.get_name()<<setw(12)<<it.get_age()<<setw(12)<<it.get_address()<<setw(15)<<it.get_blood_group()<<setw(18)<<endl;
			}
		}
	}
	else
	{
		flag=0;
		for(auto qu:q)
		{
			if(strcmp(qu.blood_group,blood_group)==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			for(auto dl:l)
			{
				if(strcmp(dl.get_blood_group(),blood_group)==0)
				{
					flag=1;
					flag1=1;
					cout<<setw(10)<<dl.get_aadhar_num()<<setw(12)<<dl.get_name()<<setw(12)<<dl.get_age()<<setw(12)<<dl.get_address()<<setw(15)<<dl.get_blood_group()<<setw(18)<<endl;
				}
			}
		
		}
		else
		{				
			for(auto it:l)
			{
				flag=0;
				for(auto it1:q)
				{
					//flag=0;
					if(strcmp(it.get_aadhar_num(),it1.donor_aadhar_num)==0)
					{
						flag=0;
						break;
					}
					else
					{
						if(strcmp(it.get_blood_group(),blood_group)==0)
						{
							flag=1;
							continue;
						}
						//else
							//flag=0;
					}
				}
				if(flag==1)
				{
					flag1=1;
				
					cout<<setw(10)<<it.get_aadhar_num()<<setw(12)<<it.get_name()<<setw(12)<<it.get_age()<<setw(12)<<it.get_address()<<setw(15)<<it.get_blood_group()<<setw(18)<<endl;
				}
			}
		}

	}
	cout<<endl<<"____________________________________________________________________________________________";
	cout<<endl<<"********************************************************************************************"<<endl;
	if(flag1==0)
	{
		cout<<endl<<"--------------Donor of blood group "<<blood_group<<" not available.--------------"<<endl;

		cout<<endl<<"********************************************************************************************"<<endl;
		return EXIT_FAILURE;
	}

	flag=0;
	while(1)
	{
		cout<<endl<<"Enter aadhar number of donor you want to select-";
		cin>>donor_aadhar_num;
		for(list<donor>::iterator it=l.begin();it!=l.end();it++)
		{
			if(strcmp(it->get_blood_group(),blood_group)==0 && strcmp(it->get_aadhar_num(),donor_aadhar_num)==0)
			{
				flag=1;
				it->set_units_donated(units);
				break;
			}
		}
		if(flag==0)
		{
			cout<<endl<<"********Please enter correct aadhar number.*********";
			continue;

		}
		else
			break;
	}
	system("read a");
	system("clear");

	return EXIT_SUCCESS;
}

/***************************************************************************************************************/
