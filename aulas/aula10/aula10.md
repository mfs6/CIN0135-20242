## Aula 10,  17-12-2024 

### Orientação a Objetos: Abstração e Encapsulamento

**Abstração**  
Na Programação Orientada a Objetos (OOP), **abstração** é uma técnica que permite identificar quais detalhes de um objeto ou classe são relevantes para o sistema e devem ser expostos, enquanto os detalhes desnecessários ou complexos são ignorados. Em outras palavras, a abstração foca nos **aspectos essenciais** que definem o comportamento ou as características de um objeto, ocultando a complexidade subjacente.  

**Exemplo:** Em um sistema bancário, uma classe **ContaBancária** pode expor métodos como `sacar()` e `depositar()`, mas os cálculos internos e os processos detalhados (como taxas ou atualizações no banco de dados) permanecem ocultos para o usuário.

---

**Encapsulamento**  
No contexto de OOP, **encapsulamento** é a técnica de **empacotar dados** (atributos) e os métodos que operam sobre esses dados em uma única unidade (a classe) e restringir o acesso direto a certos elementos internos. Através do encapsulamento, pode-se controlar quais partes da classe são **visíveis** (públicas) e quais são **ocultas** (privadas), garantindo maior segurança e integridade dos dados.

**Exemplo:** Em uma classe `ContaBancária`, os atributos como `saldo` podem ser privados e acessíveis apenas por meio de métodos públicos como `getSaldo()` ou `depositar()`, impedindo que o valor do saldo seja modificado diretamente de fora da classe.

---

**Resumo:**  
- **Abstração**: Foca em **"o que"** um objeto faz, destacando suas características essenciais e omitindo detalhes internos.  
- **Encapsulamento**: Foca em **"como"** os dados e métodos estão organizados e protegidos dentro da classe, escondendo detalhes de implementação.


### Referências

[1] [Abstraction, Encapsulation, and Information Hiding](https://www.tonymarston.co.uk/php-mysql/abstraction.txt)
