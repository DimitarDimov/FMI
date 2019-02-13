#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
int main()
{
    string first_word = "Harry";
    string second_word = "Students";
    string str_to_change = first_word + second_word;
    vector<char> vector_to_change(str_to_change.begin(), str_to_change.end());

    for(int i=0; i < first_word.length();i++)
    {
        vector_to_change.push_back(vector_to_change.front());
        vector_to_change.erase(vector_to_change.begin());

    }

    for (int i = 0; i < vector_to_change.size(); i++)
    {
    cout << vector_to_change[i];
    }
    cout << endl;
    return 0;
}
