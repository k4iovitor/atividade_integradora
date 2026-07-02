/**
 * @file alerta.hpp
 * @brief Definição da interface formatavel e da classe abstrata alerta.
 *
 * Este arquivo contém:
 * - A interface `formatavel`, que estabelece o contrato de formatação
 *   para qualquer objeto que precise ser exibido como texto.
 * - A classe abstrata `alerta`, que serve como base para todos os tipos
 *   concretos de alerta do sistema (crítico, aviso, info, debug).
 *
 * Conceitos de POO aplicados:
 * - **Abstração**: `alerta` é uma classe abstrata (possui métodos virtuais puros).
 * - **Encapsulamento**: os atributos `origem_` e `severidade_` são privados,
 *   acessíveis apenas via métodos getters públicos.
 * - **Polimorfismo**: os métodos `tipo()` e `formatar()` são virtuais puros,
 *   permitindo que cada subclasse defina seu próprio comportamento.
 * - **Interface**: `formatavel` é uma interface pura (classe com apenas
 *   métodos virtuais puros e destrutor virtual padrão).
 */

#ifndef ALERTA_HPP
#define ALERTA_HPP

#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

/**
 * @class formatavel
 * @brief Interface pura que define o contrato de formatação de objetos.
 *
 * Qualquer classe que implemente esta interface deve fornecer uma
 * representação textual do objeto através do método `formatar()`.
 * Funciona como um contrato (similar a interfaces em Java).
 */
class formatavel {
public:
    /**
     * @brief Retorna a representação formatada do objeto como string.
     * @return std::string contendo o texto formatado.
     *
     * Método virtual puro — obriga todas as classes derivadas a
     * fornecerem sua própria implementação.
     */
    virtual std::string formatar() const = 0;

    /**
     * @brief Destrutor virtual padrão.
     *
     * Necessário para garantir a destruição correta de objetos
     * derivados quando manipulados via ponteiro para a classe base.
     */
    virtual ~formatavel() = default;
};

/**
 * @class alerta
 * @brief Classe abstrata base para todos os tipos de alerta do sistema.
 *
 * Herda de `formatavel` e adiciona os atributos comuns a qualquer alerta:
 * - `origem_`: identifica a fonte/sensor que gerou o alerta.
 * - `severidade_`: nível de gravidade do alerta (1 = baixa, 2 = média, 3 = alta).
 *
 * Define o método virtual puro `tipo()`, que cada subclasse deve
 * implementar para retornar o nome do tipo de alerta (ex.: "CRITICO", "AVISO").
 *
 * Hierarquia de herança:
 * @code
 *   formatavel (interface)
 *       └── alerta (classe abstrata)
 *             ├── alerta_critico  (severidade 3)
 *             ├── alerta_aviso    (severidade 2)
 *             ├── alerta_info     (severidade 1)
 *             │     └── alerta_debug (herança multinível)
 * @endcode
 */
class alerta : public formatavel {
private:
    std::string origem_;    ///< Fonte/sensor que originou o alerta.
    int severidade_;        ///< Nível de severidade: 1 (baixa), 2 (média), 3 (alta).

public:
    /**
     * @brief Construtor da classe alerta.
     * @param origem Nome da fonte/sensor que gerou o alerta.
     * @param sev Nível de severidade (deve estar entre 1 e 3).
     * @throws std::invalid_argument se `sev` estiver fora do intervalo [1, 3].
     */
    alerta(const std::string& origem, int sev);

    /**
     * @brief Exibe o alerta formatado na saída padrão.
     *
     * O formato de saída é: [TIPO] origem: mensagem_formatada
     * Utiliza polimorfismo ao chamar `tipo()` e `formatar()`,
     * que são resolvidos em tempo de execução (late binding).
     */
    void exibir() const;

    /**
     * @brief Retorna o tipo do alerta como string.
     * @return std::string com o nome do tipo (ex.: "CRITICO", "AVISO", "INFO").
     *
     * Método virtual puro — cada subclasse concreta deve implementar.
     */
    virtual std::string tipo() const = 0;

    /**
     * @brief Retorna a origem (fonte/sensor) do alerta.
     * @return std::string com o nome da origem.
     */
    std::string origem() const;

    /**
     * @brief Retorna o nível de severidade do alerta.
     * @return int com o valor da severidade (1, 2 ou 3).
     */
    int severidade() const;

    /**
     * @brief Destrutor virtual padrão.
     *
     * Garante destruição polimórfica correta ao deletar via
     * ponteiro base (ex.: unique_ptr<alerta>).
     */
    virtual ~alerta() = default;
};

#endif
