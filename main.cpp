#include "central.hpp"
#include "alertas/alerta_critico.hpp"
#include "alertas/alerta_aviso.hpp"
#include "alertas/alerta_info.hpp"
#include "alertas/alerta_debug.hpp"

int main() {
    central c;

    c.registrar(std::make_unique<alerta_critico>(
        "sensor1", "temperatura 95.3 graus"));
    c.registrar(std::make_unique<alerta_aviso>(
        "sensor2", "umidade 78.5 pct"));
    c.registrar(std::make_unique<alerta_info>(
        "sistema", "reinicio agendado"));

    c.registrar(std::make_unique<alerta_debug>(
        "modulo_rede", "latencia elevada", "ping 350ms gateway 10.0.0.1"));

    std::cout << "Total: " << c.total() << " alertas\n\n";
    c.exibir_todos();

    return 0;
}
