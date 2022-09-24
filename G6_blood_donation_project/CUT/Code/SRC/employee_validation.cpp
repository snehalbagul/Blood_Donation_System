/*********************************************************************************************************
 ** FUNCTION NAME   :   employee_validation
 **
 ** DESCRIPTION     :
 **
 **
 ** RETURNS         :
 **
 **
 *********************************************************************************************************/

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int employee_validation()
{
	string pass;
	string password[]={"Yadav@123","Dolly@123","Snehal@123","Nidhi@123"};
	cout<<endl<<"Enter Employee password-";
	cin>>pass;
	if(pass!=password[0] && pass!=password[1] && pass!=password[2] && pass!=password[3])
		return 1;
	else
		return 0;
}

