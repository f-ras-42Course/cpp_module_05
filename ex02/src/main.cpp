#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
	try {
		std::cout << "\n\n|||||----- Robotomy Request Form -----|||||\n";
		Bureaucrat johnny("Johnny", 73);
		RobotomyRequestForm request1("Mr. Johnson");
		std::cout << "Robotomy try 0 (should fail): ";
		johnny.executeForm(request1);
		std::cout << std::endl;
		try {
			request1.beSigned(johnny);
		}
		catch(const std::exception& e) {
			std::cerr << "beSigned error: " << e.what() << '\n';
		}
		std::cout << "\n Current status:\n";
		std::cout << request1;
		std::cout << johnny << std::endl;
		johnny.incrementGrade();
		request1.beSigned(johnny);
		std::cout << "\n After signing:\n";
		std::cout << request1;
		std::cout << johnny << std::endl;
		for (size_t i = 0; i < 27; i++)
			johnny.incrementGrade();
		std::cout << "\n After incrementing Johnny's grade to 45:\n";
		std::cout << johnny << std::endl;
		for (size_t i = 0; i < 6; i++)
		{
			std::cout << "Robotomy try " << i + 1 << ": ";
			johnny.executeForm(request1);
			std::cout << std::endl;
		}

		std::cout << "\n\n|||||----- Presidential Pardon Form -----|||||\n";
		Bureaucrat pjotr("Pjotr", 6);
		PresidentialPardonForm pardonForm("Mr. Smith");
		std::cout << "Initial status:\n";
		std::cout << pjotr << std::endl;
		std::cout << pardonForm << std::endl;
		pjotr.signForm(pardonForm);
		std::cout << "\n After signing:\n";
		std::cout << pardonForm;
		std::cout << pjotr << std::endl;
		std::cout << "Pjotr tries to execute the form (should fail):\n";
		// To succeed, Pjotr needs to increment his grade:
		// pjotr.incrementGrade();
		pjotr.executeForm(pardonForm);
		std::cout << pjotr << std::endl;
		std::cout << std::endl;

		std::cout << "\n|||||----- Shrubbery Creation Form -----|||||\n";
		Bureaucrat gardener("Gardener", 146);
		ShrubberyCreationForm shrubberyForm("Garden");
		std::cout << "Initial status:\n";
		std::cout << gardener << std::endl;
		std::cout << shrubberyForm << std::endl;
		// To succeed signing, keep increment below:
		gardener.incrementGrade();
		gardener.signForm(shrubberyForm);
		std::cout << "\n After signing:\n";
		std::cout << shrubberyForm;
		std::cout << gardener << std::endl;
		std::cout << "Gardener tries to execute the form (should fail):\n";
		// To succeed executing, Gardener needs to increment his grade:
		// for (size_t i = 0; i < 8; i++) {
		// 	gardener.incrementGrade();
		// }
		gardener.executeForm(shrubberyForm);
		std::cout << gardener << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	return 0;
}