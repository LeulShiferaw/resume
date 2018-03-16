#include "hand.h"

Hand::Hand()
{
    m_Cards.reserve(7);
}

Hand::~Hand()  
{
    Clear();
}

void Hand::Add(Card* pCard)
{
    m_Cards.push_back(pCard);
}
 
void Hand::Clear()
{
    //iterate through vector, freeing all memory on the heap
    std::vector<Card*>::iterator iter = m_Cards.begin();
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        delete *iter;
        *iter = 0;
    }
    //clear vector of pointers
    m_Cards.clear();
}

int Hand::GetTotal() const
{
	int total=0;

    // to be filled with content
    // Go through all the cards in the deck check if they have aces if they do count how many
   int n_aces=0;
   for(unsigned int i=0; i<m_Cards.size(); ++i) 
   {
	  if(m_Cards[i]->GetValue()==1)
		  ++n_aces;
	  else total+=m_Cards[i]->GetValue();
   }
	
   //If it can be addes without busting then add it
   if(total<=10 && n_aces)
   { 
	   --n_aces;
	   total+=11;
   }

   //Add the rest as 1
   if(n_aces>0)
   {
	   total+=n_aces;
   }

    return total;
}
