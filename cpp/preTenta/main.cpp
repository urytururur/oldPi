#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inFileStream{"text.txt"};
    ofstream outFileStream{"textOut.txt"};
    char c;
    while(inFileStream >> c)
    {
        outFileStream << c;
    }

    inFileStream.close();
    outFileStream.close();
}