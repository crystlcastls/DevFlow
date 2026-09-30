#include "IssueManager.h"
#include <iostream> 
#include <limits> 
#include <algorithm> 
#include <cctype> 
#include <fstream> 
#include <sstream>

IssueManager::IssueManager() { 
     nextIssueId = 1; 
}  

void IssueManager::viewIssues() const {
    cout << "\n===== ALL ISSUES =====" << endl; 
    cout << "Total Issues: " << getIssueCount() << endl; 

    if(issues.empty()) { 
        cout << "\nNo issues found." << endl; 
        return;
    }

    for (int i = 0; i < issues.size(); i++) { 
        const Issue& issue = issues.at(i); 
        
        displayIssue(issue); 
    }
}

void IssueManager::searchIssue() const { 
    int searchId;
     
    cout << "Enter Issue ID to search: "; 
    searchId = getValidInteger(); 

    int index = findIssueIndex(searchId); 
    
    if (index == -1) { 
        cout << "Issue not found." << endl; 
        return;
    } 

    const Issue& issue = issues.at(index);
    
    displayIssue(issue);        
} 

void IssueManager::updateIssue() { 
    int issueId;  

    cout << "Enter Issue Id to update: " << endl; 
    issueId = getValidInteger(); 

    int index = findIssueIndex(issueId); 
    
    if (index == -1) { 
        cout << "Issue not found." << endl; 
        return;
    } 

    Issue& issue = issues.at(index);

    cout << "\n Issue #" << issue.getId() << " found!" << endl; 
    cout << "Title: " << issue.getTitle() << endl; 
    cout << "Current Status: " << issue.getStatus() << endl; 
    cout << "Current Assignee: " << issue.getAssignee() << endl; 

    int updateChoice;
    int statusChoice; 

    cout << "\nWhat would you like to update?" << endl;
    cout << "1. Status" << endl;
    cout << "2. Assignee" << endl;
    cout << "Choose an option: ";

    updateChoice = getValidInteger(1, 2); 

    if (updateChoice ==1) { 
        cout << "New Status: " << issue.getStatus() << endl;
    } 

    else if (updateChoice == 2) {
    string newAssignee;

    newAssignee = getValidText("Enter new assignee: ");

    issue.setAssignee(newAssignee);

    cout << "\nIssue #" << issueId << " reassigned successfully!" << endl;
    cout << "New Assignee: " << issue.getAssignee() << endl; 

    saveIssues();
    }

    cout << "\n1. To Do" << endl;
    cout << "2. In Progress" << endl;
    cout << "3. Done" << endl;
    cout << "Choose new status: ";

    statusChoice = getValidInteger(1, 3); 

    if (statusChoice == 1) { 
        issue.setStatus("To Do");
    }  

    else if (statusChoice == 2) { 
        issue.setStatus("In Progress");
    } 

    else if (statusChoice == 3) { 
        issue.setStatus("Done");
    }  
     
    cout << "\nIssue #" << issueId << " updated successfully!" << endl; 
    cout << "New Status: " << issue.getStatus() << endl; 
    
    saveIssues();
} 
        
void IssueManager::deleteIssue() { 
    
    int deleteId;  

    cout << "Enter Issue ID to delete: "; 
    deleteId = getValidInteger(); 

    int index = findIssueIndex(deleteId); 

    if (index == -1) { 
        cout << "Issue not found." << endl; 
        return;
    } 
    
    issues.erase(issues.begin() + index); 

    cout << "Issue #" << deleteId << " deleted successfully!" << endl; 

    saveIssues();
}  

void IssueManager::filterIssuesByStatus() const { 
    int statusChoice; 
    string selectedStatus; 

    cout << "\n===== FILTER BY STATUS =====" << endl;
    cout << "1. To Do" << endl;
    cout << "2. In Progress" << endl;
    cout << "3. Done" << endl;
    cout << "Choose a status: "; 

    statusChoice = getValidInteger(1, 3); 

    if (statusChoice == 1) {
    selectedStatus = "To Do";
    }
    else if (statusChoice == 2) {
        selectedStatus = "In Progress";
    }
    else if (statusChoice == 3) {
        selectedStatus = "Done";
    } 

    bool found = false; 

    for (int i = 0; i < issues.size(); i++) { 
        const Issue& issue = issues.at(i); 

        if (issue.getStatus() == selectedStatus) { 
            displayIssue(issue);

            found = true;
        }
    } 

    if (!found) { 
        cout << "\n No issues found with status: " << selectedStatus << endl;
    }
} 

