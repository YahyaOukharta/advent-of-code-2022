#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <fstream>

using namespace std;

int main()
{
    std::ifstream infile("3.input");
    std::string line;
    
    int score = 0;
// A Y
// B X
// C Z
    int c = 0;
    unordered_map<char,int> seen;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        string s;
        if (!(iss >> s))
        {
            cerr << "empty line " << endl;
        }
        else{
            c++;
            cerr << s << endl;
            char dup;

            for (int i = 0; i < s.size(); i++){
                if (c == 1){
                    seen[s[i]] = 1;
                }
                else if ( c == 2){
                    if (seen[s[i]])
                        seen[s[i]] = 2;
                }
                else {
                    if (seen[s[i]] == 2)
                    {
                        dup = s[i];
                        seen.clear();
                        c = 0;
                        int prio = dup > 'Z' ? (dup - 'a' + 1) : (dup - 'A' + 27);
                        cerr << "prio "<<prio  <<" dup "<<dup << endl;
                        score += prio;
                        break;
                    }
                }
            }
        }
    }
    cerr << "sol = " << score << endl;
    return (0);
}