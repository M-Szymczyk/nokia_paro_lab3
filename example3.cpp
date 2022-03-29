

#include <iostream>
#include <stdexcept>

class myPersonalException : public std::logic_error {
public:
    explicit myPersonalException(const std::string &arg) : logic_error(arg) {}
};

void validateArguments(int argc) {
    if (argc != 2) {
        std::cerr << "You need to pass 1 argument" << std::endl;
        exit(-1);
    }
}

class Resource {
public:
    void use(const char *arg) {
        std::cout << "Using resource. Passed " << *arg << std::endl;
        if (*arg == 'd') {
            throw myPersonalException("Passed d. d is prohibited.");
        }
    }
};

int main(int argc, char *argv[]) {
    validateArguments(argc);

    const char *argument = argv[1];
    Resource *rsc = nullptr;



    try {
        rsc = new Resource();
        rsc->use(argument);
    }
    catch (myPersonalException &e) {
        std::cout << e.what() << std::endl;
    }
    if (rsc != nullptr) {
        delete rsc;
    }

    return 0;
}

