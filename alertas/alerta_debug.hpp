/**
 * @file alerta_debug.hpp
 * @brief Definição da classe alerta_debug — herança multinível.
 *
 * Herda de alerta_info (não diretamente de alerta), formando:
 * formatavel → alerta → alerta_info → alerta_debug
 *
 * Conceitos de POO:
 * - **Herança multinível**: cadeia de 3 níveis de herança.
 * - **Sobrescrita seletiva**: sobrescreve apenas formatar(),
 *   reutilizando tipo() herdado de alerta_info ("INFO").
 * - **Reuso de código**: chama alerta_info::formatar() e estende.
 */

#ifndef ALERTA_DEBUG_HPP
#define ALERTA_DEBUG_HPP

#include "alerta_info.hpp"

/**
 * @class alerta_debug
 * @brief Alerta de debug que estende alerta_info com contexto extra.
 *
 * Adiciona um campo `contexto_` com informações técnicas detalhadas.
 * O tipo permanece "INFO" (herdado), mas a formatação inclui o contexto.
 */
class alerta_debug : public alerta_info {
private:
    std::string contexto_;  ///< Informação técnica de debug (ex.: "ping 350ms").

public:
    /**
     * @brief Construtor com origem, mensagem e contexto técnico.
     * @param origem Fonte do alerta.
     * @param mensagem Mensagem principal.
     * @param contexto Detalhes técnicos adicionais.
     */
    alerta_debug(const std::string& origem,
                 const std::string& mensagem,
                 const std::string& contexto);

    /**
     * @brief Formata a mensagem concatenando o contexto de debug.
     * @return "mensagem [debug: contexto]"
     *
     * Chama alerta_info::formatar() e estende o resultado.
     */
    std::string formatar() const override;
};

#endif
