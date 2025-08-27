#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm() = default;

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other) = delete;

protected:
	void executeAction() const override;

private:
	std::string _target;
};

#endif
