#include <iostream>
#include <string>
using namespace std;

class Criminal//that's the main class.it has attributes like (prison id,person name,guarisan name sch as)
{
public:
    int prison_id;
    string prison_name, guardian_name, guardian_contact, criminal_info;
    Criminal* next_criminal;//pointer to the next criminal record
};

class CriminalList //this class manage  criminal recods in linked list
{
public:
    Criminal* head = nullptr;//actually that is a member variable that use for pointing to the first criminal record

    void addCriminal()//this function use for adding new criminal records and then it insert at the end of the linked list.
    {
        int id;
        string name, guardian, contact, info;//those are atributes 

        cout << "\n\n|1| Enter Prison ID : ";
        cin >> id;
        cout << "|2| Enter Prison Name : ";
        cin.clear();
        cin.ignore();
        getline(cin, name);
        cout << "|3| Enter Guardian's Name : ";
        getline(cin, guardian);
        cout << "|4| Enter Guardian's Contact Number : ";
        cin >> contact;
        cout << "|5| Enter Criminal Information : ";
        cin.ignore();
        getline(cin, info);

        Criminal* new_criminal = new Criminal;//those are the new records pointers.that use for name each new nodes.
        new_criminal->prison_id = id;
        new_criminal->prison_name = name;
        new_criminal->guardian_name = guardian;
        new_criminal->guardian_contact = contact;
        new_criminal->criminal_info = info;

        if (head == nullptr) {
            head = new_criminal;//if head node equal to zero(null) then add new head node and after that again use above menshioned pointers
        }
        else {
            Criminal* ptr = head;
            while (ptr->next_criminal != nullptr) {
                ptr = ptr->next_criminal;
            }
            ptr->next_criminal = new_criminal;
        }
        cout << "\n----------------------------------------------";
        cout << "\n\t ~ NEW CRIMINAL RECORD INSERTED. ~";
        cout << "\n----------------------------------------------";
        cout << "\n\n IF YOU WANT TO GO TO SWITCH------> PRESS <<ENTER>>.";
    }

    void searchCriminal()//it can be use for finding any criminal record using "Criminal ID"
    {
        if (head == nullptr) {
            cout << "\n----------------------------------------------";
            cout << "\n\t ~ CRIMINAL LIST IS EMPTY ~";
            cout << "\n----------------------------------------------";
        }
        else {
            int id, found = 0;
            cout << "\n\n< / > Enter Prison ID For Search: ";
            cin >> id;
            cout << "\n----------------------------------------------";
            Criminal* ptr = head;//point to the head
            while (ptr != nullptr)
            {

                if (id == ptr->prison_id)//that's line point to the criminal ID(id == ptr->prison_id) to the search function.at this moment if we insert criminal id then we can find that criminal record details.
                {
                    cout << "\n|1| Prison ID: " << ptr->prison_id;
                    cout << "\n|2| Prison Name: " << ptr->prison_name;
                    cout << "\n|3| Guardian's Name: " << ptr->guardian_name;
                    cout << "\n|4| Guardian's Contact: " << ptr->guardian_contact;
                    cout << "\n|5| Criminal Information: " << ptr->criminal_info;
                    cout << "\n----------------------------------------------";
                    found++;
                }
                ptr = ptr->next_criminal;
            }
            if (found == 0)//if That can't be found that node then say the statement below.
            {
                cout << "\n\t~ PRISON ID " << id << " NOT FOUND ~";
                cout << "\n----------------------------------------------";
            }
        }
    }

    void countCriminals()//count the number of criminal records using this function
    {
        cout << "\n----------------------------------------------";
        if (head == nullptr)//if head node equal to nullptr
        {
            cout << "\n\t~ CRIMINAL LIST IS EMPTY ~";
            cout << "\n----------------------------------------------";
        }
        else {
            int count = 0;
            Criminal* ptr = head;
            while (ptr != nullptr) {
                count++;
                ptr = ptr->next_criminal;
            }
            cout << "\n\t NUMBER OF CRIMINAL RECORDS : " << count;
            cout << "\n----------------------------------------------";
        }
    }

    void updateCriminal()//it can be use for updating records
    {
        if (head == nullptr) {
            cout << "\n----------------------------------------------";
            cout << "\n\t~ CRIMINAL LIST IS EMPTY ~";
            cout << "\n----------------------------------------------";
        }
        else {
            int id, found = 0;
            cout << "\n\n< / > Enter Prison ID for updating: ";
            cin >> id;
            Criminal* ptr = head;
            while (ptr != nullptr) {
                if (id == ptr->prison_id)//all are the functions use Prison ID for finding,Updating anything about that
                {
                    cout << "\n\n|1| Enter New Prison ID: ";
                    cin >> ptr->prison_id;
                    cout << "|2| Enter New Prison Name: ";
                    cin.ignore();//that function use for clearing remaining character.if we don't use that must be caused lost that statement after we use previous opereation
                    getline(cin, ptr->prison_name);//that function use for reading whole line with prison name above cout mentioned.that's great one because if we don't use that then may be lost our previous part.
                    cout << "|3| Enter New Guardian's Name: ";
                    getline(cin, ptr->guardian_name);//then they display whole statement with spaces
                    cout << "|4| Enter New Guardian's Contact Number: ";
                    cin >> ptr->guardian_contact;
                    cout << "|5| Enter New Criminal Information: ";
                    cin.ignore();
                    getline(cin, ptr->criminal_info);
                    cout << "\n----------------------------------------------";
                    cout << "\n\t ~ RECORD UPDATED SUCESSFULLY ~";
                    cout << "\n----------------------------------------------";
                    cout << "\n\n IF YOU WANT TO GO TO SWITCH------> PRESS <<ENTER>>.";
                    found++;//in the beginning if we cant found node, we want then use this function for go to next record and find we want record
                }
                ptr = ptr->next_criminal;
            }
            if (found == 0) {
                cout << "\n----------------------------------------------------";
                cout << "\n\t~ UPDATE FOR PRISON ID " << id << " NOT FOUND ~";
                cout << "\n----------------------------------------------------";
            }
        }
    }

