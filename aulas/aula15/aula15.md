## Aula 15,  11-02-2025 

### Templates e Programação Genérica

- **Ideia Básica**: Criar código "parametrizado" com diferentes tipos de dados sem duplicar código.
- Dois tipos básicos:
    1. Function Templates
    2. Class Templates


#### Function Templates (Templates de Função)  
Permitem criar **funções genéricas** que funcionam com diferentes tipos de dados.

```cpp
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
```
- Pode ser usado com `int`, `double`, `char`, etc.  
  ```cpp
  max(3, 7);       // int
  max(4.5, 2.3);   // double
  ```

#### Class Templates (Templates de Classe)
Permitem criar **classes genéricas**, especialmente containers

#### **Exemplo:**
```cpp
template <typename T>
class Box {
    T value;
public:
    Box(T v) : value(v) {}
    T getValue() { return value; }
};
```
- Pode instanciar com diferentes tipos:
  ```cpp
  Box<int> intBox(10);
  Box<std::string> strBox("Hello");
  ```

___
[[Código-fonte: /src]](./src)   [[< Anterior]](../aula14/aula14.md) [[Próximo >]](../aula16/aula16.md) [[Índice ^]](../index.md)

