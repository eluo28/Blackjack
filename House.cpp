#include "House.h"
House::House(std::string name) {
	m_name = name;
}

void House::InitialDraw() {

}

std::string House::getName() {
	return m_name;
}