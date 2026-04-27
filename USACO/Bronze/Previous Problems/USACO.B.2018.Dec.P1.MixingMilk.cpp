//USACO 2018 December Contest, Bronze
//Problem 1. Mixing Milk
//USACO Guide Link : https://usaco.guide/groups/d7eYGfddXq3m2trXG2xt/post/yxuk8S2r38bWhaZO3p0S/problems/yb4EakMY0iZXWm5uDFhI
//USACO Link : https://usaco.org/index.php?page=viewproblem2&cpid=855

#include <bits/stdc++.h>
using namespace std;


int main() {
int bucket_capacity[3];
int bucket_milk_amount[3];

 for (int i=0;i<=2;i++){
        cin >> bucket_capacity[i];
        cin >> bucket_milk_amount[i];
   }
   
    //We will do 100 pour operations.
    //Lets determine which buckets we will start the 
    // pouring from and to which bucket.
    // This will repeat : 1->2 , 2->3, 3->1, (repeat) 1->2..
    //Lets determine which buckets we will start the 
    // pouring from and to which bucket.

    int from_bucket = 0,to_bucket = 1;

    for (int i=1;i<=100;i++){

        //Perform the pouring
        // Check if the amount of milk which will be poured from
        // "from bucket" to "to bucket".
        // Milk than can be poured to "to bucket"
        // = (Capacity of TO Bucket) - (Milk in To Bucket)
        // The above amount would be deducted from "Milk in From Bucket"

        //The amount of milk that can be poured.
        int pos_milk_to_pour = bucket_capacity[to_bucket] - bucket_milk_amount[to_bucket];

        //Check we have that amount of milk available in the "from bucket"
        // If we can pour the whole milk if we have enough.
        int pour_milk = pos_milk_to_pour;

        if ( pos_milk_to_pour >= bucket_milk_amount[from_bucket])
        {
            pour_milk = bucket_milk_amount[from_bucket];
        }

        //Now finally perform the pouring operation
        bucket_milk_amount[to_bucket] = bucket_milk_amount[to_bucket] + pour_milk;
        bucket_milk_amount[from_bucket] = bucket_milk_amount[from_bucket] - pour_milk;


        //set the bucket positions for pouring
        // After last bucket , it will be pured to the first one
        // Pour #3 -> #1

        if ( 1 == to_bucket) {
            from_bucket = 1;to_bucket = 2;}
        else if ( 2 == to_bucket ){
            from_bucket = 2;to_bucket = 0;}
        else {
            from_bucket = 0;to_bucket = 1;}

   } //for 100 pouring.
  
}
