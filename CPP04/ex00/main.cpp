#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	const Animal*	meta = new Animal(); 
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();
	const Animal*	j2 = new Dog("Labrador");
	const Animal*	i2 = new Cat("Scotish");
	
	std::cout << "j type: " << j->getType() << " " << std::endl;
	std::cout << "i type: " << i->getType() << " " << std::endl;
	std::cout << "j2 type: " << j2->getType() << " " << std::endl;
	std::cout << "i2 type: " << i2->getType() << " " << std::endl;
	std::cout << "meta type: " << meta->getType() << " " << std::endl;

	std::cout << "j sound: ";
	j->makeSound();
	std::cout << "i sound: ";
	i->makeSound();
	std::cout << "meta sound: ";
    meta->makeSound();
	std::cout << "j2 sound: ";
	j2->makeSound();
	std::cout << "i2 sound: ";
	i2->makeSound();

	delete meta;
	delete j;
	delete i;
	delete j2;
	delete i2;

	std::cout << std::endl << "///////////////// WRONG PART /////////////////" << std::endl << std::endl;

	const WrongAnimal*	wmeta = new WrongAnimal();
	const WrongAnimal*	wj = new WrongCat();
	const WrongAnimal*	wj2 = new WrongCat("Scotish");

	std::cout << "wj type: " << wj->getType() << " " << std::endl;
	std::cout << "wj2 type: " << wj2->getType() << " " << std::endl;
	std::cout << "wmeta type: " << wmeta->getType() << " " << std::endl;

	std::cout << "wj sound: ";
	wj->makeSound();
	std::cout << "wj2 sound: ";
	wj2->makeSound();
	std::cout << "wmeta sound: ";
    wmeta->makeSound();

	delete wmeta;
	delete wj;
	delete wj2;

	return 0;
}
