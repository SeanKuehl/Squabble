#include <vector>
#include <string>
#include <iostream>
#include <string.h>
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

void AddStringVariables(string firstVariable, string secondVariable);
void AddIntegerVariables(string firstVariable, string secondVariable);
void AddCharacterVariables(string firstVariable, string secondVariable);
void AddDoubleVariables(string firstVariable, string secondVariable);

void SubtractStringVariables(string firstVariable, string secondVariable);
void SubtractIntegerVariables(string firstVariable, string secondVariable);
void SubtractCharacterVariables(string firstVariable, string secondVariable);
void SubtractDoubleVariables(string firstVariable, string secondVariable);


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

            else if (StringToUpper(thisLine.at(0)) == "ADDS"){

                AddStringVariables(thisLine.at(1), thisLine.at(2));
            }
            else if (StringToUpper(thisLine.at(0)) == "ADDI"){
                AddIntegerVariables(thisLine.at(1), thisLine.at(2));
            }
            else if (StringToUpper(thisLine.at(0)) == "ADDC"){
                AddCharacterVariables(thisLine.at(1), thisLine.at(2));
            }
            else if (StringToUpper(thisLine.at(0)) == "ADDD"){
                AddDoubleVariables(thisLine.at(1), thisLine.at(2));
            }
            else if (StringToUpper(thisLine.at(0)) == "SUBS"){
                SubtractStringVariables(thisLine.at(1), thisLine.at(2));
            }
            else if (StringToUpper(thisLine.at(0)) == "SUBI"){
                SubtractIntegerVariables(thisLine.at(1), thisLine.at(2));
            }
            else if (StringToUpper(thisLine.at(0)) == "SUBC"){
                SubtractCharacterVariables(thisLine.at(1), thisLine.at(2));
            }
            else if (StringToUpper(thisLine.at(0)) == "SUBD"){
                SubtractDoubleVariables(thisLine.at(1), thisLine.at(2));
            }


    }
}

void SubtractStringVariables(string firstVariable, string secondVariable){
    //replaces last x characters of first string with second variable
    //where x is the length of the second variable
    //if both variables are the same size, produce empty string
    //if second variable is longer, keep characters in second variable
    //after x where x is the length of the first variable
    string resultingString = "";

    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == firstVariable){
            resultingString += userVariables.at(i).GetStringValue();
        }
    }

    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == secondVariable){
            string secondString = userVariables.at(i).GetStringValue();

            if (secondString.size() > resultingString.size()){
                resultingString = secondString.substr(resultingString.size()+1, resultingString.size());

            }
            else if (secondString.size() == resultingString.size()){
                resultingString = "";
            }
            else if (secondString.size() < resultingString.size()){
                int originalSize = resultingString.size();
                resultingString = resultingString.substr(0,resultingString.size()-secondString.size());
                resultingString += secondString;

            }

        }
    }


    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == firstVariable){
            userVariables.at(i).SetStringValue(resultingString);
        }
    }

}

void SubtractIntegerVariables(string firstVariable, string secondVariable){

    int resultingValue = 0;

    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == firstVariable){
            resultingValue = userVariables.at(i).GetIntValue();
        }
    }

    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == secondVariable){
            resultingValue -= userVariables.at(i).GetIntValue();
        }
    }

    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == firstVariable){
            userVariables.at(i).SetIntValue(resultingValue);
        }
    }


}

void SubtractCharacterVariables(string firstVariable, string secondVariable){
    int resultingChar = 0;

    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == firstVariable){
            resultingChar += (int)(userVariables.at(i).GetCharValue());
        }
    }

    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == secondVariable){
            resultingChar += (int)(userVariables.at(i).GetCharValue());
        }
    }

    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == firstVariable){
            userVariables.at(i).SetCharValue((char)(resultingChar));
        }
    }

}

void SubtractDoubleVariables(string firstVariable, string secondVariable){
    double resultingDouble = 0.0;

    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == firstVariable){
            resultingDouble += userVariables.at(i).GetDoubleValue();
        }
    }

    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == secondVariable){
            resultingDouble += userVariables.at(i).GetDoubleValue();
        }
    }

    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == firstVariable){
            userVariables.at(i).SetDoubleValue(resultingDouble);
        }
    }
}

void AddStringVariables(string firstVariable, string secondVariable){
    string resultingString = "";

    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == firstVariable){
            resultingString += userVariables.at(i).GetStringValue();
        }
    }

    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == secondVariable){
            resultingString += userVariables.at(i).GetStringValue();
        }
    }


    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == firstVariable){
            userVariables.at(i).SetStringValue(resultingString);
        }
    }

}

void AddIntegerVariables(string firstVariable, string secondVariable){
    int resultingInt = 0;

    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == firstVariable){
            resultingInt += userVariables.at(i).GetIntValue();
        }
    }

    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == secondVariable){
            resultingInt += userVariables.at(i).GetIntValue();
        }
    }


    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == firstVariable){
            userVariables.at(i).SetIntValue(resultingInt);
        }
    }

}

void AddCharacterVariables(string firstVariable, string secondVariable){
    int resultingHelper;

    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == firstVariable){
             resultingHelper = (int)(userVariables.at(i).GetCharValue());
        }
    }

    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == secondVariable){
            resultingHelper += (int)(userVariables.at(i).GetCharValue());
        }
    }


    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == firstVariable){
            userVariables.at(i).SetCharValue((char)resultingHelper);
        }
    }

}

void AddDoubleVariables(string firstVariable, string secondVariable){
    double resultingDouble = 0.0;

    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == firstVariable){
             resultingDouble += userVariables.at(i).GetDoubleValue();
        }
    }

    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == secondVariable){
            resultingDouble += userVariables.at(i).GetDoubleValue();
        }
    }


    for (int i = 0; i<userVariables.size();i++){
        if (userVariables.at(i).GetName() == firstVariable){
            userVariables.at(i).SetDoubleValue(resultingDouble);
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



