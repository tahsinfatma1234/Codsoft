#include <iostream>
#include <vector>

using namespace std;

#include <string>

struct Task {
    string description;
    bool completed;
};

void addTask(vector<Task>& tasks, const string& description) {
    Task newTask = {description, false};
    tasks.push_back(newTask);
}

void viewTasks(const vector<Task>& tasks) {
    cout << "Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". ";
        if (tasks[i].completed) {
            cout << "[Completed] ";
        }
        cout << tasks[i].description << endl;
    }
}

void markTaskAsCompleted(vector<Task>& tasks, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < tasks.size()) {
        tasks[taskIndex].completed = true;
    }
}

void removeTask(vector<Task>& tasks, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < tasks.size()) {
        tasks.erase(tasks.begin() + taskIndex);
    }
}

int main() {
    vector<Task> tasks;

    while (true) {
        cout << "Options:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string description;
            cout << "Enter the task description: ";
            cin.ignore();
            getline(cin, description);
            addTask(tasks, description);
        } else if (choice == 2) {
            viewTasks(tasks);
        } else if (choice == 3) {
            int taskIndex;
            cout << "Enter the task number to mark as completed: ";
            cin >> taskIndex;
            markTaskAsCompleted(tasks, taskIndex - 1);
        } else if (choice == 4) {
            int taskIndex;
            cout << "Enter the task number to remove: ";
            cin >> taskIndex;
            removeTask(tasks, taskIndex - 1);
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice!,Please try again.\n";
        }
    }

    return 0;
}