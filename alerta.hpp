#ifndef ALERTA_HPP
#define ALERTA_HPP

#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

class formatavel {
public:
    virtual std::string formatar() const = 0;
    virtual ~formatavel() = default;
};

class alerta : public formatavel {
private:
    std::string origem_;
    int severidade_;

public:
    alerta(const std::string& origem, int sev);

    void exibir() const;

    virtual std::string tipo() const = 0;

    std::string origem() const;
    int severidade() const;

    virtual ~alerta() = default;
};

#endif
