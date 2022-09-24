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
#include<iomanip>
#include "header.hpp"
using namespace std;

/**************************************TRANSACTION FILE TO LIST*************************************************/
//Function to read data from transaction file to list...

int transaction_file_to_list()
{
	receiver rec;
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
	return EXIT_SUCCESS;
}

/**************************************LIST TO TRANSACTION FILE*************************************************/
//Function to store data from list to file...

int list_to_transaction_file()
{
	receiver rec;
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
	return EXIT_SUCCESS;
}

/************************************************************************************************************/
