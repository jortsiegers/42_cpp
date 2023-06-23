/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsiegers <jsiegers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/26 15:10:02 by jsiegers      #+#    #+#                 */
/*   Updated: 2023/05/26 15:34:13 by jsiegers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <stdint.h>
#include "data.hpp"


t_data	*deserialize(uintptr_t intPtr)
{
	return reinterpret_cast<t_data *>(intPtr);
}

uintptr_t	serialize(t_data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

int	main( void )
{
	t_data *ptr = new t_data;
	ptr->x = 42;


	uintptr_t intPtr = serialize(ptr);
	t_data *newPtr = deserialize(intPtr);

	std::cout << "Should still be 42: " << newPtr->x << std::endl;

    delete ptr;
}