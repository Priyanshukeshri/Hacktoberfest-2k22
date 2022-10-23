/* 
Submitted by: Sneha Jaiswal
GitHub Link: https://github.com/Sneha-jais
Problem Statement:
You have been given a singly linked list of integers along with an integer 'N'. Write a function to append the last 'N' nodes towards the front of the singly linked list and returns the new head to the list.
Input format :The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
The first line of each test case or query contains the elements of the singly linked list separated by a single space.
The second line contains the integer value 'N'. It denotes the number of nodes to be moved from last to the front of the singly linked list.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.

Output format :
For each test case/query, print the resulting singly linked list of integers in a row, separated by a single space.
Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
0 <= N < M
Time Limit: 1sec

Where 'M' is the size of the singly linked list.

Sample Input 1 :
2
1 2 3 4 5 -1
3
10 20 30 40 50 60 -1
5

Sample Output 1 :
3 4 5 1 2
20 30 40 50 60 10

*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *takeInput()
{

    int data;
    cin >> data;

    Node *head = NULL;
    Node *tail = NULL;

    while (data != -1)
    {

        Node *newNode = new Node(data);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

int len_LL(Node *head, int count = 0)
{
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

Node *append_last(Node *head, int N, int len)
{

    int i = 1;
    Node *curr = head;

    while (i < (len - N))
    {
        curr = curr->next;
        i++;
    }
    Node *head2 = curr->next;
    curr->next = NULL;
    Node *tail = head2;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = head;

    return head2;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeInput();
        int N;
        cin >> N;
        int length = len_LL(head);
        // cout<<length;
        head = append_last(head, N, length);
        print(head);
    }

    return 0;
}
