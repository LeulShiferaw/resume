#include "card.h"

Card::Card(rank r, suit s, bool ifu):  m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
{} 

int Card::GetValue() const
{
	int value;

	// to be filled with content
	switch(m_Rank)
	{
		case JACK: case QUEEN: case KING:
			value=m_IsFaceUp*10;
			break;
		default:
			value=m_IsFaceUp*m_Rank;
			break;
	}

	return value;
}

void Card::Flip()
{
    m_IsFaceUp = !(m_IsFaceUp);
}

//overloads << operator so Card object can be sent to cout
std::ostream& operator<<(std::ostream& os, const Card& aCard)
{
    const std::string RANKS[] = {"0", "A", "2", "3", "4", "5", "6", "7", "8", "9", 
                            "10", "J", "Q", "K"};
    const std::string SUITS[] = {"c", "d", "h", "s"};

    if (aCard.m_IsFaceUp)
    {
        os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
    }
    else
    {
        os << "XX";
    }

    return os;
}
