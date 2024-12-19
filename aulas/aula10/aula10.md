## Aula 10,  17-12-2024 

### Orientação a Objetos

Programação Orientada a Objetos (Object-oriented Programming --- OOP) é um paradigma de programação que consiste em organizar o código em torno de tipos abstratos de dados, ou **classes**, que podem ser definidos pelo programador, e que são constituídos de maneira conjunta pelos dados da informação, ou **atributos**, e pelas operações associadas ao tipo atuando sobre esses dados, ou **métodos**. Um **objeto** é uma *instância* ou *realização* de uma classe. Classes podem representar conceitos ou entidades concretas do domínio de aplicação (como contas bancárias, funcionários, documentos, personagem de um jogo, etc.) como também abstrações como relacionamentos entre as entidades, funções matemáticas ou até construtos da própria linguagem de programação.

A OOP baseia-se em quatro conceitos centrais:
* Abstração
* Encapsulamento
* Herança 
* Polimorfismo

Nesta aula vamos nos centrar sobre os dois primeiros. É importante antes destacar que, apesar da OOP ser reconhecida hoje em dia como um paradigma dos mais importantes e populares, ela não foi concebida de maneira acabada e de uma só vez como tal. Ao contrário, os seus princípios básicos e definidores emergiram e foram se sedimentando aos poucos, ao longo da história, com a evolução das técnicas e linguagens de programação. Essas linguagens foram introduzindo os conceitos acima e outros relacionados em diferentes variações, umas mais e outras menos, e com o tempo algumas foram se tornando mais populares, enquanto outros foram sendo abandonados. A palestra a seguir contém uma boa discussão sobre os conceitos básicos e evolução das Linguagens OO.

[**Vídeo:** The Return of Procedural Programming - Richard Feldman](https://youtu.be/vQPHtAxOZZw?si=5ucZjHMC_AmVIsH8)

### Abstração e Encapsulamento [[2]](#aula10ref2)

#### Abstração

Na Programação Orientada a Objetos (OOP), **abstração** é uma técnica que permite identificar quais detalhes de um objeto ou classe são relevantes para o sistema e devem ser expostos, enquanto os detalhes desnecessários ou complexos são ignorados. Em outras palavras, a abstração foca nos **aspectos essenciais** que definem o comportamento ou as características de um objeto, ocultando a complexidade subjacente.  

**Exemplo:** Em um sistema bancário, uma classe **ContaBancária** pode expor métodos como `sacar()` e `depositar()`, mas os cálculos internos e os processos detalhados (como taxas ou atualizações no banco de dados) permanecem ocultos para o usuário.


#### Encapsulamento

No contexto de OOP, **encapsulamento** é a técnica de **empacotar dados** (atributos) e os métodos que operam sobre esses dados em uma única unidade (a classe) e restringir o acesso direto a certos elementos internos. Através do encapsulamento, pode-se controlar quais partes da classe são **visíveis** (públicas) e quais são **ocultas** (privadas), garantindo maior segurança e integridade dos dados.

**Exemplo:** Em uma classe `ContaBancária`, os atributos como `saldo` podem ser privados e acessíveis apenas por meio de métodos públicos como `getSaldo()` ou `depositar()`, impedindo que o valor do saldo seja modificado diretamente de fora da classe.


**Resumo:**  

- **Abstração**: Foca em **"o que"** um objeto faz, destacando suas características essenciais e omitindo detalhes internos.  
- **Encapsulamento**: Foca em **"como"** os dados e métodos estão organizados e protegidos dentro da classe, escondendo detalhes de implementação.


### Referências

<a id="aula10ref1"></a>[1] [Richard Feldman. The Return of Procedural Programming](https://youtu.be/vQPHtAxOZZw?si=5ucZjHMC_AmVIsH8)

<a id="aula10ref2"></a>[2] [Edward V. Berard. Abstraction, Encapsulation, and Information Hiding](https://www.tonymarston.co.uk/php-mysql/abstraction.txt)

