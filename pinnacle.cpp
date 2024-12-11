#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int prn;
    string name;
    Node* next;

    Node(int prn, string name) {
        this->prn = prn;
        this->name = name;
        this->next = nullptr;
    }
};

class PinnacleClub {
private:
    Node* president;
    Node* secretary;

public:
    PinnacleClub() {
        president = nullptr;
        secretary = nullptr;
    }

    // Add President
    void addPresident(int prn, string name) {
        Node* newNode = new Node(prn, name);
        if (president == nullptr) {
            president = newNode;
            secretary = newNode; // If there's no secretary yet, president and secretary are same
        } else {
            newNode->next = president;
            president = newNode;
        }
        cout << "President added: " << name << endl;
    }

    // Add Secretary
    void addSecretary(int prn, string name) {
        Node* newNode = new Node(prn, name);
        if (secretary == nullptr) {
            secretary = newNode;
            president = newNode; // If there's no president yet, president and secretary are same
        } else {
            secretary->next = newNode;
            secretary = newNode;
        }
        cout << "Secretary added: " << name << endl;
    }

    // Add member
    void addMember(int prn, string name) {
        if (president == nullptr || secretary == nullptr) {
            cout << "First add president and secretary." << endl;
            return;
        }
        Node* newNode = new Node(prn, name);
        Node* temp = president;

        // Insert between president and secretary
        while (temp->next != secretary) {
            temp = temp->next;
        }

        newNode->next = secretary;
        temp->next = newNode;
        cout << "Member added: " << name << endl;
    }

    // Delete a member
    void deleteMember(int prn) {
        if (president == nullptr) {
            cout << "No members to delete." << endl;
            return;
        }

        // If the member to delete is the president
        if (president->prn == prn) {
            Node* temp = president;
            president = president->next;
            delete temp;
            cout << "President deleted." << endl;
            return;
        }

        //if prn is of secretary
        if(secretary->prn==prn){
            Node* todlt = secretary;
            Node* temp=president;
            while(temp->next!=secretary){
                temp=temp->next;
            }
            secretary=temp;
            secretary->next=nullptr;
            delete todlt;
            cout << "Secretary deleted." << endl;
            return;
        }

        Node* temp = president;
        while (temp->next != nullptr && temp->next->prn != prn) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Member with PRN " << prn << " not found." << endl;
        } else {
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
            cout << "Member with PRN " << prn << " deleted." << endl;
        }
    }

    // Display members
    void displayMembers() {
        if (president == nullptr) {
            cout << "No members in the club." << endl;
            return;
        }

        Node* temp = president;
        cout << "Members of Pinnacle Club:" << endl;
        while (temp != nullptr) {
            cout << "PRN: " << temp->prn << ", Name: " << temp->name << endl;
            temp = temp->next;
        }
    }

    // Count total members
    int totalMembers() {
        int count = 0;
        Node* temp = president;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Concatenate two linked lists
    void concatenate(PinnacleClub& other) {
        if (president == nullptr) {
            president = other.president;
            secretary = other.secretary;
        } else {
            secretary->next = other.president;
            secretary = other.secretary;
        }
        cout << "Two divisions concatenated." << endl;
    }
};

int main() {
    PinnacleClub division1, division2;

    // Add President, Secretary, and Members in Division 1
    division1.addPresident(1, "Alice");
    division1.addSecretary(3, "Charlie");
    division1.addMember(2, "Bob");
    

    // Display Members
    division1.displayMembers();

    // Total Members
    cout << "Total members: " << division1.totalMembers() << endl;

    // Delete a Member
    division1.deleteMember(3);
    division1.displayMembers();

    // Add Members in Division 2
    division2.addPresident(4, "David");
    division2.addSecretary(6, "Frank");
    division2.addMember(5, "Eva");
    

    // Concatenate Division 1 and Division 2
    division1.concatenate(division2);
    division1.displayMembers();

    return 0;
}
