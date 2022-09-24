/*****************************************************************************************************************
 ** FUNCTION NAME   :   donor_registration
 **
 ** DESCRIPTION     :  
 **
 **
 ** RETURNS         :
 **
 **
 *****************************************************************************************************************/

#include<iostream>
#include<iomanip>
#include<set>
#include<list>
#include<string>
#include "header.hpp"
using namespace std;
static int flag=0;

//----------------------------BLOOD DONATION CLASS(BASE CLASS)------------------------

class blood_donation
{
	protected:
		string age;
		string aadhar_num;
		string name;
		string address;
		string blood_group;

	public:
		blood_donation()
		{
			aadhar_num="";
			name="";
			address="";
			blood_group="";
			age="";
		}
};

//-------------------------------DONOR CLASS-(DERIVED CLASS)-------------------------

class donor:public blood_donation
{
	protected:
		string medical_clear;
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
		friend class testdr;

		string get_aadhar_num()
		{
			return this->aadhar_num;
		}
		string get_blood_group()
		{
			return this->blood_group;
		}
		string get_name()
		{
			return this->name;
		}
		string get_address()
		{
			return this->address;
		}
		string get_age()
		{
			return this->age;
		}
		int get_units_donated()
		{
			return this->units_donated;
		}
		int set_units_donated(int u)
		{
			return this->units_donated=units_donated+u;
		}
		void put_aadhar_num(string a_num)
		{
			this->aadhar_num=a_num;
		}
		void put_name(string name)
		{
			this->name=name;
		}
		void put_address(string address)
		{
			this->address=address;
		}
		void put_age(string age)
		{
			this->age=age;
		}
		void put_blood_group(string blood_group)
		{
			this->blood_group=blood_group;
		}
		void put_units_donated(int units_donated)
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
					for(auto it:l)
					{
						if(it.get_aadhar_num()==aadhar_num)
						{
							cout<<"Aadhar number should not be duplicate."<<endl;
							flag=1;
							break;
						}
					}
					if(flag==1)
						continue;
				}
				else
					break;
			}
				
		
			//....Name validation.............
			while(1)
			{
				cout<<endl<<"Enter your initial name-";
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

			string str[8]={"A+","A-","B+","B-","O+","O-","AB-","AB+"};
			blood_group=str[stoi(ch)-1];

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
					return 1;
				}

			}
			system("read a");
			system("clear");
			return 0;
		}

/*__________________________________________________________________________________*/
/*************************************************************************************/

//--------------------------DONOR REGSITRATION---------------------------------------

int donor_registration()
{
	donor d;
	if(d.get_donor_data()==0)
	{
		l.push_back(d);
		return 0;
	}
	else
		return 1;
}
//____________________________________________________________________________________
/*************************************************************************************/
