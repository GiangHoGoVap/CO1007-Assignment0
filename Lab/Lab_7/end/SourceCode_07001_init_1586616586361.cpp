#include <iostream>
#include <fstream>
using namespace std;

ifstream ifs;

struct node
{
  int data;
  node *next;
};

node *createLinkList(int n)
{
	//TODO
	node *head = new node;
	node *temp;
	
	ifs >> head->data;
	head->next = NULL;
	n--;
	
	while(n > 0)
	{
		temp = new node;
		ifs >> temp->data;
		temp->next = head;
		head = temp;
		n--;
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
  ifs.open(argv[1]);

  int n = 0;
  cin >> n;
  if (n > 0)
  {
    node *head = createLinkList(n);
    print(head);
  }
  else
  {
    cout << "Invalid n" << endl;
  }

  ifs.close();
  return 0;
}
