#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <ctime>
#include "deck.h"

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
const int decksize = 52;
const int GamesToPlay = 200;

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


void playerDraw(){
    Card drawnCard = Deck.top();
    Deck.pop();
    playerScore += drawnCard.value;
    cout << "Player drew " << drawnCard.suit << " " << drawnCard.value << endl;
}

bool playerHit(){
    
    while(playerScore < 16){
        
        playerDraw();
    }
    if(playerScore > 21){
        return false;
    }
    cout << "Players score for game number " << gamesPlayed << " was " << playerScore << endl;
    return true;
}


void dealerDraw(){
    Card drawnCard = Deck.top();
    Deck.pop();
    dealerScore += drawnCard.value;
        cout << "Dealer drew " << drawnCard.suit << " " << drawnCard.value << endl;

}

bool dealerHit(){
    while(dealerScore<playerScore){
        dealerDraw();
    }
    if(dealerScore > 21){
        return false;
    }
        cout << "Dealers score for game number " << gamesPlayed << " was " << dealerScore << endl;

    return true;
}

void clearDeck(){
    for( int i =0; i < decksize; i++){
        if(!Deck.empty()){
            Deck.pop();
        }
    }
}

void newRound(){
    cout << "New round has started" << endl;
    clearDeck();
    Deck = shuffleDeck(Cards);
    print_deck(Deck);
    gamesPlayed++;
    playerScore =0;
    dealerScore=0;
    if(playerHit() && !dealerHit()){
        
        playerWins++;
        cout << "Player won" <<endl;
    }
    else{
        dealerWins++;
        cout << "Dealer won" << endl;
    }
    cout << "Round end" << endl;
}

void play_game(){
    cout << "play_game was called" << endl;
    for(int i =0; i < GamesToPlay; i++){
        cout << "this is game number: " << i << endl;
        newRound();
    }
}

int main() { 
    
    cout<<"Hello world"<<endl;
    play_game();
    cout<<"Player won: " << playerWins << " times" << endl;
    cout <<"Dealer won: " << dealerWins << " times" << endl;

    
    
    return 0; }

