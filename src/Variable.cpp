#include "Variable.h"



Variable::Variable(string passedName)
{
    variableName = passedName;
}

string Variable::GetName(){
    return variableName;
}

void Variable::SetName(string newName){
    variableName = newName;
}

int Variable::GetIntValue(){
    return intValue;
}

void Variable::SetIntValue(int newValue){
    intValue = newValue;
}

string Variable::GetStringValue(){
    return strValue;
}

void Variable::SetStringValue(string newValue){
    strValue = newValue;
}

char Variable::GetCharValue(){
    return charValue;
}

void Variable::SetCharValue(char newValue){
    charValue = newValue;
}

double Variable::GetDoubleValue(){
    return doubleValue;
}

void Variable::SetDoubleValue(double newValue){
    doubleValue = newValue;
}



