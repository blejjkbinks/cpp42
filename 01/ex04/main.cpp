#include <fstream>
#include <iostream>
#include <string>

int	printUsage(const char *s);

int	printError(std::string s);

int	openFiles(std::ifstream *stream_in, std::ofstream *stream_out,
				std::string file_in, std::string file_out);

int	sedLoser(std::ifstream *stream_in, std::ofstream *stream_out,
	std::string s1, std::string s2);

void	ft_replace(std::string *buff, std::string s1, std::string s2);

int	main(int argc, char **argv)
{
	std::ifstream	stream_in;
	std::ofstream	stream_out;
	std::string		file_in, file_out;

	if (argc != 4)
		return (printUsage(argv[0]));
	file_in = argv[1];
	file_out = file_in;
	file_out.append(".replace");
	if (openFiles(&stream_in, &stream_out, file_in, file_out))
		return (2);
	int	ret = sedLoser(&stream_in, &stream_out, argv[2], argv[3]);
	stream_in.close();
	stream_out.close();
	return (ret);
}

int	sedLoser(std::ifstream *stream_in, std::ofstream *stream_out,
	std::string s1, std::string s2)
{
	std::string	buff;

	while (std::getline(*stream_in, buff))
	{
		if (stream_in->fail())
			return (1);
		ft_replace(&buff, s1, s2);
		*stream_out << buff;
		if (!stream_in->eof())
			*stream_out << std::endl;
	}
	return (0);
}

void	ft_replace(std::string *buff, std::string s1, std::string s2)
{
	std::string	result;
	std::size_t	pos;
	std::size_t	start = 0;

	while ((pos = buff->find(s1, start)) != std::string::npos)
	{
		result += buff->substr(start, pos - start);
		result += s2;
		start = pos + s1.length();
	}
	result += buff->substr(start);
	*buff = result;
}


int	openFiles(std::ifstream *stream_in, std::ofstream *stream_out,
	std::string file_in, std::string file_out)
{
	stream_in->open(file_in.c_str(), std::ifstream::in);
	if (!stream_in->good())
		return (printError(file_in));
	stream_out->open(file_out.c_str(), std::ofstream::out | std::ofstream::trunc);
	if (!stream_out->good())
	{
		stream_in->close();
		return (printError(file_out));
	}
	return (0);
}

int	printError(std::string s)
{
	std::cerr << "Error: " << s << ": ";
	std::cerr << strerror(errno) << std::endl;
	return (1);
}

int	printUsage(const char *s)
{
	std::cout << "usage: " << s << " ";
	std::cout << "<filename> <str to find> <str to replace>";
	std::cout << std::endl;
	return (1);
}