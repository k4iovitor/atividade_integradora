/**
 * @file alerta_critico.cpp
 * @brief Implementação dos métodos da classe alerta_critico.
 */

#include "alerta_critico.hpp"

/**
 * @brief Construtor do alerta crítico.
 *
 * Chama o construtor da classe base `alerta` passando severidade 3
 * (valor fixo para alertas críticos) e inicializa a mensagem.
 * Usa lista de inicialização com chaves {} (uniform initialization).
 *
 * @param origem Nome do sensor/fonte.
 * @param mensagem Descrição do evento crítico.
 */
alerta_critico::alerta_critico(const std::string& origem,
                               const std::string& mensagem)
    : alerta{origem, 3}, mensagem_{mensagem} {}

/**
 * @brief Retorna a string "CRITICO" como identificador de tipo.
 * @return std::string "CRITICO".
 */
std::string alerta_critico::tipo() const {
    return "CRITICO";
}

/**
 * @brief Retorna a mensagem do alerta sem formatação adicional.
 * @return std::string com a mensagem do alerta.
 */
std::string alerta_critico::formatar() const {
    return mensagem_;
}
