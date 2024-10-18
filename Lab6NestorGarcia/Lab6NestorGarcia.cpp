#include <iostream>
#include <unordered_map>
#include <vector>

#include <cctype>

#include <fstream>
#include <string>

using namespace std;

vector<string> myValues, myList2; // Values
unordered_map<string, vector<string> > myMap; // <key, values> // Key is amino acids, values is list of values

ifstream myFi("Prog4-data");
string curLine;


int main(void)
{
	// Input stream
	while (!myFi.eof())
	{
		while (getline(myFi, curLine)) // Gets first line file
		{

			myValues.push_back(curLine); // value is added to list 

			getline(myFi, curLine);

			if (myMap.find(curLine) != myMap.end())
			{
				for (int i = 0; i < myValues.size(); i++)
				{
					myMap[curLine].push_back(myValues[i]); // Increments count for vector size
				}
			}
			else
			{
				myMap[curLine].push_back(myValues[0]);
			}
			myValues.clear();
		}
	}
	myFi.close();


	for (auto itr = myMap.begin(); itr != myMap.end(); itr++)
	{
		string cma = "";

		for (const auto& labels: itr->second)
		{
			cout << cma << labels;
			cma = ", ";
		}
		cout << "\n" << itr->first << endl;
	}

	
	// Output stream
	ofstream outFi("results.txt");
	for (auto itr = myMap.begin(); itr != myMap.end(); itr++)
	{
	
		string cma = "";

		for (const auto& labels : itr->second)
		{
			outFi << cma << labels;
			cma = ", ";
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