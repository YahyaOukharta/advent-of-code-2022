#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <fstream>

using namespace std;

int main()
{
    std::ifstream infile("6.input");
    std::string line;

    int size = 14;
    unordered_set<char> co;

    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        string s;
        if (!(iss >> s))
        {
            cerr << "empty line " << endl;
        }
        else
        {
            cerr << s << s.size()<< endl;
            for (int i = 0; i < s.size() - size;i++)
            {
                string sub = s.substr(i,size);
                co.clear();
                for(auto c: sub)
                    co.insert(c);
                if (co.size() == size)
                {
                    cerr << "sol = "<< i + size << endl;
                    break;
                }
            }
        }
    }
    return (0);
}