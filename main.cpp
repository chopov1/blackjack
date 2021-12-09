
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <ctime>

using namespace std;

class Card{
    public:
  string suit;
  int value;
  Card(string s, int v){
      suit = s;
      value =v;
  }

};

stack<Card> Deck;
vector<Card> Cards = {{"a of hearts", 1},{"2 of hearts", 2}, {"3 of hearts", 3}, {"4 of hearts", 4}, {"5 of hearts", 5}, {"6 of hearts", 6}, {"7 of hearts", 7}, {"8 of hearts", 8}, {"9 of hearts", 9}, {"10 of hearts", 10}, {"j of hearts", 11}, {"q of hearts", 12}, {"k of hearts", 13},
{"a of clubs", 1},{"2 of clubs", 2}, {"3 of clubs", 3}, {"4 of clubs", 4}, {"5 of clubs", 5}, {"6 of clubs", 6}, {"7 of clubs", 7}, {"8 of clubs", 8}, {"9 of clubs", 9}, {"10 of clubs", 10}, {"j of clubs", 11}, {"q of clubs", 12}, {"k of clubs", 13},
{"a of diamonds", 1},{"2 of diamonds", 2}, {"3 of diamonds", 3}, {"4 of diamonds", 4}, {"5 of diamonds", 5}, {"6 of diamonds", 6}, {"7 of diamonds", 7}, {"8 of diamonds", 8}, {"9 of diamonds", 9}, {"10 of diamonds", 10}, {"j of diamonds", 11}, {"q of diamonds", 12}, {"k of diamonds", 13},
{"a of spades", 1},{"2 of spades", 2}, {"3 of spades", 3}, {"4 of spades", 4}, {"5 of spades", 5}, {"6 of spades", 6}, {"7 of spades", 7}, {"8 of spades", 8}, {"9 of spades", 9}, {"10 of spades", 10}, {"j of spades", 11}, {"q of spades", 12}, {"k of spades", 13}};
const int decksize = 52;

int playerScore =0;
int playerWins =0;
int dealerScore =0;
int dealerWins=0;
int gamesPlayed=0;

stack<Card> shuffleDeck(vector<Card> cards){

    stack<Card> shuffled;
    while(!cards.empty()){
        srand(time(NULL));
        size_t rand_index = rand() % cards.size();
        shuffled.push(cards[rand_index]);
        cards.erase(cards.begin() + rand_index);
    }
    return shuffled;
}

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
    for(int i =0; i < 100; i++){
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

