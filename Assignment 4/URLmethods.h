#include"DataS.h"
using namespace std;


BST     Data;

//       Task 1 Methods

List URLlists;
List Temp;
void extractWords(string sentence) {
    string word;
    List TempURLs;
    for (char ch : sentence) {
        if (isalpha(ch) || ch == '\'') {
            word += ch;
        }
        else {
            if (!word.empty()) {
                URLlists.searchList(word, TempURLs);
                Data.insert(word, TempURLs);
                word.clear();
            }
        }
    }
}
void readFromFile(string fileName)
{
    ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        cerr << "Error opening the file!" <<endl;
    }
    else
    {
        cout << "File loaded Successfully" << endl;
    }

    int ID;string URL, Keyword;

    while (inputFile >> ID >> URL) {
        // Skip the newline character
        inputFile.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(inputFile, Keyword);
        URLlists.AddNode(ID, URL, Keyword);
        extractWords(Keyword);
    }
    inputFile.close();

}
void searchWord(string word)
{
    URLlists.searchList(word,Temp);
    Temp.viewData();
}
bool checkExtension(const string& fileName) {
    size_t dotPosition = fileName.find_last_of('.');
    if (dotPosition != std::string::npos) {
        string extension = fileName.substr(dotPosition + 1);
        return (extension == "txt");
    }
    return false;
}

//       Task 2 Methods
List Temp2;
void traverseBST()
{
    Data.inTrav(Data.getRoot());
}
void searchBSTword(string word)
{
  bool search=  Data.Search(word,Data.getRoot());
  if (search)
      cout << "Word found" << endl;
  else
      cout << "Word not found" << endl;
}
void deleteWord(string word)
{
    Data.deleteInBST(Data.getRoot(), word);
}
void InsertWord(string word)
{
    URLlists.searchList(word, Temp2);
    Data.insert(word, Temp2);
}

