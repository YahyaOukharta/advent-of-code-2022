#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>

using namespace std;
vector<string> tokenize(string s, string del)
{
    vector<string> res;
    int start, end = -1*del.size();
    do {
        start = end + del.size();
        end = s.find(del, start);
        res.push_back(s.substr(start, end - start));
    } while (end != -1);
    return res;
}
int main()
{
    std::ifstream infile("4.input");
    std::string line;
    
    int score = 0;

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
            int a,b,c,d;
            auto sp = tokenize(s,",");
            auto sp1 = tokenize(sp[0],"-");
            auto sp2 = tokenize(sp[1],"-");
            a = atoi(sp1[0].c_str());
            b = atoi(sp1[1].c_str());
            c = atoi(sp2[0].c_str());
            d = atoi(sp2[1].c_str());
            //cerr <<a <<" "<<b <<" "<<c <<" "<<d <<" "<<endl;
            if ( a >= c && a <= d || b >= c && b <= d || c >= a && c <= b || d >= a && d <= b)
            {
                cerr << s << endl;
                    score++;
            }
        }
    }
    cerr << "sol = " << score << endl;
    return (0);
}