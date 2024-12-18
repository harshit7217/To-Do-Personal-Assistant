#include <bits/stdc++.h>
#include <ctime>
#include <string.h>
using namespace std;

class Task
{
public:
    string taskTitle;
    string taskDescription;
    string taskDateTime;
    string taskPriority;
    string taskCategory;
    string taskStatus;
    Task *nextTask;
};

string enterDescription()
{
    string description;
    cout << "\t";
    getline(cin, description);
    return description;
}

string enterTitle()
{
    string title;
    cout << "\t";
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
        cout << "\tEnter your task Category" << endl;
        cout << "\t";
        getline(cin, category);
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
        getline(cin, priority);
        cout << "\t+-------------------------------------------+" << endl;
        return priority;
    }
    return priority;
}

string getCurrentDateTime() {
        auto now = std::chrono::system_clock::now();
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
        return std::ctime(&currentTime); // Convert to string
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
        cout << "\tPriority : " << endl;
        string priority = enterPriority();
        temp->taskPriority = priority;
        cout << "\tCategory : " << endl;
        string category = enterCategory();
        temp->taskCategory = category;
        cout << "\tStatus : " << endl;
        string status = enterStatus();
        temp->taskStatus = status;
        string date = getCurrentDateTime();
        temp->taskDateTime = date;

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
        cout << "\tPriority : " << endl;
        string priority = enterPriority();
        temp->taskPriority = priority;
        cout << "\tCategory : " << endl;
        string category = enterCategory();
        temp->taskCategory = category;
        cout << "\tStatus : " << endl;
        string status = enterStatus();
        temp->taskStatus = status;
        string date = getCurrentDateTime();
        temp->taskDateTime = date;

        temp->nextTask = head;
        head = temp;
    }
    return head;
}

