# 📐 Projeto de Geometria Analítica: Triângulos no Plano

Esse repositório refere-se ao trabalho da primeira unidade da disciplina de Geometria Analítica. O programa, em linguagem C, é destinado a receber as coordenadas de três vetores no plano (representando os lados de um triângulo com origem comum), calcular os ângulos entre eles e, dessa forma, identificar o tipo de triângulo formado (equilátero, isósceles, escaleno, retângulo, obtusângulo ou acutângulo).

![Linguagem](https://img.shields.io/badge/Linguagem-C-blue)
![Ambiente](https://img.shields.io/badge/Ambiente-VSCode-blue)
![Último commit](https://img.shields.io/github/last-commit/izalouyza/Projeto_GA)

---

## 👨‍👧‍👧 Autores

👨‍🏫 **Professor:** Otávio Floriano Paulino

👩‍🎓 **Discentes:** [Izadora Louyza Silva Figueiredo](https://github.com/izalouyza) e [Lívian Maria Lucena Gomes Pinheiro](https://github.com/livianlucena)

---

## ⚙️ Exemplo de Uso

> **Fluxo de execução do programa:**

1. O usuário **insere as coordenadas** dos três vetores: `V1`, `V2` e `V3`.  
2. O programa **calcula os ângulos** entre os vetores.  
3. É feita a **verificação automática do tipo de triângulo** formado.  
4. O resultado é exibido em tela.  
5. O sistema encerra sua execução.  

---

## 📂 Estrutura de Pastas

```
Projeto_GA/
src/
│
├── codigo-fonte/
│   └── main.c
│
└── README.md                      
                
```
main.c → Contém o código principal do programa e a lógica de análise dos triângulos.

---

## 🚀 Como Compilar e Executar  

Siga as etapas abaixo para rodar o projeto localmente:  

### 1. Verifique o ambiente  

Certifique-se de ter instalado um compilador **C** (como o **GCC**) e um ambiente de desenvolvimento, como **VSCode**.

### 2. Clone o repositório  

```
git clone https://github.com/izalouyza/Projeto_GA
```

### 3. Acesse o diretório do código-fonte
```
cd Projeto_GA/src/codigo-fonte
```

### 4. Compilar o programa
```
gcc -o aplicacao main.c
```
### 5. Executar o programa
```
./aplicacao
```
---
