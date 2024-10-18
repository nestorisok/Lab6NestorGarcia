#include <iostream>
#include <unordered_map>
#include <vector>

#include <cctype>

#include <fstream>
#include <string>

using namespace std;

vector<string> myList, myList2; // Values
unordered_map<string, vector<string> > myMap; // <key, values> // Key is amino acids, values is list of values

ifstream myFi("Prog4-data");
string line;

int main(void)
{
	// Input stream
	while (getline(myFi, line))
	{

		myList.push_back(line);

		getline(myFi, line);

		if (myMap.find(line) != myMap.end())
		{
			for (int i = 0; i < myList.size(); i++)
			{
				myMap[line].push_back(myList[i]); // Increments count for vector size
			}
		}
		else
		{
			myMap[line].push_back(myList[0]);
		}
		myList.clear();
	}
	myFi.close();


	for (auto itr = myMap.begin(); itr != myMap.end(); itr++)
	{
		for (const auto& labels: itr->second)
		{
			cout << labels << ", ";

		}
		cout << "\b";
		cout << "\n" << itr->first << endl;
	}

	
	// Output stream
	ofstream outFi("results.txt");
	for (auto itr = myMap.begin(); itr != myMap.end(); itr++)
	{
	
		for (const auto& labels : itr->second)
		{
			outFi << labels << ", ";

		}
		outFi << "\n" << itr->first << endl;
	}
	outFi.close();

	/*
	getline(myFi, line);

	if (myMap.find(line) != myMap.end())
	{
		myMap.insert({ line, myList }); // increment counter
	}
	else
	{
		myMap[line] = atoi(&myList.);	// Create counter
	}
	*/

	return 0;
}