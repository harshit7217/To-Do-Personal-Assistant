#include <bits/stdc++.h>
#include <ctime>
using namespace std;

class Task
{
public:
    string taskTitle;
    string taskDescription;
    time_t taskDateTime;
    string taskPriority;
    string taskCategory;
    string taskStatus;
    Task* nextTask;
};

string enterDescription() {
    string description ;
    cin >> description;
    return description;
}

string enterTitle() {
    string title;
    cin >> title;
    return title;
}


string enterStatus() {
    string status;
    cout << "\t+-------------------------------------------+" << endl;
    cout << "\tChoice the status"<< endl;
    cout << "\t1. Pending"<< endl;
    cout << "\t2. In Progress" << endl;
    cout << "\t3. Completed" << endl;
    cout << "\t*. Other" << endl;
    cout << "\t+-------------------------------------------+" << endl;
    cout <<"\t";
    int choice ;
    cin >> choice;
    switch(choice) {
        case 1: return "Pending";
        case 2: return "In Progress";
        case 3: return "Completed";
        default : 
            cout << "\t+-------------------------------------------+" << endl;
            cout << "\tEnter your status" << endl;
            cout << "\t";
            cin >> status;
            cout << "\t+-------------------------------------------+" << endl;
            return status;
    }
    return status;
}

string enterCategory() {
    string category;
    cout << "\t+-------------------------------------------+" << endl;
    cout << "\tChoice the category"<<endl;
    cout << "\t1. Work"<<endl;
    cout << "\t2. Personal"<<endl;
    cout << "\t3. Urgent"<<endl;
    cout << "\t*. Other"<<endl;
    cout << "\t+-------------------------------------------+" << endl;
    cout << "\t";
    int choice;
    cin >> choice;
    switch(choice) {
        case 1: return "Work";
        case 2: return "Personal";
        case 3: return "Urgent";
        default : 
            cout << "\t+-------------------------------------------+" << endl;
            cout << "Enter your task Category" << endl;
            cout << "\t";
            cin >> category;
            cout << "\t+-------------------------------------------+" << endl;
            return category;
    }
    return category;
}


string enterPriority() {
    string priority;
    cout << "\t+-------------------------------------------+" << endl;
    cout << "\tChoice the priority "<<endl;
    cout << "\t1. High"<<endl;
    cout << "\t2. Medium"<<endl;
    cout << "\t3. Low"<<endl;
    cout << "Enter the priority choice (1-3)"<<endl;
    cout << "\t+-------------------------------------------+" << endl;
    cout << "\t";
    int choice;
    cin >> choice;
    switch(choice) {
        case 1: return "High";
        case 2: return "Medium";
        case 3: return "Low";
        default: 
            cout << "\t+-------------------------------------------+" << endl;
            cout <<"\tEnter your priority"<<endl;
            cout <<"\t";
            cin >> priority;
            cout << "\t+-------------------------------------------+" << endl;
            return priority;
    }
    return priority;
}


tm time() {
    tm timeDate = {};
    cout << "\t+-------------------------------------------+" << endl;
    cout << "\tEnter Year : ";
    cin >> timeDate.tm_year;
    cout << "\tEnter Month : ";
    cin >> timeDate.tm_mon;
    cout <<"\tEnter Date : ";
    cin >> timeDate.tm_mday;
    cout << "\tEnter Hour : ";
    cin >> timeDate.tm_hour;
    cout << "\tEnter Minute : ";
    cin >> timeDate.tm_min;
    cout << "\tEnter Second : ";
    cin >> timeDate.tm_sec;
    cout << "\t+-------------------------------------------+" << endl;
    return timeDate;
}

void simpleTaskList()
{
}

void markTask()
{
}

void deletingTask()
{
}

void editingTask()
{
}

Task * insertAtFirst(Task* head) {
    Task * temp = new Task();
    cout << "\t+-------------------------------------------+" << endl;
    cout << "\tEnter the Task details"<<endl;
    cout << "\tTitle : ";
    string title = enterTitle();
    temp->taskTitle = title;
    cout << "\tDescription : ";
    string description = enterDescription();
    temp->taskDescription = description;
    cout << "\tTime and Date : "<<endl;
    tm timeDate = time();
    temp->taskDateTime = mktime(&timeDate);
    cout << "\tPriority : "<<endl;
    string priority = enterPriority();
    temp->taskPriority = priority;
    cout << "\tCategory : "<<endl;
    string category = enterCategory();
    temp->taskPriority = category;
    cout << "\tStatus : "<<endl;
    string status = enterStatus();
    if(head == NULL){
        head = temp;
    }else {
        temp->nextTask = head;
        head = temp;
    }
    return head;
}

void addingTask()
{
    Task * head = NULL;
    while (true)
    {

        cout << "\t+-------------------------------------------+" << endl;
        cout << "\t1. Task Added in starting position " << endl;
        cout << "\t2. Task added in between the tasks" << endl;
        cout << "\t3. Task added in ending position" << endl;
        cout << "\t4. Now, You are not adding task" << endl;
        cout << "\t+-------------------------------------------+" << endl;
        cout << "\t";
        int check;
        cin >> check;
        switch (check)
        {
        case 1:
            head = insertAtFirst(head);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            return;
        default:
            cout << "\t+-------------------------------------------+" << endl;
            cout << "\tYou Choice the wrong option " << endl;
            cout << "\tPlease Choice the right option in the Option list " << endl;
            cout << "\t+-------------------------------------------+" << endl;
        }
    }
}

bool toDoMenu()
{
    cout << "\t+-------------------------------------------+" << endl;
    cout << "\tChoice the task Management Option " << endl;
    cout << "\t1.\tAdding Task" << endl;
    cout << "\t2.\tEditing Task" << endl;
    cout << "\t3.\tDeleting Task" << endl;
    cout << "\t4.\tMark Task as Complete" << endl;
    cout << "\t5.\tSimple Task List View" << endl;
    cout << "\t6.\tExit" << endl;
    cout << "\t+-------------------------------------------+" << endl;
    cout<<"\t";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        addingTask();
        break;
    case 2:
        editingTask();
        break;
    case 3:
        deletingTask();
        break;
    case 4:
        markTask();
        break;
    case 5:
        simpleTaskList();
        break;
    case 6:
        cout << "\t+-------------------------------------------+" << endl;
        cout << "\tYou are exit in the To Do Personal Assistant" << endl;
        cout << "\t+-------------------------------------------+" << endl;
        return true;
    default:
        cout << "\t+-------------------------------------------+" << endl;
        cout << "\tYou Choice the wrong option " << endl;
        cout << "\tPlease Choice the right option in the Option list " << endl;
        cout << "\t+-------------------------------------------+" << endl;
    }
    return false;
}

int main()
{

    while (true)
    {
        bool check = toDoMenu();
        if (check == 1)
        {
            break;
        }
    }

    return 0;
}