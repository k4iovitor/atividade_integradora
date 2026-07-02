/**
 * @file alerta.cpp
 * @brief Implementação dos métodos da classe abstrata alerta.
 *
 * Contém a lógica do construtor (com validação de severidade),
 * o método de exibição polimórfica e os getters dos atributos.
 */

#include "alerta.hpp"

/**
 * @brief Construtor da classe alerta.
 *
 * Inicializa os atributos `origem_` e `severidade_` usando lista
 * de inicialização (member initializer list), que é mais eficiente
 * do que atribuição no corpo do construtor.
 *
 * Realiza validação do parâmetro `sev`: se estiver fora do
 * intervalo [1, 3], lança uma exceção do tipo std::invalid_argument.
 *
 * @param origem Nome do sensor/fonte que gerou o alerta.
 * @param sev Nível de severidade (1 = baixa, 2 = média, 3 = alta).
 * @throws std::invalid_argument se sev < 1 ou sev > 3.
 */
alerta::alerta(const std::string& origem, int sev)
    : origem_{origem}, severidade_{sev} {
    if (sev < 1 || sev > 3) {
        throw std::invalid_argument(
            "Severidade deve estar entre 1 e 3");
    }
}

/**
 * @brief Exibe o alerta na saída padrão com formatação padronizada.
 *
 * Formato: [TIPO] origem: mensagem_formatada
 *
 * Este método demonstra **polimorfismo em tempo de execução**:
 * - `tipo()` é resolvido dinamicamente conforme a subclasse real.
 * - `formatar()` é resolvido dinamicamente via interface `formatavel`.
 *
 * Mesmo sendo chamado via ponteiro/referência para `alerta`,
 * o comportamento correto da subclasse é invocado (late binding).
 */
void alerta::exibir() const {
    std::cout << "[" << tipo()
              << "] " << origem_ << ": "
              << formatar()
              << "\n";
}

/**
 * @brief Getter para o atributo origem_.
 * @return std::string com o nome da fonte/sensor do alerta.
 */
std::string alerta::origem() const {
    return origem_;
}

/**
 * @brief Getter para o atributo severidade_.
 * @return int com o nível de severidade (1, 2 ou 3).
 */
int alerta::severidade() const {
    return severidade_;
}
