#include <bits/stdc++.h>
#include <ctime>
#include <string.h>
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
    Task *nextTask;
};

string enterDescription()
{
    string description;
    getline(cin, description);
    return description;
}

string enterTitle()
{
    string title;
    getline(cin, title);
    getline(cin, title);
    return title;
}

string enterStatus()
{
    string status;
    cout << "\t+-------------------------------------------+" << endl;
    cout << "\tChoice the status" << endl;
    cout << "\t1. Pending" << endl;
    cout << "\t2. In Progress" << endl;
    cout << "\t3. Completed" << endl;
    cout << "\t*. Other" << endl;
    cout << "\t+-------------------------------------------+" << endl;
    cout << "\t";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        return "Pending";
    case 2:
        return "In Progress";
    case 3:
        return "Completed";
    default:
        cout << "\t+-------------------------------------------+" << endl;
        cout << "\tEnter your status" << endl;
        cout << "\t";
        getline(cin, status);
        cout << "\t+-------------------------------------------+" << endl;
        return status;
    }
    return status;
}

string enterCategory()
{
    string category;
    cout << "\t+-------------------------------------------+" << endl;
    cout << "\tChoice the category" << endl;
    cout << "\t1. Work" << endl;
    cout << "\t2. Personal" << endl;
    cout << "\t3. Urgent" << endl;
    cout << "\t*. Other" << endl;
    cout << "\t+-------------------------------------------+" << endl;
    cout << "\t";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        return "Work";
    case 2:
        return "Personal";
    case 3:
        return "Urgent";
    default:
        cout << "\t+-------------------------------------------+" << endl;
        cout << "Enter your task Category" << endl;
        cout << "\t";
        getline(cin, category);
        cout << "\t+-------------------------------------------+" << endl;
        return category;
    }
    return category;
}

string enterPriority()
{
    string priority;
    cout << "\t+-------------------------------------------+" << endl;
    cout << "\tChoice the priority " << endl;
    cout << "\t1. High" << endl;
    cout << "\t2. Medium" << endl;
    cout << "\t3. Low" << endl;
    cout << "\tEnter the priority choice (1-3)" << endl;
    cout << "\t+-------------------------------------------+" << endl;
    cout << "\t";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        return "High";
    case 2:
        return "Medium";
    case 3:
        return "Low";
    default:
        cout << "\t+-------------------------------------------+" << endl;
        cout << "\tEnter your priority" << endl;
        cout << "\t";
        getline(cin, priority);
        cout << "\t+-------------------------------------------+" << endl;
        return priority;
    }
    return priority;
}

