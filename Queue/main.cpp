/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 17:20:47 by mskinner          #+#    #+#             */
/*   Updated: 2021/06/04 17:55:08 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//clang++ -Wall -Werror -Wextra -std=c++98 main.cpp

#include "Queue.hpp"
#include <queue>

int main(void)
{
	std::srand(time(NULL));
	std::cout << "queue CREATION TESTS >>>" << std::endl;
	ft::queue<int>		q1;
	std::queue<int>		qq1;
	ft::queue<char>		q2;
	std::queue<char>	qq2;
	ft::queue<char*>	q3;
	std::queue<char*>	qq3;
	ft::queue<char**>	q4;
	std::queue<char**>	qq4;
	ft::queue<float>	q5;
	std::queue<float>	qq5;
	ft::queue<std::string>	q40;
	std::queue<std::string>	qq40;

	std::cout << "queue 1 size: " << q1.size() << std::endl;
	std::cout << "queue 2 size: " << q2.size() << std::endl;
	std::cout << "queue 3 size: " << q3.size() << std::endl;
	std::cout << "queue 4 size: " << q4.size() << std::endl;
	std::cout << "queue 5 size: " << q5.size() << std::endl;
	std::cout << "queue 6 size: " << q40.size() << std::endl;

	std::cout << "is queue 1 empty: " << q1.empty() << std::endl;
	std::cout << "is queue 2 empty: " << q2.empty() << std::endl;
	std::cout << "is queue 3 empty: " << q3.empty() << std::endl;
	std::cout << "is queue 4 empty: " << q4.empty() << std::endl;
	std::cout << "is queue 5 empty: " << q5.empty() << std::endl;
	std::cout << "is queue 6 empty: " << q40.empty() << std::endl;

	std::cout << std::endl << "QUEUE PUSH, FRONT, BACK AND POP TESTS >>>" << std::endl;
	q1.push(1);
	q1.push(0);
	q1.push(3);

	std::cout << "ft_: size: " << q1.size() << std::endl;
  	std::cout << "Popping out elements:";
  	while (!q1.empty()) {
    	std::cout << ' ' << q1.back();
    	q1.pop();
	}
  	std::cout << std::endl;

	qq1.push(1);
	qq1.push(0);
	qq1.push(3);

	std::cout << "std: size: " << qq1.size() << std::endl;
  	std::cout << "Popping out elements:";
  	while (!qq1.empty()) {
    	std::cout << ' ' << qq1.back();
    	qq1.pop();
	}
  	std::cout << std::endl;

	q40.push("Yoda");
	q40.push("says");
	q40.push("need");
	q40.push("push");
	q40.push("that");

	std::cout << "ft_: size: " << q40.size() << std::endl;
  	std::cout << "Popping out elements:";
  	while (!q40.empty()) {
    	std::cout << ' ' << q40.front();
    	q40.pop();
	}
  	std::cout << std::endl;

	qq40.push("Yoda");
	qq40.push("says");
	qq40.push("need");
	qq40.push("push");
	qq40.push("that");

	std::cout << "std: size: " << qq40.size() << std::endl;
  	std::cout << "Popping out elements:";
  	while (!qq40.empty()) {
    	std::cout << ' ' << qq40.front();
    	qq40.pop();
	}
  	std::cout << std::endl;

	std::cout << std::endl << "QUEUE COPYING TESTS >>>" << std::endl;
	q40.push("Yoda");
	q40.push("says");
	q40.push("need");
	q40.push("push");
	q40.push("that");

	ft::queue<std::string>	cq40(q40);
	std::cout << "orig: size: " << q40.size() << std::endl;
  	std::cout << "Popping out elements:";
  	while (!q40.empty()) {
    	std::cout << ' ' << q40.back();
    	q40.pop();
	}
  	std::cout << std::endl;

	std::cout << "copy: size: " << cq40.size() << std::endl;
  	std::cout << "Popping out elements:";
  	while (!cq40.empty()) {
    	std::cout << ' ' << cq40.back();
    	cq40.pop();
	}
  	std::cout << std::endl;

	std::cout << std::endl << "QUEUE ASSIGMENT OPERATOR= TESTS >>>" << std::endl;
	ft::queue<char>		q20;

	q20.push('A');
	q20.push('B');

	q2.push('c');
	q2.push('d');
	q2.push('e');

	q20 = q2;
	
  	std::cout << "Popping out copy elements:";
  	while (!q20.empty()) {
    	std::cout << ' ' << q20.back();
    	q20.pop();
	}
  	std::cout << std::endl;
	
	std::cout << std::endl << "queue COMPARISON TESTS >>>" << std::endl;
	std::queue<char>	qq20;
	qq20.push('A');
	qq20.push('B');

	q20.push('A');
	q20.push('B');

	qq2.push('c');
	qq2.push('d');
	qq2.push('e');

	std::cout << "std: equal: " << (qq2 == qq20) << ", not equal: " << (qq2 != qq20);
	std::cout << ", >: " << (qq2 > qq20) << ", >=: " << (qq2 >= qq20) << ", <: " << (qq2 < qq20);
	std::cout << ", <=: " << (qq2 <= qq20) << std::endl;
	std::cout << "ft_: equal: " << (q2 == q20) << ", not equal: " << (q2 != q20);
	std::cout << ", >: " << (q2 > q20) << ", >=: " << (q2 >= q20) << ", <: " << (q2 < q20);
	std::cout << ", <=: " << (q2 <= q20) << std::endl;
};

