#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "FunctionDecider.h"

using namespace std;

vector<string> ReadFile(string fileName);
vector<vector<string>> SplitVectorStrings(vector<string> toSplit);
vector<vector<string>> CombineStringLiteralTokens(vector<vector<string>> uncombinedLists);  //doesn't work currently

int main(){

     vector<string> fileLines = ReadFile("Test.txt");
     vector<vector<string>> splitLines = SplitVectorStrings(fileLines);
     vector<vector<string>> combinedLines = CombineStringLiteralTokens(splitLines);
     DecideCommand(combinedLines);


    return 0;
}

vector<vector<string>> CombineStringLiteralTokens(vector<vector<string>> uncombinedLists){
    string combinerString = "";
    bool stringStarted = false;
    vector<vector<string>> toReturn;

    for (int i = 0; i< uncombinedLists.size();i++){
        vector<string> thisList = uncombinedLists.at(i);
        vector<string> thisLine;
        for (int k = 0; k<thisList.size();k++){
            char firstChar = thisList.at(k).at(0);
            if (firstChar == '"'){

                combinerString += thisList.at(k) + " ";
                stringStarted = true;
            }
            else if (thisList.at(k).at(thisList.at(k).size()-1) == '"' && stringStarted == true){

                combinerString += thisList.at(k);

                thisLine.push_back(combinerString);
                stringStarted = false;
            }
            else if (stringStarted == true){

                combinerString += thisList.at(k) + " ";
            }
            else {
                thisLine.push_back(thisList.at(k));
            }

        }
        toReturn.push_back(thisLine);


     }

     return toReturn;

}


vector<string> ReadFile(string fileName){
       // Create a text string, which is used to output the text file
    string myText;
    vector<string> fileLines;

    // Read from the text file
    ifstream MyReadFile(fileName);

    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, myText)) {
      // Output the text from the file
      fileLines.push_back(myText);

    }

    // Close the file
    MyReadFile.close();

    return fileLines;

}

vector<vector<string>> SplitVectorStrings(vector<string> toSplit){

    vector<vector<string>> splitLines;
    string delimiter = " ";

    for (int i = 0; i < toSplit.size();i++){
        string s = toSplit.at(i);
        vector<string> thisLine;


        size_t pos = 0;
        string token;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            thisLine.push_back(token);
            s.erase(0, pos + delimiter.length());
        }
        thisLine.push_back(s);

        splitLines.push_back(thisLine);
    }


    return splitLines;


}
