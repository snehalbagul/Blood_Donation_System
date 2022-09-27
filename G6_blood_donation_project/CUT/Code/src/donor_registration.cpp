/*****************************************************************************************************************
 ** FUNCTION NAME   :   donor_registration
 **
 ** DESCRIPTION     :   In this file donor is registered and stored to donor database
 **
 **
 ** RETURNS         :   EXIT_SUCCESS or EXIT_FAILURE
 **
 **
 *****************************************************************************************************************/

#include<iostream>
#include<iomanip>
#include<set>
#include<list>
#include<string>
#include<string.h>
#include<stdlib.h>
using namespace std;

//----------------------------BLOOD DONATION CLASS(BASE CLASS)------------------------

class blood_donation
{
	protected:
		char age[5];
		char aadhar_num[15];
		char name[20];
		char address[30];
		char blood_group[5];

};

//-------------------------------DONOR CLASS-(DERIVED CLASS)-------------------------

class donor:public blood_donation
{
	protected:
		char medical_clear[5];
		int units_donated;
	public:
		donor()
		{
			units_donated=0;
		}
		int get_donor_data();
		int edit_donor_data();
		int remove_donor_data();
		int view_donor_data();
		int previous_day_donor_report();
		int five_highest_donor_report();
		int view_all_donor_data();

		char* get_aadhar_num()
		{
			return this->aadhar_num;
		}
		char* get_blood_group()
		{
			return this->blood_group;
		}
		char* get_name()
		{
			return this->name;
		}
		char* get_address()
		{
			return this->address;
		}
		char* get_age()
		{
			return this->age;
		}
		int* get_units_donated()
		{
			return &this->units_donated;
		}
		int set_units_donated(int u)
		{
			return this->units_donated=units_donated+u;
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
		void put_units_donated()
		{
			this->units_donated=units_donated;
		}

		bool operator>( const donor& d1) const
		{
			return units_donated>d1.units_donated;
		}

};
donor d;
list<donor> l;

/*________________________________________________________________________________________________*/
/**************************************************************************************************/

//GET DONOR DATA FUNCTION 
//To get all the donor details...

int donor::get_donor_data()
{
	//....Aadhar validation...........
	system("clear");
	int flag=0;
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
		cout<<endl<<"Enter your initial name-";
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

	char str[8][4]={"A+","A-","B+","B-","O+","O-","AB-","AB+"};
	strcpy(blood_group,str[atoi(ch)-1]);

	//....Medical clearance validation.......
	while(1)
	{
		cout<<endl<<"Enter (Y/y) if you have medical clearance-";
		cin>>medical_clear;
		if(medical_clearance_validation(medical_clear)==true)
			break;
		else
		{
			cout<<endl<<"You are not eligible to donate blood."<<endl;
			return EXIT_FAILURE;
		}

	}
	system("read a");
	system("clear");
	return EXIT_SUCCESS;
}

/*__________________________________________________________________________________*/
/*************************************************************************************/

//--------------------------DONOR REGSITRATION---------------------------------------

//Function to call getdata function and put donor details in donor list...
int donor_registration()
{
	donor d;
	if(d.get_donor_data()==0)
	{
		l.push_back(d);
		return EXIT_SUCCESS;
	}
	else
		return EXIT_FAILURE;
}
//____________________________________________________________________________________
/*************************************************************************************/
