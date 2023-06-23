/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsiegers <jsiegers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/26 16:28:04 by jsiegers      #+#    #+#                 */
/*   Updated: 2023/05/26 16:53:15 by jsiegers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    static int seed;
    seed++;
    
    srand(time(NULL) / seed);
    int r = rand();

	Base	*base = NULL;
    if (r % 3 == 0)
        base = dynamic_cast<Base *>(new A);
    else if (r % 3 == 1)
        base = dynamic_cast<Base *>(new B);
    else if (r % 3 == 2)
        base = dynamic_cast<Base *>(new C);
    return (base);
}

void	identify(Base *p)
{

    if (A *a = dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (B *b = dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (C *c = dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "error" << std::endl;

}

void	identify(Base &p)
{
    try {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::exception &e) {}

    try {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (std::exception &e) {}

    try {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (std::exception &e) {}
}

int	main(void)
{
	Base *p;
	Base *p1;

	p = generate();
	p1 = generate();

	std::cout << "with pointer" << std::endl;
	identify(p);
	identify(p1);

	std::cout << "with reference" << std::endl;
	identify(*p);
	identify(*p1);

	delete p;
	delete p1;
}