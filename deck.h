#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <ctime>
#include <algorithm>
#include <random>
#include "card.h"

using namespace std;


vector<Card> Cards = {{"a of hearts", 1},{"2 of hearts", 2}, {"3 of hearts", 3}, {"4 of hearts", 4}, {"5 of hearts", 5}, {"6 of hearts", 6}, {"7 of hearts", 7}, {"8 of hearts", 8}, {"9 of hearts", 9}, {"10 of hearts", 10}, {"j of hearts", 11}, {"q of hearts", 12}, {"k of hearts", 13},
    {"a of clubs", 1},{"2 of clubs", 2}, {"3 of clubs", 3}, {"4 of clubs", 4}, {"5 of clubs", 5}, {"6 of clubs", 6}, {"7 of clubs", 7}, {"8 of clubs", 8}, {"9 of clubs", 9}, {"10 of clubs", 10}, {"j of clubs", 11}, {"q of clubs", 12}, {"k of clubs", 13},
    {"a of diamonds", 1},{"2 of diamonds", 2}, {"3 of diamonds", 3}, {"4 of diamonds", 4}, {"5 of diamonds", 5}, {"6 of diamonds", 6}, {"7 of diamonds", 7}, {"8 of diamonds", 8}, {"9 of diamonds", 9}, {"10 of diamonds", 10}, {"j of diamonds", 11}, {"q of diamonds", 12}, {"k of diamonds", 13},
    {"a of spades", 1},{"2 of spades", 2}, {"3 of spades", 3}, {"4 of spades", 4}, {"5 of spades", 5}, {"6 of spades", 6}, {"7 of spades", 7}, {"8 of spades", 8}, {"9 of spades", 9}, {"10 of spades", 10}, {"j of spades", 11}, {"q of spades", 12}, {"k of spades", 13}};


// vector<Card> initCards(){
//     vector<Card> testcards = {{"a of hearts", 1},{"2 of hearts", 2}, {"3 of hearts", 3}, {"4 of hearts", 4}, {"5 of hearts", 5}, {"6 of hearts", 6}, {"7 of hearts", 7}, {"8 of hearts", 8}, {"9 of hearts", 9}, {"10 of hearts", 10}, {"j of hearts", 11}, {"q of hearts", 12}, {"k of hearts", 13},
//     {"a of clubs", 1},{"2 of clubs", 2}, {"3 of clubs", 3}, {"4 of clubs", 4}, {"5 of clubs", 5}, {"6 of clubs", 6}, {"7 of clubs", 7}, {"8 of clubs", 8}, {"9 of clubs", 9}, {"10 of clubs", 10}, {"j of clubs", 11}, {"q of clubs", 12}, {"k of clubs", 13},
//     {"a of diamonds", 1},{"2 of diamonds", 2}, {"3 of diamonds", 3}, {"4 of diamonds", 4}, {"5 of diamonds", 5}, {"6 of diamonds", 6}, {"7 of diamonds", 7}, {"8 of diamonds", 8}, {"9 of diamonds", 9}, {"10 of diamonds", 10}, {"j of diamonds", 11}, {"q of diamonds", 12}, {"k of diamonds", 13},
//     {"a of spades", 1},{"2 of spades", 2}, {"3 of spades", 3}, {"4 of spades", 4}, {"5 of spades", 5}, {"6 of spades", 6}, {"7 of spades", 7}, {"8 of spades", 8}, {"9 of spades", 9}, {"10 of spades", 10}, {"j of spades", 11}, {"q of spades", 12}, {"k of spades", 13}};
//     return testcards;
// }


stack<Card> shuffleDeck(vector<Card> cards){


    stack<Card> shuffled;

        //this code is inefficient because removing an index of a vector then forces the reallocation of the entire vector as a vectors underlying data structure is an array

        // while(!cards.empty()){
        // srand(time(NULL));
        // size_t rand_index = rand() % cards.size();
        // shuffled.push(cards[rand_index]);
        // cards.erase(cards.begin() + rand_index);
        // cards[rand_index].value = 0;
        // }
        
    std::random_device random_dev;
    std::mt19937       generator(random_dev());

    std::shuffle(cards.begin(), cards.end(), generator);
        // srand(time(NULL));
        // std::shuffle(cards.begin(), cards.end(), rand());
        for(Card card : cards){
            shuffled.push(card);
        }
    
    return shuffled;
}


