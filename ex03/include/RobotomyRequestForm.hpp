#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	~RobotomyRequestForm() = default;

	RobotomyRequestForm& operator=(const RobotomyRequestForm& other) = delete;

protected:
	void executeAction() const override;

private:
	std::string _target;
};

#endif
