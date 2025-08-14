#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("Robotomy Request", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other), _target(other._target) {}

// Execute method
void RobotomyRequestForm::executeAction() const {
    std::cout << "Drilling noises... " << _target << " has been robotomized successfully." << std::endl;
}
