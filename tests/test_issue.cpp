#include "../Issue.h" 
#include <cassert> 
#include <iostream> 

using namespace std; 

int main() { 
    Issue issue(1, "Fix login bug", "Login button does not work.", "High", "Kyle"); 

    assert(issue.getId() == 1); 
    assert(issue.getTitle() == "Fix login bug"); 
    assert(issue.getDescription() == "Login button does not work."); 
    assert(issue.getPriority() == "High"); 
    assert(issue.getStatus() == "To Do"); 
    assert(issue.getAssignee() == "Kyle"); 
    issue.setStatus("In Progress"); 
    assert(issue.getStatus() == "In Progress"); 
    
    issue.setAssignee("Alex");
    assert(issue.getAssignee() == "Alex");

    cout << "All Issue tests passed!" << endl; 

    return 0; 
}