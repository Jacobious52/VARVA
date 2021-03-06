//
//  Variable.h
//  VARVA
//
//  Created by Jacob Gonzalez on 14/06/2015.
//
//

#pragma once

#include "ofMain.h"

class Variable
{
public:
    Variable(string _class_name, string _func_name, string _line, float _val, string _note)
        : class_name(_class_name),
          func_name(_func_name),
          line(_line),
          var_value(_val),
          note(_note)
    {}

    string class_name;
    string func_name;
    string line;
    string note;

    float var_value;

private:

};