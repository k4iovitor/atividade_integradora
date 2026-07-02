#include "alerta_critico.hpp"

alerta_critico::alerta_critico(const std::string& origem,
                               const std::string& mensagem)
    : alerta{origem, 3}, mensagem_{mensagem} {}

std::string alerta_critico::tipo() const {
    return "CRITICO";
}

std::string alerta_critico::formatar() const {
    return mensagem_;
}
