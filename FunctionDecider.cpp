#include <vector>
#include <string>
#include <iostream>
#include "Variable.h"

using namespace std;

vector<Variable> userVariables;


void DeclareVariable(string variableName);

void SetVariableStringValue(string variableName, string newValue);
void SetVariableIntegerValue(string variableName, string newValue);
void SetVariableCharacterValue(string variableName, string newValue);
void SetVariableDoubleValue(string variableName, string newValue);

void VariablePrintDouble(string variableName);
void VariablePrintInteger(string variableName);
void VariablePrintString(string variableName);
void VariablePrintCharacter(string variableName);


void DecideCommand(vector<vector<string>> lines){
    for (int i = 0; i< lines.size();i++){
        vector<string> thisLine = lines.at(i);


            if (thisLine.at(0) == "DECLARE" || thisLine.at(0) == "declare"){
                DeclareVariable(thisLine.at(1));
            }
            else if (thisLine.at(0) == "SETS" || thisLine.at(0) == "sets"){
                SetVariableStringValue(thisLine.at(1), thisLine.at(2));
            }
            else if (thisLine.at(0) == "SETI" || thisLine.at(0) == "seti"){
                    SetVariableIntegerValue(thisLine.at(1), thisLine.at(2));

            }
            else if (thisLine.at(0) == "SETC" || thisLine.at(0) == "setc"){

                    SetVariableCharacterValue(thisLine.at(1), thisLine.at(2));

            }
            else if (thisLine.at(0) == "SETD" || thisLine.at(0) == "setd"){

                    SetVariableDoubleValue(thisLine.at(1), thisLine.at(2));

            }

            else if (thisLine.at(0) == "PRINTS" || thisLine.at(0) == "prints"){
                    VariablePrintString(thisLine.at(1));


            }
            else if (thisLine.at(0) == "PRINTI" || thisLine.at(0) == "printi"){
                    VariablePrintInteger(thisLine.at(1));

            }
            else if (thisLine.at(0) == "PRINTC" || thisLine.at(0) == "printc"){
                    VariablePrintCharacter(thisLine.at(1));

            }
            else if (thisLine.at(0) == "PRINTD" || thisLine.at(0) == "printd"){
                    VariablePrintDouble(thisLine.at(1));

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

void SetVariableIntegerValue(string variableName, string newValue){
    int convertedValue = stoi(newValue);

    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == variableName){
            userVariables.at(i).SetIntValue(convertedValue);
        }
    }

}

void SetVariableCharacterValue(string variableName, string newValue){
    char convertedValue = newValue.at(0);

    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == variableName){
            userVariables.at(i).SetCharValue(convertedValue);
        }
    }

}

void SetVariableDoubleValue(string variableName, string newValue){
    double convertedValue = stod(newValue);

    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == variableName){
            userVariables.at(i).SetDoubleValue(convertedValue);
        }
    }

}

void VariablePrintString(string variableName){
    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == variableName){
            cout << userVariables.at(i).GetStringValue() << endl;
        }
    }

}

void VariablePrintInteger(string variableName){
    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == variableName){
            cout << userVariables.at(i).GetIntValue() << endl;
        }
    }
}

void VariablePrintCharacter(string variableName){
    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == variableName){
            cout << userVariables.at(i).GetCharValue() << endl;
        }
    }
}

void VariablePrintDouble(string variableName){
    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == variableName){
            cout << userVariables.at(i).GetDoubleValue() << endl;
        }
    }
}



