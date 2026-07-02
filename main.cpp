/**
 * @file main.cpp
 * @brief Ponto de entrada do programa — demonstração do sistema de alertas.
 *
 * Este arquivo demonstra o uso de todos os conceitos de POO implementados:
 *
 * 1. **Polimorfismo**: objetos de tipos diferentes (alerta_critico,
 *    alerta_aviso, alerta_info, alerta_debug) são tratados uniformemente
 *    via ponteiros para a classe base `alerta`.
 *
 * 2. **Smart pointers**: `std::make_unique` cria objetos no heap com
 *    gerenciamento automático de memória (RAII). Não há `new`/`delete` manual.
 *
 * 3. **Herança e hierarquia de classes**: demonstra herança simples
 *    (critico, aviso, info) e herança multinível (debug → info → alerta).
 *
 * 4. **Composição**: a `central` agrega os alertas e gerencia seu ciclo de vida.
 */

#include "central.hpp"
#include "alertas/alerta_critico.hpp"
#include "alertas/alerta_aviso.hpp"
#include "alertas/alerta_info.hpp"
#include "alertas/alerta_debug.hpp"

/**
 * @brief Função principal — cria alertas e os registra na central.
 *
 * Saída esperada:
 * @code
 * Total: 4 alertas
 *
 * [CRITICO] sensor1: temperatura 95.3 graus
 * [AVISO] sensor2: umidade 78.5 pct
 * [INFO] sistema: reinicio agendado
 * [INFO] modulo_rede: latencia elevada [debug: ping 350ms gateway 10.0.0.1]
 * @endcode
 */
int main() {
    central c;

    // Alerta crítico (severidade 3) — evento de emergência
    c.registrar(std::make_unique<alerta_critico>(
        "sensor1", "temperatura 95.3 graus"));

    // Alerta de aviso (severidade 2) — situação de atenção
    c.registrar(std::make_unique<alerta_aviso>(
        "sensor2", "umidade 78.5 pct"));

    // Alerta informativo (severidade 1) — notificação de rotina
    c.registrar(std::make_unique<alerta_info>(
        "sistema", "reinicio agendado"));

    // Alerta de debug (herança multinível) — info + contexto técnico
    c.registrar(std::make_unique<alerta_debug>(
        "modulo_rede", "latencia elevada", "ping 350ms gateway 10.0.0.1"));

    // Exibe o total de alertas e lista todos com formatação polimórfica
    std::cout << "Total: " << c.total() << " alertas\n\n";
    c.exibir_todos();

    return 0;
}
