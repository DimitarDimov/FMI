#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

struct Node
{
    string from;
    string dest;
    int land;
    int time;
	int air;
	Node(string _from="", string _dest="", int land= -1, int _time =0, int _air = -1)
	{
		from = _from;
		dest = _dest;
		land = _land;
		time = _time;
		air = _air;
	}
};
class Graph
{
	map<int, list<int>> graph;
	map<int,list<string>> graph2;


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




struct pairs
{
    string from;
    string dest;
    int land;
    int time;
    int air;
};

void read_file()
{

}
int main()
{

    cout << numb;
    vector<pairs> all_cities;
    string aLine;
    bool flag = false;
    string town_name;

    ifstream myFile ("karta1.csv");
    if(myFile.is_open())
    {
        cout <<"successfully opened"<<endl;
        while(!myFile.eof())
        {
        getline(myFile, aLine);
        cout << aLine <<endl;
        while(aLine.size())
        {
            if(!flag)
            {
                string::iterator it = aLine.begin();
                while( it != aLine.end())
                {
                    if(*it == ',')
                    {
                        pairs a;
                        a.from = town_name;
                        all_cities.push_back(a);
                        town_name.clear();
                    }
                    else
                    {
                        town_name.push_back(*it);
                    }
                    it++;
                }
                town_name.clear();
            }

          else
            {
                string::iterator it = aLine.begin();
                vector<pairs>::iterator it1 = all_cities.begin();
                int counter = 0;
                int counter_comma = 0;
                int temp;
                string num;
                bool flag_comma = false;

                while(it != aLine.end())
                {   if(*it >='A' && *it <= 'z')
                        town_name.push_back(*it);
                    else if(*it !='|' &&  *it!=',')
                        num.push_back(*it);
                    if(*it == '|') counter++;
                    if(*it == ',')
                     {
                         counter_comma++;
                         if(counter == 0)
                            it1->dest = town_name;
                        else if(counter > 0)
                        {
                            istringstream(num) >> temp;
                            if(counter == 1)
                            {
                            it1->land = temp;
                            num.clear();
                            temp = 0;
                            }
                            if(counter==2)
                            {
                            it1->time = temp;
                            num.clear();
                            temp =0;
                            }
                            if(counter==2 && counter_comma>=1)
                            {
                            it1->air = temp;
                            it1++;
                            num.clear();
                            temp = 0;
                            counter = 0;
                            counter_comma=0;
                            }
                      }
                     }
                it++;
                town_name.clear();
                flag = true;
           }



    }
        aLine.clear();
  }
        }
    }
    else cout <<"not opened"<<endl;

for(vector<pairs>::iterator it = all_cities.begin(); it != all_cities.end(); it++)
    {
        cout << it->from << endl;
        cout << it->dest << endl;
        cout << it->land << endl;
        cout << it->time << endl;
        cout << it->air << endl;
        cout << endl;
    }


    myFile.close();


    return 0;
}
