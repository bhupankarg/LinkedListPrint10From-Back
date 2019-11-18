#include <iostream>
#include <cstdlib>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node(){}
	Node(int data)
	{
		this->data = data;
		this->next = nullptr;
	}
	Node* create_new_node(int);
	void insert_at_end(int);
	void display_list();
	void display_10_from_back(Node*);
};


Node* head = nullptr;

Node* Node :: create_new_node(int data)
{
	return new Node(data);
}

void Node :: insert_at_end(int data)
{
	Node* newNode = create_new_node(data);
	if(head != nullptr)
	{
		Node* temp = head;
		while(true)
		{
			if(temp->next == nullptr)
			{
				temp->next = newNode;
				return;
			}
			temp = temp->next;
		}
	}
	head = newNode;
	cout << data << " is inserted successfully at end." << endl;
}

void Node :: display_list()
{
	if(head != nullptr)
	{
		cout << "The list is..." << endl;
		Node* temp = head;
		while(temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		return;
	}
	cout << "Empty list. Nothing to display." << endl;
}

void Node :: display_10_from_back(Node* head)
{
	static int i = 0;
	if(head == nullptr)
	{
		i = 1;
		return;
	}
	display_10_from_back(head->next);
	if(i == 10)
	{
		cout << "The 10th value from back is: " << head->data << endl;
	}
	i++;
}

int main()
{
	while(true)
	{
		int choice, data;
		Node linkedList;
		cout << endl;
		cout << "1 -> Insert at end" << endl;
		cout << "2 -> Display list" << endl;
		cout << "3 -> Display 10th from end" << endl;
		cout << "0 -> Exit menu" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			cout << "Enter the data: ";
			cin >> data;
			linkedList.insert_at_end(data);
			break;
		case 2:
			linkedList.display_list();
			break;
		case 3:
			linkedList.display_10_from_back(head);
			break;
		case 0:
			exit(0);
		default:
			cout << "Invalid choice. Enter again." << endl;
			break;
		}
	}
	return 0;
}