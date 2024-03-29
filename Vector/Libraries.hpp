/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Libraries.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@yandex.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:23:38 by mskinner          #+#    #+#             */
/*   Updated: 2021/02/03 07:56:38 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef _LIBRARIES_HPP_
# define _LIBRARIES_HPP_

# include <iostream>
# include <iterator>
# include <cstddef>
# include <limits>
# include <memory>
# include <time.h>

//https://en.cppreference.com/w/cpp/iterator/iterator_tags
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

#endif
