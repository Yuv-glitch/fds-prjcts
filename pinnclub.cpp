#include <iostream>
#include <cstring>

using namespace std;

// Structure to represent a club member
struct ClubMember {
    int prn;
    char name[50];
    ClubMember* next;
};

// Class to manage the linked list operations
class ClubManager {
private:
    ClubMember* head; // Head of the linked list

public:
    // Constructor to initialize an empty list
    ClubManager() {
    	head = NULL;
	}

    // Function to add a new member to the club
    void addMember(int prn, const char* name) {
        ClubMember* newMember = new ClubMember;
        newMember->prn = prn;
        strcpy(newMember->name, name);
        newMember->next = head;
        head = newMember;
    }

    // Function to delete a member from the club based on PRN
    void deleteMember(int prn) {
        ClubMember* current = head;
        ClubMember* prev = NULL;

        while (current != NULL && current->prn != prn) {
            prev = current;
            current = current->next;
        }

        if (current == NULL) {
            cout << "Member with PRN " << prn << " not found.\n";
            return;
        }

        if (prev == NULL) {
            head = current->next;
        } else {
            prev->next = current->next;
        }

        delete current;
        cout << "Member with PRN " << prn << " deleted.\n";
    }

    // Function to compute the total number of members in the club
    int getTotalMembers() {
        int count = 0;
        ClubMember* current = head;

        while (current != NULL) {
            count++;
            current = current->next;
        }

        return count;
    }

    // Function to display all members of the club
    void displayMembers() {
        ClubMember* current = head;

        cout << "Club Members:\n";
        while (current != NULL) {
            cout << "PRN: " << current->prn << ", Name: " << current->name << "\n";
            current = current->next;
        }
    }

    // Function to concatenate two linked lists
    void concatenateLists(ClubManager& otherList) {
        ClubMember* current = head;

        if (current == NULL) {
            head = otherList.head;
        } else {
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = otherList.head;
        }

        otherList.head = NULL; // To avoid double deletion of nodes
    }
};

int main() {
    ClubManager clubList1; // First linked list for the first division
    ClubManager clubList2; // Second linked list for the second division

    // Add members to the first division
    clubList1.addMember(123, "John");
    clubList1.addMember(456, "Alice");
    clubList1.addMember(789, "Bob");

    // Add members to the second division
    clubList2.addMember(111, "Eve");
    clubList2.addMember(222, "Charlie");
    clubList2.addMember(333, "David");

    // Display members of the first division
    cout << "Members of Division 1:\n";
    clubList1.displayMembers();

    // Display members of the second division
    cout << "\nMembers of Division 2:\n";
    clubList2.displayMembers();

    // Concatenate the two divisions
    clubList1.concatenateLists(clubList2);

    // Display the concatenated list
    cout << "\nConcatenated List:\n";
    clubList1.displayMembers();

    return 0;
}

