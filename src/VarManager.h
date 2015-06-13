//
//  VarManager.h
//  VARVA
//
//  Created by Jacob Gonzalez on 14/06/2015.
//
//

#pragma once

#include "ofMain.h"
#include "Variable.h"

class VarManager
{
public:
    static VarManager &shared_manager()
    {
        static VarManager instance;
        return instance;
    }

    void load_varibles(string directory);

    vector<Variable> &operator[](string key);

    map<string, vector<Variable> > var_map;

private:
    VarManager()
    {}

    VarManager(VarManager const &) = delete;
    void operator=(VarManager const &) = delete;
};