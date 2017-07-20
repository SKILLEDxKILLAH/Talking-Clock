#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace chrono;

void clock(string s){
    int h = stoi(s.substr(0,2));
    int m = stoi(s.substr(3,2));

    string ampm = "pm";
    if (h < 12)
        ampm = "am";

    string tens[] = {"oh", "twenty", "thirty", "forty", "fifty"};
    string ones[] = {"twelve", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven ", "twelve ",
                     "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ",
                     "eighteen ", "nineteen "};

    if (m == 0) {
        cout << " iIt's " << ones[h%12] << ampm << endl;
    }else if (m % 10 == 0) {
        cout << " It's " << ones[h%12] << tens[m/10] << ampm << endl ;
    }else if (m < 10 || m > 20) {
        cout << " It's " << ones[h%12] << tens[m/10] << ones[m%10] << ampm << endl ;
    }else {
        cout << " It's " << ones[h % 12] << ones[m] << ampm << endl;
    }
}

    string time()
    {
        time_t currentTime;
        struct tm *newlocaltime;

        time(&currentTime);
        newlocaltime = localtime(&currentTime);

        int Hour = newlocaltime->tm_hour;
        int Min = newlocaltime->tm_min;

        string time = Hour + ":" + Min;

        return time;

    }


int main()
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, 80, "%I:%M%p.", timeinfo);

    cout << buffer << endl;

    return 0;
}