#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void    gnl_cpp(std::string &str, std::string first, std::string secong)
{
	if (first.empty())
	{
		std::cout << "Error: string to replace cannot be empty." << std::endl;
		return ;
	}
    size_t i = 0;
    while((i = str.find(first, i)) != std::string::npos)
    {
        str = str.substr(0, i) + secong + str.substr(i + first.length());
        i += secong.length();
    }
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Usage : ./main file_in string1 string2" << "\n";
        return 0;
    }
    std::string	in_file = argv[1];
	std::string	first = argv[2];
	std::string	second = argv[3];
	std::string	line;
	std::string	out_file = in_file + ".replace";

	if (first.empty())
    {
        std::cout << "Error: string to replace cannot be empty." << std::endl;
        return 1;
    }
	std::ifstream	input(in_file.c_str());
	std::ofstream	output(out_file.c_str());
	if (input.is_open())
	{
		while (std::getline(input, line))
		{
			gnl_cpp(line, first, second);
			output << line;
			if (!input.eof())
				output << std::endl;
		}
		input.close();
		output.close();
	}
	else
	{
		std::cout << "Error: cannot open file." << std::endl;
		return 1;
	}
	return 0;
}