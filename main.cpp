/*
 * Created by Saumya Lohia and Vignesh Ravindranath
 * plagerismCatcher
 */

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <locale>

using namespace std;

string FILE_PATH = "C:/Github/cheaters/cmake-build-debug/sm_doc_set/";
string FOLDER = "sm_doc_set";

int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

int main(int argc, char *argv[]) {
    //int N = *argv[2];
    //int chunkSize = *argv[3];
    int N = 6;
    int chunkSize = 200;

    string dir = string(FOLDER);
    vector<string> files = vector<string>();

    getdir(dir, files);

    for (int i = 0; i < files.size(); i++) {
        cout << i << files[i] << endl;
    }

    int numFiles = files.size();
    cout << "Number of files: " << numFiles << endl;

    vector<vector<string> > *VectorTable = new vector<vector<string>>();
    for (int j = 2; j < numFiles; j++) {
        ifstream curFile;
        ofstream newFile;
        string newFileName = "processed_" + files[j];

        curFile.open(FILE_PATH + files[j]);
        newFile.open(newFileName);
        string curLine;
        int curSize;
        char curChar;
        if (!curFile) {
            cout << "Unable to open file " << files[j] << endl;
        } else {
            cout << "File " << files[j] << " is open" << endl;

            while (getline(curFile, curLine, '\0')) {
                curSize = curLine.size();

                for (int i = 0; i < curSize; i++) {
                    if (ispunct(curLine[i])) {
                        curLine.erase(i--, 1);
                        i++;
                    } else
                        curLine[i] = toupper(curLine[i]);
                    newFile << curLine[i];
                }
            }
            newFile.close();
            curFile.close();

            string words;
            string wordChunk = "";
            int numWords;
            ifstream readFile;

            readFile.open(newFileName);

            string word;
            vector<string> vectWords;
            vector<string> vectChunks;

            string chunk = "";

            while (!readFile.eof()) {
                readFile >> word;
                cout << word << endl;
                vectWords.push_back(word);
            }

            for (int i = 0; i < vectWords.size(); i++) {
                cout << i << ": " << vectWords[i] << endl;
            }

            for (int i = 0; i < vectWords.size() - chunkSize; i++) {
                chunk = "";
                for (int j = i; j < i + chunkSize; j++) {
                    chunk += vectWords[j];
                }
                vectChunks.push_back(chunk);

            }

            for (int i = 0; i < vectChunks.size(); i++) {
                cout << i << ": " << vectChunks[i] << endl;
            }
        }
    }

}
