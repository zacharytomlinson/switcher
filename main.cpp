#include <iostream>
#include <fstream>
#include <dirent.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <sys/stat.h>

using namespace std;

string tolower(string);

bool startChildProcess(const char*, string, string);

bool is_file(const char* path) {
    struct stat buf;
    stat(path, &buf);
    return S_ISREG(buf.st_mode);
}

bool is_dir(const char* path) {
    struct stat buf;
    stat(path, &buf);
    return S_ISDIR(buf.st_mode);
}

int main()
{
    ifstream inFile;
    ofstream finFile;
    const char* PATH;
    string searchWord, inputFolder, replaceWord;
    string line, fullPath, lowerLine;
    vector<string> fileBuffer;
    int startPos;

    cout << "Enter Folder Name: ";
    getline(cin, inputFolder);
    PATH = inputFolder.c_str();
    cout << endl;
    cout << "Enter Search Word: ";
    getline(cin, searchWord);
    searchWord = tolower(searchWord);
    cout << endl;
    cout << "Enter Replacement Word: ";
    getline(cin, replaceWord);
    cout << endl;

    DIR *dir = opendir(PATH);
    struct dirent *entry = readdir(dir);
    while(entry != NULL) {
        string FILE(entry->d_name);
        string ROUTE(PATH);
        fullPath = ROUTE + "/" + FILE;
        if(!is_file(fullPath.c_str())) {
            if(FILE != ".." && FILE != ".") {
                startChildProcess(fullPath.c_str(), searchWord, replaceWord);
            }
        }
        inFile.open(fullPath.c_str());
        while(getline(inFile, line)) {
            lowerLine = tolower(line);
            while(lowerLine.find(searchWord) != -1) {
                startPos = lowerLine.find(searchWord);
                line.replace(startPos, searchWord.length(), replaceWord);
                lowerLine.replace(startPos, searchWord.length(), replaceWord);
            }
            fileBuffer.push_back(line);
        }
        inFile.close();
        finFile.open(fullPath.c_str());
        for(int i = 0; i < fileBuffer.size(); i++) {
            finFile << fileBuffer[i] << endl;
        }
        finFile.close();
        entry = readdir(dir);
        fileBuffer.clear();
    }

    closedir(dir);

    return 0;
}

bool startChildProcess(const char* PATH, string searchWord, string replaceWord) {
    ofstream finFile;
    ifstream inFile;
    string fullPath, line, lowerLine;
    vector<string> fileBuffer;
    int startPos;

    DIR *dir = opendir(PATH);
    struct dirent *entry = readdir(dir);
    while(entry != NULL) {
        string FILE(entry->d_name);
        string ROUTE(PATH);
        fullPath = ROUTE + "/" + FILE;
        if(!is_file(fullPath.c_str())) {
            if(FILE != ".." && FILE != ".") {
                startChildProcess(fullPath.c_str(), searchWord, replaceWord);
            }
        }
        inFile.open(fullPath.c_str());
        while(getline(inFile, line)) {
            lowerLine = tolower(line);
            while(lowerLine.find(searchWord) != -1) {
                startPos = lowerLine.find(searchWord);
                line.replace(startPos, searchWord.length(), replaceWord);
                lowerLine.replace(startPos, searchWord.length(), replaceWord);
            }
            fileBuffer.push_back(line);
        }
        inFile.close();
        finFile.open(fullPath.c_str());
        for(int i = 0; i < fileBuffer.size(); i++) {
            finFile << fileBuffer[i] << endl;
        }
        finFile.close();
        entry = readdir(dir);
        fileBuffer.clear();
    }

    closedir(dir);
}

string tolower(string s) {
    for(int i = 0; i < s.length(); i++) {
        char letter = s[i];
        switch(letter) {
            case 'A':
                s[i] = 'a';
                break;
            case 'B':
                s[i] = 'b';
                break;
            case 'C':
                s[i] = 'c';
                break;
            case 'D':
                s[i] = 'd';
                break;
            case 'E':
                s[i] = 'e';
                break;
            case 'F':
                s[i] = 'f';
                break;
            case 'G':
                s[i] = 'g';
                break;
            case 'H':
                s[i] = 'h';
                break;
            case 'I':
                s[i] = 'i';
                break;
            case 'J':
                s[i] = 'j';
                break;
            case 'K':
                s[i] = 'k';
                break;
            case 'L':
                s[i] = 'l';
                break;
            case 'M':
                s[i] = 'm';
                break;
            case 'N':
                s[i] = 'n';
                break;
            case 'O':
                s[i] = 'o';
                break;
            case 'P':
                s[i] = 'p';
                break;
            case 'Q':
                s[i] = 'q';
                break;
            case 'R':
                s[i] = 'r';
                break;
            case 'S':
                s[i] = 's';
                break;
            case 'T':
                s[i] = 't';
                break;
            case 'U':
                s[i] = 'u';
                break;
            case 'V':
                s[i] = 'v';
                break;
            case 'W':
                s[i] = 'w';
                break;
            case 'X':
                s[i] = 'x';
                break;
            case 'Y':
                s[i] = 'y';
                break;
            case 'Z':
                s[i] = 'z';
                break;
        }
    }
    return s;
}
