#include <string>
#include <iostream>
#include <fstream>

static	std::string replaceLine(std::string& src, std::string& s1, std::string& s2) {
	if (s1.empty())
		return src;
	
	std::string	result;
	std::string::size_type	pos = 0;
	std::string::size_type	found;

	while ((found = src.find(s1, pos)) != std::string::npos) {
		result.append(src, pos, found - pos);
		result.append(s2);
		pos = found + s1.length();
	}
	result.append(src, pos, src.length() - pos);
	return result;
}

int	main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string	filename = av[1];
	std::string	s1 = av[2];
	std::string	s2 = av[3];

	std::ifstream in(filename.c_str());
	if (!in) {
		std::cerr << "Error: cannot open input file." << std::endl;
		return 1;
	}
	std::string outfile = filename + ".replace";
	std::ofstream out(outfile.c_str());
	if (!out) {
		std::cerr << "Error: cannot open output file." << std::endl;
		return 1;
	}
	std::string line;
	while (std::getline(in, line)) {
		out << replaceLine(line, s1, s2);
		if (!in.eof())
			out << std::endl;
	}

	in.close();
	out.close();
	return 0;
}
