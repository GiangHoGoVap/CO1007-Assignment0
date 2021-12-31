#include <iostream>
#include <fstream>
using namespace std;

ifstream ifs;

struct node
{
  int data;
  node *next;
};

node *createLinkList(int n){
	//TODO
	
	node *head = new node;
	node *temp;
	node *current = new node;
	
	cin >> head->data;
	head->next = NULL;
	n--;
	
	current = head;
	
	while(n > 0)
	{
		temp = new node;
		cin >> temp->data;
		temp->next = NULL;
		current->next = temp;
		n--;
		current = current->next;
	}
	
	current->next = NULL;
	
	return head;
	
}

node *insertNode(node *head, node *newNode, int position)
{
	//TODO
	
	node *current = new node;
	
	current = head;
	
	int i = 1;
	
	if (position < 1) return head;
	
	if (position == 1)
	{
		newNode->next = head;
		head = newNode;
		return head;
	}
	else
	{

		while (i < position-1){
			if (current->next == NULL) break;
			current = current->next;
			i++;
		}
		
		if (current->next == NULL){
			current->next = newNode;
			newNode->next = NULL;
		}
		else{
			newNode->next = current->next;
			current->next = newNode;
		}
		
	}
	return head;
}

void print(node *head)
{
  while (head != NULL)
  {
    cout << head->data << endl;
    head = head->next;
  }
}

int main(int narg, char **argv)
{
  //ifs.open(argv[1]);

  int n = 0;
  cin >> n;
  if (n > 0)
  {
    node *head = createLinkList(n);

    node *newNode = new node();
    cout << "-------------\n";
    cin >> newNode->data;
    int position = 0;
    cin >> position;
    head = insertNode(head, newNode, position);
	cout << "----------\n";
    print(head);
  }
  else
  {
    cout << "Invalid n" << endl;
  }

  //ifs.close();
  return 0;
}
