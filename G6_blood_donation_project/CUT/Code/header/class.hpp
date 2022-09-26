#ifdef CLASS_H
#define CLASS_H

#include<list>
#include<deque>
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
};

deque<receiver> q;
list<receiver> rl;
receiver r;

#endif
