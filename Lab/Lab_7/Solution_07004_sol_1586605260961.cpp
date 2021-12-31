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
    node *newTail = new node();
    ifs >> newTail->data;
    tail->next = newTail;
    tail = newTail;
  }
  return head;
}

bool isEqual(node *head1, node *head2)
{
  node *runNode1 = head1;
  node *runNode2 = head2;
  while (runNode1 != nullptr)
  {
    if (runNode2 == nullptr || runNode1->data != runNode2->data)
    {
      return false;
    }
    runNode1 = runNode1->next;
    runNode2 = runNode2->next;
  }
  if (runNode2 != nullptr)
  {
    return false;
  }
  return true;
}

int main(int narg, char **argv)
{
  ifs.open(argv[1]);

  int n = 0;
  ifs >> n;
  if (n <= 0)
  {
    cout << "Invalid n" << endl;
    return 0;
  }
  node *head1 = createLinkList(n);

  int m = 0;
  ifs >> m;
  if (m <= 0)
  {
    cout << "Invalid m" << endl;
    return 0;
  }
  node *head2 = createLinkList(m);

  cout << isEqual(head1, head2) << endl;

  ifs.close();
  return 0;
}
