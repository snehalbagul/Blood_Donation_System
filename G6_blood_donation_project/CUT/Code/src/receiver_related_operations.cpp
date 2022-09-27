/***************************************************************************************************************
 ** FUNCTION NAME   :    receiver_registration_operation
 **
 **
 ** DESCRIPTION     :    In this file the receiver registration operations are performed
 **
 **
 ** RETURNS         :    EXIT_SUCCESS or EXIT_FAILURE
 **
 **
 **************************************************************************************************************/

#include<iostream>
#include<iomanip>
#include<set>
#include<list>
#include<deque>
#include<mutex>
#include<string>
#include "header.hpp"
using namespace std;

/*_____________________________________________________________________________________________________________*/
/**************************************************************************************************************/
//****************************************VIEW RECEIVER QUEUE**************************************************/
//function to display all the recivers present in a queue after registration...

mutex accum_mutex;

int receiver::view_receiver_queue()
{
	
	//if list is emptythen returns...
	if(q.empty())
	{
		system("clear");
		
		cout<<endl<<"____________________________________________________________________________________"<<endl;

		cout<<endl<<"************************************************************************************"<<endl;
		cout<<endl<<setw(25)<<"RECEIVER QUEUE IS EMPTY."<<endl;
		cout<<endl<<"____________________________________________________________________________________"<<endl;
		cout<<endl<<"************************************************************************************"<<endl;
		system("read a");
		system("clear");

		return EXIT_FAILURE;
	}
	system("clear");

	//if list is not empty then display the receiver's queue...
	cout<<endl<<"____________________________________________________________________________________________";
	cout<<endl<<"********************************************************************************************";

	cout<<endl<<"                                  RECEIVER'S QUEUE";

	cout<<endl<<"********************************************************************************************"<<endl;
	cout<<setw(10)<<"AADHAR NUMBER"<<setw(15)<<"NAME"<<setw(18)<<"ADDRESS"<<setw(18)<<"AGE"<<setw(22)<<"DONOR_AADHAR_NUMBER"<<setw(20)<<endl;

	//traverse through each receiver object present in queue...
	for(receiver it:q)
	{
		cout<<setw(10)<<it.aadhar_num<<setw(18)<<it.name<<setw(18)<<it.address<<setw(18)<<it.age<<setw(20)<<it.donor_aadhar_num<<setw(20)<<endl;
	}
	cout<<endl<<"____________________________________________________________________________________________"<<endl;

	system("read a");
	system("clear");
	return EXIT_SUCCESS;

}



/*________________________________________________________________________________________________________*/
/**********************************************************************************************************/
//***********************************CARRY OUT DONATION****************************************************/
//Function to carry out donation and storing all details of receiver in the transaction file by deleting 
//receiver from queue one by one before storing it to transaction file...


int receiver::carry_out_donation()
{

	receiver r;

	//if list is empty then returns...
	if(q.empty())
	{

		system("clear");
		
		cout<<endl<<"____________________________________________________________________________________"<<endl;

		cout<<endl<<"************************************************************************************"<<endl;
		cout<<endl<<setw(25)<<"RECEIVER QUEUE IS EMPTY."<<endl;
		cout<<endl<<"____________________________________________________________________________________"<<endl;
		cout<<endl<<"************************************************************************************"<<endl;
		system("read a");
		system("clear");

		return EXIT_FAILURE;
	}
	//locking the process through mutex...
	accum_mutex.lock();
	while(!q.empty())
	{
		r=q.front(); 
		rl.push_back(r);
		q.pop_front();
	}
	//unlocking the process through mutex...
	accum_mutex.unlock();

	system("clear");
	cout<<endl<<"____________________________________________________________________________________________";

	cout<<endl<<"____________________________________________________________________________________________"<<endl;


	cout<<endl<<"******************************DONATION PROCESS SUCCESSFULL**********************************"<<endl;
	cout<<endl<<"____________________________________________________________________________________________";
	cout<<endl<<"____________________________________________________________________________________________"<<endl;

	system("read a");
	system("clear");
	return EXIT_SUCCESS;
}



/*______________________________________________________________________________________________________________*/
/***************************************************************************************************************/
/************************************REMOVE DAILY TRANSACTION FILE**********************************************/
//function to remove daily transaction file ...

int receiver::remove_daily_transaction_file()
{
	system("clear");

	cout<<endl<<"____________________________________________________________________________________________"<<endl;

	cout<<endl<<"____________________________________________________________________________________________"<<endl;
	//clearing the receiver list...
	rl.clear();

	cout<<endl<<"*************************************FILE DELETED*******************************************"<<endl;
	cout<<endl<<"____________________________________________________________________________________________"<<endl;

	cout<<endl<<"____________________________________________________________________________________________"<<endl;
	system("read a");
	system("clear");
	return EXIT_SUCCESS;
}



/*_____________________________________________________________________________________________________________*/
/***************************************************************************************************************/
/***************************************RECEIVER REGISTRATION***************************************************/
//Function to call get_receiver_data() function that will get all receiver details and after that 
//this function will store all details of receiver in a queue...


void receiver_registration()
{
	receiver r;

	accum_mutex.lock();
	if(r.get_receiver_data()==0)
	{
		q.push_back(r);
	}
	accum_mutex.unlock();
}

/*_____________________________________________________________________________________________________________*/
/***************************************************************************************************************/
