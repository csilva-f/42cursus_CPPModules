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
	brain->setIdeas(0, "IdeaHey");
	brain->setIdeas(1, "IdeaBye");
	std::cout << std::endl << "PRINT IDEAS" << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << "Idea n" << i << ": " << j[0]->getBrain().getIdeas(i) << std::endl;
	std::cout << std::endl << "............................................" << std::endl << std::endl;
	for (int i = 0; i < 5; i++)
		delete j[i];
	for (int i = 0; i < 5; i++)
		delete k[i];
	std::cout << std:: endl;
	std::cout << "-------------------------------------" << std::endl << std:: endl;
	{
		std::cout << "Check deep copy of Dog class using copy constructor:" << std::endl << std::endl;
		Dog *dogA = new Dog;
		Dog *dogB = new Dog(*dogA);

		delete dogA;
		delete dogB;
	}
	std::cout << std::endl << "-------------------------------------" << std::endl << std::endl;
	{
		std::cout << "Check deep copy of Dog class using assignment operator overload:" << std::endl << std::endl;
		Dog *dogA = new Dog;
		Dog *dogB = new Dog;

		*dogA = *dogB;
		delete dogA;
		delete dogB;
	}
	std::cout << std::endl << "-------------------------------------" << std::endl << std::endl;
	{
		std::cout << "Check deep copy of Cat class using copy constructor:\n" << std::endl;
		Cat *catA = new Cat;
		Cat *catB = new Cat(*catA);

		catA->getBrain().setIdeas(0, "IdeaHello");
		catA->getBrain().setIdeas(1, "IdeaGoodbye");
		std::cout << "PRINT IDEAS" <<std::endl;
		for (int i = 0; i < 100; i++)
			std::cout << "Idea n" << i << ": " << catA->getBrain().getIdeas(i) << std::endl;
		for (int i = 0; i < 100; i++)
			std::cout << "Idea n" << i << ": " << catB->getBrain().getIdeas(i) << std::endl;
		delete catA;
		delete catB;
	}
	std::cout << std::endl << "-------------------------------------" << std::endl << std::endl;
	{
		std::cout << "Check deep copy of Cat class using assignment operator overload:" << std::endl << std::endl;
		Cat *catA = new Cat;
		Cat *catB = new Cat;

		*catA = *catB;
		catA->getBrain().setIdeas(0, "IdeaOi");
		catA->getBrain().setIdeas(1, "IdeaXau");
		std::cout << "PRINT IDEAS" <<std::endl;
		for (int i = 0; i < 100; i++)
			std::cout << "Idea n" << i << ": " << catA->getBrain().getIdeas(i) << std::endl;
		for (int i = 0; i < 100; i++)
			std::cout << "Idea n" << i << ": " << catB->getBrain().getIdeas(i) << std::endl;
		delete catA;
		delete catB;
	}
	std::cout << std::endl << "-------------------------------------" << std::endl << std::endl;
	Dog basic;
	{
		Dog tmp = basic;
	}
	std::cout << std::endl;
	Cat basic1;
	{
		Cat tmp1 = basic1;
	}

	return 0;
}
