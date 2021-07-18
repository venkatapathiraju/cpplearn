#include <vector>

namespace learnvector{
using namespace std;

//Return value optimization or copy elision is performed using move semantic to have 
//performance gain (or not having performance penalty)
vector<int> createVectorofSize(size_t size)
{
    vector<int> vec(size);
    int contents = 0;
    for(auto&i : vec)
    {
        i = contents++;
    }
    return vec;
}

void run()
{
    cout << "****************vector run begin " << endl;
    vector<int> myvec{1,2,3,4,5};
    vector<string> mystrvec{"hello","hi"};
    auto itstrend = mystrvec.end();
    auto itend = myvec.end();
    //cout << itstrend == itend << endl;
    cout << "****************vector run end " << endl;
}

}