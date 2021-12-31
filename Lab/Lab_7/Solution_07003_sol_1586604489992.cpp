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
  node *head = new node();
  ifs >> head->data;
  node *tail = head;
  for (int i = 1; i < n; i++)
  {
    node *newtail = new node();
    ifs >> newtail->data;
    tail->next = newtail;
    tail = newtail;
  }
  return head;
}

node *insertNode(node *head, node *newNode, int position)
{
  if (position <= 0)
    return head;
  if (position == 1)
  {
    newNode->next = head;
    return newNode;
  }

  node *runNode = head;
  for (int i = 2; i < position; i++)
  {
    if (runNode->next == nullptr)
      break;
    runNode = runNode->next;
  }
  newNode->next = runNode->next;
  runNode->next = newNode;
  return head;
}

void print(node *head)
{
  while (head != nullptr)
  {
    cout << head->data << endl;
    head = head->next;
  }
}

int main(int narg, char **argv)
{
  ifs.open(argv[1]);

  int n = 0;
  ifs >> n;
  if (n > 0)
  {
    node *head = createLinkList(n);

    node *newNode = new node();
    ifs >> newNode->data;
    int position = 0;
    ifs >> position;
    head = insertNode(head, newNode, position);

    print(head);
  }
  else
  {
    cout << "Invalid n" << endl;
  }

  ifs.close();
  return 0;
}
