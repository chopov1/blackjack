#pragma once
#include <iostream>
#include <functional>

using namespace std;

const int GamesToPlay = 200;


void testNewRound(){};

int play_game(const function<void()> &newround, bool isTest){
    cout << "play_game was called" << endl;
    int gamesplayed = 0;
    for(int i = 0; i < GamesToPlay; i++){
        if(!isTest){
            cout << "this is game number: " << i << endl;
        }
        newround();
        gamesplayed++;
    }
    return gamesplayed;
}