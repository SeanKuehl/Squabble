#ifndef SCOPE_H
#define SCOPE_H
#include <vector>
#include <string>

using namespace std;

class Scope
{
    public:

        Scope();
        Scope(string name, vector<string> initalVariables, vector<vector<string>> commands);
        virtual ~Scope();
        string GetScopeName();
        void SetScopeName(string newName);
        vector<vector<string>> GetScopeCommands();



        vector<string> GetScopeVariables();
        void SetScopeVariables(vector<string> newVars);

    protected:

    private:
        string scopeName = "";
        vector<vector<string>> scopeCommands;
        vector<string> scopeVariables;
};

#endif // SCOPE_H
