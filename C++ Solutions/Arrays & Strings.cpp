#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//Q1.1
bool isUnique(const string& str){
    bool hist[128]= {false};
    for(const char& c : str){
        if(hist[c]) return false;
        hist[c]=true;
    }
    return true;
}

//Q1.2
bool CheckPermutation(const string& str1, const string& str2){
    if(str1.size() != str2.size()) return false;
    int hist1[128]= {false}, hist2[128]= {false};
    for(const char& c : str1) ++hist1[c];
    for(const char& c : str2) ++hist2[c];
    for(int i=0; i<128; i++){
        if(hist1[i] != hist2[i])
            return false;
    }
    return true;
}

//Q1.3
void URLify(char* str){
    int end= strlen(str)-1;
    for(int i=0; i<end; ++i){
        if(str[i]==' '){
            for(int g=0; g<2; ++g) {
                for (int j = end; j > i; --j)
                    swap(str[j], str[j-1]);
            }
            str[i]='%';
            str[i+1]='2';
            str[i+2]='0';
            i+=2;
        }
    }
}

//Q1.4
bool PalindromePermutation(const string& str){
    char hist[128]= {0};
    for(const char& c : str){
        if (c!=' '){
            ++hist[tolower(c)];
        }
    }
    bool even=false;
    for(char i : hist){
        if(i%2 && even)
            return false;
        else if(i%2)
            even=true;
    }
    return true;
}


//Q1.5
bool OneAway(const string& s1, const string& s2){
    int diff=s1.size()-s2.size();
    if(labs(diff) > 1)
        return false;
    bool one_away = false;
    for(auto cur1=s1.begin(), cur2=s2.begin();
        cur1!=s1.end() and cur2!=s2.end();
        ++cur1, ++cur2){
        if(*cur1 != *cur2){
            if(one_away) return false;
            one_away=true;
            if(diff==1) ++cur1;
            else if (diff==-1) ++cur2;
        }
    }
    return true;
}


int main() {
    //cout << isUnique("Hello, World!") << endl;
    //cout << isUnique("Ofir") << endl;
    //cout << CheckPermutation("ABCD", "DCAB") << endl;
    //cout << CheckPermutation("AAA", "AA") << endl;
    //cout << CheckPermutation("ABC", "ABD") << endl;
    //char input[strlen("Mr John Smith    ")+1];
    //char input[]= "Mr John Smith    ";
    //URLify(input);
    //cout << input << endl;
    //cout << PalindromePermutation("Tact Coa") << endl;
    cout << OneAway("pale", "ple") << endl;
    cout << OneAway("pales", "pale") << endl;
    cout << OneAway("pale", "bale") << endl;
    cout << OneAway("pale", "bake") << endl;
    return 0;
}