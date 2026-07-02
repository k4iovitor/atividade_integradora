/**
 * @file alerta_critico.hpp
 * @brief Definição da classe alerta_critico — alerta de severidade máxima.
 *
 * Representa alertas críticos do sistema (severidade 3), como falhas
 * de hardware, temperaturas extremas ou situações de emergência.
 *
 * Conceitos de POO aplicados:
 * - **Herança**: herda de `alerta` (que por sua vez herda de `formatavel`).
 * - **Polimorfismo**: sobrescreve `tipo()` e `formatar()` da classe base.
 * - **Palavra-chave `final`**: impede que outras classes herdem de
 *   `alerta_critico`, fechando a hierarquia neste ponto.
 * - **Palavra-chave `override`**: garante em tempo de compilação que os
 *   métodos estão corretamente sobrescrevendo métodos virtuais da base.
 */

#ifndef ALERTA_CRITICO_HPP
#define ALERTA_CRITICO_HPP

#include "../alerta.hpp"

/**
 * @class alerta_critico
 * @brief Alerta de nível crítico (severidade 3 — máxima).
 *
 * Classe concreta e final que representa alertas de alta gravidade.
 * Sempre inicializa a severidade como 3 (valor fixo).
 */
class alerta_critico final : public alerta {
private:
    std::string mensagem_;  ///< Mensagem descritiva do alerta crítico.

public:
    /**
     * @brief Construtor do alerta crítico.
     * @param origem Nome do sensor/fonte que gerou o alerta.
     * @param mensagem Descrição do evento crítico.
     *
     * A severidade é automaticamente definida como 3 (máxima).
     */
    alerta_critico(const std::string& origem, const std::string& mensagem);

    /**
     * @brief Retorna o tipo do alerta como "CRITICO".
     * @return std::string "CRITICO".
     */
    std::string tipo() const override;

    /**
     * @brief Retorna a mensagem formatada do alerta.
     * @return std::string com a mensagem do alerta crítico.
     */
    std::string formatar() const override;
};

#endif
