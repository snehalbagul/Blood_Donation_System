/****************************************************************************************************************
 ** FUNCTION NAME    :    report
 **
 ** DESCRIPTION      :    In this file report related operation are performed
 **
 **
 ** RETURNS          :    EXIT_FAILURE or EXIT_SUCCESS
 **
 **
 ***************************************************************************************************************/
#include<iostream>
#include<iomanip>
#include<list>
#include<iterator>
#include<fstream>
#include<algorithm>
#include<string>
#include "header.hpp"
using namespace std;


/*___________________________________________________________________________________________________________*/
/*************************************************************************************************************/
/**************************************DAILY DONATION REPORT**************************************************/
//Function to display daily donation report...


int receiver::daily_donation_report()
{

	system("clear");

	//checks if list is empty...
	if(rl.empty())
	{
		cout<<endl<<"____________________________________________________________________________________"<<endl;

		cout<<endl<<"*****************************TRANSACTION LIST IS EMPTY!!!***************************"<<endl;
		cout<<endl<<"____________________________________________________________________________________"<<endl;

		return EXIT_FAILURE;
	}


	//if not empty then displays the donation list...
	cout<<endl<<"____________________________________________________________________________________________________";
	cout<<endl<<"____________________________________________________________________________________________________";
	cout<<endl<<"****************************************************************************************************"<<endl;
	cout<<endl<<"                             DETAILS OF RECEIVER'S"<<endl;
	cout<<endl<<"****************************************************************************************************"<<endl;
	cout<<endl<<setw(10)<<"AADHAR_NO."<<setw(12)<<"NAME"<<setw(18)<<"ADDRESS"<<setw(18)<<"BLOOD_GROUP"<<setw(18)<<"DONOR_AADHAR_NO."<<setw(12)<<endl;
	
	//traverse through each receiver object present in a receiver list...
	for(auto it:rl)
	{
		cout<<setw(10)<<it.aadhar_num<<setw(12)<<it.name<<setw(18)<<it.address<<setw(18)<<it.blood_group<<setw(18)<<it.donor_aadhar_num<<setw(12)<<endl;

	}
	cout<<endl<<"____________________________________________________________________________________________________";
	cout<<endl<<"____________________________________________________________________________________________________";

	system("read a");
	system("clear");
	return EXIT_SUCCESS;
}



/*__________________________________________________________________________________________________________________*/
/********************************************************************************************************************/
/********************************FIVE HIGHEST DONOR REPORT***********************************************************/
//function to display five highest donor report...


int donor::five_highest_donor_report()
{
	system("clear");
	l.sort(greater<donor>());  //sorting donor in descending order on the basis of units donated...
	int flag=0;

	//checks if list is empty or not...
	if(l.empty())
	{
		cout<<endl<<"____________________________________________________________________________________"<<endl;
		cout<<endl<<"********************************LIST IS EMPTY!!!************************************"<<endl;
		cout<<endl<<"____________________________________________________________________________________"<<endl;
		return EXIT_FAILURE;
	}

	//if list is not empty then display the report...
	cout<<endl<<"____________________________________________________________________________________________________"<<endl;
	cout<<endl<<"****************************************************************************************************";
	cout<<endl<<"                                 FIVE HIGHEST DONOR";

	cout<<endl<<"****************************************************************************************************"<<endl;

	cout<<endl<<"____________________________________________________________________________________________________"<<endl;
	cout<<endl<<setw(10)<<"AADHAR_NO."<<setw(12)<<"NAME"<<setw(18)<<"ADDRESS"<<setw(18)<<"AGE"<<setw(14)<<"BLOOD_GROUP"<<setw(18)<<"UNITS_DONATED"<<setw(18)<<endl;
	cout<<endl<<"____________________________________________________________________________________________________"<<endl<<endl;

	//traverse though each donor object present in a donor list...
	for(auto it:l)
	{
		if(flag==5)
			break;
		else
		{
			flag++;
			cout<<setw(10)<<it.aadhar_num<<setw(12)<<it.name<<setw(18)<<it.address<<setw(18)<<it.age<<setw(12)<<it.blood_group<<setw(18)<<it.units_donated<<setw(18)<<endl;
		}
	}

	cout<<endl<<"____________________________________________________________________________________________________"<<endl;
	system("read a");
	system("clear");
	return EXIT_SUCCESS;

}

/*____________________________________________________________________________________________________________________*/
/**********************************************************************************************************************/
