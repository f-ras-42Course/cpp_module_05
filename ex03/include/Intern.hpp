#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public:
	Intern() = default;
	Intern(const Intern& other) = default;
	Intern& operator=(const Intern& other) = default;
	~Intern() = default;
	
	AForm* makeForm(const std::string& formName, const std::string& target) const;
	
	private:
	static AForm* createShrubberyForm(const std::string& target);
	static AForm* createRobotomyForm(const std::string& target);
	static AForm* createPresidentialForm(const std::string& target);
};

enum FormType {UNKNOWN, SHRUBBERY, ROBOTOMY, PRESIDENTIAL};

FormType getFormType(const std::string& formName);

#endif