#include<iostream>
#include<list>
#include<queue>
#include<vector>

using namespace std;

vector<int> construct(list<queue<int> > &dl)
{
    vector<int> result;
	while (!dl.empty())
    {
		list<queue<int> >::reverse_iterator rev_it = dl.rbegin();
		while(rev_it != dl.rend())
		{
			if (!rev_it->empty())
			{
				result.push_back(rev_it->front());
				rev_it->pop();
				rev_it++;
			}
			else
			{
				if (rev_it != dl.rbegin())
                {
                    dl.pop_back();
					rev_it++;
				}
				else
                {
                    rev_it++;
                }
			}
		}
		if (dl.empty())
        return result;

		list<queue<int> >::iterator it = dl.begin();
		while(it != dl.end())
		{
			if (!it->empty())
            {
				result.push_back(it->front());
				it->pop();
				it++;
			}
			else
			{
				it++;
                dl.pop_front();
			}
		}
		if (dl.empty())
        return result;
	}
}

void print(vector<int> &result)
{
	cout << '(';
	for(int i = 0; i < result.size(); i++)
    {
        cout << result[i];
        if(i != result.size() - 1)
        cout << ",";
	}
	cout << ')' << endl;
}

void insert_in_list(int elements_in_queue, list<queue<int> > &dl )
{
    queue<int> temp;
    list<queue<int> >::iterator it= dl.begin();
    for(int i = 1; i < ((elements_in_queue * 5) + 1); i++)
    {
		if (i % elements_in_queue == 0)
        {
			temp.push(i);
			dl.push_back(temp);
			queue<int> empty;
            swap(temp, empty);
		}
		else
			temp.push(i);
	}
}

int main()
{
    vector<int> result;
    list<queue<int> > dl;

    cout << "3 elements in queue: " <<endl;
    insert_in_list(3,dl);
    result = construct(dl);
    print(result);
    cout<< endl;

    cout << "1 element in queue: " <<endl;
    insert_in_list(1,dl);
    result = construct(dl);
    print(result);
    cout<< endl;

    cout << "4 elements in queue: " <<endl;
    insert_in_list(4,dl);
    result = construct(dl);
    print(result);
    cout << endl;

    cout << "5 elements in queue: " <<endl;
    insert_in_list(4,dl);
    result = construct(dl);
    print(result);
    cout << endl;

    cout << "6 elements in queue: " <<endl;
    insert_in_list(6,dl);
    result = construct(dl);
    print(result);
    cout << endl;

    cout << "8 elements in queue: " <<endl;
    insert_in_list(8,dl);
    result = construct(dl);
    print(result);
    cout << endl;
    return 0;
}
