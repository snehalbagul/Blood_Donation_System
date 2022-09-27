/******************************************************************************************
 ** FILE NAME     :     header
 **
 ** DESCRIPTION   :     In this fileall headers are included
 **
 **
 ****************************************************************************************/

#ifndef HEADER_H
#define HEADER_H

static int flag=0;
int donor_file_to_list();
int list_to_donor_file();
int transaction_file_to_list();
int list_to_transaction_file();
int donor_registration();
void receiver_registration();
int employee_validation();
bool aadhar_validation(char*);
bool name_validation(char*);
bool address_validation(char*);
bool age_validation(char*);
bool blood_group_validation(char*);
bool medical_clearance_validation(char*);
bool submenu();
int report_corner_menu();
int manage_donor_menu();
int copy_donor_data();
#include "donor_registration.cpp"
#include "donor_file_operation.cpp"
#include "receiver_registration.cpp"
#include "class.hpp"
#include "receiver_related_operations.cpp"
#include "employee_validation.cpp"
#include "report.cpp"
#include "submenu.cpp"
#include "transaction_file_operation.cpp"

#endif

