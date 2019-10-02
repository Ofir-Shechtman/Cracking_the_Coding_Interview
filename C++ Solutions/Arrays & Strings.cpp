#include <iostream>
#include <cstdbool>
#include <string>
using namespace std;


bool is_Unique(const string& str){
    bool hist[128]= {false};
    for(const char& c : str){
        if(hist[c]) return false;
        hist[c]=true;
    }
    return true;

}



int main() {
    cout << is_Unique("Hello, World!") << endl;
    cout << is_Unique("Ofir") << endl;
    return 0;
}