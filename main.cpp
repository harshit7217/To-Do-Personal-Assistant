#include <bits/stdc++.h>
#include <ctime>
using namespace std;

class Task
{
public:
    string taskTitle;
    string taskDescription;
    tm taskDateTime = {};
    string taskPriority;
    tm taskReminder = {};
    string taskCategory;
    string taskStatus;
    Task* nextTask;
};

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
    Task * temp = head;
    cout << "\t+-------------------------------------------+" << endl;
    cout << "\tEnter the Task details"<<endl;
    cout << "\tTitle : ";
    string title;
    cin  >> title;
    temp->taskTitle = title;
    cout << "\t Description : ";
    string description;
    cin >> description;
    temp->taskDescription = description;
    cout << "\tTime and Date ";
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