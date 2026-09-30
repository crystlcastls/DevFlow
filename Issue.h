#ifndef ISSUE_H 
#define ISSUE_H 

#include <string> 
using namespace std; 

class Issue { 
private: 
    int id; 
    string title; 
    string description; 
    string priority; 
    string status; 
    string assignee;  

    public: 
        Issue(int id, string title, string description, string priority, string assignee); 
        int getId() const; 
        string getTitle() const; 
        string getDescription() const; 
        string getPriority() const; 
        string getStatus() const; 
        string getAssignee() const;

        void setStatus(string newStatus); 
        void setAssignee(string newAssignee);

};

#endif 