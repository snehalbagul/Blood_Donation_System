/********************************************************************************************************************
 ** FUNCTION NAME     :      transaction_file_operation
 **
 ** DESCRIPTION       :
 **
 **
 ** RETURNS           :
 **
 **
 ******************************************************************************************************************/

#include<iostream>
#include<iomanip>
#include "header.hpp"
using namespace std;

int transaction_file_to_list()
{
	receiver rec;
	fstream fl;
	fl.open("Transaction_database",ios::in|ios::binary);
	if(!fl)
	{
		cout<<endl<<"Can't open a file.";
		return 0;
	}
	fl.read((char *)&rec,sizeof(receiver));
	while(!fl.eof())
	{
		rl.push_back(rec);
		fl.read((char *)&rec,sizeof(receiver));
	}
	fl.close();

	//cout<<"not available."<<endl;
	return 0;
}

int list_to_transaction_file()
{
	receiver rec;
	fstream fl;
	fl.open("Transacton_database",ios::out|ios::binary);
	if(!fl)
	{
		cout<<endl<<"can't open a file.";
		return 0;
	}
	for(receiver rec:rl)
	{
		fl.write((char *)&rec,sizeof(receiver));
	}
	fl.close();
	rl.clear();
	//cout<<"not available."<<endl;
	return 0;
}
