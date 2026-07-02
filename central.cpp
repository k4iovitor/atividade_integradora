/**
 * @file central.cpp
 * @brief Implementação dos métodos da classe central.
 *
 * Contém a lógica de registro, exibição e contagem de alertas.
 */

#include "central.hpp"

/**
 * @brief Registra um alerta na central, transferindo ownership.
 *
 * Utiliza `std::move()` para transferir a posse do unique_ptr
 * para o vetor interno `alertas_`. Essa é a forma correta de
 * trabalhar com unique_ptr, já que eles não podem ser copiados
 * (semântica de movimentação / move semantics).
 *
 * @param a unique_ptr<alerta> contendo o alerta a ser registrado.
 */
void central::registrar(std::unique_ptr<alerta> a) {
    alertas_.push_back(std::move(a));
}

/**
 * @brief Exibe todos os alertas registrados.
 *
 * Itera sobre o vetor usando range-based for com referência const,
 * chamando o método polimórfico `exibir()` de cada alerta.
 * O tipo correto de cada alerta é resolvido em tempo de execução.
 */
void central::exibir_todos() const {
    for (const auto& a : alertas_) {
        a->exibir();
    }
}

/**
 * @brief Retorna o número total de alertas registrados.
 *
 * Usa `static_cast<int>` para converter o retorno de `size()`
 * (que é do tipo size_t / unsigned) para int, evitando warnings
 * de conversão implícita entre tipos signed e unsigned.
 *
 * @return int com a quantidade de alertas.
 */
int central::total() const noexcept {
    return static_cast<int>(alertas_.size());
}
