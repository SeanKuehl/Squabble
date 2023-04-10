#include <vector>
#include <string>
#include <iostream>
#include "Variable.h"

using namespace std;

vector<Variable> userVariables;

string StringToUpper(string input);


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


            if (StringToUpper(thisLine.at(0)) == "DECLARE"){
                DeclareVariable(thisLine.at(1));
            }
            else if (StringToUpper(thisLine.at(0)) == "SETS"){
                SetVariableStringValue(thisLine.at(1), thisLine.at(2));
            }
            else if (StringToUpper(thisLine.at(0)) == "SETI"){
                    SetVariableIntegerValue(thisLine.at(1), thisLine.at(2));

            }
            else if (StringToUpper(thisLine.at(0)) == "SETC"){

                    SetVariableCharacterValue(thisLine.at(1), thisLine.at(2));

            }
            else if (StringToUpper(thisLine.at(0)) == "SETD"){

                    SetVariableDoubleValue(thisLine.at(1), thisLine.at(2));

            }

            else if (StringToUpper(thisLine.at(0)) == "PRINTS"){
                    VariablePrintString(thisLine.at(1));


            }
            else if (StringToUpper(thisLine.at(0)) == "PRINTI"){
                    VariablePrintInteger(thisLine.at(1));

            }
            else if (StringToUpper(thisLine.at(0)) == "PRINTC"){
                    VariablePrintCharacter(thisLine.at(1));

            }
            else if (StringToUpper(thisLine.at(0)) == "PRINTD"){
                    VariablePrintDouble(thisLine.at(1));

            }

            else if (StringToUpper(thisLine.at(0)) == "COMPARES"){

            }
            else if (StringToUpper(thisLine.at(0)) == "COMPAREI"){

            }
            else if (StringToUpper(thisLine.at(0)) == "COMPAREC"){

            }
            else if (StringToUpper(thisLine.at(0)) == "COMPARED"){

            }


    }
}

string StringToUpper(string input){
    string output;
    for (int i = 0; i<input.size();i++){
        output += toupper(input.at(i));
    }
    return output;
}

void DeclareVariable(string variableName){
    Variable newVar = Variable(variableName);
    userVariables.push_back(newVar);
}

void SetVariableStringValue(string variableName, string newValue){
    string formattedNewValue = "";
    for (int i = 0;i<newValue.size();i++){
        if (newValue.at(i) != '"'){
            formattedNewValue += newValue.at(i);
        }
    }

    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == variableName){
            userVariables.at(i).SetStringValue(formattedNewValue);
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



