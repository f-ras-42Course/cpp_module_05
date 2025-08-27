#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	~PresidentialPardonForm() = default;

	PresidentialPardonForm& operator=(const PresidentialPardonForm& other) = delete;

protected:
	void executeAction() const override;

private:
	std::string _target;
};

#endif