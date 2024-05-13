/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          main.cpp                                      ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-05-07                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "easyfind.hpp"
#include "easyfind.tpp"
#include <vector>
#include <list>
#include <deque>

int	main(void)
{
	std::vector<int>	vec;
	std::list<int>		lst;
	std::deque<int>		deq;
	int			array[7] = {-128283, 18182, 0, INT_MIN, INT_MAX, 42, 420};

	std::cout << "\nTesting with vector\n" << std::endl;
	test(vec, array, 7, 420);
	test(vec, array, 7, -1);
	test(vec, array, 7, INT_MIN);
	std::cout << "\nTesting with list\n" << std::endl;
	test(lst, array, 7, 420);
	test(lst, array, 7, 18183);
	test(lst, array, 7, INT_MAX);
	std::cout << "\nTesting with deque\n" << std::endl;
	test(deq, array, 7, 420);
	test(deq, array, 7, -9874);
	test(deq, array, 7, 18182);
	return (0);
}
