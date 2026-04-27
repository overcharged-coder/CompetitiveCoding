//USACO 2020 December Contest, Bronze
//Problem 3. Stuck in a Rut
//USACO Link https://usaco.org/index.php?page=viewproblem2&cpid=1061
//USACO Guide Link https://usaco.guide/groups/rma5Gov1kElNL9hzEHec/post/qqEc7gnjHahO87Zj9YFv/problems/ki2YXS4sgQgcGG69O7YY
//Google Slide https://docs.google.com/presentation/d/1d9cn9T6qdsA5Xf444O6cEUhxhuKztzv67RAfigfNQdQ/edit#slide=id.g340eafc224f_0_14


#include <bits/stdc++.h>
using namespace std;

struct CowPos {
    int X;
    int Y;
    int idx;
};
bool compareByX(const CowPos& a, const CowPos& b) {
    return a.X < b.X; // Ascending order
}
bool compareByY(const CowPos& a, const CowPos& b) {
    return a.Y < b.Y; // Ascending order
}
int main() {
	int numCowMoves;
    vector<CowPos> n_Cows;  // Declaring an empty vector of CowPos
    vector<CowPos> e_Cows;
    cin >> numCowMoves;

    vector<int> cowBlocksTravel(numCowMoves,0);

    for (int i=0;i<numCowMoves;i++){
        char cowDir; int X,Y;
        cin >> cowDir >> X >> Y;
        CowPos cp = {X,Y,i};
        if (cowDir=='N'){
            n_Cows.push_back(cp);
        } else {
            e_Cows.push_back(cp);
        }
    }
    
    sort(n_Cows.begin(), n_Cows.end(), compareByX);
    sort(e_Cows.begin(), e_Cows.end(), compareByY);
    
    for (const auto& n_cow : n_Cows) {
        for (const auto& e_cow : e_Cows) {
            if (
                (e_cow.X < n_cow.X) and 
                (e_cow.Y > n_cow.Y) and
                (cowBlocksTravel[e_cow.idx] == 0) and
                (cowBlocksTravel[n_cow.idx] == 0)) {

                    if ((n_cow.X-e_cow.X)>(e_cow.Y-n_cow.Y)){
                        cowBlocksTravel[e_cow.idx] = (n_cow.X-e_cow.X);
                    }else if((n_cow.X-e_cow.X)==(e_cow.Y-n_cow.Y)){
                        // Do nothing.
                    } else {
                        cowBlocksTravel[n_cow.idx] = (e_cow.Y-n_cow.Y);
                    }
            }
        }
    }
    
    for (const int& blocks : cowBlocksTravel) {
        //ternary operator
        cout << (blocks == 0 ? "Infinity" : to_string(blocks)) << endl;
    }

}
