#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inputfileA,inputfileB;
    //ofstream ofileA,ofileB;

    inputfileA.open("sample.txt");
    if(!inputfileA.fail())
    {
        cout << "File open success" << endl;
    }   
    else
    {
        cout << "File open failed" << endl;
    }
    inputfileA.close();
    return 0;
}