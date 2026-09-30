#ifndef ISSUE_MANAGER_H 
#define ISSUE_MANAGER_H 

#include <vector> 
#include "Issue.h" 

using namespace std; 

class IssueManager {   
    private: 
        vector<Issue> issues; 
        int nextIssueId; 

        int getValidInteger() const;
        int getValidInteger(int min, int max) const; 
        string normalizePriority(string priority) const; 
        bool isBlank(string text) const; 
        string trim(string text) const; 
        string toLowerCase(string text) const; 
        void displayIssue(const Issue& issue) const; 
        int getPriorityRank(string priority) const; 
        int getStatusRank(string status) const; 
        size_t getIssueCount() const; 
        string getValidText(string prompt) const; 
        string getValidPriority() const; 
        int findIssueIndex(int issueId) const; 
    

    public: 
        IssueManager(); 

        void createIssue(); 
        int createIssue(const string& title, const string& description, const string& priority, const string& assignee); 
        void viewIssues() const; 
        void updateIssue(); 
        void searchIssue() const;
        void deleteIssue(); 
        void filterIssuesByStatus() const; 
        void filterIssuesByPriority() const; 
        void filterIssuesByAssignee() const; 
        void sortIssuesByPriority() const; 
        void sortIssuesById() const; 
        void sortIssuesByStatus() const; 

        void saveIssues() const; 
        void loadIssues();

};

#endif