#include <stdio.h>
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
    return acos(cosTheta) * (180.0 / PI); // Convertendo de radianos para graus
}

// Função para verificar se os vetores são colineares
int saoColineares(Vetor v1, Vetor v2, Vetor v3) {
    double determinante = v1.x * (v2.y - v3.y) + v2.x * (v3.y - v1.y) + v3.x * (v1.y - v2.y);
    return determinante == 0; // Retorna 1 se colineares, 0 caso contrário
}

// Função para verificar o tipo de triângulo por lados
const char* tipoTrianguloPorLados(double a, double b, double c) {
    if (a == b && b == c) {
        return "Equilátero";
    } else if (a == b || b == c || a == c) {
        return "Isósceles";
    } else {
        return "Escaleno";
    }
}

// Função para verificar o tipo de triângulo por ângulos
const char* tipoTrianguloPorAngulos(double ang1, double ang2, double ang3) {
    if (ang1 == 90.0 || ang2 == 90.0 || ang3 == 90.0) {
        return "Retângulo";
    } else if (ang1 < 90.0 && ang2 < 90.0 && ang3 < 90.0) {
        return "Acutângulo";
    } else {
        return "Obtusângulo";
    }
}

int main() {
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

    // Cálculos básicos
    double ang1 = calcularAngulo(v1, v2);
    double ang2 = calcularAngulo(v2, v3);
    double ang3 = calcularAngulo(v3, v1);

    // Cálculo dos lados
    double a = modulo(v1);
    double b = modulo(v2);
    double c = modulo(v3);

    // Saída dos ângulos
    printf("Ângulo entre V1 e V2: %.2f graus\n", ang1);
    printf("Ângulo entre V2 e V3: %.2f graus\n", ang2);
    printf("Ângulo entre V3 e V1: %.2f graus\n", ang3);

    // Classificação do triângulo
    printf("Tipo de triângulo por lados: %s\n", tipoTrianguloPorLados(a, b, c));
    printf("Tipo de triângulo por ângulos: %s\n", tipoTrianguloPorAngulos(ang1, ang2, ang3));

    return 0;
}