void IssueManager::filterIssuesByPriority() const { 

    int priorityChoice; 
    string selectedPriority; 

    cout << "\n===== FILTER BY PRIORITY =====" << endl;
    cout << "1. Low" << endl;
    cout << "2. Medium" << endl;
    cout << "3. High" << endl;
    cout << "4. Critical" << endl;
    cout << "Choose a priority: ";

    priorityChoice = getValidInteger(1, 4); 

    if (priorityChoice == 1) { 
        selectedPriority = "Low"; 
    } 

    else if (priorityChoice == 2) {
        selectedPriority = "Medium";
    } 

    else if (priorityChoice == 3) {
        selectedPriority = "High";
    }
    else if (priorityChoice == 4) {
        selectedPriority = "Critical";
    } 

    bool found = false; 
    
    for (int i = 0; i < issues.size(); i++) { 
        const Issue& issue = issues.at(i); 

        if (issue.getPriority() == selectedPriority) { 
            displayIssue(issue);

            found = true;
        } 
    }  

    if (!found) { 
        cout << "\nNo issues found with priority: " << selectedPriority << endl;
    }
}

void IssueManager::createIssue() {
    string title;
    string description;
    string priority; 
    string assignee;

    title = getValidText("Enter issue title: ");
    description = getValidText("Enter description: ");
    priority = getValidPriority(); 
    assignee = getValidText("Enter assignee: ");

    Issue newIssue(nextIssueId, title, description, priority, assignee); 

    issues.push_back(newIssue);

    cout << "\nIssue #" << nextIssueId
         << " created successfully!" << endl;

    nextIssueId++; 

    saveIssues();
} 

void IssueManager::filterIssuesByAssignee() const { 
    string selectedAssignee; 

    selectedAssignee = getValidText("Enter assignee to filter by: "); 

    bool found = false; 

    for (int i = 0; i < issues.size(); i++) { 
        const Issue& issue = issues.at(i); 

        if (toLowerCase(issue.getAssignee()) == toLowerCase(selectedAssignee)) { 
            displayIssue(issue);

            found = true;
        }
    } 

    if (!found) { 
        cout << "\nNo issues found to: " << selectedAssignee << endl;
    }
} 

void IssueManager::sortIssuesByPriority() const { 
    vector<Issue> sortedIssues = issues; 
    
    if (sortedIssues.empty()) { 
        cout << "\nNo issues to sort." << endl; 
        return;
    } 

    sort(sortedIssues.begin(), sortedIssues.end(), [this](const Issue& a, const Issue& b) { 
        
        return getPriorityRank(a.getPriority()) > getPriorityRank(b.getPriority()); 

        } 
    ); 

    cout << "\n==== ISSUES SORTED BY PRIORITY ====" << endl; 

    for (int i = 0; i < sortedIssues.size(); i++) { 
        const Issue& issue = sortedIssues.at(i); 

        displayIssue(issue); 
    } 
} 

void IssueManager::sortIssuesById() const { 
    vector<Issue> sortedIssues = issues; 

    if (sortedIssues.empty()) { 
        cout << "\nNo issues to sort." << endl;
        return; 
    }

    int sortChoice; 

    cout << "\n===== SORT BY ISSUE ID =====" << endl;
    cout << "1. Oldest First" << endl;
    cout << "2. Newest First" << endl;
    cout << "Choose an option: ";

    sortChoice = getValidInteger(1, 2); 

    if (sortChoice == 1) { 
        sort(sortedIssues.begin(), sortedIssues.end(), [](const Issue& a, const Issue& b) { 
            return a.getId() < b.getId();
        }  
    );  
    } 

    else if (sortChoice == 2) { 
        sort(sortedIssues.begin(), sortedIssues.end(), [](const Issue& a, const Issue& b) { 
            return a.getId() > b.getId();
        } 
    );
    } 

    cout << "\n==== ISSUES SORTED BY ID ====" << endl;
    for (int i = 0; i < sortedIssues.size(); i++) { 
        const Issue& issue = sortedIssues.at(i); 

        displayIssue(issue);
    }
}

void IssueManager::sortIssuesByStatus() const { 
    vector<Issue> sortedIssues = issues;
    if (sortedIssues.empty()) { 
        cout << "\nNo issues to sort." << endl; 
        return;
    } 

    sort(sortedIssues.begin(), sortedIssues.end(), [this](const Issue& a, const Issue& b) { 
        return getStatusRank(a.getStatus()) < getStatusRank(b.getStatus());
    } 
); 
    cout << "\n===== ISSUES SORTED BY STATUS =====" << endl;

    for (int i = 0; i < sortedIssues.size(); i++) {
        const Issue& issue = sortedIssues.at(i);

        displayIssue(issue);
    }
}

int IssueManager::getValidInteger() const { 
    int number; 
    while (!(cin >> number)) { 
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>:: max(), '\n'); 

        cout << "Invalid input. Please enter a number: ";
    } 

    return number;
}
int IssueManager::getValidInteger(int min, int max) const { 
    int number; 

    while (!(cin >> number) || number < min || number > max) { 
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        cout << "Invalid input. Please enter a number from " << min << " to " << max << ": ";
    } 

    return number;
} 

