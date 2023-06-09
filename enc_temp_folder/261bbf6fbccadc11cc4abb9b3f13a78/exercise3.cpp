#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};
class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** pangestu, Node** bimo);
	bool listEmpty();
	bool delNode();
	void traverse();
};
void CircularLinkedList::addNode() { //write your answer here
	Node* newNode = new Node();
	cout << "masukan roll number";
	cin >> newNode->rollNumber;
	cout << "masukan nama";
	cin.ignore();
	getline(cin, newNode->name);

	if (LAST == NULL)
		newNode = LAST->next;
	else {
		newNode->next = LAST->next;
		LAST->next = newNode;
	}

}
bool CircularLinkedList::search(int rollno, Node** pangestu, Node** bimo) {
	*pangestu = LAST->next;
	*bimo = LAST->next;
	while (*bimo != LAST) {
		if (rollno == (*bimo)->rollNumber) {
			return true;
		}
		*pangestu = *bimo;
		*bimo = (*bimo)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}
bool CircularLinkedList::delNode() { //write your answer here
	int rollno;
	cout << "masukan nomor yang ingin dihapus";
	cin >> rollno;

	Node* bimo = NULL;
	Node* pangestu = NULL;

	if (search(rollno, &pangestu, &bimo) == false)
		return false;
}
void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}
int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
				obj.addNode();
				break;
			}
			case '2': {
				obj.delNode();
				break;
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}
