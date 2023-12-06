#include <iostream>
#include <vector>

#define NAME(x) #x

using namespace std;

class matrix {
public:
    //size
    int x, y;
    //using information
    string name;
    vector<vector<int>>mass;
    //construct
    matrix(int x, int y, string name) :x{ x }, y{ y }, name{ name }{
    vector<vector<int>> mass(x, vector<int>(y));
    for (int i = 0; i < mass.size(); i++) {
        for (int j = 0; j < mass[i].size(); j++) {
         if(i==j && x==y){
             mass[i][j] = 1;
         }
         else {
             mass[i][j] = 0;
         }
        }
        }
    };
private:

protected:
};
//functions
//sum with int
matrix operator+= (matrix a, int n) {
    for (int i = 0;i < a.mass.size(); i++) {
        for (int j = 0;j < a.mass[i].size(); j++) {
            if (i == j) {
                a.mass[i][j] += n;
            }
        }
    }
    return a;
}
//cout
std::ostream& operator<< (std::ostream& os,matrix a) {
    string out;
    for (int i = 0;i < a.mass.size(); i++) {
        out += "{ ";
        
        for (int j = 0;j < a.mass[i].size(); j++) {
            out += a.mass[i][j] + " ";
            
            if (j == a.mass[i].size() - 1) {
                out += "}\n";
                
            }
        }
    }
    return os<<out;
}

int main() {
    
    matrix a(3, 3, "Natasha");
    
   
    
    

    return 0;
}