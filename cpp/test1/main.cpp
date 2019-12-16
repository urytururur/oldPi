#include "date_handling.h"
#include <limits>
#include <vector>

using namespace std;

bool checkIfAlreadyBooked(vector<Date_type> const & dates, Date_type const & date);

int main()
{
    vector<Date_type> dates;

    while(!cin.eof())
    {
        cout << "Mata in ett datum: ";
        Date_type date;
        get(date);

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(cin.eof())
        {
            break;
        }

        if(checkIfAlreadyBooked(dates, date))
        {
            cout << "Redan bokat!" << endl;
        }
        else
        {
            dates.push_back(date);
            cout << "Datum bokat!" << endl;
        }
    }

    cout << endl << endl;

    for(Date_type temp: dates)
    {
        temp.log();
    }

    cout << endl;
    return 0;
}

bool checkIfAlreadyBooked(vector<Date_type> const & dates, Date_type const & date)
{
    for(Date_type dateIt: dates)
    {
        if(dateIt.year == date.year && dateIt.month == date.month && dateIt.day == date.day)
        {
            return true;
        }
    }

    return false;
}