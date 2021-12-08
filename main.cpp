#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Card{
    public:
string suit;
int value;
    Card(string s, int v){
        suit = s;
        value = v;
    }
};

stack<Card> Deck;
vector<Card> Cards = {{"2 of hearts", 2},{"3 of hearts", 3},{"4 of hearts", 4}, {"5 of hearts", 5}};

stack<Card> shuffleDeck(vector<Card> &cards){
    stack<Card> shuffledDeck;
    while(!cards.empty()){
        size_t rand_index = rand() % cards.size();
        shuffledDeck.push(cards[rand_index]);
        //erase function for vectors, call the begin func then add the index you want to erase
        cards.erase(cards.begin() + rand_index);
    }
    return shuffledDeck;
}

void print_deck(stack<Card> &deck){
    for(int i =0; i < deck.size(); i++){
        
        deck.pop();
        Card currentCard = deck.top();
        std::cout << currentCard.suit << std::endl;
    }
}

int main() { 
    
    cout << "Hello world" << endl;
    stack<Card> deck;
    deck = shuffleDeck(Cards);
    print_deck(deck);
    
    return 0; }