Task *goingToEndPosition(Task *head)
{
    if (head == NULL)
    {
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
    cout << "\tPriority : " << endl;
    string priority = enterPriority();
    temp->taskPriority = priority;
    cout << "\tCategory : " << endl;
    string category = enterCategory();
    temp->taskCategory = category;
    cout << "\tStatus : " << endl;
    string status = enterStatus();
    temp->taskStatus = status;
    string date = getCurrentDateTime();
    temp->taskDateTime = date;

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
    Task *check = checkTaskPosition(head, position);
    if (position == 1)
    {
        head = insertAtFirst(head);
        return head;
    }
    else if (check->nextTask == NULL)
    {
        head = insertAtEnd(head, check);
        return head;
    }
    else if (check != NULL)
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
        cout << "\tPriority : " << endl;
        string priority = enterPriority();
        temp->taskPriority = priority;
        cout << "\tCategory : " << endl;
        string category = enterCategory();
        temp->taskCategory = category;
        cout << "\tStatus : " << endl;
        string status = enterStatus();
        temp->taskStatus = status;
        string date = getCurrentDateTime();
        temp->taskDateTime = date;

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
            cout << "\t+-------------------------------------------+" << endl;
            cout << "\tCongurtulations, Your task inserted successfully" << endl;
            cout << "\t+-------------------------------------------+" << endl;
            break;
        case 2:
            head = insertAtPosition(head);
            cout << "\t+-------------------------------------------+" << endl;
            cout << "\tCongurtulations, Your task inserted successfully" << endl;
            cout << "\t+-------------------------------------------+" << endl;
            break;
        case 3:
            temp = goingToEndPosition(head);
            head = insertAtEnd(head, temp);
            cout << "\t+-------------------------------------------+" << endl;
            cout << "\tCongurtulations, Your task inserted successfully" << endl;
            cout << "\t+-------------------------------------------+" << endl;
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

bool fullDetials(Task *head)
{
    string title;
    cout << "\t";
    getline(cin, title);
    getline(cin, title);
    Task *temp = head;
    while (temp != NULL)
    {
        if (temp->taskTitle == title)
        {
            cout << "\t+-------------------------------------------+" << endl;
            cout << "\t\t" << "Title : " << temp->taskTitle << endl;
            cout << "\t\t" << "Description : " << temp->taskDescription << endl;
            cout << "\t\t" << "Date & Time : " << temp->taskDateTime << endl;
            cout << "\t\t" << "Priority : " << temp->taskPriority << endl;
            cout << "\t\t" << "Category : " << temp->taskCategory << endl;
            cout << "\t\t" << "Status : " << temp->taskStatus << endl;
            cout << "\t+-------------------------------------------+" << endl;
            return false;
        }
        temp = temp->nextTask;
    }
    return true;
}

void simpleTaskList(Task *head)
{
    Task *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        cout << "\t" << count << ".\n\t\t" << "Title : " << temp->taskTitle << endl;
        temp = temp->nextTask;
    }
    cout << "\t+-------------------------------------------+" << endl;
    cout << "\tCongurtulations, You view the task successfully" << endl;
    cout << "\t+-------------------------------------------+" << endl;
    cout << endl;
    cout << "\t+-------------------------------------------+" << endl;
    cout << "\tIf you want to view the full details of particular task  : " << endl;
    cout << "\t+-------------------------------------------+" << endl;
    cout << endl;
    int checking;
    cout << "\tChoice the option :-" << endl;
    cout << "\t1. To see the task." << endl;
    cout << "\t2. Not see the task" << endl;
    cout << "\t";
    cin >> checking;
    while (checking == 1)
    {
        cout << "\t+-------------------------------------------+" << endl;
        cout << "\tEnter the task title" << endl;
        cout << "\t+-------------------------------------------+" << endl;
        bool check = fullDetials(head);
        if (check == 0)
        {
            cout << "\t+-------------------------------------------+" << endl;
            cout << "\tIf you want to view the another task details : " << endl;
            cout << "\tChoose option" << endl;
            cout << "\t1. Again view the task." << endl;
            cout << "\t2. Exit" << endl;
            cout << "\t+-------------------------------------------+" << endl;
            cout << "\t";
            cin >> checking;
        }
        else
        {
            cout << "\t+-------------------------------------------+" << endl;
            cout << "\tYou choice the wrong task i.e. not in the task list : " << endl;
            cout << "\tChoose option" << endl;
            cout << "\t1. Again enter the task." << endl;
            cout << "\t2. Exit" << endl;
            cout << "\t+-------------------------------------------+" << endl;
            cout << "\t";
            cin >> checking;
        }
    }
}

string deletePositionValue()
{
    cout << "\t+-------------------------------------------+" << endl;
    cout << "\tEnter the task title to delete the task : " << endl;
    cout << "\t+-------------------------------------------+" << endl;
    string value;
    cout << "\t";
    getline(cin, value);
    getline(cin, value);
    return value;
}
Task *deleteFirst(Task *head)
{
    head = head->nextTask;
    return head;
}

void deleting(Task *previous)
{
    previous->nextTask = previous->nextTask->nextTask;
}

void deletingEnd(Task *previous)
{
    previous->nextTask = NULL;
}

Task *deletingTask(Task *head)
{
    string title = deletePositionValue();
    Task *temp = head, *previous;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        if (temp->taskTitle == title)
        {
            if (count == 1)
            {
                head = deleteFirst(head);
                return head;
            }
            else if (temp->nextTask == NULL)
            {
                deletingEnd(previous);
                return head;
            }
            else
            {
                deleting(previous);
                return head;
            }
        }
        previous = temp;
        temp = temp->nextTask;
    }
}

void markTask(Task *head)
{
    string task;
    cout << "\t+-------------------------------------------+" << endl;
    cout << "\tEnter the task title to mark as completed :-" << endl;
    cout << "\t+-------------------------------------------+" << endl;
    cout << "\t";
    getline(cin, task);
    getline(cin, task);
    Task *temp = head;
    while (temp != NULL)
    {
        if (temp->taskTitle == task)
        {
            temp->taskStatus = "Completed";
            return;
        }
        temp = temp->nextTask;
    }
    cout << "\t+-------------------------------------------+" << endl;
    cout << "\tYour task not find it" << endl;
    cout << "\tChoice the option :-" << endl;
    cout << "\t1. Try Again" << endl;
    cout << "\t2. Exit" << endl;
    cout << "\t+-------------------------------------------+" << endl;
    int check;
    cout << "\t";
    cin >> check;
    if (check == 1)
    {
        markTask(head);
    }
    else if (check == 2)
    {
        return;
    }
    else
    {
        cout << "\t+-------------------------------------------+" << endl;
        cout << "\tYou choice the wrong option" << endl;
        cout << "\tNow, you again go to the mark option" << endl;
        cout << "\t+-------------------------------------------+" << endl;
        markTask(head);
    }
}