tm time()
{
    tm timeDate = {};
    cout << "\t+-------------------------------------------+" << endl;
    cout << "\tEnter Year : ";
    cin >> timeDate.tm_year;
    cout << "\tEnter Month : ";
    cin >> timeDate.tm_mon;
    cout << "\tEnter Date : ";
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

Task *insertAtFirst(Task *head)
{
    Task *temp = new Task();
    if (head == NULL)
    {
        cout << "\t+-------------------------------------------+" << endl;
        cout << "\tEnter the Task details" << endl;
        cout << "\tTitle : ";
        string title = enterTitle();
        temp->taskTitle = title;
        cout << "\tDescription : ";
        string description = enterDescription();
        temp->taskDescription = description;
        cout << "\tTime and Date : " << endl;
        tm timeDate = time();
        temp->taskDateTime = mktime(&timeDate);
        cout << "\tPriority : " << endl;
        string priority = enterPriority();
        temp->taskPriority = priority;
        cout << "\tCategory : " << endl;
        string category = enterCategory();
        temp->taskPriority = category;
        cout << "\tStatus : " << endl;
        string status = enterStatus();

        head = temp;
        temp->nextTask = NULL;
    }
    else
    {
        cout << "\t+-------------------------------------------+" << endl;
        cout << "\tEnter the Task details" << endl;
        cout << "\tTitle : ";
        string title = enterTitle();
        temp->taskTitle = title;
        cout << "\tDescription : ";
        string description = enterDescription();
        temp->taskDescription = description;
        cout << "\tTime and Date : " << endl;
        tm timeDate = time();
        temp->taskDateTime = mktime(&timeDate);
        cout << "\tPriority : " << endl;
        string priority = enterPriority();
        temp->taskPriority = priority;
        cout << "\tCategory : " << endl;
        string category = enterCategory();
        temp->taskPriority = category;
        cout << "\tStatus : " << endl;
        string status = enterStatus();

        temp->nextTask = head;
        head = temp;
    }
    return head;
}

Task *goingToEndPosition(Task *head)
{
    if(head == NULL) {
        return head;
    }
    Task *temp = head;
    while (temp->nextTask != NULL)
    {
        temp = temp->nextTask;
    }
    return temp;
}

Task *insertAtEnd(Task *head, Task *temporary)
{
    if (temporary == NULL)
    {
        head = insertAtFirst(temporary);
        return head;
    }
    Task *temp = new Task();
    cout << "\t+-------------------------------------------+" << endl;
    cout << "\tEnter the Task details" << endl;
    cout << "\tTitle : ";
    string title = enterTitle();
    temp->taskTitle = title;
    cout << "\tDescription : ";
    string description = enterDescription();
    temp->taskDescription = description;
    cout << "\tTime and Date : " << endl;
    tm timeDate = time();
    temp->taskDateTime = mktime(&timeDate);
    cout << "\tPriority : " << endl;
    string priority = enterPriority();
    temp->taskPriority = priority;
    cout << "\tCategory : " << endl;
    string category = enterCategory();
    temp->taskPriority = category;
    cout << "\tStatus : " << endl;
    string status = enterStatus();

    temporary->nextTask = temp;
    temp->nextTask = NULL;
    return head;
}

int insertPositionValue()
{
    cout << "\t+-------------------------------------------+" << endl;
    cout << "\tEnter the position value to insert the task : " << endl;
    int value;
    cout << "\t";
    cin >> value;
    return value;
}

Task *checkTaskPosition(Task *head, int value)
{
    int count = 1;
    Task *temp = head;
    while (temp != NULL)
    {
        count++;
        if (count == value)
        {
            return temp;
        }
        temp = temp->nextTask;
    }
    return temp;
}

Task *insertAtPosition(Task *head)
{
        int position = insertPositionValue();
        Task* check = checkTaskPosition(head, position);
        if(position == 1) {
            head = insertAtFirst(head);
            return head;
        }else if(check->nextTask == NULL) {
            head = insertAtEnd(head, check);
            return head;
        }else if (check != NULL)
        {
            Task *temp = new Task();
            cout << "\t+-------------------------------------------+" << endl;
            cout << "\tEnter the Task details" << endl;
            cout << "\tTitle : ";
            string title = enterTitle();
            temp->taskTitle = title;
            cout << "\tDescription : ";
            string description = enterDescription();
            temp->taskDescription = description;
            cout << "\tTime and Date : " << endl;
            tm timeDate = time();
            temp->taskDateTime = mktime(&timeDate);
            cout << "\tPriority : " << endl;
            string priority = enterPriority();
            temp->taskPriority = priority;
            cout << "\tCategory : " << endl;
            string category = enterCategory();
            temp->taskPriority = category;
            cout << "\tStatus : " << endl;
            string status = enterStatus();

            temp->nextTask = check->nextTask;
            check->nextTask = temp;
        }
    return head;
}

Task *addingTask(Task *head)
{
    Task *temp = NULL;
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
            head = insertAtPosition(head);
            break;
        case 3:
            temp = goingToEndPosition(head);
            head = insertAtEnd(head, temp);
            break;
        case 4:
            return head;
        default:
            cout << "\t+-------------------------------------------+" << endl;
            cout << "\tYou Choice the wrong option " << endl;
            cout << "\tPlease Choice the right option in the Option list " << endl;
            cout << "\t+-------------------------------------------+" << endl;
        }
    }
}

void simpleTaskList(Task *head)
{
    Task *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        cout << "\t" << count << ".\t" << temp->taskTitle << endl;
        temp = temp->nextTask;
    }
}

int deletePositionValue()
{
    cout << "\t+-------------------------------------------+" << endl;
    cout << "\tEnter the position value to delete the task : " << endl;
    int value;
    cout << "\t";
    cin >> value;
    return value;
}

Task* deleteFirst(Task * head) {
    head = head->nextTask;
    return head;
}

void deletePosition(Task* temp) {
    temp = temp->nextTask;
}

Task* deletingTask(Task* head) {
    int position = deletePositionValue();
    Task* check = checkTaskPosition(head, position);
    if(position == 1) {
        head = deleteFirst(head);
        return head;
    }else {
        deletePosition(check);
    }
    return head;
}


Task *toDoMenu(Task *head)
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
    cout << "\t";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        head = addingTask(head);
        break;
    case 2:
        // editingTask();
        break;
    case 3:
        head = deletingTask(head);
        break;
    case 4:
        // markTask();
        break;
    case 5:
        simpleTaskList(head);
        break;
    case 6:
        return head;
    default:
        cout << "\t+-------------------------------------------+" << endl;
        cout << "\tYou Choice the wrong option " << endl;
        cout << "\tPlease Choice the right option in the Option list " << endl;
        cout << "\t+-------------------------------------------+" << endl;
    }
    return head;
}

int main()
{
    Task *head = NULL;
    while (true)
    {
        cout << "\t+-------------------------------------------+" << endl;
        cout << "\tChoice the option " << endl;
        cout << "\t1.\tGo to Menu " << endl;
        cout << "\t2.\tExit" << endl;
        cout << "\t+-------------------------------------------+" << endl;
        int check;
        cout << "\t";
        cin >> check;
        if (check != 1)
        {
            break;
        }
        head = toDoMenu(head);
    }
    cout << "\t+-------------------------------------------+" << endl;
    cout << "\tYou are exit in the To Do Personal Assistant " << endl;
    cout << "\t+-------------------------------------------+" << endl;

    return 0;
}