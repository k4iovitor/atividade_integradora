/**
 * @file alerta_info.hpp
 * @brief Definição da classe alerta_info — alerta informativo (severidade 1).
 *
 * Conceitos de POO: herança, polimorfismo, base para herança multinível
 * (alerta → alerta_info → alerta_debug).
 */

#ifndef ALERTA_INFO_HPP
#define ALERTA_INFO_HPP

#include "../alerta.hpp"

/**
 * @class alerta_info
 * @brief Alerta informativo (severidade 1). Base para alerta_debug.
 */
class alerta_info : public alerta {
private:
    std::string mensagem_;  ///< Mensagem informativa.

public:
    /** @brief Construtor. Severidade fixa em 1. */
    alerta_info(const std::string& origem, const std::string& mensagem);

    /** @brief Retorna "INFO". */
    std::string tipo() const override;

    /** @brief Retorna a mensagem. Sobrescrito por alerta_debug. */
    std::string formatar() const override;
};

#endif
