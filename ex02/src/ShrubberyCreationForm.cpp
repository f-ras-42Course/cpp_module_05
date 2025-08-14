#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(other), _target(other._target) {}

// Execute method
void ShrubberyCreationForm::executeAction() const {
    std::cout << "Creating a shrubbery at " << _target << "..." << std::endl;
    std::ofstream file;
    std::string filename = _target + "_shrubbery";

    file.open(filename.c_str(), std::ios::out | std::ios::trunc);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file " + filename);
    }
    file << "              _{\\ _{\\{\\/}/}/}__\n"
         << "             {/{/\\}{/{/\\}(\\}{/\\} _\n"
         << "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _\n"
         << "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n"
         << "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n"
         << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n"
         << "     {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n"
         << "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}\n"
         << "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\n"
         << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n"
         << "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n"
         << "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\n"
         << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\n"
         << "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n"
         << "          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)\n"
         << "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}\n"
         << "             {/{\\{\\{\\/}/}{\\{\\\\}/}\n"
         << "              {){/ {\\/}{\\/} \\}\\}\n"
         << "              (_)  \\.-'.-/\n"
         << "          __...--- |'-.-'| --...__\n"
         << "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__\n"
         << " -\"    ' .  . '    |.'-._| '  . .  '   jro\n"
         << " .  '-  '    .--'  | '-.'|    .  '  . '\n"
         << "          ' ..     |'-_.-|\n"
         << "  .  '  .       _.-|-._ -|-._  .  '  .\n"         
         << "              .'   |'- .-|   '.\n"
         << "  ..-'   ' .  '.   `-._.-�   .'  '  - .\n"
         << "   .-' '        '-._______.-'     '  .\n"
         << "        .      ~,\n"
         << "    .       .   |\\   .    ' '-.\n";
    file.close();
    std::cout << "Shrubbery created in " << filename << std::endl;
}
    
