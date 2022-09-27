/**************************************************************************************************************
 ** FUNCTION NAME   :   manage_donor_data
 **
 ** DESCRIPTION     :   In this file edit, remove and view functions are performed on donor data 
 **
 **
 ** RETURNS         :   EXIT_FAILURE or EXIT_SUCCESS
 **
 **
 *************************************************************************************************************/
#include<iostream>
#include<iomanip>
#include<set>
#include<list>
#include<string>
#include<string.h>
#include<stdlib.h>
using namespace std;

//-----------------------------EDIT DONOR DATA------------------------------------------

int donor::edit_donor_data()
{
	system("clear");
	if(l.empty())
	{
		cout<<endl<<"Donor list is empty."<<endl;
		return EXIT_FAILURE;
	}
	flag=0;
	char a_num[15];
	while(1)
	{
		cout<<endl<<"Enter Aadhar number of donor-";
		cin>>a_num;
		if(strlen(a_num)!=6)
		{
			cout<<"Aadhar number should be of 6 digits."<<endl;
			continue;
		}
		for(int i=0;i<6;i++)
		{
			if(!isdigit(a_num[i]))
			{
				flag=1;
				cout<<"Aadhar number should only digits."<<endl;
				break;
			}
		}
		if(flag==1)
			continue;
		else
			break;
	}
	flag=0;
	for(list<donor>::iterator it=l.begin();it!=l.end();it++)
		//for(auto it:l)
	{
		if(strcmp(it->aadhar_num,a_num)==0)
		{
			flag=1;
			cout<<endl<<"**************************************************************************************"<<endl;
			cout<<"                               PREVIOUS DETAILS OF DONOR (AADHAR NUM-"<<a_num<<")"<<endl;
			cout<<endl<<"**************************************************************************************"<<endl;
			cout<<endl<<"Name-"<<it->name<<"     "<<"Address-"<<it->address<<"     "<<"Age-"<<it->age<<"     "<<"Blood Group-"<<it->blood_group<<"     "<<"Units donated-"<<it->units_donated<<endl;

			cout<<endl<<"**************************************************************************************"<<endl;

			while(1)
			{
				cout<<endl<<"Enter updated name-";
				cin>>it->name;
				if(name_validation(it->name)==true)
					break;
				else
					continue;
			}
			while(1)
			{
				cout<<endl<<"Enter updated address-";
				cin>>it->address;
				if(address_validation(it->address)==true)
					break;
				else 
					continue;
			}
			while(1)
			{
				cout<<endl<<"Enter age-";
				cin>>it->age;
				if(age_validation(it->age)==true)
					break;
				else
					continue;
			}
		}

	}
	if(flag==0)
	{
		cout<<endl<<"Aadhar  number does not exists.";
	}
	system("read a");
	system("clear");

	return EXIT_SUCCESS;
}

/*______________________________________________________________________________________*/
/****************************************************************************************/

int donor::remove_donor_data()
{
	system("clear");

	if(l.empty())
	{

		cout<<endl<<"************************************************************************************"<<endl;
		cout<<endl<<"	                          Donor list is empty."<<endl;

		cout<<endl<<"************************************************************************************"<<endl;
		return EXIT_FAILURE;
	}

	flag=0;
	char a_num[15];
	while(1)
	{
		cout<<endl<<"Enter aadhar number of the donor whose record you want to delete-";
		cin>>a_num;
		if(strlen(a_num)!=6)
		{
			cout<<"Aadhar number should be of 6 digits."<<endl;
			continue;
		}
		for(int i=0;i<6;i++)
		{
			if(!isdigit(a_num[i]))
			{
				flag=1;
				cout<<"Aadhar number should only digits."<<endl;
				break;
			}
		}
		if(flag==1)
			continue;
		else
			break;
	}
	flag=0;
	for(list<donor>::iterator it=l.begin();it!=l.end();it++)
	{
		if(strcmp(it->aadhar_num,a_num)==0)
		{
			flag=1;
			l.erase(it);
			break;
		}
	}
	if(flag==0)
	{
		cout<<endl<<"*********Aadhar number not found!!!*********"<<endl;
		system("read a");
		system("clear");
		return EXIT_FAILURE;
	}
	else 
	{

		cout<<endl<<"************************************************************************************"<<endl;
		cout<<endl<<"                        DONOR DELETED SUCCESSFULLY."<<endl;
		cout<<endl<<"************************************************************************************"<<endl;

		system("read a");
		system("clear");
		return EXIT_SUCCESS;
	}
}

