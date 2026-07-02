#ifndef ALERTA_AVISO_HPP
#define ALERTA_AVISO_HPP

#include "../alerta.hpp"

class alerta_aviso : public alerta {
private:
    std::string mensagem_;

public:
    alerta_aviso(const std::string& origem, const std::string& mensagem);

    std::string tipo() const override;
    std::string formatar() const override;
};

#endif
