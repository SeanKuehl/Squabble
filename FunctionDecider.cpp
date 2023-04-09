#include <vector>
#include <string>
#include "Variable.h"

using namespace std;

vector<Variable> userVariables;


void DeclareVariable(string variableName);
void SetVariableStringValue(string variableName, string newValue);


void DecideCommand(vector<vector<string>> lines){
    for (int i = 0; i< lines.size();i++){
        vector<string> thisLine = lines.at(i);
        for (int k = 0; k<thisLine.size();k++){

            if (thisLine.at(0) == "DECLARE" || thisLine.at(0) == "declare"){
                DeclareVariable(thisLine.at(1));
            }
            else if (thisLine.at(0) == "SETS" || thisLine.at(0) == "sets"){
                SetVariableStringValue(thisLine.at(1), thisLine.at(2));
            }
            else if (thisLine.at(0) == "SETI" || thisLine.at(0) == "seti"){

            }
            else if (thisLine.at(0) == "SETC" || thisLine.at(0) == "setc"){

            }
            else if (thisLine.at(0) == "SETD" || thisLine.at(0) == "setd"){

            }

        }
    }
}

void DeclareVariable(string variableName){
    Variable newVar = Variable(variableName);
    userVariables.push_back(newVar);
}

void SetVariableStringValue(string variableName, string newValue){
    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == variableName){
            userVariables.at(i).SetStringValue(newValue);
        }
    }
}
