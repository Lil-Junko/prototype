#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
using namespace std;

/*
[place stranger]
dialogue:
/
"hello stranger"
"can you help me?"
[option] yes ([quest]"find my pendant please") | no ([quest]"You don't have a choice")
/
[open door]
[place chest]
*/

int typecheck(string line);
int action(string line);

int main()
{
    //initialize game from file
    string line;
    ifstream myfile("test.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            //do perform each action
            if (typecheck(line) == 1) //action
            {
                int act = action(line);
                if (act == 1)
                {
                    cout << "a door opened" << endl;
                }
                else if (act == 2)
                {
                    cout << "a chest unlocked" << endl;
                }
                else if (act == 3)
                {
                    cout << "a stranger approaches" << endl;
                }
            }
            else if (typecheck(line) == 2) //dialogue
            {
                //read out full dialogue
                getline(myfile, line); //skip the dialogue line
                do
                {
                    cout << "dialogue: " << line << endl;
                    getline(myfile, line);
                } while (line[0] != '/');
            }
            else
            {
                cout << "error: " << line << endl;
            }

        }
        myfile.close();
    }
    else
    {
        cout << "Unable to open file";
    }
    //start game loop
    return 0;
}

int typecheck(string line)
{
    if (line[0] == '[' && line[line.length() - 1] == ']') //action
    {
        return 1;
    }
    else if (line[0] == '/') //dialogue
    {
        return 2;
    }
    return 0;
}

int action(string line)
{
    if(line == "[open door]")
    {
        return 1;
    }
    else if(line == "[place chest]")
    {
        return 2;
    }
    else if(line == "[place stranger]")
    {
        return 3;
    }
    return 0;
}