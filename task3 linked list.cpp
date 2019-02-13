#include<iostream>
using namespace std;

struct Node
{
	int inf;
	Node* next;
};

class LList
{
	Node* start;
	Node* end;
public:
	LList()
	{
		start = NULL;
		end = NULL;
	}
	~LList()
	{
		while (start != end)
		{
			Node* temp = start;
			start = start->next;
			delete temp;
		}
		delete end;
	}

	void toEnd(int x)
	{
		if (empty())
		{
			Node* elem = new Node();
			elem->inf = x;
			elem->next = NULL;
			start = elem;
			end = elem;
		}
		else
		{
			Node* elem = new Node();
			elem->inf = x;
			end->next = elem;
			end = elem;
		}
	}
	void toStart(int x)
	{
		if (empty())
		{
			Node* elem = new Node();
			elem->inf = x;
			elem->next = NULL;
			start = elem;
			end = elem;
		}
		else
		{
			Node* elem = new Node();
			elem->inf = x;
			elem->next = start;
			start = elem;
		}
	}
	bool removeEnd()
	{
		if (!empty())
		{
			Node* elem = start;
			Node* temp = end;
			while (elem->next != end)
			{
				elem = elem->next;
			}
			elem->next = NULL;
			delete temp;
			end = elem;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool removeStart()
	{
		if (!empty())
		{
			Node* temp = start;
			start = start->next;
			delete temp;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool empty()
	{
		return start == NULL;
	}

	Node* find(int x)
	{
		Node* temp = start;
		while (temp->next != NULL)
		{
			if (temp->inf == x)
			{
				return temp;
			}
		}
	}

	bool insertBefore(Node* before, int x)
	{
		if (before == start)
		{
			toStart(x);
		}
		else
		{
			Node* elem = new Node();
			elem->inf = x;
			Node* temp = start;
			while (temp->next != before)
			{
				temp = temp->next;
			}
			elem->next = temp->next;
			temp->next = elem;
			return true;
		}
	}

	bool insertAfter(Node* after, int x)
	{
		if (after == start)
		{
			toEnd(x);
		}
		else
		{
			Node* elem = new Node();
			elem->inf = x;
			elem->next = after->next;
			after->next = elem;
			return true;

		}
	}
	Node* getBox(int x)
	{
		Node* temp = start;
		while (temp != NULL)
		{
			if (temp->inf == x)
			{
				return temp;
			}
			temp = temp->next;
		}
	}

	void print()const
	{
		Node* temp = start;
		while (temp != NULL)
		{
			cout << temp->inf << ' ';
			temp = temp->next;

		}
		cout << endl;
	}

};


int main()
{
	LList l1;
	l1.toEnd(5);
	l1.toEnd(6);
	l1.toStart(8);

	l1.insertBefore(l1.getBox(6), 1);

	l1.print();

	system("pause");
	return 0;
}
