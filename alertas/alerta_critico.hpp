#ifndef ALERTA_CRITICO_HPP
#define ALERTA_CRITICO_HPP

#include "../alerta.hpp"

class alerta_critico final : public alerta {
private:
    std::string mensagem_;

public:
    alerta_critico(const std::string& origem, const std::string& mensagem);

    std::string tipo() const override;
    std::string formatar() const override;
};

#endif
