/**
 * @file alerta_aviso.cpp
 * @brief Implementação dos métodos da classe alerta_aviso.
 */

#include "alerta_aviso.hpp"

/**
 * @brief Construtor do alerta de aviso.
 *
 * Chama o construtor da classe base `alerta` com severidade 2
 * e inicializa a mensagem descritiva do aviso.
 *
 * @param origem Nome do sensor/fonte.
 * @param mensagem Descrição do aviso.
 */
alerta_aviso::alerta_aviso(const std::string& origem,
                           const std::string& mensagem)
    : alerta{origem, 2}, mensagem_{mensagem} {}

/**
 * @brief Retorna a string "AVISO" como identificador de tipo.
 * @return std::string "AVISO".
 */
std::string alerta_aviso::tipo() const {
    return "AVISO";
}

/**
 * @brief Retorna a mensagem do aviso sem formatação adicional.
 * @return std::string com a mensagem.
 */
std::string alerta_aviso::formatar() const {
    return mensagem_;
}
