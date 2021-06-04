/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 10:51:49 by mskinner          #+#    #+#             */
/*   Updated: 2021/06/04 18:18:31 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//clang++ -Wall -Werror -Wextra --std=c++98 main.cpp

#include "Map.hpp"
#include <map>

//Inorder traversal print
template < typename Key, typename T >
void	printMap(ft::map<Key, T> &m) {
	typename ft::map<Key, T>::iterator	it;

	std::cout << "size: " << m.size() << std::endl;
	for (it = m.begin(); it != m.end(); ++it) {
		std::cout << "ft_: first: " << it->first;
		std::cout << ", second: " << it->second << std::endl;
	}
	
	typename ft::map<Key, T>::reverse_iterator	rit;

	for (rit = m.rbegin(); rit != m.rend(); ++rit) {
		std::cout << "ft_rev: first: " << rit->first;
		std::cout << ", second: " << rit->second << std::endl;
	}
};

template < typename Key, typename T >
void	printConstantMap(const ft::map<Key, T> &m) {
	typename ft::map<Key, T>::const_iterator	it;

	std::cout << "size: " << m.size() << std::endl;
	for (it = m.begin(); it != m.end(); ++it) {
		std::cout << "cft: first: " << it->first;
		std::cout << ", second: " << it->second << std::endl;
	}
	
	typename ft::map<Key, T>::const_reverse_iterator	rit;

	for (rit = m.rbegin(); rit != m.rend(); ++rit) {
		std::cout << "cft_rev: first: " << rit->first;
		std::cout << ", second: " << rit->second << std::endl;
	}
};

template < typename Key, typename T >
void	printMap(std::map<Key, T> &m) {
	typename std::map<Key, T>::iterator	it;

	std::cout << "size: " << m.size() << std::endl;
	for (it = m.begin(); it != m.end(); ++it) {
		std::cout << "std: first: " << it->first;
		std::cout << ", second: " << it->second << std::endl;
	}
	
	typename std::map<Key, T>::reverse_iterator	rit;

	for (rit = m.rbegin(); rit != m.rend(); ++rit) {
		std::cout << "std_rev: first: " << rit->first;
		std::cout << ", second: " << rit->second << std::endl;
	}
};

//Level traversal print
template < typename Key, typename T >
void	printLevelNode(ft::Node<Key, T> *n) {
	if (!n || (n->_color == 2))
		return ;
	std::cout << "ft_: first: " << n->_content.first;
	std::cout << ", second: " << n->_content.second;
	std::cout << ", color: " << n->_color << std::endl;

	printLevelNode(n->_left);
	printLevelNode(n->_right);
};

template < typename Key, typename T >
void	printLevelMap(ft::map<Key, T> &m) {
	typename ft::map<Key, T>::iterator	it = m.begin();

	while (it.get_root()->_parent)
		it++;
	std::cout << std::endl << "Level traversal:" << std::endl;
	printLevelNode(it.get_root());
	std::cout << std::endl;
};

int	main() {
	std::cout << "MAP CREATION TESTS >>>" << std::endl;
	ft::map<int, int>		m1;
	std::map<int, int>		sm1;
	ft::map<char, std::string>	m2;
	std::map<char, std::string>	sm2;
	ft::map<int, char*>		m3;
	std::map<int, char*>	sm3;
	ft::map<int, char**>	m4;
	std::map<int, char**>	sm4;
	ft::map<int, float>		m5;
	std::map<int, float>	sm5;
	ft::map<std::string, std::string>	m99;
	std::map<std::string, std::string>	sm99;

	std::cout << "map 1 size: " << m1.size() << std::endl;
	std::cout << "map 2 size: " << m2.size() << std::endl;
	std::cout << "map 3 size: " << m3.size() << std::endl;
	std::cout << "map 4 size: " << m4.size() << std::endl;
	std::cout << "map 5 size: " << m5.size() << std::endl;
	std::cout << "map 6 size: " << m99.size() << std::endl;

	std::cout << "is map 1 empty: " << m1.empty() << std::endl;
	std::cout << "is map 2 empty: " << m2.empty() << std::endl;
	std::cout << "is map 3 empty: " << m3.empty() << std::endl;
	std::cout << "is map 4 empty: " << m4.empty() << std::endl;
	std::cout << "is map 5 empty: " << m5.empty() << std::endl;
	std::cout << "is map 6 empty: " << m99.empty() << std::endl;

	std::cout << "maximal map 1 size: " << m1.max_size() << " vs std: " << sm1.max_size() << std::endl;
	std::cout << "maximal map 2 size: " << m2.max_size() << " vs std: " << sm2.max_size() << std::endl;
	std::cout << "maximal map 3 size: " << m3.max_size() << " vs std: " << sm3.max_size() << std::endl;
	std::cout << "maximal map 4 size: " << m4.max_size() << " vs std: " << sm4.max_size() << std::endl;
	std::cout << "maximal map 5 size: " << m5.max_size() << " vs std: " << sm5.max_size() << std::endl;
	std::cout << "maximal map 6 size: " << m99.max_size() << " vs std: " << sm99.max_size() << std::endl;
	
	std::map<int, int>::iterator sit1;
	ft::map<int, int>::iterator it1;

	for (sit1 = sm1.begin(); sit1 != sm1.end(); ++sit1) {
		std::cout << "std: first: " << sit1->first;
		std::cout << ", second: " << sit1->second << std::endl;
	}
	for (it1 = m1.begin(); it1 != m1.end(); ++it1) {
		std::cout << "ft_: first: " << it1->first;
		std::cout << ", second: " << it1->second << std::endl;
	}

	std::cout << std::endl << "MAP RANGES ASSIGMENT TESTS (INC. CONSTANT CONTAINERS) >>>" << std::endl;
	std::pair<int, int>				arr1[] = {std::make_pair(0, 1), std::make_pair(1, 0), std::make_pair(2, 1)};
	std::pair<char, std::string>	arr2[] = {std::make_pair('a', "bonjour"), std::make_pair('c', "je"), std::make_pair('b', "suis")};

	ft::map<int, int>				m6(arr1, arr1 + 3);
	const ft::map<int, int>			constm6(arr1, arr1 + 3);
	std::map<int, int>				sm6(arr1, arr1 + 3);
	std::cout << "ft_: ";
	printMap(m6);
	std::cout << "ftc: ";
	printConstantMap(constm6);
	std::cout << "std: ";
	printMap(sm6);

	printLevelMap(m6);
	
	ft::map<char, std::string>			m7(arr2, arr2 + 3);
	const ft::map<char, std::string>	constm7(arr2, arr2 + 3);
	std::map<char, std::string>			sm7(arr2, arr2 + 3);
	std::cout << "ft_: ";
	printMap(m7);
	std::cout << "ftc: ";
	printConstantMap(constm7);
	std::cout << "std: ";
	printMap(sm7);

	printLevelMap(m7);
	
	std::cout << std::endl << "MAP COPYING TESTS >>>" << std::endl;
	ft::map<int, int>	cm6(m6);
	std::map<int, int> csm6(sm6);
	std::cout << "orig: ";
	printMap(m6);
	std::cout << "copy: ";
	printMap(cm6);
	std::cout << "std_: ";
	printMap(csm6);
	
	ft::map<char, std::string>	cm7(m7);
	std::map<char, std::string>	csm7(sm7);
	std::cout << "orig: ";
	printMap(m7);
	std::cout << "copy: ";
	printMap(cm7);
	std::cout << "std_: ";
	printMap(csm7);
	
	std::cout << std::endl << "MAP ASSIGMENT OPERATOR= TESTS >>>" << std::endl;
	std::cout << "ft__orig: ";
	printMap(cm6);
	m1 = cm6;
	std::cout << "ft__ass_: ";
	printMap(m1);
	std::cout << "std_orig: ";
	printMap(csm6);
	sm6 = csm6;
	std::cout << "std_ass_: ";
	printMap(sm6);
	
	printLevelMap(m1);

	m2 = cm7;
	std::cout << "ft__orig: ";
	printMap(cm7);
	std::cout << "ft__ass_: ";
	printMap(m2);
	sm2 = csm7;
	std::cout << "std_orig: ";
	printMap(csm7);
	std::cout << "std_ass_: ";
	printMap(sm2);
	
	printLevelMap(m2);
	
	std::cout << std::endl << "MAP OPERATOR[] TESTS >>>: ";
	printMap(m1);
	std::cout << "element with key value 2: " << m1[2] << std::endl;
	std::cout << "adding element with key value 3: " << m1[3] << std::endl;
	m1[3] = 100;
	
	printLevelMap(m1);
	
	printMap(m2);
	std::cout << "element with key value b: " << m2['b'] << std::endl;
	std::cout << "adding element with key value d: " << m2['d'] << std::endl;
	m2['d'] = "new";
	
	printLevelMap(m2);
	
	std::cout << std::endl << "MAP CLEAR TESTS >>>: ";
	std::cout << "before clearing: " << std::endl;
	printMap(m2);
	m2.clear();
	std::cout << "after clearing: " << std::endl;
	printMap(m2);

	std::cout << "map 2 size: " << m2.size() << std::endl;
	
	std::cout << std::endl << "MAP INSERT TESTS >>>: ";
	m2.insert(std::make_pair('e', "add"));
	m2.insert(std::make_pair('d', "suis"));
	m2.insert(std::make_pair('f', "new"));
	m2.insert(std::make_pair('a', "bonjour"));
	m2.insert(std::make_pair('c', "je"));

	printLevelMap(m2);

	sm2.clear();
	sm2.insert(std::make_pair('e', "add"));
	sm2.insert(std::make_pair('d', "suis"));
	sm2.insert(std::make_pair('f', "new"));
	sm2.insert(std::make_pair('a', "bonjour"));
	sm2.insert(std::make_pair('c', "je"));

	ft::map<char, std::string>::iterator	it2 = m2.find('a');
//	ft::map<char, std::string>::iterator	it2 = m2.find('c');
	m2.insert(it2, std::make_pair('b', "add2"));
	printMap(m2);
	printLevelMap(m2);

	std::map<char, std::string>::iterator	sit2 = sm2.find('f');
	sm2.insert(sit2, std::make_pair('b', "add"));
	printMap(sm2);
	
	std::cout << std::endl << "MAP ERASE TESTS >>>: ";
	std::cout << std::endl << "before erasing:";
	m7 = m2;
	printMap(m7);
	it2 = m7.find('a');
	m7.erase(it2);
	std::cout << std::endl << "after erasing:";
	printMap(m7);
	
	std::cout << std::endl << "before erasing:";
	it2 = m7.begin();
	m7.erase(++it2, --m7.end());
	std::cout << std::endl << "after range erasing:";
	printMap(m7);
	
	std::cout << std::endl << "MAP SWAP TESTS >>>: " << std::endl;
	std::cout << "first map before swap:";
	printMap(m1);
	std::cout << "second map before swap:";
	printMap(m6);
	m1.swap(m6);
	std::cout << "first map after swap:";
	printMap(m1);
	std::cout << "second map after swap:";
	printMap(m6);
	
	
	std::cout << std::endl << "MAP COUNT TESTS >>>: ";
	printMap(m2);
	std::cout << m2.count('e') << std::endl;
	std::cout << m2.count('z') << std::endl;

	std::cout << std::endl << "MAP FIND TESTS >>>: ";
	printMap(m2);
	it2 = m2.find('e');
	std::cout << "ft_: first: " << it2->first;
	std::cout << ", second: " << it2->second << std::endl;

	std::cout << std::endl << "MAP BOUND AND EQUAL RANGE TESTS >>>: ";
	printMap(m2);
	printMap(sm2);
	std::cout << "ft_: " << m2.lower_bound('b')->first << std::endl;
	std::cout << "std: " << sm2.lower_bound('b')->first << std::endl;
	std::cout << "ft_: " << m2.upper_bound('b')->first << std::endl;
	std::cout << "std: " << sm2.upper_bound('b')->first << std::endl;

	it2 = m2.equal_range('e').first;
	ft::map<char, std::string>::iterator	it2_2 = m2.equal_range('e').second;
	for (; it2 != it2_2; ++it2) {
		std::cout << "ft_: first: " << it2->first;
		std::cout << ", second: " << it2->second << std::endl;
	}

	sit2 = sm2.equal_range('e').first;
	std::map<char, std::string>::iterator	sit2_2 = sm2.equal_range('e').second;
	for (; sit2 != sit2_2; ++sit2) {
		std::cout << "std: first: " << sit2->first;
		std::cout << ", second: " << sit2->second << std::endl;
	}
	
	std::cout << std::endl << "MAP KEY_COMP TESTS >>>: " << std::endl;
	ft::map<int, char> cont;
	cont.insert(std::make_pair(1, 'a'));
	cont.insert(std::make_pair(2, 'b'));
	cont.insert(std::make_pair(3, 'c'));
	cont.insert(std::make_pair(4, 'd'));
	cont.insert(std::make_pair(5, 'e'));
 
	ft::map<int, char>::key_compare	comp_func = cont.key_comp();
	ft::map<int, char>::iterator	iter;
 
	for (iter = cont.begin(); iter != cont.end(); ++iter) {
		bool before = comp_func(iter->first % 97, 100 % 97);
		bool after = comp_func(100 % 97, iter->first % 97);
 
		std::cout << '(' << iter->first << ',' << iter->second;
		if (!before && !after)
			std::cout << ") equivalent to key 100" << std::endl;
		else if (before)
			std::cout << ") goes before key 100" << std::endl;
		else if (after)
			std::cout << ") goes after key 100" << std::endl;
		else
			assert(0); // Cannot happen
	}

	std::cout << std::endl << "MAP VALUE_COMP TESTS >>>: " << std::endl;
	std::map<char,int>	mymaps;
	mymaps['x']=1001;
	mymaps['y']=2002;
	mymaps['z']=3003;
	
	std::cout << "std: mymap contains:" <<std ::endl;
	std::pair<char,int>			highests = *mymaps.rbegin();
	std::map<char,int>::iterator	its = mymaps.begin();
	while (mymaps.value_comp()(*its, highests)) {
		std::cout << its->first << " => " << its->second << std::endl;
		its++;
	}
	
	ft::map<char,int>	mymap;
	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;
	
	std::cout << "ft_: mymap contains:" <<std ::endl;
	std::pair<char,int>			highest = *mymap.rbegin();
	ft::map<char,int>::iterator	it = mymap.begin();
	while (mymap.value_comp()(*it, highest)) {
		std::cout << it->first << " => " << it->second << std::endl;
		it++;
	}

	std::cout << std::endl << "MAP SWAP TESTS >>>" << std::endl;
	std::cout << "before swap:" << std::endl;
	printMap(m2);
	printMap(m7);
	m2.swap(m7);
	std::cout << "after_ swap:" << std::endl;
	printMap(m2);
	printMap(m7);

	std::cout << std::endl << "MAP COMPARISON TESTS >>>" << std::endl;
	std::cout << "ft_ maps for comparison: " << std::endl;
	printMap(m2);
	printMap(m7);
	std::cout << "ft_: equal: " << (m2 == m7) << ", not equal: " << (m2 != m7);
	std::cout << ", >: " << (m2 > m7) << ", >=: " << (m2 >= m7) << ", <: " << (m2 < m7);
	std::cout << ", <=: " << (m2 <= m7) << std::endl;

	std::map<char, std::string> sm20(m2.begin(), m2.end());
	std::map<char, std::string> sm70(m7.begin(), m7.end());
	std::cout << "std: equal: " << (sm20 == sm70) << ", not equal: " << (sm20 != sm70);
	std::cout << ", >: " << (sm20 > sm70) << ", >=: " << (sm20 >= sm70) << ", <: " << (sm20 < sm70);
	std::cout << ", <=: " << (sm20 <= sm70) << std::endl;
	return (EXIT_SUCCESS);
}
