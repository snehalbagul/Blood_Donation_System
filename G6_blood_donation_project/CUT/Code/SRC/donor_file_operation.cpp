/******************************************************************************************************************
 ** FUNCTION NAME  :  donar_file_operation
 **
 ** DESCRIPTION    :   
 **
 **
 ** RETURNS        :
 **
 **
******************************************************************************************************************/ 
#include<iostream>
#include<iomanip>
#include "header.hpp"
using namespace std;



int donor_file_to_list()
{
	/*fstream fl;
	donor dl;
	
	string a_num;
	string name;
	string address;
	string age;
	string blood_group;
	int units_donated;
	fl.open("Donor_database",ios::in|ios::binary);
	if(fl)
	{
		fl>>a_num;
		while(!fl.eof())
		{
			dl.put_aadhar_num(a_num);
			fl>>name;
			dl.put_name(name);
			fl>>address;
			dl.put_address(address);
			fl>>age;
			dl.put_age(age);
			fl>>blood_group;
			dl.put_blood_group(blood_group);
			fl>>units_donated;
			dl.put_units_donated(units_donated);
			l.push_back(dl);
		}
	}
	fl.close();
	return EXIT_SUCCESS;*/

	donor d1;
	fstream fl;
	fl.open("Donor_database",ios::in|ios::binary);
	if(!fl)
	{
		cout<<endl<<"Can't open a file.";
		return 0;
	}
	fl.read((char *)&d1,sizeof(donor));
	while(!fl.eof())
	{
		l.push_back(d1);
		fl.read((char *)&d1,sizeof(donor));
	}
	fl.close();

	//cout<<"not available."<<endl;
	return 0;
}

int list_to_donor_file()
{
	/*fstream fl;
	donor dl;
	string a_num;
	string name;
	string address;
	string age;
	string blood_group;
	int units_donated;

	if(l.empty())
		return EXIT_FAILURE;

	fl.open("Donor_database",ios::out|ios::binary);

	for(list<donor>::iterator it=l.begin();it!=l.end();it++)
	{
		 a_num=dl.get_aadhar_num();
		 fl<<a_num;
		 fl<<" ";

		 name=dl.get_name();
		 fl<<name;
		 fl<<" ";

		 address=dl.get_address();
		 fl<<address;
		 fl<<" ";

		 age=dl.get_age();
		 fl<<age;
		 fl<<" ";

		 blood_group=dl.get_blood_group();
		 fl<<blood_group;
		 fl<<" ";

		 units_donated=dl.get_units_donated();
		 fl<<units_donated;
		 fl<<" ";
	}
	fl.close();
	return EXIT_SUCCESS;*/
	donor d2;
	fstream fl;
	fl.open("Donor_database",ios::out|ios::binary);
	if(!fl)
	{
		cout<<endl<<"can't open a file.";
		return 0;
	}
	for(donor d2:l)
	{
		fl.write((char *)&d2,sizeof(donor));
	}
	fl.close();
	l.clear();
	//cout<<"not available."<<endl;
	return 0;
}
