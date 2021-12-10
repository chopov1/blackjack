#include "utils.h"
#include <iostream>
#include <vector>
#include <stack>
#include "deck.h"
#include "card.h"


using namespace std;



//is there a way to access card class and shuffletest directly from main.cpp? or do I need to create copies here and run this file seperatly?


//this seems like a very inefficent way to test in terms of memory use as I have to re create this large data structure

    

//why do we put public here? would this not be taken care of when we make the class in utils.h?
class DeckTestHarness : public AbstractTestHarness{

private: 
//what is this called where we just call the class name as a function to create an instance of it?
//vector<Card> testcards = initCards();


public:
    DeckTestHarness(){
        register_test_func("deckShuffled", [this]()-> void { assert_equal((size_t)52, shuffleDeck(Cards).size());});
        register_test_func("deckShuffledfail", [this]()-> void { assert_equal((size_t)50, shuffleDeck(Cards).size());});
    }
};

class GlobalTestManager : public TestManager{
    public:
    GlobalTestManager(){add_test("DeckTests", DeckTestHarness());};
};

int main() {

    GlobalTestManager tm = GlobalTestManager();
    tm.execute();
    return 0;
}
