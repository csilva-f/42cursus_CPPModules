#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define N_ANIMALS 5

int	main()
{
	Animal*	j[N_ANIMALS];
	Animal*	k[N_ANIMALS];

	for (int i = 0; i < N_ANIMALS; i++)
		j[i] = new Cat();
	for (int i = 0; i < N_ANIMALS; i++)
		k[i] = new Dog();

	std::cout << std::endl << "............................................" << std::endl;
	Brain *brain;
	brain = &j[0]->getBrain();
	brain->setIdeas(1, "You are awesome!");
	brain->setIdeas(2, "Keep going");
	std::cout << "Print the ideas:" << std::endl;
	std::cout << j[0]->getBrain().getIdeas(1) << std::endl;
	std::cout << j[0]->getBrain().getIdeas(2) << std::endl;
	std::cout << "............................................" << std::endl << std::endl;
	for (int i = 0; i < 5; i++)
		delete j[i];
	for (int i = 0; i < 5; i++)
		delete k[i];
		
	std::cout << std:: endl;
	Dog dog1;
	Dog dog2(dog1);

	dog1.getBrain().setIdeas(1, "Dog1");
	std::cout << "Ideas dog1: " << dog1.getBrain().getIdeas(1) <<std::endl;
	std::cout << "Ideas dog2: " << dog2.getBrain().getIdeas(1) <<std::endl;
	std::cout << std::endl;

	Cat cat1;
	Cat cat2;
	cat2 = cat1;
	cat1.getBrain().setIdeas(1, "Cat1");
	std::cout << "Ideas cat1: " << cat1.getBrain().getIdeas(1) <<std::endl;
	std::cout << "Ideas cat2: " << cat2.getBrain().getIdeas(1) <<std::endl;
	std::cout << std::endl;

	std::cout << "-------------------------------------" << std::endl << std:: endl;
	{
		std::cout << "Check deep copy of Dog class using copy constructor:" << std::endl << std::endl;
		Dog *dogA = new Dog;
		std::cout << "     ---------------------     " << std::endl;
		Dog *dogB = new Dog(*dogA);
		std::cout << "     ---------------------     " << std::endl;
		delete dogA;
		delete dogB;
	}
	std::cout << std::endl << "-------------------------------------" << std::endl << std::endl;
	{
		std::cout << "Check deep copy of Dog class using assignment operator overload:" << std::endl << std::endl;
		Dog *dogA = new Dog;
		Dog *dogB = new Dog;

		std::cout << "     ---------------------     " << std::endl;
		*dogA = *dogB;
		std::cout << "     ---------------------     " << std::endl;
		delete dogA;
		delete dogB;
	}
	std::cout << std::endl << "-------------------------------------" << std::endl << std::endl;
	{
		std::cout << "Check deep copy of Cat class using copy constructor:\n" << std::endl;
		Cat *catA = new Cat;
		std::cout << "     ---------------------     " << std::endl;
		Cat *catB = new Cat(*catA);
		std::cout << "     ---------------------     " << std::endl;
		delete catA;
		delete catB;
	}
	std::cout << std::endl << "-------------------------------------" << std::endl << std::endl;
	{
		std::cout << "Check deep copy of Cat class using assignment operator overload:" << std::endl << std::endl;
		Cat *catA = new Cat;
		Cat *catB = new Cat;
		std::cout << "     ---------------------     " << std::endl;
		*catA = *catB;
		std::cout << "     ---------------------     " << std::endl;
		delete catA;
		delete catB;
	}
	return 0;
}
