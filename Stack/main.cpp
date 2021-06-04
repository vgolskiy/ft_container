/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 17:20:47 by mskinner          #+#    #+#             */
/*   Updated: 2021/02/28 20:55:10 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//clang++ -Wall -Werror -Wextra -std=c++98 main.cpp

#include "Stack.hpp"
#include <stack>

int main(void)
{
	std::srand(time(NULL));
	std::cout << "STACK CREATION TESTS >>>" << std::endl;
	ft::stack<int>		s1;
	std::stack<int>		ss1;
	ft::stack<char>		s2;
	std::stack<char>	ss2;
	ft::stack<char*>	s3;
	std::stack<char*>	ss3;
	ft::stack<char**>	s4;
	std::stack<char**>	ss4;
	ft::stack<float>	s5;
	std::stack<float>	ss5;
	ft::stack<std::string>	s40;
	std::stack<std::string>	ss40;

	std::cout << "stack 1 size: " << s1.size() << std::endl;
	std::cout << "stack 2 size: " << s2.size() << std::endl;
	std::cout << "stack 3 size: " << s3.size() << std::endl;
	std::cout << "stack 4 size: " << s4.size() << std::endl;
	std::cout << "stack 5 size: " << s5.size() << std::endl;
	std::cout << "stack 5 size: " << s40.size() << std::endl;

	std::cout << "is stack 1 empty: " << s1.empty() << std::endl;
	std::cout << "is stack 2 empty: " << s2.empty() << std::endl;
	std::cout << "is stack 3 empty: " << s3.empty() << std::endl;
	std::cout << "is stack 4 empty: " << s4.empty() << std::endl;
	std::cout << "is stack 5 empty: " << s5.empty() << std::endl;
	std::cout << "is stack 5 empty: " << s40.empty() << std::endl;

	std::cout << std::endl << "STACK PUSH, TOP AND POP TESTS >>>" << std::endl;
	s1.push(1);
	s1.push(0);
	s1.push(3);

	std::cout << "ft_: size: " << s1.size() << std::endl;
  	std::cout << "Popping out elements:";
  	while (!s1.empty()) {
    	std::cout << ' ' << s1.top();
    	s1.pop();
	}
  	std::cout << std::endl;

	ss1.push(1);
	ss1.push(0);
	ss1.push(3);

	std::cout << "std: size: " << ss1.size() << std::endl;
  	std::cout << "Popping out elements:";
  	while (!ss1.empty()) {
    	std::cout << ' ' << ss1.top();
    	ss1.pop();
	}
  	std::cout << std::endl;

	std::cout << std::endl << "STACK COPYING TESTS >>>" << std::endl;
	s40.push("Yoda");
	s40.push("says");
	s40.push("need");
	s40.push("push");
	s40.push("that");

	ft::stack<std::string>	cs40(s40);
	std::cout << "orig: size: " << s40.size() << std::endl;
  	std::cout << "Popping out elements:";
  	while (!s40.empty()) {
    	std::cout << ' ' << s40.top();
    	s40.pop();
	}
  	std::cout << std::endl;

	std::cout << "copy: size: " << cs40.size() << std::endl;
  	std::cout << "Popping out elements:";
  	while (!cs40.empty()) {
    	std::cout << ' ' << cs40.top();
    	cs40.pop();
	}
  	std::cout << std::endl;

	std::cout << std::endl << "STACK ASSIGMENT OPERATOR= TESTS >>>" << std::endl;
	ft::stack<char>		s20;

	s20.push('A');
	s20.push('B');

	s2.push('c');
	s2.push('d');
	s2.push('e');

	s20 = s2;

  	std::cout << "Popping out copy elements:";
  	while (!s20.empty()) {
    	std::cout << ' ' << s20.top();
    	s20.pop();
	}
  	std::cout << std::endl;
	
	std::cout << std::endl << "stack COMPARISON TESTS >>>" << std::endl;
	std::stack<char>	ss20;
	ss20.push('A');
	ss20.push('B');

	s20.push('A');
	s20.push('B');

	ss2.push('c');
	ss2.push('d');
	ss2.push('e');

	std::cout << "std: equal: " << (ss2 == ss20) << ", not equal: " << (ss2 != ss20);
	std::cout << ", >: " << (ss2 > ss20) << ", >=: " << (ss2 >= ss20) << ", <: " << (ss2 < ss20);
	std::cout << ", <=: " << (ss2 <= ss20) << std::endl;
	std::cout << "ft_: equal: " << (s2 == s20) << ", not equal: " << (s2 != s20);
	std::cout << ", >: " << (s2 > s20) << ", >=: " << (s2 >= s20) << ", <: " << (s2 < s20);
	std::cout << ", <=: " << (s2 <= s20) << std::endl;
};

