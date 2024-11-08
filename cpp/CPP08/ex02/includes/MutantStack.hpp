/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          MutantStack.tpp                               ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-05-15                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#pragma once

#include <iostream>
#include <deque>
#include <stack>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
	private:
		typedef	std::stack<T, Container> StackType;
	public:
		typedef typename	Container::iterator			iterator;
		typedef typename	Container::const_iterator		const_iterator;
		typedef typename	Container::reverse_iterator		reverse_iterator;
		typedef typename	Container::const_reverse_iterator	const_reverse_iterator;

		MutantStack(void);
		MutantStack(const MutantStack &mutantstack);
		
		~MutantStack(void);

		MutantStack &operator=(const MutantStack &mutantstack);

		iterator		begin(void);
		const_iterator		begin(void) const;
		iterator		end(void);
		const_iterator		end(void) const;
		reverse_iterator	rbegin(void);
		const_reverse_iterator	rbegin(void) const;
		reverse_iterator	rend(void);
		const_reverse_iterator	rend(void) const;
};

template<typename T, typename Container>
void pdfTest(MutantStack<T, Container> mstack);

#include "MutantStack.tpp"