string editEnterDescription()
{
    string description;
    cout << "\t";
    getline(cin, description);
    getline(cin, description);
    return description;
}

void edit(Task *head)
{
    cout << "\t+-------------------------------------------+" << endl;
    cout << "\tWhat do you want to edit" << endl;
    cout << "\t\t1. Title" << endl;
    cout << "\t\t2. Description" << endl;
    cout << "\t\t3. Date and Time" << endl;
    cout << "\t\t4. Priority" << endl;
    cout << "\t\t5. Category" << endl;
    cout << "\t\t6. Status" << endl;
    cout << "\t+-------------------------------------------+" << endl;
    int check;
    cout << "\t";
    cin >> check;
    string title, description, priority, category, status;
    string dateTime;
    switch(check)
    {
    case 1:
        cout << "\t+-------------------------------------------+" << endl;
        cout << "\tEnter your title" << endl;
        cout << "\t+-------------------------------------------+" << endl;
        cout << "\t";
        title = enterTitle();
        head->taskTitle = title;
        cout << "\t+-------------------------------------------+" << endl;
        cout << "\tYour Title successfully edited" << endl;
        cout << "\t+-------------------------------------------+" << endl;
        return;
    case 2:
        cout << "\t+-------------------------------------------+" << endl;
        cout << "\tEnter your Description" << endl;
        cout << "\t+-------------------------------------------+" << endl;
        cout << "\t";
        description = editEnterDescription();
        head->taskDescription = description;
        cout << "\t+-------------------------------------------+" << endl;
        cout << "\tYour Description successfully edited" << endl;
        cout << "\t+-------------------------------------------+" << endl;
        return;
    case 3: 
        cout << "\t+-------------------------------------------+" << endl;
        cout << "\tYour Date and Time" << endl;
        cout << "\t+-------------------------------------------+" << endl;
        cout << "\t";
        dateTime = getCurrentDateTime();
        head->taskDateTime = dateTime;
        cout << "\t+-------------------------------------------+" << endl;
        cout << "\tYour Date and Time successfully edited" << endl;
        cout << "\t+-------------------------------------------+" << endl;
        return;
    case 4: 
        priority = enterPriority();
        head->taskPriority = priority;
        cout << "\t+-------------------------------------------+" << endl;
        cout << "\tYour Priority successfully edited" << endl;
        cout << "\t+-------------------------------------------+" << endl;
        return;
    case 5:
        category = enterCategory();
        head->taskCategory = category;
        cout << "\t+-------------------------------------------+" << endl;
        cout << "\tYour Category successfully edited" << endl;
        cout << "\t+-------------------------------------------+" << endl;
        return;
    case 6:
        status = enterStatus();
        head->taskStatus = status;
        cout << "\t+-------------------------------------------+" << endl;
        cout << "\tYour Status successfully edited" << endl;
        cout << "\t+-------------------------------------------+" << endl;
        return;
    default : 
        cout << "\t+-------------------------------------------+" << endl;
        cout << "\tYou Choose the wrong option" << endl;
        cout << "\t+-------------------------------------------+" << endl;
        return;
    }
}

void editingTask(Task *head)
{
    string task;
    cout << "\t+-------------------------------------------+" << endl;
    cout << "\tEnter the task title to editing a task :-" << endl;
    cout << "\t";
    getline(cin, task);
    getline(cin, task);
    Task *temp = head;
    while (temp != NULL)
    {
        if (temp->taskTitle == task)
        {
            edit(temp);
        }
        temp = temp->nextTask;
    }
    cout << "\t+-------------------------------------------+" << endl;
    cout << "\tYou write the wrong title" << endl;
    cout << "\t+-------------------------------------------+" << endl;
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
    cout << "\t+-------------------------------------------+" << endl;
    switch (choice)
    {
    case 1:
        head = addingTask(head);
        break;
    case 2:
        editingTask(head);
        break;
    case 3:
        head = deletingTask(head);
        cout << "\t+-------------------------------------------+" << endl;
        cout << "\tCongurtulations, Your task deleted successfully" << endl;
        cout << "\t+-------------------------------------------+" << endl;
        break;
    case 4:
        markTask(head);
        cout << "\t+-------------------------------------------+" << endl;
        cout << "\tCongurtulations, Your task mark as completed successfully" << endl;
        cout << "\t+-------------------------------------------+" << endl;
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