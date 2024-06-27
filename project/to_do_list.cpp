#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& taskDesc) {
        tasks.emplace_back(taskDesc);
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks in the list." << std::endl;
            return;
        }
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << (tasks[i].completed ? "[Completed] " : "[Pending] ") << tasks[i].description << std::endl;
        }
    }

    void markTaskAsCompleted(int taskIndex) {
        if (taskIndex < 1 || taskIndex > tasks.size()) {
            std::cout << "Invalid task index." << std::endl;
            return;
        }
        tasks[taskIndex - 1].completed = true;
    }

    void removeTask(int taskIndex) {
        if (taskIndex < 1 || taskIndex > tasks.size()) {
            std::cout << "Invalid task index." << std::endl;
            return;
        }
        tasks.erase(tasks.begin() + taskIndex - 1);
    }
};

void displayMenu() {
    std::cout << "To-Do List Manager" << std::endl;
    std::cout << "1. Add Task" << std::endl;
    std::cout << "2. View Tasks" << std::endl;
    std::cout << "3. Mark Task as Completed" << std::endl;
    std::cout << "4. Remove Task" << std::endl;
    std::cout << "5. Exit" << std::endl;
}

int main() {
    ToDoList todoList;
    int choice;
    std::string taskDesc;
    int taskIndex;

    while (true) {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter task description: ";
            std::cin.ignore();
            std::getline(std::cin, taskDesc);
            todoList.addTask(taskDesc);
            break;
        case 2:
            todoList.viewTasks();
            break;
        case 3:
            std::cout << "Enter task index to mark as completed: ";
            std::cin >> taskIndex;
            todoList.markTaskAsCompleted(taskIndex);
            break;
        case 4:
            std::cout << "Enter task index to remove: ";
            std::cin >> taskIndex;
            todoList.removeTask(taskIndex);
            break;
        case 5:
            return 0;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}
