#include <vector>
#include <string>
#include <map>

namespace learnclass {
    using namespace std;

    class myclass
    {
      
    public:
        string data;
        myclass() {
            cout << "Constructor" << endl;
        }
        virtual ~myclass()
        {
            cout << "Destructor" << endl;
        }
        myclass(string d) : data(d)
        {
            cout << "Constructor with init" << endl;
        }
        myclass(const myclass& c)
        {
            cout << "Copy Constructor" << endl;
            data = c.data;
        }

        myclass& operator=(const myclass& c)
        {
            cout << "Assignement" << endl;
            data = c.data;
            return *this;
        }

        //Move constructor
        myclass(myclass&& c)
        {
            cout << "Move Constructor" << endl;
            data = std::move(c.data);
        }

        //Move assignment
        myclass& operator=(myclass&& c)
        {
            cout << "Move Assignement" << endl;
            data = std::move(c.data);
            return *this;
        }

        bool operator<(const myclass& other)
        {
            return data < other.data;
        }

        
    };

    bool operator<(const myclass& a, const myclass& b)
    {
        return a.data < b.data;
    }

    void run()
    {
        cout << "****************class run begin " << endl;
        
        std::map<myclass, myclass> mymap;
        //Directly creates the myclass objects in the container , very efficient
        mymap.emplace("1", "one");

        //First creates constructor and then moves , called twice
        //mymap.emplace(myclass("2"), myclass("two"));

        //This is even worse, First creates constructor and then moves 2 times, so three times constructor and destructor for each key and value
        //mymap.emplace(std::make_pair(myclass("2"), myclass("two")));

        
        for (const auto& [key, value] : mymap)
            cout << key.data << "->" << value.data << endl;
        /*
        myclass myc("hi");
        {
            myclass v(std::move(myc));

           
        }

        cout << "does myc hold data " << myc.data << endl;
        */
        //cout << itstrend == itend << endl;
        cout << "****************class run end " << endl;
    }

}