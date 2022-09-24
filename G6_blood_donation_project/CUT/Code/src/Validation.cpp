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
#include<string>
//#include "header.hpp"
//#include "donor_registration.cpp"
//#include "receiver_registration.cpp"
using namespace std;

// aadhar validation

bool aadhar_validation(string aadhar_num)
{

	try
	{
		for(int i=0;i<aadhar_num.length();i++)
		{
			if(isdigit(aadhar_num[i])!=1)
				throw aadhar_num;

		}
	}
	catch(string a)
	{
		cout<<"Aadhar number should be only in digits."<<endl;
		return false;
	}

	try
	{

		if(aadhar_num.length()!=6)
			throw aadhar_num;
	}
	catch(string a)

	{
		cout<<"Aadhar number should be of 6 digits only."<<endl;
		return false;
	}

	return true;
}

// name validation
bool name_validation(string name)
{
	//transform(name.begin(),name.end(),name.begin(), ::toupper);
	try
	{
		for(int i=0;i<name.length();i++)
		{

			if(isalpha(name[i])==0)
				throw name;
		}
	}
	catch(string a)
	{
		cout<<"Name should be in only alphabets(A-Z)."<<endl;
		return false;
	}

	try
	{

		if(name.length()>20||name.length()<3)
			throw name;
	}
	catch(string a)
	{
		cout<<"Name should be maximum 20 characters. and min 5 characters"<<endl;
		return false;
	}

	return true;
}   


// address validation
bool address_validation(string address)
{
	int length=address.length();
	try
	{
		if(length>50 || length<5)
			throw address;
	}
	catch(string a)
	{
		cout<<"Address should be more than 5 characters and less than 50 characters."<<endl;
		return false;

	}

	return true;

}

// age validation
bool age_validation(string age)
{
	try
	{
		for(int i=0;i<age.length();i++)
		{

			if(isdigit(age[i])!=1)
				throw age;
		}
	}
	catch(string a)
	{
		cout<<"Age should be only in digits."<<endl;
		return false;
	}


	try
	{
		if(stoi(age)>50 || stoi(age)<18)
			throw age;
	}
	catch(string a)
	{
		cout<<"Age should be between 18-50."<<endl;
		return false;
	}

	return true;
}

// blood group validation
bool blood_group_validation(string ch)
{
	try
	{
		if(ch.length()!=1)
			throw ch;
	}
	catch(string a)
	{
		cout<<endl<<"Choice should be of only 1 digit.";
		return false;
	}
	try
	{
		if(!isdigit(ch[0]))
			throw ch;
	}
	catch(string b)
	{
		cout<<endl<<"Choice should be only digit.";
		return false;
	}
	try
	{
		if(stoi(ch)<1 || stoi(ch)>8)
		{
			throw ch;
		}
	}
	catch(string c)
	{
		cout<<endl<<"Choice should be between 1-8";
		return false;
	}
	return true;

}

//medical clearance validation
bool medical_clearance_validation(string medical_clear)
{
	try
	{
		if(medical_clear!="Y" && medical_clear!="y")
			throw medical_clear;
	}
	catch(string a)
	{
		cout<<"You should enter  only Y/y for medical clearance"<<endl;
		return false;
	}

	return true;
}

