#include "DisplayManager.h"

DisplayManager::DisplayManager()
{
    //ctor
}

DisplayManager::~DisplayManager()
{
    //dtor
}

 void DisplayManager::horizontalLineDisplay(vector<string> strings, int cellWidth)
 {
    ostringstream stringBuilder;

    for(size_t i = 0; i < strings.size(); ++i)
    {
        int spaceLeft = cellWidth - strings.at(i).size();
        stringBuilder << '|' << strings.at(i);

        for(int si = 0; si < spaceLeft; ++si)
        {
            stringBuilder << ' ';//padding
        }
    }

    cout << stringBuilder.str() << endl;
 }

  void DisplayManager::horizontalLinesDisplay(vector<string> multiLineStrings, int cellWidth)
  {
    string delimiter = "\n";
    bool dowrite = true;
    while(dowrite)
    {
        dowrite = false;
        vector<string> lines;
        for(size_t i = 0; i < multiLineStrings.size(); ++i)
        {
            string line;
            int pos = multiLineStrings.at(i).find(delimiter);
            if(pos != string::npos)
            {
                //found end of line
                line = multiLineStrings.at(i).substr(0, pos);
                multiLineStrings.at(i).erase(0, pos + delimiter.length());

                dowrite = true;
            }
            else
            {
                //no more lines
                line = " ";
            }

            lines.push_back(line);
        }

        if(dowrite)
        {
            DisplayManager::horizontalLineDisplay(lines, cellWidth);
        }
    }
  }
