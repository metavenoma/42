/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          stringReplacer.cpp                            ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-05-06                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include <iostream>
#include <fstream>
#include <string>

void	customReplace(std::string &str, const std::string &s1, const std::string &s2)
{
	size_t pos = 0;
	while ((pos = str.find(s1, pos)) != std::string::npos)
	{
		str.erase(pos, s1.length());
		str.insert(pos, s2);
		pos += s2.length();
	}
}

void	stringReplacer(const std::string& filename, const std::string& s1, const std::string& s2)
{
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Input file cannot be opened" << std::endl;
		return;
	}
	std::string	filename_replace = filename;
	filename_replace.append(".replace");
	std::ofstream outputFile(filename_replace.c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "Output file cannot be created" << std::endl;
		inputFile.close();
		return;
	}

	std::string file;
	while (std::getline(inputFile, file))
	{
		customReplace(file, s1, s2);
		outputFile << file << std::endl;
	}

	inputFile.close();
	outputFile.close();
	std::cout << "Replacement file created successfully! Output written to " << filename << ".replace" << std::endl;
}
