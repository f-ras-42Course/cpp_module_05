#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("Robotomy Request", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other), _target(other._target) {}

// Execute method
void RobotomyRequestForm::executeAction() const {
    sranddev();
    if (rand() % 2 == true)
    {
        std::cout << "**PDDRRRRTTTTDDDD** Drilling noises fill the room..." \
            << _target << " has been robotomized successfully." << std::endl;
    }
    else
    {
        std::cout << "Robotomy failed. Better luck next time." << std::endl;
    }
}

