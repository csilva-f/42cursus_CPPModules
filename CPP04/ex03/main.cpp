#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
    
	AMateria* tmp;
	tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
	
	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
    me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;

////////////////////////// MORE TESTS //////////////////////////

	std::cout << std::endl << std::endl;
	std::cout << "1. Check maximum learnMateria" << std::endl;
	IMateriaSource* src2 = new MateriaSource();
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());
	AMateria *mat = new Cure();
	src2->learnMateria(mat);
	std::cout << std::endl;
		
	std::cout << "2. Test deep copy:" << std::endl;
	Character *dur0 = new Character("Alice");
	ICharacter *dur1 = new Character(*dur0);
	delete dur0;
	delete dur1;
	std::cout << std::endl;

	std::cout << "3. Check unknown materias" << std::endl;
	AMateria* tmp2;
	ICharacter *dur2 = new Character("Alice");
	tmp2 = src2->createMateria("ice");
	dur2->equip(tmp2);
	tmp2 = src2->createMateria("cure");
	dur2->equip(tmp2);
	tmp2 = src2->createMateria("hi");
	dur2->equip(tmp2);
	delete src2;
	std::cout << std::endl;

	std::cout << "4. Check unequip" << std::endl;
	AMateria *cure = new Cure();
	AMateria *ice = new Ice();
	dur2->equip(cure);
	dur2->equip(cure);
	dur2->equip(ice);
	dur2->unequip(2);
	delete cure; // Cure must be deleted manually when unequipped
	dur2->unequip(2);
	dur2->unequip(6);
	std::cout << std::endl;

	std::cout << "5. Use materias on new character" << std::endl;
	ICharacter* bob2 = new Character("Bob");
	dur2->use(0, *bob2);
	dur2->use(1, *bob2);
	dur2->use(2, *bob2);
	dur2->use(6, *bob2);
	dur2->use(-4, *bob2);
	dur2->use(3, *bob2);
	delete bob2;
	std::cout << std::endl;
	std::cout << "teste8" << std::endl;

	delete dur2;
	std::cout << "teste9" << std::endl;
	
	return 0;
}
