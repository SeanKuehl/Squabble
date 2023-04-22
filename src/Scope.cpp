#include "Scope.h"

Scope::Scope(string name, vector<string> initalVariables, vector<vector<string>> commands)
{
    scopeName = name;
    scopeVariables = initalVariables;
    scopeCommands = commands;

}

Scope::~Scope()
{
    //dtor
}

vector<string> GetScopeVariables();
        void SetScopeVariables(vector<string> newVars);


string Scope::GetScopeName(){
    return scopeName;
}

void Scope::SetScopeName(string newName){
    scopeName = newName;
}

vector<vector<string>> Scope::GetScopeCommands(){
    return scopeCommands;
}



vector<string> Scope::GetScopeVariables(){
    return scopeVariables;
}

void SetScopeVariables(vector<string> newVars);