/*______________________________________________________________________________________*/
/****************************************************************************************/

int donor::view_donor_data()
{
	system("clear");
	if(l.empty())
	{

		cout<<endl<<"************************************************************************************"<<endl;
		cout<<endl<<"                             Donor list is empty."<<endl;
		cout<<endl<<"************************************************************************************"<<endl;
		return EXIT_FAILURE;
	}
	flag=0;
	char a_num[15];
	while(1)
	{
		cout<<endl<<"Enter aadhar number of donor-";
		cin>>a_num;
		if(strlen(a_num)!=6)
		{
			cout<<"Aadhar number should be of 6 digits only."<<endl;
			continue;
		}
		for(int i=0;i<6;i++)
		{
			if(!isdigit(a_num[i]))
			{
				flag=1;
				cout<<"Aadhar number should be only digits."<<endl;
				break;
			}
		}
		if(flag==0)
			break;
		else
			continue;
	}
	flag=0;	
	for(auto it:l)
	{
		if(strcmp(it.aadhar_num,a_num)==0)
		{
			flag=1;
			cout<<endl<<"____________________________________________________________________________________________________"<<endl;
			cout<<endl<<"****************************************************************************************************"<<endl;
			cout<<endl<<"                          DONOR DETAILS(AADHAR_NO.)-"<<a_num<<endl;
			cout<<endl<<"****************************************************************************************************"<<endl;
			cout<<"Aadhar No.-"<<it.aadhar_num<<"    "<<"Name-"<<it.name<<"    "<<"Address-"<<it.address<<"    "<<"Age-"<<it.age<<"    "<<"Blood Group-"<<it.blood_group<<"    "<<"Units donated-"<<it.units_donated<<endl<<endl;
			cout<<endl<<"____________________________________________________________________________________________________"<<endl;
			break;
		}

	}
	if(flag==0)
	{

		cout<<endl<<"***********************************************************************************"<<endl;
		cout<<endl<<"                            Aadhar number not found!!!";
		cout<<endl<<"***********************************************************************************"<<endl;
	}
	system("read a");
	system("clear");
	return EXIT_SUCCESS;
}

/*______________________________________________________________________________________*/
/****************************************************************************************/

int donor::view_all_donor_data()
{
	system("clear");
	if(l.empty())
	{
		cout<<endl<<"***********************************************************************************"<<endl;
		cout<<endl<<"                          Donor list is empty."<<endl;
		cout<<endl<<"***********************************************************************************"<<endl;
		return EXIT_FAILURE;
	}
	cout<<endl<<"____________________________________________________________________________________________"<<endl<<endl;
	cout<<endl<<"********************************************************************************************"<<endl;
	cout<<endl<<"                                   DONOR DETAILS"<<endl;
	cout<<endl<<"********************************************************************************************"<<endl;
	cout<<endl<<setw(10)<<"AADHAR_NO."<<setw(12)<<"NAME"<<setw(18)<<"ADDRESS"<<setw(18)<<"AGE"<<setw(15)<<"BLOOD_GROUP"<<setw(18)<<"UNITS_DONATED"<<setw(18)<<endl;
	cout<<endl<<"____________________________________________________________________________________________"<<endl<<endl;
	for(auto it:l)
	{
		cout<<setw(10)<<it.aadhar_num<<setw(12)<<it.name<<setw(18)<<it.address<<setw(18)<<it.age<<setw(15)<<it.blood_group<<setw(18)<<it.units_donated<<setw(18)<<endl;
	}
	cout<<endl<<"____________________________________________________________________________________________"<<endl<<endl;

	system("read a");
	system("clear");
	return EXIT_SUCCESS;
}
/*______________________________________________________________________________________*/
/****************************************************************************************/
