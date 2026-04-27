/*
USACO 2020 December Contest, Bronze
Problem 1. Do You Know Your ABCs
https://usaco.org/index.php?page=viewproblem2&cpid=1059
USACO Guide Link
https://usaco.guide/groups/rma5Gov1kElNL9hzEHec/post/z0PHo7r5pxSiM5S08ZXy/problems/DU77AGCRB4EyKHvU8jyZ
*/
#include <bits/stdc++.h>
using namespace std;
int N[7];

// Function - isCombinationValid
// The following logic is executed :
// 1- Generate possible combinations using A,B,C
// 2 -Store the possible values in vector for easy iteration
// 3 - For each combination check if the value is also present
//     in the original N array.
// 4 - If any of the combination is not found, the function
//    would return FASLE. If all the combinations are found 
//   It will return TRUE.
bool isCombinationValid ( int A, int B , int C){
    
    bool retEval = true;

    std::vector<int> checkCombVals = {A+B, B+C, A+C,A+B+C};  
    for (size_t i = 0; i < checkCombVals.size(); ++i) {
       
        int* result = std::find(N, N+7 , checkCombVals[i]);
        
        // Check if found (compare with arr + n, which is end iterator)
        if (result != N+7) {
            // Do nothing
        } else {
            retEval=false;
            break;
        }
    }
    
    return retEval;
}

int main() {
	//Get all the user input 
    cin >> N[0] >> N[1] >> N[2] >> N[3] >> N[4] >> N[5] >> N[6];

    //Sort the input.
    std::sort(std::begin(N), std::end(N));

    //Now that we have sorted the sequence we know 
    // that A and B are the first and second number 
    // because every thing else would be A+B , A+B+C etc.
    // So lets take that those digits out

    int A = N[0];
    int B = N[1];
    int C = -1;

    //Our next step is to determine what is C
    //We also know that the 7th Number is A+B+C.
    //So we just need to check for the digits from 
    // 3rd to 6th.
    // Test would would be find if we assume a number
    // to be C , then all combinations A+B,B+C,C+A,A+B+C 
    // must exist in the provided sequence.

    for (int n=2;n<=6;n++)
    {
        C = N[n];

        if ( true == isCombinationValid(A,B,C))
        {
            //It means we have found the combination 
            //that works . So lets break the loop
            //and publish the results.
            break;
        }    
    

    }

    //Publish the results
    cout << A << " " << B << " " << C << endl;


}
