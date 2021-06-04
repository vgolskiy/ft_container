/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Libraries.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:23:38 by mskinner          #+#    #+#             */
/*   Updated: 2021/02/15 12:08:50 by mskinner         ###   ########.fr       */
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
# include <functional>
# include <utility>

//https://en.cppreference.com/w/cpp/iterator/iterator_tags
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

#endif
