#include "../IssueManager.h" 
#include <cassert> 
#include <iostream> 

using namespace std; 

int main() { 
    IssueManager manager; 

    int createdIssueId = manager.createIssue("Fix login bug", "Login button does not work.", "high", "Kyle"); 

    assert(createdIssueId > 0); 
    
    int invalidTitleId = manager.createIssue("  ", "Users cannot log in", "High", "Kyle");
    assert(invalidTitleId == -1); 

    int invalidPriorityId = manager.createIssue("Fix dashboard", "Dashboard does not load", "Banana", "Kyle"); 
    assert(invalidPriorityId == -1); 

    int invalidAssigneeId = manager.createIssue("Fix Dashboard", "Dashboard does not load", "High", "  "); 
    assert(invalidAssigneeId == -1); 

    cout << "All IssueManager tests passed!" << endl;
    return 0;
}