// USACO 2017 December Contest, Bronze
// Problem 1. Blocked Billboard
//https://usaco.org/index.php?page=viewproblem2&cpid=759
// USACO Guide
// https://usaco.guide/groups/d7eYGfddXq3m2trXG2xt/post/ZkhTvlw0KgyHrqQ69LD1/problems/xWWpKqF6flpFOJ3PUybh

#include <bits/stdc++.h>
using namespace std;

//Function - OverlapArea
// This function taxes the coordinates of two rectangles.
// Then follows the following design to get the coordinates of overlapping area
// - For x coordinate overlap,
//    - First finds the total possible lenght by adding width of both rectangles.
//    - Then finds the actual width of the combined shape by subsrtating the second 
//      rectable end of width by starting position of first rectanles width.
//   Then if the combined shape total width is lower that the total width of two recatgles 
//   seperately , it means there is a width overlap.
// - Follow the same logic to get the height overlap.
// - Finally multiply the overlaps to get the overlap area. 

int OverlapArea ( int b1x1,int b1y1,int b1x2,int b1y2,int b2x1,int b2y1,int b2x2,int b2y2)
{
    int ret_overalap_area = 0;
    int len_overlap;
    int height_overlap;

    //---------------------------------------------------------------------------------
    // Get the overlapping width
    //---------------------------------------------------------------------------------
    //Total witdh when measured sperately
    int len_of_both_rec = (b1x2-b1x1)+(b2x2-b2x1);
    //Total width of the combined shape.
    int len_of_combined_shape = max(b1x2,b2x2) - min(b1x1,b2x1);
    // Check for overlap.
    if ( len_of_both_rec > len_of_combined_shape ) {
        // Calculate the width overlap
        len_overlap = len_of_both_rec - len_of_combined_shape;
    }
    else {
        len_overlap =0;
    }


    //---------------------------------------------------------------------------------
    // Get the overlapping height
    //---------------------------------------------------------------------------------
    // Refer the comments for width.
    int height_of_both_rec = (b1y2-b1y1)+(b2y2-b2y1);
    int height_of_combined_shape = max(b1y2,b2y2) - min(b1y1,b2y1);

    if ( height_of_both_rec > height_of_combined_shape ) {
        height_overlap = height_of_both_rec - height_of_combined_shape;
    }
    else {
        height_overlap =0;
    }


    //---------------------------------------------------------------------------------
    // Get the overlapping area
    //---------------------------------------------------------------------------------
    ret_overalap_area = len_overlap*height_overlap;

    return abs(ret_overalap_area);
}

int main() {
	
    //Cordinates for 1st billboard ( Billboard 1)
    int b1x1, b1y1, b1x2, b1y2;
    //Cordinates for 2nd billboard ( Billboard 2)
    int b2x1, b2y1, b2x2, b2y2;
    //Coordinates for the truck
    int tx1, ty1, tx2, ty2;
    
    //Get all the user inputs
    cin >> b1x1 >> b1y1 >> b1x2 >> b1y2 >> b2x1 >> b2y1 >> b2x2 >> b2y2 >> tx1 >> ty1 >> tx2 >> ty2;

    //Calcutate the visible area
    // Add the billboard 1 and billboards 2 areas to 
    // Substract the following
    // 1- Overlap area of Billboard1 and Truck
    // 2- Overlap area of Billboard2 and Truck

    cout <<
        ( 
            ((b1x2-b1x1)*(b1y2-b1y1)) + 
            ((b2x2-b2x1)*(b2y2-b2y1)) -
            OverlapArea (b1x1, b1y1, b1x2, b1y2, tx1, ty1, tx2, ty2 ) -
            OverlapArea (b2x1, b2y1, b2x2, b2y2, tx1, ty1, tx2, ty2 )
        ) 
        
        << "\n";

}
