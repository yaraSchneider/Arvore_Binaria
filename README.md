# Árvore Binária - Atividade de Estruturas de Dados

## Descrição do Projeto

Este repositório contém a resolução de exercícios sobre **Árvores Binárias de Busca (ABB)** desenvolvidos em Linguagem C. A atividade busca demonstrar clareza, organização e compreensão profunda do funcionamento de estruturas de dados fundamentais em ciência da computação.

---

## 📋 Conteúdo do Repositório

### Arquivos de Código-Fonte (C)

| Arquivo | Descrição |
|---------|-----------|
| **exe3.c** | Definição da estrutura de dados `No` para representar nós da árvore binária |
| **exe4.h** | Implementação da função `criarNo()` - aloca memória e inicializa um novo nó |
| **exe6.c** | Implementação da função `inserir()` - insere valores mantendo a ordem BST |
| **exe8.h** | Implementação da função `buscar()` - busca recursiva por um valor na árvore |
| **exe10.c** | Programa principal - demonstra todas as operações com um exemplo completo |

### Arquivos de Documentação (LaTeX)

Os arquivos `.tex` contêm as descrições dos enunciados dos exercícios e orientações detalhadas para cada etapa.

---

## 🌳 O que é uma Árvore Binária de Busca?

Uma **Árvore Binária de Busca (ABB)** é uma estrutura de dados que organiza valores em uma árvore onde:

### Características Principais:
- **Cada nó** possui um valor inteiro e até 2 filhos (esquerdo e direito)
- **Propriedade de Busca**: Para qualquer nó da árvore:
  - Todos os valores da **subárvore esquerda** são **menores** que o valor do nó
  - Todos os valores da **subárvore direita** são **maiores** que o valor do nó

### Estrutura do Nó:
```
typedef struct No {
    int valor;              // Valor armazenado
    struct No *esquerda;    // Ponteiro para filho esquerdo
    struct No *direita;     // Ponteiro para filho direito
} No;
```

### Exemplo Visual:
```
        50
       /  \
      30   70
     / \   / \
    20 40 60 80
```

Nesta árvore:
- 50 é a raiz
- 30, 20, 40 estão à esquerda (menores que 50)
- 70, 60, 80 estão à direita (maiores que 50)

---

## 🔧 Operações Implementadas

### 1. **Criar Nó** (`criarNo`)
```c
No* criarNo(int valor)
```
- Aloca memória dinâmica para um novo nó
- Inicializa o valor
- Define os filhos como NULL (nó folha)

### 2. **Inserir Valor** (`inserir`)
```c
No* inserir(No *raiz, int valor)
```
- Insere recursivamente um valor mantendo a propriedade ABB
- Se valor < raiz, vai para esquerda
- Se valor > raiz, vai para direita
- Se valor = raiz, ignora (evita duplicatas)

### 3. **Buscar Valor** (`buscar`)
```c
int buscar(No *raiz, int valor)
```
- Busca recursivamente um valor na árvore
- Retorna 1 se encontrado, 0 caso contrário
- Usa a propriedade de ordem para reduzir buscas

### 4. **Percurso em Ordem** (`emOrdem`)
```c
void emOrdem(No *raiz)
```
- Percurso em-ordem (esquerda → raiz → direita)
- Imprime os valores em **ordem crescente**

---

## 💻 Como Compilar e Executar

### Pré-requisitos
- Compilador C (GCC, Clang ou similar)
- Terminal/Prompt de Comando
- Editor de texto (opcional, para visualizar código)

### Compilação

#### Windows (MinGW/GCC):
```bash
gcc -o exe10 exe10.c
```

#### Linux/macOS (GCC):
```bash
gcc -o exe10 exe10.c
```

#### Com warnings habilitados (recomendado):
```bash
gcc -Wall -Wextra -o exe10 exe10.c
```

### Execução

#### Windows:
```bash
exe10.exe
```

#### Linux/macOS:
```bash
./exe10
```

### Saída Esperada:
```
Valores em ordem:
20 30 40 50 60 70 80 

Valor 40 encontrado!
Valor 90 nao encontrado!
```

---

## 📊 Compilação e Teste de Todos os Arquivos

Se desejar compilar e testar cada exercício individualmente:

```bash
# Compilar exe3 (apenas estrutura - não tem main)
gcc -c exe3.c

# Compilar exe4 (funções de criação)
gcc -c exe4.h

# Compilar exe6 (função de inserção)
gcc -c exe6.c

# Compilar exe8 (função de busca)
gcc -c exe8.h

# Compilar exe10 (programa completo com main)
gcc -o exe10 exe10.c
./exe10
```

---

## 🎯 Conceitos Demonstrados

### 1. **Alocação Dinâmica de Memória**
- Uso de `malloc()` para criar nós em tempo de execução
- Gerenciamento de ponteiros

### 2. **Recursão**
- Implementação recursiva de inserção, busca e percurso
- Compreensão de casos base e casos recursivos

### 3. **Estruturas de Dados**
- Uso de `typedef struct` para definir tipos personalizados
- Ponteiros para auto-referência

### 4. **Algoritmos de Busca**
- Busca binária em árvores (O(log n) no melhor caso)
- Diferença entre busca linear e busca estruturada

### 5. **Ordenação através de Estrutura**
- Percurso em-ordem produz sequência ordenada
- Propriedade fundamental da ABB

---

## 📌 Observações Importantes

### Gerenciamento de Memória
O código atual **não desaloca** a memória utilizando `free()`. Em uma aplicação real, seria necessário implementar uma função para liberar memória:

```c
void liberarArvore(No *raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}
```

### Limitações da Implementação
- Não trata duplicatas (apenas ignora)
- Não implementa balanceamento (pode degenedar em lista ligada)
- Sem função de remoção de nós

### Sugestões de Melhorias
- Implementar deleção de nós
- Adicionar rotinas de balanceamento (AVL ou Rubro-Negra)
- Implementar percursos pré-ordem e pós-ordem
- Calcular altura e profundidade da árvore

---

## 🧠 Entendimento Esperado do Aluno

Ao concluir este projeto, o aluno deve compreender:

✅ Como funcionam árvores binárias e suas propriedades  
✅ Diferença entre árvores de busca balanceadas e desbalanceadas  
✅ Quando usar recursão e sua eficiência  
✅ Alocação dinâmica e gestão de memória em C  
✅ Análise de complexidade de algoritmos (O(n), O(log n))  
✅ Como estruturas de dados otimizam buscas e inserções  

---

## 📚 Referências e Recursos Adicionais

- **Estruturas de Dados Clássicas**: Livro "Introduction to Algorithms" (CLRS)
- **Recursão**: Artigos sobre análise de complexidade recursiva
- **C Avançado**: Documentação de ponteiros e alocação dinâmica
- **Visualização**: Sites como visualgo.net para ver ABBs em ação

---

## ✍️ Autor
**Yara Schneider**

Repositório: https://github.com/yaraSchneider/Arvore_Binaria

---

**Versão**: 1.0  
**Data**: Maio de 2026  
**Linguagem Principal**: C (64.8%)
