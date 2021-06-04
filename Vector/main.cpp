/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:35:09 by mskinner          #+#    #+#             */
/*   Updated: 2021/06/04 17:52:57 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//clang++ -Wall -Werror -Wextra -std=c++98 main.cpp

#include "Vector.hpp"
#include <vector>

typedef bool	(* Compare)(const int &, const int &);

bool	compare(const int &val1, const int &val2) {
	return (val1 < val2);
}

template <typename T>
void    printContainer(ft::vector<T> &cont) {
	typename ft::vector<T>::iterator it;

	std::cout << "size: " << cont.size();
	std::cout << " cap: " << cont.capacity();
	std::cout << " [";
	for (it = cont.begin(); it != cont.end(); ++it)
	{
		if (it != cont.begin())
			std::cout << ", ";
		std::cout << *it;
	}
	std::cout << "] in reverse: ";

	typename ft::vector<T>::reverse_iterator rit;

	std::cout << "[";
	for (rit = cont.rbegin(); rit != cont.rend(); ++rit)
	{
		if (rit != cont.rbegin())
			std::cout << ", ";
		std::cout << *rit;
	}
	std::cout << "]" << std::endl;
}

template <typename T>
void    printConstantContainer(const ft::vector<T> &cont) {
	typename ft::vector<T>::const_iterator it;

	std::cout << "size: " << cont.size();
	std::cout << " cap: " << cont.capacity();
	std::cout << " [";
	for (it = cont.begin(); it != cont.end(); ++it)
	{
		if (it != cont.begin())
			std::cout << ", ";
		std::cout << *it;
	}
	std::cout << "] in reverse: ";

	typename ft::vector<T>::const_reverse_iterator rit;

	std::cout << "[";
	for (rit = cont.rbegin(); rit != cont.rend(); ++rit)
	{
		if (rit != cont.rbegin())
			std::cout << ", ";
		std::cout << *rit;
	}
	std::cout << "]" << std::endl;
}

template <typename T>
void    printContainer(T &cont) {
	typename T::iterator it;

	std::cout << "size: " << cont.size();
	std::cout << " cap: " << cont.capacity();
	std::cout << " [";
	for (it = cont.begin(); it != cont.end(); ++it)
	{
		if (it != cont.begin())
			std::cout << ", ";
		std::cout << *it;
	}
	std::cout << "] in reverse: ";

	typename T::reverse_iterator rit;

	std::cout << "[";
	for (rit = cont.rbegin(); rit != cont.rend(); ++rit)
	{
		if (rit != cont.rbegin())
			std::cout << ", ";
		std::cout << *rit;
	}
	std::cout << "]" << std::endl;
}

template <typename T>
void    printConstantContainer(const T &cont) {
	typename T::const_iterator it;

	std::cout << "size: " << cont.size();
	std::cout << " cap: " << cont.capacity();
	std::cout << " [";
	for (it = cont.begin(); it != cont.end(); ++it)
	{
		if (it != cont.begin())
			std::cout << ", ";
		std::cout << *it;
	}
	std::cout << "] in reverse: ";

	typename T::const_reverse_iterator rit;

	std::cout << "[";
	for (rit = cont.rbegin(); rit != cont.rend(); ++rit)
	{
		if (rit != cont.rbegin())
			std::cout << ", ";
		std::cout << *rit;
	}
	std::cout << "]" << std::endl;
}

int main(void)
{
	std::srand(time(NULL));
	std::cout << "vector CREATION TESTS >>>" << std::endl;
	ft::vector<int>		v1;
	std::vector<int>	sv1;
	ft::vector<char>	v2;
	std::vector<char>	sv2;
	ft::vector<char*>	v3;
	std::vector<char*>	sv3;
	ft::vector<char**>	v4;
	std::vector<char**>	sv4;
	ft::vector<float>	v5;
	std::vector<float>	sv5;
	ft::vector<std::string>	v99;
	std::vector<std::string>	sv99;

	std::cout << "vector 1 size: " << v1.size() << std::endl;
	std::cout << "vector 2 size: " << v2.size() << std::endl;
	std::cout << "vector 3 size: " << v3.size() << std::endl;
	std::cout << "vector 4 size: " << v4.size() << std::endl;
	std::cout << "vector 5 size: " << v5.size() << std::endl;
	std::cout << "vector 6 size: " << v99.size() << std::endl;

	std::cout << "is vector 1 empty: " << v1.empty() << std::endl;
	std::cout << "is vector 2 empty: " << v2.empty() << std::endl;
	std::cout << "is vector 3 empty: " << v3.empty() << std::endl;
	std::cout << "is vector 4 empty: " << v4.empty() << std::endl;
	std::cout << "is vector 5 empty: " << v5.empty() << std::endl;
	std::cout << "is vector 6 empty: " << v99.empty() << std::endl;

	std::cout << "maximal vector 1 size: " << v1.max_size() << " vs std: " << sv1.max_size() << std::endl;
	std::cout << "maximal vector 2 size: " << v2.max_size() << " vs std: " << sv2.max_size() << std::endl;
	std::cout << "maximal vector 3 size: " << v3.max_size() << " vs std: " << sv3.max_size() << std::endl;
	std::cout << "maximal vector 4 size: " << v4.max_size() << " vs std: " << sv4.max_size() << std::endl;
	std::cout << "maximal vector 5 size: " << v5.max_size() << " vs std: " << sv5.max_size() << std::endl;
	std::cout << "maximal vector 6 size: " << v99.max_size() << " vs std: " << sv99.max_size() << std::endl;

	std::cout << std::endl << "vector FILLING AND ITERATION TESTS >>>" << std::endl;
	ft::vector<int> v7(5);
	std::cout << "vector has 5 elements? " << (v7.size() == 5) << std::endl;
	printContainer(v7);
	std::cout << "vector has int front? " << (v7.front() == int()) << std::endl;
	std::cout << "vector has int back? " << (v7.back() == int()) << std::endl;
	std::cout << "every vector element is int? ";
	for (ft::vector<int>::iterator it = v7.begin(); it != v7.end(); ++it) {
		if (it != v7.begin())
			std::cout  << ", ";
		std::cout << (*it == int());
	};
	std::cout << std::endl;

	ft::vector<char> v8(3, 'A');
	std::vector<char> sv8(3, 'A');
	std::cout << "vector has 3 elements? " << (v8.size() == 3) << std::endl;
	printContainer(v8);
	std::cout << "vector has char front? " << (v8.front() == char()) << std::endl;
	std::cout << "vector has char back? " << (v8.back() == char()) << std::endl;
	std::cout << "every vector element is char? ";
	for (ft::vector<char>::iterator it2 = v8.begin(); it2 != v8.end(); ++it2) {
		if (it2 != v8.begin())
			std::cout  << ", ";
		std::cout << (*it2 == char());
	};
	std::cout << std::endl;

	ft::vector<float> v9(14, 42.42f);
	std::cout << "vector has 14 elements? " << (v9.size() == 14) << std::endl;
	printContainer(v9);
	std::cout << "vector has 42.42f front? " << (v9.front() == 42.42f) << std::endl;
	std::cout << "vector has 42.42f back? " << (v9.back() == 42.42f) << std::endl;
	std::cout << "every vector element is 42.42f? ";
	for (ft::vector<float>::iterator it3 = v9.begin(); it3 != v9.end(); ++it3) {
		if (it3 != v9.begin())
			std::cout  << ", ";
		std::cout << (*it3 == 42.42f);
	};
	std::cout << std::endl;

	std::cout << std::endl << "vector RANGES ASSIGMENT TESTS (INC. CONSTANT CONTAINERS) >>>" << std::endl;
	int								arr1[5] = {1, 2, 3, 4, 5};
	std::string						arr2[3] = {"bonjour", "je", "suis"};
	float							arr3[5] = {1.2, 2.3, 3.4, 4.5, 5.6};
	ft::vector<int>					v10(arr1, arr1 + 5);
	const ft::vector<int>			constv10(arr1, arr1 + 5);
	std::vector<int>				sv10(arr1, arr1 + 5);
	std::cout << "ft_: ";
	printContainer(v10);
	std::cout << "ftc: ";
	printConstantContainer(constv10);
	std::cout << "std: ";
	printContainer(sv10);

	ft::vector<std::string>			v11(arr2, arr2 + 3);
	const ft::vector<std::string>	constv11(arr2, arr2 + 3);
	std::vector<std::string>		sv11(arr2, arr2 + 3);
	std::cout << "ft_: ";
	printContainer(v11);
	std::cout << "ftc: ";
	printConstantContainer(constv11);
	std::cout << "std: ";
	printContainer(sv11);


	ft::vector<float>				v12(arr3, arr3 + 5);
	const ft::vector<float>			constv12(arr3, arr3 + 5);
	std::vector<float>				sv12(arr3, arr3 + 5);
	std::cout << "ft_: ";
	printContainer(v12);
	std::cout << "ftc: ";
	printConstantContainer(constv12);
	std::cout << "std: ";
	printContainer(sv12);

	ft::vector<int>					v13(arr1 + 1, arr1 + 4);
	const ft::vector<int>			constv13(arr1 + 1, arr1 + 4);
	std::vector<int>				sv13(arr1 + 1, arr1 + 4);
	std::cout << "ft_: ";
	printContainer(v13);
	std::cout << "ftc: ";
	printConstantContainer(constv13);
	std::cout << "std: ";
	printContainer(sv13);

	std::cout << std::endl << "vector COPYING TESTS >>>" << std::endl;
	ft::vector<int>	cv13(v13);
	std::vector<int> csv13(sv13);
	std::cout << "orig: ";
	printContainer(v13);
	std::cout << "copy: ";
	printContainer(cv13);
	std::cout << "std_: ";
	printContainer(csv13);
	ft::vector<char>	cv8(v8);
	std::vector<char>	csv8(sv8);
	std::cout << "orig: ";
	printContainer(v8);
	std::cout << "copy: ";
	printContainer(cv8);
	std::cout << "std_: ";
	printContainer(csv8);
	ft::vector<std::string>	cv11(v11);
	std::vector<std::string>	csv11(sv11);
	std::cout << "orig: ";
	printContainer(v11);
	std::cout << "copy: ";
	printContainer(cv11);
	std::cout << "std_: ";
	printContainer(csv11);
	ft::vector<float>	cv12(v12);
	std::vector<float>	csv12(sv12);
	std::cout << "orig: ";
	printContainer(v12);
	std::cout << "copy: ";
	printContainer(cv12);
	std::cout << "std_: ";
	printContainer(csv12);

	std::cout << std::endl << "vector ASSIGMENT OPERATOR= TESTS >>>" << std::endl;
	ft::vector<int>		v14(5, 1);
	v14 = cv13;
	std::vector<int>	sv14(5, 1);
	sv14 = csv13;
	std::cout << "ft__orig: ";
	printContainer(cv13);
	std::cout << "ft__ass_: ";
	printContainer(v14);
	std::cout << "std_orig: ";
	printContainer(csv13);
	std::cout << "std_ass_: ";
	printContainer(sv14);
	ft::vector<char>	v15(2, 'Z');
	v15 = cv8;
	std::vector<char>	sv15(2, 'Z');
	sv15 = csv8;
	std::cout << "ft__orig: ";
	printContainer(cv8);
	std::cout << "ft__ass_: ";
	printContainer(v15);
	std::cout << "std_orig: ";
	printContainer(csv8);
	std::cout << "std_ass_: ";
	printContainer(sv15);
	ft::vector<float>	v16 = cv12;
	std::vector<float>	sv16 = csv12;
	std::cout << "orig: ";
	printContainer(cv12);
	std::cout << "ass_: ";
	printContainer(v16);
	std::cout << "std_: ";
	printContainer(sv16);
	ft::vector<std::string>	v17 = cv11;
	std::vector<std::string>	sv17 = csv11;
	std::cout << "orig: ";
	printContainer(cv11);
	std::cout << "ass_: ";
	printContainer(v17);
	std::cout << "std_: ";
	printContainer(sv17);
	ft::vector<float>	empty;
	cv12 = empty;
	std::vector<float>	empty_std;
	csv12 = empty_std;
	std::cout << "orig: ";
	printContainer(empty);
	std::cout << "ass_: ";
	printContainer(cv12);
	std::cout << "std_: ";
	printContainer(csv12);
	
	std::cout << std::endl << "vector ASSIGN MEMBER TESTS >>>: ";
	std::cout << "assigning 3 repeats of 2:";
	ft::vector<int>	vector1;
	vector1.assign(3,2);
	printContainer(vector1);
	std::cout << "assigning 4 last values of vector:";
	printContainer(v10);
	vector1.assign(v10.end() - 4, v10.end());
	printContainer(vector1);
	
	std::cout << std::endl << "vector AT MEMBER TESTS >>>: ";
	printContainer(v12);
	std::cout << "element on 3rd position: " << v12.at(2) << std::endl;
	std::cout << "trying to get out of range: ";
	try {
		v12.at(10);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << "vector OPERATOR[] TESTS >>>: ";
	printContainer(v12);
	std::cout << "element on 3rd position: " << v12[2] << std::endl;

	std::cout << std::endl << "vector FRONT/BACK TESTS >>>" << std::endl;
	std::cout << "ft_: front " << v10.front() << " back " << v10.back() << std::endl;
	std::cout << "ftc: front " << constv10.front() << " back " << constv10.back() << std::endl;
	std::cout << "std: front " << sv10.front() << " back " << sv10.back() << std::endl;

	std::cout << "ft_: front " << v11.front() << " back " << v11.back() << std::endl;
	std::cout << "ftc: front " << constv11.front() << " back " << constv11.back() << std::endl;
	std::cout << "std: front " << sv11.front() << " back " << sv11.back() << std::endl;

	std::cout << "ft_: front " << v12.front() << " back " << v12.back() << std::endl;
	std::cout << "ftc: front " << constv12.front() << " back " << constv12.back() << std::endl;
	std::cout << "std: front " << sv12.front() << " back " << sv12.back() << std::endl;

	std::cout << "ft_: front " << v13.front() << " back " << v13.back() << std::endl;
	std::cout << "ftc: front " << constv13.front() << " back " << constv13.back() << std::endl;
	std::cout << "std: front " << sv13.front() << " back " << sv13.back() << std::endl;
	
 
	std::cout << std::endl << "vector INSERT TESTS >>>";
	std::cout << std::endl << "POSITION + VALUE >>>" << std::endl;
	std::cout << "std_before: ";
	printContainer(sv10);
	sv10.insert(sv10.begin(), 65);
	sv10.insert(sv10.begin() + 2, 65);
	sv10.insert(sv10.end(), 65);
	std::cout << "std_after_: ";
	printContainer(sv10);
	std::cout << "ft__before: ";
	printContainer(v10);
	v10.insert(v10.begin(), 65);
	v10.insert(v10.begin() + 2, 65);
	v10.insert(v10.end(), 65);
	std::cout << "ft__after_: ";
	printContainer(v10);

	std::cout << "std_before: ";
	printContainer(sv8);
	sv8.insert(sv8.begin(), 65);
	sv8.insert(sv8.begin() + 2, 65);
	sv8.insert(sv8.end(), 65);
	std::cout << "std_after_: ";
	printContainer(sv8);
	std::cout << "ft__before: ";
	printContainer(v8);
	v8.insert(v8.begin(), 'B');
	v8.insert(v8.begin() + 2, 'B');
	v8.insert(v8.end(), 'B');
	std::cout << "ft__after_: ";
	printContainer(v8);

	std::cout << "std_before: ";
	printContainer(sv11);
	sv11.insert(sv11.begin(), "add");
	sv11.insert(sv11.begin() + 2, "add");
	sv11.insert(sv11.end(), "add");
	std::cout << "std_after_: ";
	printContainer(sv11);
	std::cout << "ft__before: ";
	printContainer(v11);
	v11.insert(v11.begin(), "add");
	v11.insert(v11.begin() + 2, "add");
	v11.insert(v11.end(), "add");
	std::cout << "ft__after_: ";
	printContainer(v11);

	std::cout << std::endl << "POSITION + VALUE REPEATS >>>" << std::endl;
	std::cout << "std_before: ";
	printContainer(sv10);
	sv10.insert(sv10.begin(), 2, 77);
	sv10.insert(sv10.begin() + 5, 2, 77);
	sv10.insert(sv10.end(), 2, 77);
	std::cout << "std_after_: ";
	printContainer(sv10);
	std::cout << "ft__before: ";
	printContainer(v10);
	v10.insert(v10.begin(), 2, 77);
	v10.insert(v10.begin() + 5, 2, 77);
	v10.insert(v10.end(), 2, 77);
	std::cout << "ft__after_: ";
	printContainer(v10);

	std::cout << "std_before: ";
	printContainer(sv8);
	sv8.insert(sv8.begin(), 2, 'E');
	sv8.insert(sv8.begin() + 4, 2, 'E');
	sv8.insert(sv8.end(), 2, 'E');
	std::cout << "std_after_: ";
	printContainer(sv8);
	std::cout << "ft__before: ";
	printContainer(v8);
	v8.insert(v8.begin(), 2, 'E');
	v8.insert(v8.begin() + 4, 2, 'E');
	v8.insert(v8.end(), 2, 'E');
	std::cout << "ft__after_: ";
	printContainer(v8);

	std::cout << "std_before: ";
	printContainer(sv11);
	sv11.insert(sv11.begin(), 2, "rep");
	sv11.insert(sv11.begin() + 4, 2, "rep");
	sv11.insert(sv11.end(), 2, "rep");
	std::cout << "std_after_: ";
	printContainer(sv11);
	std::cout << "ft__before: ";
	printContainer(v11);
	v11.insert(v11.begin(), 2, "rep");
	v11.insert(v11.begin() + 4, 2, "rep");
	v11.insert(v11.end(), 2, "rep");
	std::cout << "ft__after_: ";
	printContainer(v11);

	std::cout << std::endl << "POSITION + INTERVAL >>>" << std::endl;
	v10.erase(v10.begin(), v10.begin() + 2);
	v10.erase(v10.begin() + 3, v10.begin() + 5);
	v10.erase(v10.end() - 2, v10.end());
	std::cout << "ft_ before: ";
	printContainer(v10);
	sv10.erase(sv10.begin(), sv10.begin() + 2);
	sv10.erase(sv10.begin() + 3, sv10.begin() + 5);
	sv10.erase(sv10.end() - 2, sv10.end());
	std::cout << "std before: ";
	printContainer(sv10);
	v10.insert(v10.begin() + 4, v10.end() - 4, v10.end());
	std::cout << "ft_ after: ";
	printContainer(v10);
	sv10.insert(sv10.begin() + 4, sv10.end() - 4, sv10.end());
	std::cout << "std after: ";
	printContainer(sv10);
	v10.insert(v10.begin() + 4, v10.rbegin(), v10.rbegin() + 4);
	std::cout << "ft_ after: ";
	printContainer(v10);
	sv10.insert(sv10.begin() + 4, sv10.rbegin(), sv10.rbegin() + 4);
	std::cout << "std after: ";
	printContainer(sv10);
	
	std::cout << std::endl << " <<< SOME INTERNAL CLEAR TEST >>>" << std::endl;
	std::cout << "ft_ before: ";
	printContainer(v8);
	std::cout << "std before: ";
	printContainer(sv8);
	int	i = 0;
	
	v8.clear();
	sv8.clear();
	std::cout << "ft_ after: ";
	printContainer(v8);
	std::cout << "std after: ";
	printContainer(sv8);
	
	std::cout << std::endl << "continue to POSITION + INTERVAL >>>" << std::endl;
	while (i++ < 5) {
		v8.push_back(65 + i);
		sv8.push_back(65 + i);
	}
	std::cout << "ft_ before: ";
	printContainer(v8);
	std::cout << "std before: ";
	printContainer(sv8);
	v8.insert(v8.begin() + 3, v8.begin(), v8.begin() + 2);
	std::cout << "ft_ after: ";
	printContainer(v8);
	sv8.insert(sv8.begin() + 3, sv8.begin(), sv8.begin() + 2);
	std::cout << "std after: ";
	printContainer(sv8);
	v8.insert(v8.begin() + 3, v8.end() - 4, v8.end());
	std::cout << "ft_ after: ";
	printContainer(v8);
	sv8.insert(sv8.begin() + 3, sv8.end() - 4, sv8.end());
	std::cout << "std after: ";
	printContainer(sv8);
	v8.insert(v8.begin() + 3, v8.rbegin(), v8.rbegin() + 4);
	std::cout << "ft_ after: ";
	printContainer(v8);
	sv8.insert(sv8.begin() + 3, sv8.rbegin(), sv8.rbegin() + 4);
	std::cout << "std after: ";
	printContainer(sv8);
	
	std::cout << std::endl << "vector ERASE TEST >>>";
	std::cout << std::endl << "POSITION >>>" << std::endl;
	std::cout << "ft_: before deleting the first element: ";
	printContainer(v11);
	ft::vector<std::string>::iterator it11 = v11.begin();
	it11 = v11.erase(it11);
	std::cout << "ft_: _after deleting the first element: ";
	printContainer(v11);
	std::cout << "ft_: vector from the iterator position: ";
	while (it11 != v11.end())
		std::cout << *(it11++) << " ";
	std::cout << std::endl;
	
	std::cout << "std: before deleting the first element: ";
	printContainer(sv11);
	std::vector<std::string>::iterator sit11 = sv11.begin();
	sit11 = sv11.erase(sit11);
	std::cout << "std: _after deleting the first element: ";
	printContainer(sv11);
	std::cout << "std: vector from the iterator position: ";
	while (sit11 != sv11.end())
		std::cout << *(sit11++) << " ";
	std::cout << std::endl;
	
	std::cout << "ft_: before deleting the second element: ";
	printContainer(v11);
	it11 = v11.begin();
	it11 = v11.erase(++it11);
	std::cout << "ft_: _after deleting the second element: ";
	printContainer(v11);
	std::cout << "ft_: vector from the iterator position: ";
	while (it11 != v11.end())
		std::cout << *(it11++) << " ";
	std::cout << std::endl;
	
	std::cout << "std: before deleting the second element: ";
	printContainer(sv11);
	sit11 = sv11.begin();
	sit11 = sv11.erase(++sit11);
	std::cout << "std: _after deleting the second element: ";
	printContainer(sv11);
	std::cout << "std: vector from the iterator position: ";
	while (sit11 != sv11.end())
		std::cout << *(sit11++) << " ";
	std::cout << std::endl;

	std::cout << std::endl << "INTERVAL >>>" << std::endl;
	std::cout << "ft_: before deleting of interval [last - 1, last): ";
	printContainer(v12);
	ft::vector<float>::iterator it12 = v12.begin();
	v12.erase(it12 + 4, v12.end());
	std::cout << "ft_: _after deleting of interval: ";
	printContainer(v12);
	std::cout << "ft_: vector from the iterator position: ";
	while (it12 != v12.end())
		std::cout << *(it12++) << " ";
	std::cout << std::endl;
	
	std::cout << "std: before deleting of interval: ";
	printContainer(sv12);
	std::vector<float>::iterator sit12 = sv12.begin();
	sv12.erase(sit12 + 4, sv12.end());
	std::cout << "std: _after deleting of interval: ";
	printContainer(sv12);
	std::cout << "std: vector from the iterator position: ";
	while (sit12 != sv12.end())
		std::cout << *(sit12++) << " ";
	std::cout << std::endl;

	std::cout << std::endl << "ft_: before deleting of interval [first, first + 2): ";
	printContainer(v12);
	it12 = v12.begin();
	v12.erase(it12, it12 + 2);
	std::cout << "ft_: _after deleting of interval: ";
	printContainer(v12);
	std::cout << "ft_: vector from the iterator position: ";
	while (it12 != v12.end())
		std::cout << *(it12++) << " ";
	std::cout << std::endl;
	
	std::cout << "std: before deleting of interval: ";
	printContainer(sv12);
	sit12 = sv12.begin();
	sv12.erase(sit12, sit12 + 2);
	std::cout << "std: _after deleting of interval: ";
	printContainer(sv12);
	std::cout << "std: vector from the iterator position: ";
	while (sit12 != sv12.end())
		std::cout << *(sit12++) << " ";
	std::cout << std::endl;
	
	std::cout << "vector POP_BACK MEMBER TESTS >>>: ";
	std::cout << "popping 3 end values of previous vector:";
	i = 0;
	while (i++ < 3)
		vector1.pop_back();
	printContainer(vector1);

	std::cout << std::endl << "vector RESIZE MEMBER TESTS >>>" << std::endl;
	ft::vector<int>	vector2(3, 2);
	std::vector<int> c(3,2);
	std::cout << "std: ";
	printContainer(c);
	c.resize(7);
	vector2.resize(7);
	std::cout << "After resize up to 7: " << std::endl;
	std::cout << "std: ";
	printContainer(c);
	std::cout << "ft_: ";
	printContainer(vector2);
	c.resize(2);
	vector2.resize(2);
	std::cout << "After resize down to 2: " << std::endl;
	std::cout << "std: ";
	printContainer(c);
	std::cout << "ft_: ";
	printContainer(vector2);
	
	std::cout << std::endl << "vector SWAP TESTS >>>" << std::endl;
	ft::vector<char>	swapped;
	std::vector<char>	swapped_std;
	cv8.assign(v8.begin(), v8.end());
	v8.swap(swapped);
	sv8.swap(swapped_std);
	std::cout << "ft_: swapped container :";
	printContainer(swapped);
	std::cout << "ft_: original container :";
	printContainer(v8);
	std::cout << "std: swapped container :";
	printContainer(swapped_std);
	std::cout << "std: original container :";
	printContainer(sv8);
	ft::vector<char>	little(5, 'Z');
	std::vector<char>	little_std(5, 'Z');
	cv8.swap(little);
	std::cout << "ft_: swapped little container :";
	printContainer(little);
	std::cout << "ft_: original container :";
	printContainer(cv8);
	little_std.swap(swapped_std);
	std::cout << "std: swapped little container :";
	printContainer(little_std);
	std::cout << "std: original container :";
	printContainer(swapped_std);
	swap(little, cv8);
	std::cout << "ft_: swapped little container :";
	printContainer(little);
	std::cout << "ft_: swapped container :";
	printContainer(cv8);	
	
	std::cout << std::endl << "vector COMPARISON TESTS >>>" << std::endl;
	std::cout << "std vectors for comparison: " << std::endl;
	printContainer(sv13);
	printContainer(csv13);
	std::cout << "std: equal: " << (sv13 == csv13) << ", not equal: " << (sv13 != csv13);
	std::cout << ", >: " << (sv13 > csv13) << ", >=: " << (sv13 >= csv13) << ", <: " << (sv13 < csv13);
	std::cout << ", <=: " << (sv13 <= csv13) << std::endl;
	std::cout << "ft vectors for comparison: " << std::endl;
	printContainer(v13);
	printContainer(cv13);
	std::cout << "ft_: equal: " << (v13 == cv13) << ", not equal: " << (v13 != cv13);
	std::cout << ", >: " << (v13 > cv13) << ", >=: " << (v13 >= cv13) << ", <: " << (v13 < cv13);
	std::cout << ", <=: " << (v13 <= cv13) << std::endl;

	std::cout << std::endl << "std vectors for comparison: " << std::endl;
	printContainer(sv10);
	printContainer(sv13);
	std::cout << "std: equal: " << (sv10 == sv13) << ", not equal: " << (sv10 != sv13);
	std::cout << ", >: " << (sv10 > sv13) << ", >=: " << (sv10 >= sv13) << ", <: " << (sv10 < sv13);
	std::cout << ", <=: " << (sv10 <= sv13) << std::endl;
	std::cout << "ft vectors for comparison: " << std::endl;	
	printContainer(v10);
	printContainer(v13);
	std::cout << "ft_: equal: " << (v10 == v13) << ", not equal: " << (v10 != v13);
	std::cout << ", >: " << (v10 > v13) << ", >=: " << (v10 >= v13) << ", <: " << (v10 < v13);
	std::cout << ", <=: " << (v10 <= v13) << std::endl;
};
