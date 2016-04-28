// main.cpp

#include "tools.hpp"
#include "interface.hpp"
#include <string>
#include <iostream>
using namespace std;

void email_list_instructions(void)
{
    cout << ">> BEGIN INSTRUCTIONS" << endl << endl;
    cout << "\t- Open Excel Sheet." << endl;
    cout << "\t- Row A must be desired email address. App will check for duplicateds. make sure there are no blanks!" << endl;
    cout << "\t- Row B must be \"$$$\" next to EVERY email" << endl;
    cout << "\t- Save as tab_delim txt." << endl;
    cout << "\t- Make sure txt file is in same location as this exe" << endl << endl << endl;
}

int main(void)
{
    email_list_instructions();
    
    do{
        cout << "\n\n\t\t-------- Safe Email Blast --------\n\n\n";
        interface_namespace::launch();
    }while(tools_namespace::getBool("Run Again? "));
    
    cout << "\n\nShut Down!\n\n";
    return 0;
}