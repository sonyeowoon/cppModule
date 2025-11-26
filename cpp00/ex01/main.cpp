#include "PhoneBook.hpp"
#include <iostream>

int	main() {
	PhoneBook pb;
	std::string input;

	while (true) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, input))
			break;
		if (input == "ADD") {
			pb.addPB();
		} else if (input == "SEARCH") {
			pb.searchPB();
			if (pb.size() == 0) {
				std::cout << "Empty." << std::endl;
				continue;
			}
			std::cout << "Index to display: ";
			std::string s; if (!std::getline(std::cin, s)) break;
			bool ok = !s.empty();
			for (size_t i = 0; i < s.size(); ++i)
				if (s[i] < '0' || s[i] > '9') ok = false;
			if (!ok) {
				std::cout << "Invalid index.\n";
				continue;
			}
			int idx = 0;
			for (size_t i = 0; i < s.size(); i++)
				idx = idx * 10 + (s[i] - '0');
			pb.showByIndex(idx);
		} else if (input == "EXIT") {
			break;
		} else if (input.empty()) {
			continue;
		} else {
			std::cout << "Unknown command.\n";
		}
	}
	return 0;
}
