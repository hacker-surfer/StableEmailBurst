//  interface.cpp

#include "interface.hpp"
#include "tools.hpp"
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

namespace interface_namespace
{
    void launch(void)
    {
        vector<string> email_list_vec;
        string subject, body;
        
        collect_email_list(email_list_vec);
        
        collect_subject_line(subject);
        
        collect_body_message(body);
        
        review_matierals(subject, body, email_list_vec);
        
        create_script(subject, body, email_list_vec);
    }
    
    void collect_email_list(vector<string> &email_list)
    {
        string file_name = tools_namespace::getString("Enter file name: ");
        ifstream file1(file_name);
        
        char iter = '$$$';
        vector<string> temp;
        
        for(string token; getline(file1, token, iter); temp.push_back(token));
        
        sort(temp.begin(), temp.end());
        
        for(int x = 0; x < temp.size(); ++x)
        {
            if(temp[x].length() > 3 && temp[x].find('@') != std::string::npos && temp[x] != temp [x-1])
            {
                tools_namespace::new_line_problem_solver(temp[x]);
                email_list.push_back(temp[x]);
            }
        }
        
        if(email_list.size() < 1)
        {
            cout << "There is no data in the file. try again.\n\n";
            email_list.clear();
            collect_email_list(email_list);
        }
        
        file1.close();
    }
    
    void collect_subject_line(string &subject_str)
    {
        subject_str = tools_namespace::getString("Enter a subject line: ");
    }
    
    void collect_body_message(string &body_str)
    {
        cout << "\n\t- Just enter the body. \n\t- A \'hello\' will automatically be inputed with spacing. \n\t- Thank you and signature will automatically be added at the bottom with spacing.";
        body_str = "Good Morning, \n\n";
        
        
        string file_name2 = tools_namespace::getString("\n\nEnter txt file name containing body here: " );
        ifstream file3(file_name2);
        string str;
        for(string token; getline(file3, token, '\n'); str += token + '\n');
        
        if(str.length() < 5)
        {
            cout << "No data in file. Try again." << endl << endl;
            str.clear();
            body_str.clear();
            collect_body_message(body_str);
        }
        
        body_str += str;
        
        body_str += "\n\nThank you,\n\n";
        body_str += "NICHOLAS NELSON | Estimator\n";
        body_str += "DriverSPG | Special Project Group\n";
        body_str += "1501 SOUTH HARRIS COURT, ANAHEIM, CA 92806\n";
        body_str += "T:  855.300.4SPG (855.300.4774)\n";
        body_str += "F:  855.FAX.2SPG (855.329.2774)\n";
        body_str += "nnelson@driverspg.com\n";
        
        file3.close();
    }
    
    void review_matierals(string subject_str, string body_str, vector<string> vec)
    {
        cout << "AUTO MESSAGE REVIEW" << endl << endl;
        cout << "Subject Line: " << subject_str << endl << endl;
        cout << "\t--- Body Message --- \n" << body_str << endl << endl << endl;
        
        cout << "Emails: " << endl << endl;
        for(int x = 0; x < vec.size(); ++x)
        {
            cout << x << ".) " << vec[x] << endl;
        }
        cout << endl << endl << endl;
        
        bool response = tools_namespace::getBool("Is the information above correct? ");
        if(response == false) launch();
    }
    
    void create_script(string subject_str, string body_str, vector<string> vec)
    {
        ofstream file2("raw_email_script.scpt");
        
        for(int x = 0; x < vec.size(); ++x)
        {
            string cur_str;
            
            // line 1
            cur_str += "tell application \"Mail\"\n";
            
            // line 2
            cur_str += "\tset theMessage to make new outgoing message with properties {visible:false, subject:\"";
            cur_str += subject_str;
            cur_str += "\", content:\"";
            cur_str += body_str;
            cur_str += "\"}\n";
            
            // line 3
            cur_str += "\ttell theMessage\n";
            
            // line 4
            cur_str += "\t\tmake new to recipient at end of to recipients with properties {address:\"";
            cur_str += vec[x];
            cur_str += "\"}\n";
            
            // line 5
            cur_str += "\tend tell\n";
            
            // line 6
            //cur_str += "\tdelay 0.01\n";
            
            // line 7
            cur_str += "\tsend theMessage\n";
            
            // line 8
            cur_str += "end tell\n\n\n\n";
            
            file2 << cur_str;
        }
        
        file2.close();
    }
}







































