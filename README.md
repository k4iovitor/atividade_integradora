
## Descrição do Projeto

Sistema de gerenciamento de alertas que simula uma central de monitoramento de sensores. A central recebe alertas de diferentes tipos e severidades, armazena-os e exibe-os de forma polimórfica — cada alerta sabe como se formatar e se identificar.

---

## Diagrama de Classes 

```
        ┌──────────────────┐
        │   «interface»    │
        │    formatavel     │
        ├──────────────────┤
        │ + formatar(): str│  ← método virtual puro
        └────────┬─────────┘
                 │ herança
        ┌────────┴─────────┐
        │  «classe abstrata»│
        │      alerta       │
        ├───────────────────┤
        │ - origem_: string │
        │ - severidade_: int│
        ├───────────────────┤
        │ + exibir()        │
        │ + tipo(): str     │  ← virtual puro
        │ + formatar(): str │  ← herdado de formatavel
        │ + origem(): str   │
        │ + severidade(): int│
        └───┬───┬───┬───────┘
            │   │   │
    ┌───────┘   │   └────────┐
    │           │            │
┌───┴────┐ ┌───┴───┐  ┌─────┴─────┐
│ «final»│ │alerta │  │  alerta   │
│ alerta │ │ aviso │  │   info    │
│critico │ │       │  │           │
│sev = 3 │ │sev = 2│  │  sev = 1  │
└────────┘ └───────┘  └─────┬─────┘
                            │ herança multinível
                      ┌─────┴─────┐
                      │  alerta   │
                      │   debug   │
                      │           │
                      │+ contexto_│
                      └───────────┘
```

---

### 1. Abstração
- A classe `alerta` é **abstrata** — não pode ser instanciada diretamente.
- Possui métodos virtuais puros (`tipo()` e `formatar()`), obrigando as subclasses a fornecerem implementações concretas.

### 2. Encapsulamento
- Atributos das classes são **privados** (`private`), acessíveis apenas via métodos públicos (getters).
- Exemplo: `origem_` e `severidade_` em `alerta` são acessados via `origem()` e `severidade()`.

### 3. Herança
- **Herança simples**: `alerta_critico`, `alerta_aviso` e `alerta_info` herdam diretamente de `alerta`.
- **Herança multinível**: `alerta_debug` herda de `alerta_info`, que herda de `alerta`, formando uma cadeia de 3 níveis.

### 4. Polimorfismo
- **Polimorfismo em tempo de execução (late binding)**: ao chamar `exibir()` em um ponteiro `alerta*`, os métodos `tipo()` e `formatar()` são resolvidos dinamicamente, chamando a versão da subclasse concreta.
- A `central` armazena `unique_ptr<alerta>` e trata todos os alertas uniformemente, sem conhecer seus tipos concretos.

### 5. Interface
- `formatavel` é uma **interface pura** (classe com apenas métodos virtuais puros), equivalente a interfaces em Java.
- Define o contrato: qualquer classe formatável deve implementar `formatar()`.

### 6. Especificadores `final` e `override`
- `alerta_critico` usa **`final`** para impedir extensão da hierarquia.
- Todos os métodos sobrescritos usam **`override`** para segurança em tempo de compilação.

### 7. Gerenciamento de Memória (RAII e Smart Pointers)
- Uso de `std::unique_ptr<alerta>` para ownership exclusivo e destruição automática.
- `std::make_unique` cria os objetos de forma segura (sem `new`/`delete` manual).
- `std::move` transfere ownership ao registrar alertas na central.

### 8. Tratamento de Exceções
- O construtor de `alerta` lança `std::invalid_argument` se a severidade estiver fora do intervalo [1, 3].

### Saída esperada

```
Total: 4 alertas

[CRITICO] sensor1: temperatura 95.3 graus
[AVISO] sensor2: umidade 78.5 pct
[INFO] sistema: reinicio agendado
[INFO] modulo_rede: latencia elevada [debug: ping 350ms gateway 10.0.0.1]
```
