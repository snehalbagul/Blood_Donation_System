/******************************************************************************************************************
 ** FUNCTION NAME  :    donar_file_operation
 **
 ** DESCRIPTION    :    In this file we have performed all the file handling operation for donor
 **
 **
 ** RETURNS        :    EXIT_SUCCESS or EXIT_FAILURE 
 **
 **
******************************************************************************************************************/ 
#include<iostream>
#include<iomanip>
#include<fstream>
#include "header.hpp"
#include<cstring>
#include<string.h>
using namespace std;


//Donor file to list function to read data from donor file and put into donor list...
struct temp1
{
	char a_num[15];
	char name[20];
	char address[30];
	char age[5];
	char blood_group[5];
	int units_donated;

}tmp;

int donor_file_to_list()
{
	fstream fl;
	donor dl;
	
	fl.open("Donor_database",ios::in|ios::binary);
	if(fl)
	{
		fl.read((char*)&tmp,sizeof(tmp));

		while(!fl.eof())
		{
			strcpy(dl.get_aadhar_num(),tmp.a_num);
			strcpy(dl.get_name(),tmp.name);
			strcpy(dl.get_address(),tmp.address);
			strcpy(dl.get_age(),tmp.age);
			strcpy(dl.get_blood_group(),tmp.blood_group);
			*(dl.get_units_donated())=tmp.units_donated;
			l.push_back(dl);
			fl.read((char*)&tmp,sizeof(tmp));
		}

	}
	fl.close();
	return EXIT_SUCCESS;

	/*donor d1;
	fstream fl;
	fl.open("Donor_database",ios::in|ios::binary);
	if(!fl)
	{
		cout<<endl<<"Can't open a file.";
		return EXIT_FAILURE;
	}
	fl.read((char *)&d1,sizeof(donor));
	while(!fl.eof())
	{
		l.push_back(d1);
		fl.read((char *)&d1,sizeof(donor));
	}
	fl.close();

	//cout<<"not available."<<endl;
	return EXIT_SUCCESS;*/
}


/*__________________________________________________________________________________________________*/
/****************************************************************************************************/
//List to donot file function to store the data from donor list to donor database file...


int list_to_donor_file()
{
	fstream fl;
	if(!l.empty())
	{
		fl.open("Donor_database",ios::out);
		for(list<donor>::iterator it=l.begin();it!=l.end();it++)
		{
			strcpy(tmp.a_num,it->get_aadhar_num());
			strcpy(tmp.name,it->get_name());
			strcpy(tmp.address,it->get_address());
			strcpy(tmp.age,it->get_age());
			strcpy(tmp.blood_group,it->get_blood_group());
			tmp.units_donated=*(it->get_units_donated());
			fl.write((char*)&tmp,sizeof(tmp));

		}
		fl.close();
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
	/*donor d2;
	fstream fl;
	fl.open("Donor_database",ios::out|ios::binary);
	if(!fl)
	{
		cout<<endl<<"can't open a file.";
		return EXIT_FAILURE;
	}
	for(donor d2:l)
	{
		fl.write((char *)&d2,sizeof(donor));
	}
	fl.close();
	l.clear();
	return EXIT_SUCCESS;*/
}

/*__________________________________________________________________________________________________*/
/****************************************************************************************************/
