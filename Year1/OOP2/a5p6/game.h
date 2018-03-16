#ifndef GAME_H
#define GAME_H

#include "deck.h"
#include "house.h"
#include "player.h"

class Game
{
public:
    Game(const std::vector<std::string>& names);
    
    ~Game();
    
    //plays the game of blackjack    
    void Play();

private:
    Deck m_Deck;
    House m_House;
    std::vector<Player> m_Players;  
};

#endif
