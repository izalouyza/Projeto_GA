#include <stdio.h>
#include <locale.h>
#include <math.h>

#define PI 3.14159265

// Estrutura para armazenar um vetor
typedef struct {
    double x;
    double y;
} Vetor;

// Função para calcular o módulo (norma) de um vetor
double modulo(Vetor v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

// Função para calcular o produto escalar entre dois vetores
double produtoEscalar(Vetor u, Vetor v) {
    return (u.x * v.x + u.y * v.y);
}

// Função para calcular o ângulo entre dois vetores em graus
double calcularAngulo(Vetor u, Vetor v) {
    double cosTheta = produtoEscalar(u, v) / (modulo(u) * modulo(v));
    // Corrigir possíveis erros de precisão fazendo clamp para o intervalo [-1, 1]
    if (cosTheta > 1.0) cosTheta = 1.0;
    if (cosTheta < -1.0) cosTheta = -1.0;
    return acos(cosTheta) * (180.0 / PI); // Convertendo de radianos para graus
}

// Função para verificar se os vetores são colineares
int saoColineares(Vetor v1, Vetor v2, Vetor v3) {
    double determinante = v1.x * (v2.y - v3.y) + v2.x * (v3.y - v1.y) + v3.x * (v1.y - v2.y);
    return fabs(determinante) < 1e-10; // Retorna 1 se colineares, 0 caso contrário (tolerância para ponto flutuante)
}

// Função para calcular a distância entre dois pontos
double distancia(Vetor a, Vetor b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

// Função para verificar o tipo de triângulo por lados
const char* tipoTrianguloPorLados(double a, double b, double c) {
    if (fabs(a - b) < 1e-10 && fabs(b - c) < 1e-10) {
        return "Equilátero";
    } else if (fabs(a - b) < 1e-10 || fabs(b - c) < 1e-10 || fabs(a - c) < 1e-10) {
        return "Isósceles";
    } else {
        return "Escaleno";
    }
}

// Função para verificar o tipo de triângulo por ângulos
const char* tipoTrianguloPorAngulos(double ang1, double ang2, double ang3) {
    if (fabs(ang1 - 90.0) < 1e-10 || fabs(ang2 - 90.0) < 1e-10 || fabs(ang3 - 90.0) < 1e-10) {
        return "Retângulo";
    } else if (ang1 < 90.0 && ang2 < 90.0 && ang3 < 90.0) {
        return "Acutângulo";
    } else {
        return "Obtusângulo";
    }
}

// Função para criar vetor que vai de a até b (b - a)
Vetor vetorEntre(Vetor a, Vetor b) {
    Vetor v;
    v.x = b.x - a.x;
    v.y = b.y - a.y;
    return v;
}

int main() {
    setlocale(LC_ALL, "Portuguese"); 
    Vetor v1, v2, v3;

    // Entrada dos dados
    printf("Digite as coordenadas do primeiro vetor (x1 y1): ");
    scanf("%lf %lf", &v1.x, &v1.y);
    printf("Digite as coordenadas do segundo vetor (x2 y2): ");
    scanf("%lf %lf", &v2.x, &v2.y);
    printf("Digite as coordenadas do terceiro vetor (x3 y3): ");
    scanf("%lf %lf", &v3.x, &v3.y);

    // Verificação de colinearidade
    if (saoColineares(v1, v2, v3)) {
        printf("Os vetores são colineares e não formam um triângulo.\n");
        return 1; // Encerra o programa
    }

    // Cálculo dos lados (distâncias entre pontos)
    double a = distancia(v2, v3); // Lado entre v2 e v3
    double b = distancia(v1, v3); // Lado entre v1 e v3
    double c = distancia(v1, v2); // Lado entre v1 e v2

    // Construir os vetores para cálculo dos ângulos no triângulo
    Vetor vetorA = vetorEntre(v2, v3); // vetor lado a
    Vetor vetorB = vetorEntre(v1, v3); // vetor lado b
    Vetor vetorC = vetorEntre(v1, v2); // vetor lado c

    // Para ângulos, precisamos dos vetores entre os lados a partir de cada vértice:
    // Ângulo no vértice v1 entre os vetores (v2 - v1) e (v3 - v1)
    Vetor v1_v2 = vetorEntre(v1, v2);
    Vetor v1_v3 = vetorEntre(v1, v3);
    double ang1 = calcularAngulo(v1_v2, v1_v3);

    // Ângulo no vértice v2 entre os vetores (v1 - v2) e (v3 - v2)
    Vetor v2_v1 = vetorEntre(v2, v1);
    Vetor v2_v3 = vetorEntre(v2, v3);
    double ang2 = calcularAngulo(v2_v1, v2_v3);

    // Ângulo no vértice v3 entre os vetores (v1 - v3) e (v2 - v3)
    Vetor v3_v1 = vetorEntre(v3, v1);
    Vetor v3_v2 = vetorEntre(v3, v2);
    double ang3 = calcularAngulo(v3_v1, v3_v2);

    // Saída dos ângulos
    printf("Ângulo no vértice V1: %.2f graus\n", ang1);
    printf("Ângulo no vértice V2: %.2f graus\n", ang2);
    printf("Ângulo no vértice V3: %.2f graus\n", ang3);

    // Classificação do triângulo
    printf("Tipo de triângulo por lados: %s\n", tipoTrianguloPorLados(a, b, c));
    printf("Tipo de triângulo por ângulos: %s\n", tipoTrianguloPorAngulos(ang1, ang2, ang3));

    return 0;
}