string IssueManager:: normalizePriority(string priority) const { 
    transform(priority.begin(), priority.end(), priority.begin(), ::tolower); 

    if(!priority.empty()) { 
        priority[0] = toupper(priority[0]);
    } 

    return priority;
} 

bool IssueManager::isBlank(string text) const { 
    return text.find_first_not_of(" \t\n\r") == string::npos;
} 

string IssueManager::trim(string text) const { 
    size_t start = text.find_first_not_of(" \t\n\r"); 

    if(start == string::npos) { 
        return "";  
    } 

    size_t end = text.find_last_not_of(" \t\n\r"); 

    return text.substr(start, end - start + 1); 
} 

string IssueManager::toLowerCase(string text) const { 
    transform(text.begin(), text.end(), text.begin(), ::tolower); 

    return text;
} 

void IssueManager::displayIssue(const Issue& issue) const { 
    cout << "\nIssue #" << issue.getId() << endl;
    cout << "Title: " << issue.getTitle() << endl;
    cout << "Description: " << issue.getDescription() << endl;
    cout << "Priority: " << issue.getPriority() << endl;
    cout << "Status: " << issue.getStatus() << endl;
    cout << "Assignee: " << issue.getAssignee() << endl; 

    cout << "Created At: " << issue.getCreatedAt() << endl;
} 

int IssueManager::getPriorityRank(string priority) const { 
    if (priority == "Critical") {
        return 4;
    }
    else if (priority == "High") {
        return 3;
    }
    else if (priority == "Medium") {
        return 2;
    }
    else if (priority == "Low") { 
        return 1;
    } 

    return 0;
} 

int IssueManager::getStatusRank(string status) const { 
    if (status == "To Do") {
    return 1;
    }
    else if (status == "In Progress") {
        return 2;
    }
    else if (status == "Done") {
        return 3;
    } 

    return 0;
} 

size_t IssueManager::getIssueCount() const { 
    return issues.size(); 
}

string IssueManager::getValidText(string prompt) const { 
    string text; 

    cout << prompt;
    getline(cin >> ws, text);
    text = trim(text); 
    
    while (isBlank(text)) { 
        cout << "Input cannot be empty. " << prompt; 
        getline(cin, text); 
        text = trim(text); 
    }  

    return text;
} 

string IssueManager::getValidPriority() const { 
    string priority; 

    cout << "Enter priority (Low/Medium/High/Critical): "; 
    getline(cin >> ws, priority);  

    priority = trim(priority); 
    priority = normalizePriority(priority); 

    while (priority != "Low" && priority != "Medium" && priority != "High" && priority != "Critical") { 
        cout << "Invalid priority. Enter Low, Medium, High, or Critical: ";
        getline(cin, priority);

        priority = trim(priority);
        priority = normalizePriority(priority);
    } 

    return priority;
} 

int IssueManager::findIssueIndex(int issueId) const { 
    for (int i = 0; i < issues.size(); i++) { 
        if (issues.at(i).getId() == issueId) { 
            return i; 
        } 
    } 

    return -1;
} 

void IssueManager::saveIssues() const { 
    ofstream file("issues.txt"); 

    if (!file.is_open()) { 
        cout << "Error: Could not save issues." << endl;
    } 
    
    for (int i = 0; i < issues.size(); i++) {
        const Issue& issue = issues.at(i);

        file << issue.getId() << "|"
             << issue.getTitle() << "|"
            << issue.getDescription() << "|"
            << issue.getPriority() << "|"
            << issue.getStatus() << "|"
            << issue.getAssignee() << "|"
            << issue.getCreatedAt() << endl;
    }

    file.close();
} 

void IssueManager::loadIssues() { 
    
    ifstream file("issues.txt"); 

    if (!file.is_open()) { 
        return;
    } 
    
    issues.clear(); 
    int highestId = 0; 

    string line; 

    while(getline(file, line)) { 
        if (line.empty()) { 
            continue;
        }  

        stringstream ss(line); 

        string idString; 
        string title; 
        string description; 
        string priority; 
        string status; 
        string assignee; 
        string createdAt; 

        if (!getline(ss, idString, '|') || 
            !getline(ss, title, '|') ||
            !getline(ss, description, '|') || 
            !getline(ss, priority, '|') || 
            !getline(ss, status, '|') || 
            !getline(ss, assignee, '|') ||
            !getline(ss, createdAt)) { 
                continue;
            } 

        int id; 
        
        try { 
            id = stoi(idString);
        } 

        catch (...) { 
            continue;
        }

        Issue loadedIssue(id, title, description, priority, assignee);
        loadedIssue.setStatus(status);
        loadedIssue.setCreatedAt(createdAt); 

        issues.push_back(loadedIssue); 

        if (id > highestId) { 
            highestId = id;
        }
    } 

    nextIssueId = highestId + 1;

    file.close();
}

