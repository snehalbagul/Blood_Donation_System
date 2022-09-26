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
bool blood_group_validation(std::string);
bool medical_clearance_validation(char*);
//menu......................
bool submenu();
int report_corner_menu();
int manage_donor_menu();
int copy_donor_data();

//void copy_donor_data(const std::list<>,const char*);
//class donor;
//list<donor> l;

