#ifndef VARIABLE_H
#define VARIABLE_H
#include <string>

using namespace std;

class Variable
{
    public:
        Variable(string);

        string GetName();

        void SetName(string newName);

        int GetIntValue();

        void SetIntValue(int newValue);

        string GetStringValue();

        void SetStringValue(string newValue);

        char GetCharValue();

        void SetCharValue(char newValue);

        double GetDoubleValue();

        void SetDoubleValue(double newValue);

    protected:

    private:
        string variableName = "ERROR";
        int intValue = 0;
        string strValue = " ";
        char charValue = ' ';
        double doubleValue = 0.0;

};

#endif // VARIABLE_H
