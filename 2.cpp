#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    std::ifstream infile("2.input");
    std::string line;
    
    int score = 0;
// A Y
// B X
// C Z
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        char a,b;
        if (!(iss >> a >> b))
        {
            cerr << "empty line " << endl;
        }
        else{

            cerr << a << b << endl;

            int p1 = a - 'A';

            int p2 = (b - 'X');
            cerr << "p1 " << p1 <<endl;
            cerr << "p2 " << p2 <<endl;
            
            p2 = (p2 == 0 ? 0 : p2 == 2 ? 6 : 3);

            cerr << "p2 " << p2 <<endl;

            int mv = (p1 + (p2 == 0 ? 2 : p2 == 3 ? 0 : 1)) % 3 + 1;

            cerr << "p2 " << p2 << " mv " << mv << endl;

            score += p2 + mv;
        }
    }
    cerr << "sol = " << score << endl;
    return (0);
}