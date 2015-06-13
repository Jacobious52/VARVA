//
//  VarManager.cpp
//  VARVA
//
//  Created by Jacob Gonzalez on 14/06/2015.
//
//

#include "VarManager.h"

void VarManager::load_varibles(string directory)
{
    ofDirectory dir(directory);
    dir.allowExt("var");
    dir.listDir();

    for (int i = 0; i < dir.numFiles(); i++)
    {
        ofBuffer buff = ofBufferFromFile(dir.getPath(i));
        printf("%s\n", dir.getPath(i).c_str());

        var_map[dir.getName(i)] = vector<Variable>();

        string line = "";

        vector<string> lines = ofSplitString(buff.getText(), "\n");

        for (auto line : lines)
        {
            printf("%s\n", line.c_str());
            vector<string> split = ofSplitString(line, ",");
            if (line.empty() == false && split.size() == 4)
            {
                var_map[dir.getName(i)].push_back(Variable(split[1], split[2], split[3], ofToFloat(split[0])));
            }
        }
    }

    dir.close();
}

vector<Variable> &VarManager::operator[](string key)
{
    return var_map[(key + ".var")];
}