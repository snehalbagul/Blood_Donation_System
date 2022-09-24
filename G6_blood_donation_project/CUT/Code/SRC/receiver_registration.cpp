/***************************************************************************************************************
 ** FUNCTION NAME   :    receiver_registration
 **
 **
 ** DESCRIPTION     :     
 **
 **
 ** RETURNS         :
 **
 **
 **************************************************************************************************************/

#include<iostream>
#include<iomanip>
#include<set>
#include<list>
#include<deque>
#include<string>
#include "header.hpp"

//#include "transaction_file_operation.cpp"
//#include "donor_registration.cpp"
//#include "Validation.cpp"
using namespace std;


class receiver:public blood_donation
{
	private:
		string donor_aadhar_num;
	public:
		int view_receiver_queue();
		int carry_out_donation();
		int daily_donation_report();
		int remove_daily_transaction_file();
		int get_receiver_data();
		string get_aadhar_num()
		{
			return this->aadhar_num;
		}
		string get_name()
		{
			return this->name;
		}
		string get_blood_group()
		{
			return this->blood_group;
		}
};

deque<receiver> q;
list<receiver> rl;
receiver r;

/*______________________________________________________________________________________*/
/***************************************************************************************/

int receiver::get_receiver_data()
{
	system("clear");
	//....Aadhar validation...........
	while(1)
	{
		cout<<endl<<"Enter your Aadhar number-";
		cin>>aadhar_num;
		if(aadhar_validation(aadhar_num)==true)
			break;
		else
			continue;
	}

	//....Name validation.............
	while(1)
	{
		cout<<endl<<"Enter your name-";
		getline(cin>>ws,name);
		if(name_validation(name)==true)
			break;
		else
			continue;
	}

	//....Address validation..........
	while(1)
	{
		cout<<endl<<"Enter your address-";
		getline(cin,address);
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
              string ch;
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
			string bg[8]={"A+","A-","B+","B-","O+","O-","AB+","AB-"};
			blood_group=bg[stoi(ch)-1];
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
			if(it.get_blood_group()==blood_group)
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
			if(qu.blood_group==blood_group)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			for(auto dl:l)
			{
				if(dl.get_blood_group()==blood_group)
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
					if(it.get_aadhar_num()==it1.donor_aadhar_num)
					{
						flag=0;
						break;
					}
					else
					{
						if(it.get_blood_group()==blood_group)
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
//	system("read a");
	//system("clear");
	flag=0;
	while(1)
	{
		cout<<endl<<"Enter aadhar number of donor you want to select-";
		cin>>donor_aadhar_num;
		for(list<donor>::iterator it=l.begin();it!=l.end();it++)
		{
			if(it->get_blood_group()==blood_group && it->get_aadhar_num()==donor_aadhar_num)
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

/********************************************************************************************************/
