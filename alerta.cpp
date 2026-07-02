#include "alerta.hpp"

alerta::alerta(const std::string& origem, int sev)
    : origem_{origem}, severidade_{sev} {
    if (sev < 1 || sev > 3) {
        throw std::invalid_argument(
            "Severidade deve estar entre 1 e 3");
    }
}

void alerta::exibir() const {
    std::cout << "[" << tipo()
              << "] " << origem_ << ": "
              << formatar()
              << "\n";
}

std::string alerta::origem() const {
    return origem_;
}

int alerta::severidade() const {
    return severidade_;
}
