#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    std::ifstream infile("1.input");
    std::string line;
    
    int m1 = 0;
    int m2 = 0;
    int m3 = 0;
    int s = 0;

    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        int a;
        if (!(iss >> a))
        {
            cerr << "empty line " << endl;
            // m1=max(m1,s);
            if (s > m1)
            {
                m3 = m2;
                m2 = m1;
                m1 = s;
            }
            else if (s > m2)
            {
                m3 = m2;
                m2 = s;
            }
            else if (s > m3) m3 = s;
            s=0;
        }
        else{
            cerr << a << endl;
            s+=a;
        }
    }
    cerr << "sol = " << m1 + m2 + m3 << endl;
    return (0);
}