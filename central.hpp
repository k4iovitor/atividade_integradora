/**
 * @file central.hpp
 * @brief Definição da classe central, responsável por gerenciar alertas.
 *
 * A classe `central` atua como um agregador/gerenciador de alertas,
 * armazenando-os em um vetor de ponteiros inteligentes (unique_ptr).
 *
 * Conceitos de POO aplicados:
 * - **Composição**: a central possui (owns) os alertas via unique_ptr,
 *   garantindo gerenciamento automático de memória.
 * - **Polimorfismo**: armazena ponteiros para a classe base `alerta`,
 *   permitindo que qualquer subtipo concreto seja registrado.
 * - **Encapsulamento**: o vetor interno é privado, acessível apenas
 *   através dos métodos públicos.
 *
 * Uso de smart pointers:
 * - `std::unique_ptr<alerta>` garante ownership exclusivo de cada alerta.
 * - Ao destruir a `central`, todos os alertas são liberados automaticamente.
 */

#ifndef CENTRAL_HPP
#define CENTRAL_HPP

#include "alerta.hpp"

/**
 * @class central
 * @brief Gerenciador central de alertas do sistema.
 *
 * Responsável por registrar, armazenar e exibir todos os alertas.
 * Utiliza um vetor de `unique_ptr<alerta>` para ownership polimórfico.
 */
class central {
    /// @brief Vetor que armazena os alertas registrados.
    /// Usa unique_ptr para gerenciamento automático de memória (RAII).
    std::vector<std::unique_ptr<alerta>> alertas_;

public:
    /**
     * @brief Registra um novo alerta na central.
     * @param a Ponteiro único (unique_ptr) para o alerta a ser registrado.
     *
     * O ownership do alerta é transferido para a central via std::move.
     * Após a chamada, o ponteiro original fica em estado "moved-from" (nulo).
     */
    void registrar(std::unique_ptr<alerta> a);

    /**
     * @brief Exibe todos os alertas registrados na saída padrão.
     *
     * Itera sobre o vetor e chama `exibir()` em cada alerta.
     * Graças ao polimorfismo, cada alerta exibe seu tipo e formato corretos.
     */
    void exibir_todos() const;

    /**
     * @brief Retorna a quantidade total de alertas registrados.
     * @return int com o número de alertas.
     *
     * Marcado como `noexcept` pois nunca lança exceções.
     */
    int total() const noexcept;
};

#endif
