/**
 * @file alerta_aviso.hpp
 * @brief Definição da classe alerta_aviso — alerta de severidade média.
 *
 * Representa alertas de aviso do sistema (severidade 2), como leituras
 * de sensores fora do padrão ou condições que merecem atenção.
 *
 * Conceitos de POO aplicados:
 * - **Herança**: herda de `alerta`, obtendo atributos e comportamentos comuns.
 * - **Polimorfismo**: sobrescreve `tipo()` e `formatar()` para fornecer
 *   comportamento específico de alertas de aviso.
 * - **Encapsulamento**: `mensagem_` é um atributo privado.
 *
 * Diferente de `alerta_critico`, esta classe NÃO usa `final`,
 * permitindo que futuras subclasses possam herdar dela.
 */

#ifndef ALERTA_AVISO_HPP
#define ALERTA_AVISO_HPP

#include "../alerta.hpp"

/**
 * @class alerta_aviso
 * @brief Alerta de nível aviso (severidade 2 — média).
 *
 * Classe concreta que representa situações que exigem atenção
 * mas não são emergenciais. Severidade fixa em 2.
 */
class alerta_aviso : public alerta {
private:
    std::string mensagem_;  ///< Mensagem descritiva do aviso.

public:
    /**
     * @brief Construtor do alerta de aviso.
     * @param origem Nome do sensor/fonte que gerou o aviso.
     * @param mensagem Descrição da situação de aviso.
     *
     * A severidade é automaticamente definida como 2 (média).
     */
    alerta_aviso(const std::string& origem, const std::string& mensagem);

    /**
     * @brief Retorna o tipo do alerta como "AVISO".
     * @return std::string "AVISO".
     */
    std::string tipo() const override;

    /**
     * @brief Retorna a mensagem formatada do aviso.
     * @return std::string com a mensagem do alerta de aviso.
     */
    std::string formatar() const override;
};

#endif
