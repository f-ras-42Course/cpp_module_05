#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
	Intern intern;
	AForm* form1 = intern.makeForm("shrubbery creation", "Garden");
	AForm* form2 = intern.makeForm("robotomy request", "Bender");
	AForm* form3 = intern.makeForm("presidential pardon", "Zaphod");

	form1->beSigned(Bureaucrat("Pim", 1));
	form2->beSigned(Bureaucrat("Klaassen", 2));
	form3->beSigned(Bureaucrat("Jippie", 3));

	form1->execute(Bureaucrat("Pim", 1));
	form2->execute(Bureaucrat("Klaassen", 2));
	form3->execute(Bureaucrat("Jippie", 3));

	delete form1;
	delete form2;
	delete form3;

	return 0;
}