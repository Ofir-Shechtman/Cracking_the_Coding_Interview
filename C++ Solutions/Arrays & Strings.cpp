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

//Q1.6
unsigned int GetCompressLength(const string& org){
    unsigned int new_len=org.size();
    bool second=false;
    char prev=0;
    for(const char c: org){
        if(c==prev) {
            if (second)
                --new_len;
            second = true;
        }
        else{
            second=false;
        }
        prev=c;
    }
    return new_len;
}

char* WriteCompress(char* cur, char letter, int counter){
    *cur++=letter;
    if(counter==2){
        *cur++=letter;
    }
    else if(counter>2){
        *cur++=counter+'0';
    }
    return cur;

}
string StringCompression(const string& org){
    unsigned int new_len=GetCompressLength(org);
    if(new_len==org.size()) return org;
    char output[new_len+1];
    char* cur=output;
    char prev=*org.begin();
    int counter=0;
    for(char i : org){
        if(i == prev){
            counter++;
        }
        else{
           cur=WriteCompress(cur, prev, counter);
           counter=0;
        }
        prev=i;
    }
    cur=WriteCompress(cur, prev, counter);
    *cur=0;
    return output;
}

//Q1.7
void swap4(int& a, int& b, int& c, int& d){
    int temp=a;
    a=b;
    b=c;
    c=d;
    d=temp;
}
const int N=4;
void RotateMatrix(int matrix[N][N]){
    for(int i=0; i<N/2; ++i){
        for(int j=0; j<N/2; ++j){
            swap4(matrix[i][j], matrix[j][N-i-1], matrix[N-i-1][N-j-1], matrix[N-j-1][i]);
        }
    }
}

//Q1.8
const int M=5;
//const int N=4;
void ZeroMatrix(int matrix[M][N]){
    bool row[M]={false};
    bool col[N]={false};
    for(int i=0;i<M;++i){
        for(int j=0;j<N;++j){
            if(matrix[i][j]==0){
                row[i]=true;
                col[j]=true;
            }
        }
    }
    for(int i=0;i<M;++i) {
        for (int j = 0; j < N; ++j) {
            if (row[i] || col[j])
                matrix[i][j] = 0;
        }
    }
}

//Q1.9
bool isSubstring(const string& s1, const string& s2){
    for(int i=0; i<=s2.size()-s1.size(); ++i){
        string t=s2.substr(i, s1.size());
        if(s2.substr(i, s1.size())==s1)
            return true;
    }
    return false;
}

bool StringRotation(const string& s1, const string& s2){
    for(int i=0; i<s2.size(); ++i){
        if(isSubstring(s2.substr(0, i), s1) && isSubstring(s2.substr(i, s2.size()), s1))
            return true;
    }
    return false;
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
    //cout << OneAway("pale", "ple") << endl;
    //cout << OneAway("pales", "pale") << endl;
    //cout << OneAway("pale", "bale") << endl;
    //cout << OneAway("pale", "bake") << endl;
    //cout << StringCompression("aaaabbbbcddaaaa") << endl;
    //int m1[4][4] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    //RotateMatrix(m1);
    //cout << m1 << endl;
    //int m2[5][4] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
    //ZeroMatrix(m2);
    cout<< isSubstring("erbottle", "waterbottle") << endl;
    cout<< StringRotation("waterbottle", "erbottlewat") << endl;
    return 0;
}