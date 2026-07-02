#ifndef ALERTA_DEBUG_HPP
#define ALERTA_DEBUG_HPP

#include "alerta_info.hpp"

class alerta_debug : public alerta_info {
private:
    std::string contexto_;

public:
    alerta_debug(const std::string& origem,
                 const std::string& mensagem,
                 const std::string& contexto);

    std::string formatar() const override;
};

#endif
