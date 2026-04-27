//USACO 2015 February Contest, Bronze
//Problem 1. Censoring (Bronze)
//USACO Link https://usaco.org/index.php?page=viewproblem2&cpid=526
//USACO Guide https://usaco.guide/groups/rma5Gov1kElNL9hzEHec/post/qqEc7gnjHahO87Zj9YFv
// Google Slide https://docs.google.com/presentation/d/1gnj33o4Y00Eaf0tiiSzgheBiBjah8qoHWRiicJmUMSM/edit#slide=id.p


#include <iostream>
#include <vector>

using namespace std;

int main() {
  
    string T;
    string S;
	cin >> S;
    cin >> T;
    string O = "";

    int t_size = T.size();

    for (int i = 0; i < S.size(); i++) {
        O += S[i];
        //The below fails USACO 
        //O = O + S[i];
        int o_size = O.size();
        
        if (o_size>=t_size && (O.substr(o_size-t_size) == T )) {
            O.resize(o_size-t_size);
        }
    }
    
    cout << O << endl;

    return 0;
}

