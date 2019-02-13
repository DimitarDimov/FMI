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
	bool removeMiddle(Node* f1, Node* f2)
	{
	    if(!empty())
        {
            Node* temp = f1->next;
            f1->next = f2;
            delete temp;
        }
        else return false;
	}

	bool empty()
	{
		return start == NULL;
	}

	bool findd(int x)
	{
		Node* temp = start;
		while (temp != NULL)
		{
			if (temp->inf == x)
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
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
	Node* getStart()
	{
	    return start;
	}
Node* reversed(Node* head)
{
    Node* prev = NULL;
    Node* next;
    while(head)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
Node* setStart(Node* s)
{
    start = s;
    return start;
}
void concat(LList &l2)
{

    Node* y = l2.start;
    end->next = y;

}
};


int main()
{
	LList l1;
	l1.toEnd(5);
	l1.toEnd(6);
	l1.toStart(8);
    l1.print(); cout << endl;
	l1.insertBefore(l1.getBox(6), 1);

	l1.print();
   Node* s =l1.getBox(6);
   cout << s->inf;
   cout << endl;
   l1.toEnd(7);
   l1.print(); cout<< endl;
    l1.removeMiddle(l1.getBox(5),l1.getBox(6));
    l1.print();
    cout<< endl;
    cout << l1.findd(8); cout<< endl;
    l1.setStart(l1.reversed(l1.getStart()));
    l1.print();
    LList l2,l3;
    l2.toEnd(1);
    l2.toEnd(2);
    l2.toEnd(3);
    l3.toEnd(4);
    l3.toEnd(5);
    l3.toEnd(6);
    l2.print(); cout<<endl;
    l2.concat(l3);
    l2.print();
	return 0;
}
