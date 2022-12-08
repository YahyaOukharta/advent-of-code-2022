#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>

using namespace std;

int main()
{
    std::ifstream infile("5.input");
    std::string line;

    int score = 0;

    int parsing = 1;
    vector<string> stacks(9);
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        string s;
        if (!(iss >> s))
        {
            cerr << "empty line " << endl;
            parsing = 0;
            for (auto st : stacks)
            {
                cerr << st << endl;
            }
        }
        else
        {
            if (parsing)
            {
                // cerr << line << endl;
                int i = 1;
                int j = 0;
                while (i < line.size())
                {
                    cerr << line[i] << " ";
                    if (line[i] != ' ' && line[i] > '9')
                    {
                        stacks[j] = line[i] + stacks[j];
                    }
                    i += 4;
                    j++;
                }
                cerr << endl;
            }
            else
            {
                line = line.substr(5);
                int count = atoi(line.c_str());
                int i = 0;
                while (line[i++] != ' ')
                    ;
                line = line.substr(i + 5);
                int from = atoi(line.c_str()) - 1;
                i = 0;
                while (line[i++] != ' ')
                    ;
                line = line.substr(i + 3);
                int to = atoi(line.c_str()) - 1;

                cerr << count << " " << from << " " << to << endl;

                stacks[to] = stacks[to] + stacks[from].substr(stacks[from].size() - count );
                while (count)
                {
                    // char top = stacks[from].back();
                    stacks[from].pop_back();

                    count--;
                }
            }
        }
    }
    for (auto st : stacks)
    {
        cerr << st.back();
    }
    cerr << endl;
    cerr << "sol = " << score << endl;
    return (0);
}