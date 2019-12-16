
#include <iostream>
#include "json/include/nlohmann/json.hpp"
#include <fstream>
#include <string>
#include <iterator>
#include <vector>

using namespace std;
using json = nlohmann::json;

void getJsonFromFile(json& jsonObject, string fileUrl);
void fillWithJson(vector<json>& lights, json const & data);

int main()
{
	json data;
	json lastData;
	vector<json> lights;

	getJsonFromFile(data, "../test0/sharedData/data.json");
	fillWithJson(lights, data);

	cout << lights.at(1);

	/*
	for(json element: lights)
	{
		cout << element << endl;
	}
	*/

	return 0;
}

void getJsonFromFile(json & jsonObject, string fileUrl)
{
	std::ifstream i(fileUrl);
	i >> jsonObject;
}

void fillWithJson(vector<json> & lights, json const & data)
{
	for (auto it = data.begin(); it != data.end(); ++it) {

		// if the current index is needed:
		auto i = std::distance(data.begin(), it);

		// access element as *it
		lights.push_back(*it);

		// any code including continue, break, return
		// ...
	}
}