    void removeCriminal()//that function use for deleting record and if we successfully deleted then display success message
    {
        if (head == nullptr) {
            cout << "\n----------------------------------------------";
            cout << "\n\t~ CRIMINAL LIST IS EMPTY ~";
            cout << "\n----------------------------------------------";
        }
        else {
            int id, found = 0;
            cout << "\n\n< / > Enter Prison ID for Deletion: ";
            cin >> id;

            if (id == head->prison_id) {
                Criminal* ptr = head;
                head = head->next_criminal;
                cout << "\n----------------------------------------------";
                cout << "\n\t ~ RECORD DELETED SUCCESSFULLY ~";///that we talk about above
                cout << "\n----------------------------------------------";
                found++;
                delete ptr;
            }
            else {
                Criminal* pre = head;
                Criminal* ptr = head->next_criminal;
                while (ptr != nullptr) {
                    if (id == ptr->prison_id)//above mensioned
                    {
                        pre->next_criminal = ptr->next_criminal;
                        cout << "\n----------------------------------------------";
                        cout << "\n\t  ~ RECORD DELETED SUCCESSFULLY. ~";
                        cout << "\n----------------------------------------------";
                        found++;
                        delete ptr;
                        break;
                    }
                    pre = ptr;
                    ptr = ptr->next_criminal;
                }
            }
            if (found == 0) {
                cout << "\n----------------------------------------------------";
                cout << "\n\t ~ DELETION FOR PRISON ID " << id << " NOT FOUND ~";
                cout << "\n----------------------------------------------------";
            }
        }
    }

    void showCriminals()//Display all Criminal records 
    {
        cout << "\n----------------------------------------------";
        if (head == nullptr) {
            cout << "\n\t ~ CRIMINAL LIST IS EMPTY ~";
            cout << "\n----------------------------------------------";

        }
        else {
            Criminal* ptr = head;
            while (ptr != nullptr) {
                cout << "\n |1| Prison ID: " << ptr->prison_id;
                cout << "\n |2| Prison Name: " << ptr->prison_name;
                cout << "\n |3| Guardian's Name: " << ptr->guardian_name;
                cout << "\n |4| Guardian's Contact: " << ptr->guardian_contact;
                cout << "\n |5| Criminal Information: " << ptr->criminal_info;
                cout << "\n----------------------------------------------";
                ptr = ptr->next_criminal;//use for go to next node and display next criminal records
            }
        }
    }
};

int main()//user can add,update,remove,display criminal records
{
    CriminalList criminalList;
    int choice;//Declares an integer variable to store the user's menu choice.
    do //if we use case7(exit)then this loop exit but if not then this do-while loop continue untill we choose case 7.
    {
        // Clear the screen (manually simulate clearing) and this is the main user interface it have mentioned statement below.
        cout << "\n\n\n\t\t\t\t<< ===================================== >>";
        cout << "\n\t\t\t\t<< WELCOME TO CRIMINAL MANAGEMENT SYSTEM >>";
        cout << "\n\t\t\t\t<< ===================================== >>";
        cout << "\n\n\t\t\t\t\t\t<< SWITCH >>";
        cout << "\n\n\t\t\t\t\t[1] Add Criminal Record";
        cout << "\n\t\t\t\t\t[2] Search Criminal Record";
        cout << "\n\t\t\t\t\t[3] Count Criminal Records";
        cout << "\n\t\t\t\t\t[4] Update Criminal Record";
        cout << "\n\t\t\t\t\t[5] Remove Criminal Record";
        cout << "\n\t\t\t\t\t[6] Show All Criminal Records";
        cout << "\n\t\t\t\t\t[7] Exit";
        cout << "\n\n< / > Please Enter Your Choice: ";
        cin >> choice;//it can be use for insert input in choice

        switch (choice)//this function is used for switching in above mentioned statements.
        {
        case 1:
            // Clear the screen (manually simulate clearing)

            criminalList.addCriminal();
            break;
        case 2:
            // Clear the screen (manually simulate

            criminalList.searchCriminal();
            break;
        case 3:
            // Clear the screen (manually simulate clearing)

            criminalList.countCriminals();
            break;
        case 4:
            // Clear the screen (manually simulate clearing)

            criminalList.updateCriminal();
            break;
        case 5:
            // Clear the screen (manually simulate clearing)

            criminalList.removeCriminal();
            break;
        case 6:
            // Clear the screen (manually simulate clearing)

            criminalList.showCriminals();
            break;
        case 7:
            exit(0);//in previously we said that if we use case7(exit(0)) function then we can close the loop in while-do function.
        default:
            cout << "\n----------------------------------------------";
            cout << "\n\t<!!! INVALID CHOISE !!!>";
            cout << "\n----------------------------------------------";
            break;
        }
        cin.get();
    } while (true);//above mentioned.

    return 0;
}