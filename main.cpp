#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <ctime>
#include "deck.h"
#include <functional>
#include "game.h"

using namespace std;

// class Card{
//     public:
//   string suit;
//   int value;
//   Card(string s, int v){
//       suit = s;
//       value =v;
//   }

// };

stack<Card> Deck;

int playerScore =0;
int playerWins =0;
int dealerScore =0;
int dealerWins=0;
int gamesPlayed = 0;

// stack<Card> shuffleDeck(vector<Card> cards){

//     stack<Card> shuffled;
//     while(!cards.empty()){
//         srand(time(NULL));
//         size_t rand_index = rand() % cards.size();
//         shuffled.push(cards[rand_index]);
//         cards.erase(cards.begin() + rand_index);
//     }
//     return shuffled;
// }

void print_deck(stack<Card> deck){
    
    for(int i =0; i < decksize; i++){
        Card current = deck.top();
        deck.pop();
        cout << "current is "<<current.suit << endl;
    }
    
}


void playerDraw(stack<Card> &deck){
    Card drawnCard = deck.top();
    deck.pop();
    playerScore += drawnCard.value;
    cout << "Player drew " << drawnCard.suit << " " << drawnCard.value << endl;
}

bool playerHit(stack<Card> &deck){
    
    while(playerScore < 16){
        
        playerDraw(deck);
    }
    if(playerScore > 21){
        return false;
    }
    cout << "Players score for game number " << gamesPlayed << " was " << playerScore << endl;
    return true;
}


void dealerDraw(stack<Card> &deck){
    Card drawnCard = deck.top();
    deck.pop();
    dealerScore += drawnCard.value;
        cout << "Dealer drew " << drawnCard.suit << " " << drawnCard.value << endl;

}

bool dealerHit(stack<Card> &deck){
    while(dealerScore<playerScore){
        dealerDraw(deck);
    }
    if(dealerScore > 21){
        return false;
    }
        cout << "Dealers score for game number " << gamesPlayed << " was " << dealerScore << endl;

    return true;
}



void newRound(){
    cout << "New round has started" << endl;
    //stack<Card>
    clearDeck(Deck);
    Deck = shuffleDeck(Cards);
    print_deck(Deck);
    gamesPlayed++;
    playerScore =0;
    dealerScore=0;
    if(playerHit(Deck) && !dealerHit(Deck)){
        
        playerWins++;
        cout << "Player won" <<endl;
    }
    else{
        dealerWins++;
        cout << "Dealer won" << endl;
    }
    cout << "Round end" << endl;
}



int main() { 
    
    cout<<"Hello world"<<endl;
    play_game(newRound, false);
    cout<<"Player won: " << playerWins << " times" << endl;
    cout <<"Dealer won: " << dealerWins << " times" << endl;

    
    
    return 0; }

