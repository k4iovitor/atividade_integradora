#include "alerta_aviso.hpp"

alerta_aviso::alerta_aviso(const std::string& origem,
                           const std::string& mensagem)
    : alerta{origem, 2}, mensagem_{mensagem} {}

std::string alerta_aviso::tipo() const {
    return "AVISO";
}

std::string alerta_aviso::formatar() const {
    return mensagem_;
}
