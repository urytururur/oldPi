#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

using namespace std;

class Light
{
private:
    int m_id;
    int m_on;
    string m_name;
    int m_bri;
    int m_hue;
    int m_sat;

public:
    Light(int id, string name, bool on, int bri, int hue, int sat)
    {
        m_id = id;
        m_name = name;
        m_on = on;
        m_bri = bri;
        m_hue = hue;
        m_sat = sat;
    };

    void print()
    {
        cout << "id: " << m_id << ", " << endl;
        cout << "name: " << m_name << ", " << endl;
        cout << "on: " << m_on << ", " << endl;
        cout << "bri: " << m_bri << ", " << endl;
        cout << "hue: " << m_hue << ", " << endl;
        cout << "sat: " << m_sat << '\n' << endl;
    }

//GETTERS AND SETTERS
    int getId()
    {
        return m_id;
    }
    void setId(int val)
    {
        m_id = val;
    }
    string getName()
    {
        return m_name;
    }
    void setName(string val)
    {
        m_name = val;
    }
    bool getOn()
    {
        return m_on;
    }
    void setOn(int val)
    {
        m_on = val;
    }
    int getBri()
    {
        return m_bri;
    }
    void setBri(int val)
    {
        m_bri = val;
    }
    int getHue()
    {
        return m_hue;
    }
    void setHue(int val)
    {
        m_hue = val;
    }
    int getSat()
    {
        return m_sat;
    }
    void setSat(int val)
    {
        m_sat = val;
    }
};

string getJson(ifstream & fileStream, int index);

int main()
{
    /*
    struct Rand
    {
        random_device rnd;

        int getValueBetween(int min, int max)
        {
            uniform_int_distribution<int> intervall(min, max);
            return intervall(rnd);
        }
    };

    Rand rand;
    */

    //string data;


    vector<Light> lights;

    char streamChar;
    ifstream fileStream{"../flask_sqlalchemy_rest/data/data.json"};
    fileStream >> noskipws;
    while(true)
    {
        try
        {
            lights.push_back(Light(stoi(getJson(fileStream, 0)), getJson(fileStream, 0), stoi(getJson(fileStream, 0)), stoi(getJson(fileStream, 0)), stoi(getJson(fileStream, 0)), stoi(getJson(fileStream, 0))));
            cout << "light added..." << endl;
        }
        catch(const std::exception& e)
        {
            cout << "Exeption! Breaking out of light-adding loop.\n" << endl;
            break;
        }
    }
    fileStream.close();


    for(Light & light: lights)
    {
        light.print();
    }

    return 0;
}

string getJson(ifstream & fileStream, int index)
{
    char streamChar{};
    while(fileStream >> streamChar)
    {
        if(streamChar == ':')
        {   
            if(index > 0)
            {
                index--;
                continue;
            }

            string valueAsString{};
            while(fileStream >> streamChar)
            {
                if(streamChar == ',' || streamChar == '}')
                {
                    break;
                }
                valueAsString += streamChar;
            }
            return valueAsString;
        }
    }
    return "END_OF_FILE";
}