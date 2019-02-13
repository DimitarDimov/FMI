#include<iostream>
#include<algorithm>
#include<map>
#include<list>
#include<stack>
#include<vector>

using namespace std;
struct Node
{
	int info;
	string value;
	Node(int _info = 0, string _value = " ")
	{
		info = _info;
		value = _value;
	}
};
class Graph
{
	map<int, list<int>> graph;
	map < int, list<string>> graph2 ; 


public:
	void add(int _id, int info, string name)
	{
		if (graph.count(_id) == 0)
		{
			list<int> lInfo;
			lInfo.push_back(info);
			graph[_id] = lInfo;
			list<string> lString;
			lString.push_back(name); 
			graph2[_id] = lString;
		}
		else
		{
			graph[_id].push_back(info);
			graph2[_id].push_back(name);
		}
	}
	void print()
	{
		typedef map<int, list<string>>::const_iterator MapIterator;
		for (MapIterator iter = graph2.begin(); iter != graph2.end(); iter++)
		{
			cout << "Key: " << iter->first << endl << "Values:" << endl;
			typedef list<string>::const_iterator ListIterator;
			for (ListIterator list_iter = iter->second.begin(); list_iter != iter->second.end(); list_iter++)
			{
				for (int i = 0; i < (*list_iter).size(); i++)

				{
					cout << (*list_iter)[i];
				}
				cout << endl;
			}
		}
	}

	void DFS(int start)
	{
		stack<int> s;
		vector<int> visited;
			s.push(start);
			while (!s.empty())
			{
				int current = s.top();
				typedef map<int, list<int>>::const_iterator MapIterator;
				for (MapIterator iter = graph.begin(); iter != graph.end(); iter++)
				{
					if (!(find(visited.begin(), visited.end(), (*iter).second) != visited.end()))
					{
					
						visited.push_back(current);
						s.push(current);
						cout << current;
					}
				}
				s.pop();
			}
	}
};



int main()
{
	Graph g;
	
	g.add(1, 2, "rebro 2");
	g.add(1, 5, "rebro 5");

	g.add(2, 1, "rebro 1");
	g.add(2, 3, "rebro 3");
	g.add(2, 5, "rebro 5");
	g.add(2, 6, "rebro 6");

	g.add(3, 2, "rebro 2");
	g.add(3, 4, "rebro 4");

	g.add(4, 3, "rebro 3");
	g.add(4, 5, "rebro 5");
	g.add(4, 6, "rebro 6");

	g.add(5, 1, "rebro 1");
	g.add(5, 2, "rebro 2");
	g.add(5, 4, "rebro 4");

	g.add(6, 2, "rebro 2");
	g.add(6, 4, "rebro 4");

	//g.print();
	int first = 1;
	g.DFS(first);
	system("pause");
	return 0;
}