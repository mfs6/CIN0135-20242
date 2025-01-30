## Aula 13,  30-01-2025 


## Herança e Polimorfismo na Programação Orientada a Objetos (POO)  

Além da abstração e encapsulamento (vistos [anteriormente](../aula10/aula10.md)), a POO se baseia em outros dois conceitos-chave: herança e polimorfismo.


### Herança  

A **herança** é um mecanismo da POO que permite a crição de subtipos de um certo TAD. Através dela, uma **classe derivada**, ou **subclasse**, "herda" atributos e métodos de outra **classe base**, ou **superclasse**. Isso promove a **reutilização de código** e facilita a manutenção.  


#### Exemplo de Herança em C++

```cpp

```

A herança permite descrever uma **Interface**, ou seja, um contrato ou comportamento básico esperado para vários tipos. Em C++ isso é feito através de funções virtuais (`virtual`) que permitem definir **(super)classes abstratas**.


### Polimorfismo  

O **polimorfismo** permite que uma mesma interface ou método tenha diferentes implementações. Isso melhora a **extensibilidade** e a **flexibilidade** do código.  

#### Tipos de Polimorfismo

1. Polimorfismo de Sobrecarga (Compile-time)
   - Mesma função com diferentes assinaturas.
   
2. Polimorfismo de Sobrescrita (Runtime)
   - Métodos da classe derivada substituem os da classe base.


#### Polimorfismo por Sobrecarga

A **sobrecarga** ocorre quando definimos várias funções com o mesmo nome, mas com parâmetros diferentes.

```cpp
```

---

### **Polimorfismo por Sobrescrita com Métodos Virtuais**

A **sobrescrita** permite que uma classe filha forneça sua própria implementação para um método da classe pai.  

```cpp
```

