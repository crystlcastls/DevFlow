#include "Issue.h" 

Issue::Issue(int id, string title, string description, string priority, string assignee) { 
    this->id = id; 
    this->title = title; 
    this->description = description; 
    this->priority = priority; 
    this->assignee = assignee;
    status = "To Do"; 
} 

int Issue::getId() const {  
    return id;
} 

string Issue::getTitle() const { 
    return title; 
} 

string Issue::getDescription() const { 
    return description;
} 

string Issue::getPriority() const { 
    return priority;
} 

string Issue::getStatus() const { 
    return status;
}  

string Issue::getAssignee() const { 
    return assignee;
}

void Issue::setStatus(string newStatus) { 
        status = newStatus; 
} 

void Issue::setAssignee(string newAssignee) { 
    assignee = newAssignee;
}






