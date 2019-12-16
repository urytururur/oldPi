#include <iostream>
#include <fstream>
#include <vector>
#include "json/include/nlohmann/json.hpp"
#include "lights.h"
#include <cctype>

using namespace std;
using json = nlohmann::json;

void get(vector<Light> & lights, ifstream & inFileStream);
void put(vector<Light> & lights);

int main()
{
	vector<Light> lights;
	std::ifstream inFileStream("../test0/sharedData/data.json");

	char c;
	while(inFileStream.get(c))
	{
		if(c == ',' || isspace(c))
		{
			continue;
		}
		inFileStream.putback(c);
		get(lights, inFileStream);
	}

	put(lights);

	return 0;
}

void get(vector<Light> & lights, ifstream & inFileStream)
{
	json fileData;
	inFileStream >> fileData;
	cout << fileData << endl;

	Light light;
	for (auto it = fileData.begin(); it != fileData.end(); ++it) {

		auto i = std::distance(fileData.begin(), it);
		
		if(i % 4 == 0)
		{
			light.setOn(it.value());
		}
		else if(i % 4 == 1)
		{
			light.setBri(it.value());
		}
		else if(i % 4 == 2)
		{
			light.setHue(it.value());
		}
		else
		{
			light.setSat(it.value());
			lights.push_back(light);
		}
	}
}

void put(vector<Light> & lights)
{
	for(int i{}; i < lights.size(); i++)
	{
		cout << "on: " << lights.at(i).getOn() << endl;
		cout << "bri: " << lights.at(i).getBri() << endl;
		cout << "hue: " << lights.at(i).getHue() << endl;
		cout << "sat: " << lights.at(i).getSat() << endl << endl;
	}
}