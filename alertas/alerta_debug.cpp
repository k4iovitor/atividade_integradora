#include "alerta_debug.hpp"

alerta_debug::alerta_debug(const std::string& origem,
                           const std::string& mensagem,
                           const std::string& contexto)
    : alerta_info{origem, mensagem}, contexto_{contexto} {}

std::string alerta_debug::formatar() const {
    return alerta_info::formatar() + " [debug: " + contexto_ + "]";
}
