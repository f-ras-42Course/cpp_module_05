#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("Presidential Pardon", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: AForm(other), _target(other._target) {}

// Execute method
void PresidentialPardonForm::executeAction() const {
    std::cout << _target << " is pardoned by Zaphod Beeblebrox." << std::endl;
}
