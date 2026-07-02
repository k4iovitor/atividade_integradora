#include "alerta_info.hpp"

alerta_info::alerta_info(const std::string& origem,
                         const std::string& mensagem)
    : alerta{origem, 1}, mensagem_{mensagem} {}

std::string alerta_info::tipo() const {
    return "INFO";
}

std::string alerta_info::formatar() const {
    return mensagem_;
}
