/******************************************************************************************************************
 *
 ** FUNCTION NAME    :       Validation
 **
 ** DESCRIPTION      :       In this file we perform all the necessary validations for data members of
 **                          donor and receiver class
 **                         
 ** RETURNS          :       Bool returns true and false
 **
 **
 ******************************************************************************************************************/

#include<iostream>
#include<iomanip>
#include<string.h>
#include<string>
using namespace std;

// aadhar validation

bool aadhar_validation(char* aadhar_num)
{
	int length=sizeof(aadhar_num)/sizeof(aadhar_num[0]);

	try
	{
		for(int i=0;aadhar_num[i]!='\0';i++)
		{
			if(!isdigit(aadhar_num[i]))
				throw aadhar_num;

		}
	}
	catch(const char* a)
	{
		cout<<"Aadhar number should be only in digits."<<endl;
		return false;
	}

	try
	{

		if(strlen(aadhar_num)!=6)
			throw aadhar_num;
	}
	catch(const char* a)

	{
		cout<<"Aadhar number should be of 6 digits only."<<endl;
		return false;
	}

	return true;
}

// name validation
bool name_validation(char* name)
{
	//transform(name.begin(),name.end(),name.begin(), ::toupper);
	try
	{
		for(int i=0;name[i]!='\0';i++)
		{

			if(!isalpha(name[i]))
				throw name;
		}
	}
	catch(const char*  a)
	{
		cout<<"Name should be in only alphabets(A-Z)."<<endl;
		return false;
	}

	try
	{

		if(strlen(name)>20||strlen(name)<3)
			throw name;
	}
	catch(const char* a)
	{
		cout<<"Name should be maximum 20 characters. and min 5 characters"<<endl;
		return false;
	}

	return true;
}   


// address validation
bool address_validation(char* address)
{
	int length=strlen(address);
	try
	{
		if(length>50 || length<5)
			throw address;
	}
	catch(const char* a)
	{
		cout<<"Address should be more than 5 characters and less than 50 characters."<<endl;
		return false;

	}

	return true;

}

// age validation
bool age_validation(char* age)
{
	try
	{
		for(int i=0;age[i]!='\0';i++)
		{

			if(isdigit(age[i])!=1)
				throw age;
		}
	}
	catch(const char* a)
	{
		cout<<"Age should be only in digits."<<endl;
		return false;
	}


	try
	{
		if(stoi(age)>50 || stoi(age)<18)
			throw age;
	}
	catch(const char* a)
	{
		cout<<"Age should be between 18-50."<<endl;
		return false;
	}

	return true;
}

// blood group validation
bool blood_group_validation(char* ch)
{
	try
	{
		if(strlen(ch)!=1)
			throw ch;
	}
	catch(const char* a)
	{
		cout<<endl<<"Choice should be of only 1 digit.";
		return false;
	}
	try
	{
		if(!isdigit(ch[0]))
			throw ch;
	}
	catch(const char* b)
	{
		cout<<endl<<"Choice should be only digit.";
		return false;
	}
	try
	{
		if(atoi(ch)<1 || atoi(ch)>8)
		{
			throw ch;
		}
	}
	catch(const char* c)
	{
		cout<<endl<<"Choice should be between 1-8";
		return false;
	}
	return true;

}

//medical clearance validation
bool medical_clearance_validation(char* medical_clear)
{
	try
	{
		if(medical_clear[0]!='Y' && medical_clear[0]!='y')
			throw medical_clear;
	}
	catch(const char* a)
	{
		cout<<"You should enter  only Y/y for medical clearance"<<endl;
		return false;
	}

	return true;
}

