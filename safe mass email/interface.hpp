//  interface.hpp

#ifndef interface_hpp
#define interface_hpp

#include <string>
#include <iostream>
#include <vector>
using namespace std;

namespace interface_namespace
{
    void launch(void);
    void collect_email_list(vector<string> &email_list);
    void email_list_instructions(void);
    void collect_subject_line(string &subject_str);
    void collect_body_message(string &body_str);
    void review_matierals(string subject_str,
                          string body_str,
                          vector<string> vec);
    void create_script(string subject_str,
                       string body_str,
                       vector<string> vec);
}


#endif 
