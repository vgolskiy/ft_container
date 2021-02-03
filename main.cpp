/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@yandex.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:35:09 by mskinner          #+#    #+#             */
/*   Updated: 2021/02/03 09:30:53 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//clang++ -Wall -Werror -Wextra -std=c++98 main.cpp

#include "List.hpp"
#include <list>

template <typename T>
void    printContainer(ft::List<T> &cont) {
    typename ft::List<T>::iterator it = cont.begin();

    std::cout << "size: " << cont.size();
    std::cout << " [";
    while (it != cont.end())
    {
        if (it != cont.begin())
            std::cout << ", ";
        std::cout << *it;
        it++;
    }
    std::cout << "] in reverse: ";

    typename ft::List<T>::reverse_iterator rit;

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
void    printConstantContainer(const ft::List<T> &cont) {
    typename ft::List<T>::const_iterator it;

    std::cout << "size: " << cont.size();
    std::cout << " [";
    for (it = cont.begin(); it != cont.end(); ++it)
    {
        if (it != cont.begin())
            std::cout << ", ";
        std::cout << *it;
    }
    std::cout << "] in reverse: ";

    typename ft::List<T>::const_reverse_iterator rit;

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
    std::cout << "LIST CREATION TESTS >>>" << std::endl;
    ft::List<int>        l1;
    std::list<int>        sl1;
    ft::List<char>        l2;
    std::list<char>        sl2;
    ft::List<char*>        l3;
    std::list<char*>    sl3;
    ft::List<char**>    l4;
    std::list<char**>    sl4;
    ft::List<float>        l5;
    std::list<float>    sl5;

    std::cout << "list 1 size: " << l1.size() << std::endl;
    std::cout << "list 2 size: " << l2.size() << std::endl;
    std::cout << "list 3 size: " << l3.size() << std::endl;
    std::cout << "list 4 size: " << l4.size() << std::endl;
    std::cout << "list 5 size: " << l5.size() << std::endl;

    std::cout << "is list 1 empty: " << l1.empty() << std::endl;
    std::cout << "is list 2 empty: " << l2.empty() << std::endl;
    std::cout << "is list 3 empty: " << l3.empty() << std::endl;
    std::cout << "is list 4 empty: " << l4.empty() << std::endl;
    std::cout << "is list 5 empty: " << l5.empty() << std::endl;

    std::cout << "maximal list 1 size: " << l1.max_size() << " vs std: " << sl1.max_size() << std::endl;
    std::cout << "maximal list 2 size: " << l2.max_size() << " vs std: " << sl2.max_size() << std::endl;
    std::cout << "maximal list 3 size: " << l3.max_size() << " vs std: " << sl3.max_size() << std::endl;
    std::cout << "maximal list 4 size: " << l4.max_size() << " vs std: " << sl4.max_size() << std::endl;
    std::cout << "maximal list 5 size: " << l5.max_size() << " vs std: " << sl5.max_size() << std::endl;

    std::cout << std::endl << "LIST FILLING AND ITERATION TESTS >>>" << std::endl;
    ft::List<int> l7(5);
    std::cout << "list has 5 elements? " << (l7.size() == 5) << std::endl;
    printContainer(l7);
    std::cout << "list has int front? " << (l7.front() == int()) << std::endl;
    std::cout << "list has int back? " << (l7.back() == int()) << std::endl;
    std::cout << "every list element is int? ";
    for (ft::List<int>::iterator it = l7.begin(); it != l7.end(); ++it) {
        if (it != l7.begin())
            std::cout  << ", ";
        std::cout << (*it == int());
    };
    std::cout << std::endl;

    ft::List<char> l8(static_cast<std::size_t>(3), 65);
    std::cout << "list has 3 elements? " << (l8.size() == 3) << std::endl;
    printContainer(l8);
    std::cout << "list has char front? " << (l8.front() == char()) << std::endl;
    std::cout << "list has char back? " << (l8.back() == char()) << std::endl;
    std::cout << "every list element is char? ";
    for (ft::List<char>::iterator it2 = l8.begin(); it2 != l8.end(); ++it2) {
        if (it2 != l8.begin())
            std::cout  << ", ";
        std::cout << (*it2 == char());
    };
    std::cout << std::endl;

    ft::List<float> l9(4, 42.42f);
    std::cout << "list has 4 elements? " << (l9.size() == 4);
    printContainer(l9);
    std::cout << "list has 42.42f front? " << (l9.front() == 42.42f) << std::endl;
    std::cout << "list has 42.42f back? " << (l9.back() == 42.42f) << std::endl;
    std::cout << "every list element is 42.42f? ";
    for (ft::List<float>::iterator it3 = l9.begin(); it3 != l9.end(); ++it3) {
        if (it3 != l9.begin())
            std::cout  << ", ";
        std::cout << (*it3 == 42.42f);
    };
    std::cout << std::endl;

    std::cout << std::endl << "LIST RANGES ASSIGMENT TESTS (INC. CONSTANT CONTAINERS) >>>" << std::endl;
    int                        arr1[5] = {1, 2, 3, 4, 5};
    std::string                arr2[3] = {"bonjour", "je", "suis"};
    float                    arr3[5] = {1.2, 2.3, 3.4, 4.5, 5.6};
    ft::List<int>            l10(arr1, arr1 + 5);
    const ft::List<int>        constl10(arr1, arr1 + 5);
    std::list<int>            sl10(arr1, arr1 + 5);
    std::cout << "ft_: ";
    printContainer(l10);
    std::cout << "ftc: ";
    printConstantContainer(constl10);
    std::cout << "std: ";
    printContainer(sl10);

    ft::List<std::string>    l11(arr2, arr2 + 3);
    const ft::List<std::string>    constl11(arr2, arr2 + 3);
    std::list<std::string>    sl11(arr2, arr2 + 3);
    std::cout << "ft_: ";
    printContainer(l11);
    std::cout << "ftc: ";
    printConstantContainer(constl11);
    std::cout << "std: ";
    printContainer(sl11);


    ft::List<float>            l12(arr3, arr3 + 5);
    const ft::List<float>    constl12(arr3, arr3 + 5);
    std::list<float>        sl12(arr3, arr3 + 5);
    std::cout << "ft_: ";
    printContainer(l12);
    std::cout << "ftc: ";
    printConstantContainer(constl12);
    std::cout << "std: ";
    printContainer(sl12);

    ft::List<int>            l13(arr1 + 1, arr1 + 4);
    const ft::List<int>        constl13(arr1 + 1, arr1 + 4);
    std::list<int>            sl13(arr1 + 1, arr1 + 4);
    std::cout << "ft_: ";
    printContainer(l13);
    std::cout << "ftc: ";
    printConstantContainer(constl13);
    std::cout << "std: ";
    printContainer(sl13);

    std::cout << std::endl << "LIST COPYING TESTS >>>" << std::endl;
    ft::List<int>            cl13(l13);
    std::cout << "orig: ";
    printContainer(l13);
    std::cout << "copy: ";
    printContainer(cl13);
    ft::List<char>            cl8(l8);
    std::cout << "orig: ";
    printContainer(l8);
    std::cout << "copy: ";
    printContainer(cl8);
    ft::List<std::string>    cl11(l11);
    std::cout << "orig: ";
    printContainer(l11);
    std::cout << "copy: ";
    printContainer(cl11);
    ft::List<float>            cl12(l12);
    std::cout << "orig: ";
    printContainer(l12);
    std::cout << "copy: ";
    printContainer(cl12);

    std::cout << std::endl << "LIST ASSIGMENT OPERATOR= TESTS >>>" << std::endl;
    ft::List<int>            l14 = cl13;
    std::cout << "orig: " << cl13.size() << " ";
    printContainer(cl13);
    std::cout << "ass_: " << l14.size() << " ";
    printContainer(l14);
    ft::List<char>            l15 = cl8;
    std::cout << "orig: " << cl8.size() << " ";
    printContainer(cl8);
    std::cout << "ass_: " << l15.size() << " ";
    printContainer(l15);
    ft::List<float>            l16 = cl12;
    std::cout << "orig: " << cl12.size() << " ";
    printContainer(cl12);
    std::cout << "ass_: " << l16.size() << " ";
    printContainer(l16);
    ft::List<std::string>    l17 = cl11;
    std::cout << "orig: " << cl11.size() << " ";
    printContainer(cl11);
    std::cout << "ass_: " << l17.size() << " ";
    printContainer(l17);
    
    std::cout << std::endl << "LIST FRONT/BACK TESTS >>>" << std::endl;
    std::cout << "ft_: front " << l10.front() << " back " << l10.back() << std::endl;
    std::cout << "ftc: front " << constl10.front() << " back " << constl10.back() << std::endl;
    std::cout << "std:  front " << sl10.front() << " back " << sl10.back() << std::endl;

    std::cout << "ft_: front " << l11.front() << " back " << l11.back() << std::endl;
    std::cout << "ftc: front " << constl11.front() << " back " << constl11.back() << std::endl;
    std::cout << "std: front " << sl11.front() << " back " << sl11.back() << std::endl;

    std::cout << "ft_: front " << l12.front() << " back " << l12.back() << std::endl;
    std::cout << "ftc: front " << constl12.front() << " back " << constl12.back() << std::endl;
    std::cout << "std: front " << sl12.front() << " back " << sl12.back() << std::endl;

    std::cout << "ft_: front " << l13.front() << " back " << l13.back() << std::endl;
    std::cout << "ftc: front " << constl13.front() << " back " << constl13.back() << std::endl;
    std::cout << "std: front " << sl13.front() << " back " << sl13.back() << std::endl;

    std::cout << std::endl << "LIST INSERT TESTS >>>";
    std::cout << std::endl << "POSITION + VALUE >>>" << std::endl;
    l10.insert(l10.begin(), 65);
    l10.insert(l10.begin() + 2, 65);
    l10.insert(l10.end(), 65);
    printContainer(l10);
    
    l8.insert(l8.begin(), 66);
    l8.insert(l8.begin() + 2, 66);
    l8.insert(l8.end(), 66);
    printContainer(l8);
    
    l11.insert(l11.begin(), "add");
    l11.insert(l11.begin() + 2, "add");
    l11.insert(l11.end(), "add");
    printContainer(l11);
    
    std::cout << std::endl << "POSITION + VALUE REPEATS >>>" << std::endl;
    l10.insert(l10.begin(), 2, 77);
    l10.insert(l10.begin() + 2, 2, 77);
    l10.insert(l10.end(), 2, 77);
    printContainer(l10);
    
    l8.insert(l8.begin(), 3, 'E');
    l8.insert(l8.begin() + 2, 3, 'E');
    l8.insert(l8.end(), 3, 'E');
    printContainer(l8);
    
    l11.insert(l11.begin(), 2, "rep");
    l11.insert(l11.begin() + 3, 2, "rep");
    l11.insert(l11.end(), 2, "rep");
    printContainer(l11);
    
    std::cout << std::endl << "POSITION + INTERVAL >>>" << std::endl;
    printContainer(l10);
    l10.sort();
    l10.unique();
    printContainer(l10);
    
    
    std::cout << std::endl << "LIST SORTING TESTS >>>" << std::endl;
    char                    arr4[4] = {'b', 'A', 'c', 'D'};
    int                        arr5[6] = {0, -3, 10, 5, 4, 6};
    float                    arr6[5] = {4.5, 3.4, 1.2, 2.3, -5.6};

    ft::List<char>            l18(arr4, arr4 + 4);
    std::list<char>            sl18(arr4, arr4 + 4);
    ft::List<int>            l19(arr5, arr5 + 6);
    std::list<int>            sl19(arr5, arr5 + 6);
    ft::List<float>            l20(arr6, arr6 + 5);
    std::list<float>        sl20(arr6, arr6 + 5);

    std::cout << "orig: ";
    printContainer(l18);
    l18.sort();
    std::cout << "ft_: ";
    printContainer(l18);
    sl18.sort();
    std::cout << "std: ";
    printContainer(sl18);
    std::cout << "orig: ";
    printContainer(l19);
    l19.sort();
    std::cout << "ft_: ";
    printContainer(l19);
    sl19.sort();
    std::cout << "std: ";
    printContainer(sl19);
    std::cout << "orig: ";
    printContainer(l20);
    l20.sort();
    std::cout << "ft_: ";
    printContainer(l20);
    sl20.sort();
    std::cout << "std: ";
    printContainer(sl20);

    std::cout << std::endl << "LIST ALL MEMBRERS TESTING ONE BY ONE >>>" << std::endl;
    ft::List<int> list1,list2;
    int i;
    
    // inserting at the back
    for(i=0;i<10;i++)
        list1.push_back(i+1);

    //inserting at the front
    for(i=0;i<10;i++)
        list2.push_front(std::rand() % 10);

    std::cout << "Content of List 1: ";
    printContainer(list1);
    
    std::cout << "Content of list 2: ";
    printContainer(list2);
    
    // sorting the second list
    list2.sort();
    std::cout << "Sorted List2 : ";
    printContainer(list2);

    std::cout << "Removing five elements from front in list1: ";
    int times = 5;
    while(times--)
        list1.pop_front();
    printContainer(list1);

    std::cout << "Removing five elements from the back in list2: ";
    times = 5;
    while(times--)
        list2.pop_back();
    printContainer(list2);

    std::cout << "Get the first element of list 1: ";
    std::cout << list1.front() << " is now at the front in list 1" << std::endl;

    std::cout << "Get the last element in list 2: ";
    std::cout << list2.back() << " is now the last element in list 2" << std::endl;

    std::cout << "Inserting elements in list 1: ";
    printContainer(list1);
    ft::List<int>::iterator it = list1.begin();
    list1.insert(it, 5, 10);
    std::cout << "After Insertion list 1: ";
    printContainer(list1);

    std::cout << "Removing all the elements with value 10 in list 1: ";
    list1.remove(10);
    printContainer(list1);

    std::cout << "Reversing the content of list 2: ";
    printContainer(list2);
    list2.reverse();
    std::cout << "Reversed list 2: ";
    printContainer(list2);

    std::cout << "Erasing first element of list 2: ";
    printContainer(list2);
    list2.erase(list2.begin());
    std::cout << "After erasing from list 2: ";
    printContainer(list2);

    std::cout << "Removing all elements from list 1 with empty() function verification: ";
    list1.clear();
    
    if(list1.empty())
        std::cout << "List 1 is now empty\n";
    else
        std::cout << "Not Empty\n";

    std::cout << "Using of assign function, List 1: ";
    list1.assign(4,2); // 2 2 2 2
    printContainer(list1);
    
    std::cout << "Resizing of list 1 with std example for compare:" << std::endl;
    std::list<int> c = {1, 2, 3};
    std::cout << "std: ";
    printContainer(c);
    c.resize(6);
    list1.resize(6);
    std::cout << "After resize up to 6: ";
    std::cout << "std: ";
    printContainer(c);
    std::cout << "ft_: ";
    printContainer(list1);
    c.resize(2);
    list1.resize(2);
    std::cout << "After resize down to 2: ";
    std::cout << "std: ";
    printContainer(c);
    std::cout << "ft_: ";
    printContainer(list1);
    

};
