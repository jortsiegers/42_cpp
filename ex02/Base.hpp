/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Base.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsiegers <jsiegers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/26 16:22:32 by jsiegers      #+#    #+#                 */
/*   Updated: 2023/05/26 16:26:38 by jsiegers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include <unistd.h>

#ifndef BASE_HPP
#define BASE_HPP

class Base
{
    public:
        virtual	~Base() {
            std::cout << "Destructor from the parent called" << std::endl;
        };
};

#endif