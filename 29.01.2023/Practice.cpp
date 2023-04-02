#include <iostream>
#include <string>

using namespace std;

class Tasks {
private:
	struct Task //структура одной задачи
	{
		string title;
		string description;
		int priority; //1 - max; 5 - min
	};
	Task* tasks = nullptr; // указатель на массив из структур Task
	int size = 0;
	void add(Task task) {
		Task* ntasks = new Task[size + 1];
		for (int i = 0; i < size; i++) {
			ntasks[i] = tasks[i];
		}
		ntasks[size++] = task;
		delete[]tasks;
		tasks = ntasks;
	}
	void del(int index) {
		Task* ntasks = new Task[size - 1];
		for (int i = 0; i < index; i++) {
			ntasks[i] = tasks[i];
		}
		for (int i = index+1; i < size; i++) {
			ntasks[i-1] = tasks[i];
		}
		size--;
		delete[]tasks;
		tasks = ntasks;

	}
	string print_one(Task task) {
		string str = "Title: " + task.title + "\nPriority: " + to_string(task.priority) + "\nDescription: " + task.description + "\n";
		return str;
	}
public:
	void print() {
		for (int i = 0; i < size; i++) {
			cout << "#" << i + 1 << endl << print_one(tasks[i]);
		}
	}
	void add_task() {
		string title, description;
		int priority;
		cout << "Title: ";
		cin.ignore();
		getline(cin, title);
		cout << "Description: ";
		getline(cin, description);
		for (;;) {
			cout << "Priority: ";
				cin >> priority;
				if (priority >= 1 && priority <= 5) {
					break;
				}
				cout << "Wrong priority" << endl;
		}
		Task task{ title, description, priority };
		add(task);
	}
	void delete_task() {
		int index;
		cout << "Enter the task number to delete: ";
		cin >> index;
		if (index < 1 || index > size) {
			cout << "Wrong number" << endl;
			return;
		}
		del(index - 1);
		cout << "The task's been deleted" << endl;
	}
	void search_task() {
		string title;
		cin.ignore();
		cout << "Enter the title of the task: ";
		getline(cin, title);
		int tsize = 0;
		for (int i = 0; i < size; i++) {
			if (tasks[i].title == title) {
				tsize++;
			}
		}
		Task* ttasks = new Task[tsize];
		int j = 0;
		for (int i = 0; i < size; i++) {
			if (tasks[i].title == title) {
				ttasks[j++] = tasks[i];
			}
		}
	}
};

int main() {
	cout << "The task programm" << endl;
	Tasks tasks;
	for (;;) {
		cout << "1. Add a task" << endl;
		cout << "2. Delete a task" << endl;
		cout << "3. Print the list of the tasks" << endl;
		cout << "4. Search the task" << endl;
		cout << "5. Exit" << endl;
		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			tasks.add_task();
			break;
		case 2:
			tasks.delete_task();
			break;
		case 3: 
			tasks.print();
			break;
		case 4:
			tasks.search_task();
			break;
		case 5:
			return 0;
		default:
			cout << "Wrong choice" << endl;
		}
	}
	return 0;
}