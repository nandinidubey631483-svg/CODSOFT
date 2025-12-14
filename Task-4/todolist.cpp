#include <iostream>
#include <vector>
using namespace std;
vector<string> tasks;
vector<bool> completed;
void addTask() {
    string task;
    cout << "Enter task: ";
    cin.ignore();
    getline(cin, task);
    tasks.push_back(task);
    completed.push_back(false);
    cout << "Task added!\n";
}
void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i];
        if (completed[i])
            cout << " [Completed]";
        else
            cout << " [Pending]";
        cout << endl;
    }
}
void markCompleted() {
    int num;
    cout << "Enter task number to mark completed: ";
    cin >> num;
    if (num < 1 || num > tasks.size()) {
        cout << "Invalid task number.\n";
        return;
    }
    completed[num - 1] = true;
    cout << "Task marked as completed!\n";
}
void removeTask() {
    int num;
    cout << "Enter task number to remove: ";
    cin >> num;
    if (num < 1 || num > tasks.size()) {
        cout << "Invalid task number.\n";
        return;
    }
    tasks.erase(tasks.begin() + num - 1);
    completed.erase(completed.begin() + num - 1);
    cout << "Task removed!\n";
}
int main() {
    int Choice;
    do {
        cout <<endl<< "--- TO DO LIST ---"<<endl;
        cout << "1. Add Task"<<endl;
        cout << "2. View Tasks"<<endl;
        cout << "3. Mark Task as Completed"<<endl;
        cout << "4. Remove Task"<<endl;
        cout << "5. Exit"<<endl;
        cout << "Enter choice: ";
        cin >>Choice;

      switch (Choice) {
         case 1: addTask(); break;
         case 2: viewTasks(); break;
         case 3: markCompleted(); break;
         case 4: removeTask(); break;
         case 5: cout << "Exit...\n"; break;
         default: cout << "Invalid choice\n";
        }
    } while (Choice != 5);

    return 0;
}
