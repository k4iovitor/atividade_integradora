#ifndef ALERTA_INFO_HPP
#define ALERTA_INFO_HPP

#include "../alerta.hpp"

class alerta_info : public alerta {
private:
    std::string mensagem_;

public:
    alerta_info(const std::string& origem, const std::string& mensagem);

    std::string tipo() const override;
    std::string formatar() const override;
};

#endif
