#include "Hand.h"

Hand::Hand() {
	m_hand.reserve(7);

}

Hand::~Hand() {
	Clear();

}

void Hand::AddCard(Card* card) {
	card->Flip();
	m_hand.push_back(card);
}

void Hand::Clear()
{
	std::vector<Card*>::iterator iter = m_hand.begin();
	for (iter = m_hand.begin(); iter != m_hand.end(); ++iter)
	{
		delete* iter;
		*iter = 0;
	}

	m_hand.clear();
}

void Hand::FlipFirstCard() {
	m_hand.front()->Flip();
}