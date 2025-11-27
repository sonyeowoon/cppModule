#include "Brain.hpp"

Brain::Brain() {
	std::cout << "[Brain] Default constructor\n" << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout << "[Brain] Copy constructor\n" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
}

Brain&	Brain::operator=(const Brain& other) {
	std::cout << "[Brain] Copy assignment\n";
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "[Brain] Destructor\n";
}

void	Brain::setIdea(int idx, const std::string& idea) {
	if (idx < 0 || idx >= 100)
		return;
	ideas[idx] = idea;
}

std::string Brain::getIdea(int idx) const {
	if (idx < 0 || idx >= 100)
		return "";
	return ideas[idx];
}
