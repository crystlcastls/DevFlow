#include <iostream> 
#include <vector> 
#include <limits> 
#include "Issue.h" 
#include "IssueManager.h" 

 
using namespace std; 

int main () {  
    IssueManager manager; 
    manager.loadIssues();

    int choice; 
    choice = 0; 

    while (choice != 12) { 

        cout << "===== DEVFLOW MENU =====" << endl;
        cout << "1. Create Issue" << endl;
        cout << "2. View All Issues" << endl;
        cout << "3. Update Issue" << endl;
        cout << "4. Search Issue" << endl;
        cout << "5. Delete Issue" << endl;
        cout << "6. Filter Issues by Status" << endl; 
        cout << "7. Filter Issues by Priority" << endl; 
        cout << "8. Filter Issues by Assignee" << endl; 
        cout << "9. Sort Issues by Priority" << endl; 
        cout << "10. Sort Issues by ID" << endl; 
        cout << "11. Sort Issues by Status" << endl;
        cout << "12. Exit" << endl; 
        cout << "Choose an option: " ;  

        if(!(cin >> choice)) { 
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

            cout << "Invalid input. Please enter a number from 1 to 12." << endl; 

            continue;
        }  
 
        if(choice == 1) { 
            manager.createIssue();   
        } 

        else if(choice == 2) { 
            manager.viewIssues(); 
        } 

        else if(choice == 3) { 
            manager.updateIssue();
        } 

        else if(choice == 4) { 
            manager.searchIssue();
        } 
    
        else if (choice == 5) { 
            manager.deleteIssue();
        }

        else if(choice == 6) { 
            manager.filterIssuesByStatus(); 
        }  

        else if (choice == 7) { 
            manager.filterIssuesByPriority();
        } 

        else if (choice == 8) { 
            manager.filterIssuesByAssignee();
        } 

        else if (choice == 9) { 
            manager.sortIssuesByPriority();
        } 

        else if (choice == 10) { 
            manager.sortIssuesById();
        } 

        else if (choice == 11) { 
            manager.sortIssuesByStatus();
        }

        else if (choice == 12) { 
            cout <<"Exiting Devflow..." << endl;
        } 

        else { 
            cout << "Invalid Option" << endl; 
        } 
    }

    return 0;

}