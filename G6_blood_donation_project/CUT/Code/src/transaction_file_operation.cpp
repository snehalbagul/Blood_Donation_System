/********************************************************************************************************************
 ** FUNCTION NAME     :      transaction_file_operation
 **
 ** DESCRIPTION       :      In this file all file operation performed on related to transaction
 **
 **
 ** RETURNS           :      EXIT_FAILURE or EXIT_SUCCESS
 **
 **
 ******************************************************************************************************************/

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
#include "header.hpp"
using namespace std;

/**************************************TRANSACTION FILE TO LIST*************************************************/
//Function to read data from transaction file to list...

struct temp2
{
	char a_num[15];
	char da_num[15];
	char name[20];
	char address[30];
	char age[5];
	char blood_group[5];
	int units_donated;
}tmp1;


int transaction_file_to_list()
{
	fstream fl;
	receiver r;
	
	fl.open("Transaction_database",ios::in|ios::binary);
	if(fl)
	{
		fl.read((char*)&tmp1,sizeof(tmp1));

		while(!fl.eof())
		{
			strcpy(r.get_aadhar_num(),tmp1.a_num);
			strcpy(r.get_donor_aadhar_num(),tmp1.da_num);
			strcpy(r.get_name(),tmp1.name);
			strcpy(r.get_address(),tmp1.address);
			strcpy(r.get_age(),tmp1.age);
			rl.push_back(r);
			fl.read((char*)&tmp1,sizeof(tmp1));
		}

	}
	fl.close();
	return EXIT_SUCCESS;
	/*receiver rec;
	fstream fl;
	fl.open("Transaction_database",ios::in|ios::binary);
	if(!fl)
	{
		cout<<endl<<"Can't open a file.";
		return EXIT_FAILURE;
	}
	fl.read((char *)&rec,sizeof(receiver));
	while(!fl.eof())
	{
		rl.push_back(rec);
		fl.read((char *)&rec,sizeof(receiver));
	}
	fl.close();

	//cout<<"not available."<<endl;
	return EXIT_SUCCESS;*/
}

/**************************************LIST TO TRANSACTION FILE*************************************************/
//Function to store data from list to file...

int list_to_transaction_file()
{
	fstream fl;
	if(!rl.empty())
	{
		fl.open("Transaction_database",ios::out);
		for(list<receiver>::iterator it=rl.begin();it!=rl.end();it++)
		{
			strcpy(tmp1.a_num,it->get_aadhar_num());
			strcpy(tmp1.da_num,it->get_donor_aadhar_num());
			strcpy(tmp1.name,it->get_name());
			strcpy(tmp1.address,it->get_address());
			strcpy(tmp1.age,it->get_age());
			strcpy(tmp1.blood_group,it->get_blood_group());
			fl.write((char*)&tmp1,sizeof(tmp1));

		}
		fl.close();
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
	/*receiver rec;
	fstream fl;
	fl.open("Transacton_database",ios::out|ios::binary);
	if(!fl)
	{
		cout<<endl<<"can't open a file.";
		return EXIT_FAILURE;
	}
	for(receiver rec:rl)
	{
		fl.write((char *)&rec,sizeof(receiver));
	}
	fl.close();
	rl.clear();
	//cout<<"not available."<<endl;
	return EXIT_SUCCESS;*/
}

/************************************************************************************************************/
