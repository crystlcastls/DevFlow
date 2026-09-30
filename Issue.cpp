#include "Issue.h" 
#include <ctime> 

Issue::Issue(int id, string title, string description, string priority, string assignee) { 
    this->id = id; 
    this->title = title; 
    this->description = description; 
    this->priority = priority; 
    this->assignee = assignee;
    status = "To Do"; 
    time_t now = time(0);
    createdAt = ctime(&now); 
    if (!createdAt.empty() && createdAt.back() == '\n') { 
        createdAt.pop_back(); 
    }
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

string Issue::getCreatedAt() const { 
    return createdAt; 
}

void Issue::setStatus(string newStatus) { 
        status = newStatus; 
} 

void Issue::setAssignee(string newAssignee) { 
    assignee = newAssignee;
} 

void Issue::setCreatedAt(string newCreatedAt) { 
    createdAt = newCreatedAt; 
}






