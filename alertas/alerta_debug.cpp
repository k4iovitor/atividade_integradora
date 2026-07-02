/**
 * @file alerta_debug.cpp
 * @brief Implementação dos métodos da classe alerta_debug.
 */

#include "alerta_debug.hpp"

/**
 * @brief Construtor. Delega para alerta_info (que delega para alerta).
 *
 * Cadeia de construção: alerta_debug → alerta_info → alerta.
 * O contexto técnico é armazenado como atributo adicional.
 */
alerta_debug::alerta_debug(const std::string& origem,
                           const std::string& mensagem,
                           const std::string& contexto)
    : alerta_info{origem, mensagem}, contexto_{contexto} {}

/**
 * @brief Estende a formatação de alerta_info com informações de debug.
 *
 * Chama explicitamente alerta_info::formatar() para obter a mensagem
 * base e concatena o contexto de debug entre colchetes.
 * Resultado: "mensagem [debug: contexto]"
 */
std::string alerta_debug::formatar() const {
    return alerta_info::formatar() + " [debug: " + contexto_ + "]";
}
