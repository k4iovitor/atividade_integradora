/**
 * @file alerta_info.cpp
 * @brief Implementação dos métodos da classe alerta_info.
 */

#include "alerta_info.hpp"

/**
 * @brief Construtor. Severidade fixa em 1 (baixa).
 */
alerta_info::alerta_info(const std::string& origem,
                         const std::string& mensagem)
    : alerta{origem, 1}, mensagem_{mensagem} {}

/** @brief Retorna "INFO". */
std::string alerta_info::tipo() const {
    return "INFO";
}

/** @brief Retorna a mensagem informativa. */
std::string alerta_info::formatar() const {
    return mensagem_;
}
