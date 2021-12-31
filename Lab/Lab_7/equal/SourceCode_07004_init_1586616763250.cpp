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
	node *current = new node;
	
	ifs >> head->data;
	head->next = NULL;
	n--;
	
	current = head;
	
	while(n > 0)
	{
		temp = new node;
		ifs >> temp->data;
		temp->next = NULL;
		current->next = temp;
		n--;
		current = current->next;
	}
	
	current->next = NULL;
	
	return head;
}

bool isEqual(node *head1, node *head2)
{
	//TODO
	node *current1 = head1;
	node *current2 = head2;
	while (current1 != NULL && current2 != NULL){
		if (current1->data != current2->data) return false;
		current1 = current1->next;
		current2 = current2->next;
	}
	if (current1 == NULL && current2 == NULL) return true;
	else return false;
}

int main(int narg, char **argv)
{
  //ifs.open(argv[1]);

  int n = 0;
  cin >> n;
  if (n <= 0)
  {
    cout << "Invalid n" << endl;
    return 0;
  }
  node *head1 = createLinkList(n);

  int m = 0;
  cin >> m;
  if (m <= 0)
  {
    cout << "Invalid m" << endl;
    return 0;
  }
  node *head2 = createLinkList(m);

  cout << isEqual(head1, head2) << endl;

  //ifs.close();
  return 0;
}
