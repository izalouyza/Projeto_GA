#include <stdio.h>
#include <math.h>
#include <locale.h>

#define PI 3.14159265

// Estrutura para armazenar um vetor 2D
typedef struct {
    double x;
    double y;
} Vetor;

// Função para calcular o módulo de um vetor
double modulo(Vetor v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

// Função para calcular o produto escalar entre dois vetores
double produtoEscalar(Vetor u, Vetor v) {
    return u.x * v.x + u.y * v.y;
}

// Função para calcular o ângulo entre dois vetores (em graus)
double calcularAngulo(Vetor u, Vetor v) {
    double modU = modulo(u);
    double modV = modulo(v);
    if (modU == 0 || modV == 0) return 0.0;

    double cosTheta = produtoEscalar(u, v) / (modU * modV);

    // Correção numérica para evitar erros de domínio em acos
    if (cosTheta > 1.0) cosTheta = 1.0;
    if (cosTheta < -1.0) cosTheta = -1.0;

    return acos(cosTheta) * (180.0 / PI);
}

// Função para verificar se três pontos são colineares
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
    setlocale(LC_ALL, "Portuguese");

    Vetor v1, v2, v3;

    // Entrada dos vetores
    printf("Digite as coordenadas do vetor V1 (x y): ");
    scanf("%lf %lf", &v1.x, &v1.y);
    printf("Digite as coordenadas do vetor V2 (x y): ");
    scanf("%lf %lf", &v2.x, &v2.y);
    printf("Digite as coordenadas do vetor V3 (x y): ");
    scanf("%lf %lf", &v3.x, &v3.y);

    // Verificação de colinearidade
    if (saoColineares(v1, v2, v3)) {
        printf("Os vetores são colineares e não formam um triângulo válido.\n");
        return 1; // Encerra o programa
    }

    // Construção dos vetores de lados do triângulo
    Vetor AB = {v2.x - v1.x, v2.y - v1.y};  // Vetor do ponto A para o ponto B
    Vetor AC = {v3.x - v1.x, v3.y - v1.y};  // Vetor do ponto A para o ponto C
    Vetor BC = {v3.x - v2.x, v3.y - v2.y};  // Vetor do ponto B para o ponto C

    // Vetores invertidos para cálculo dos ângulos em B e C
    Vetor BA = {-AB.x, -AB.y};  // Vetor de B para A
    Vetor CB = {-BC.x, -BC.y};  // Vetor de C para B
    Vetor CA = {-AC.x, -AC.y};  // Vetor de C para A

    // Cálculo dos ângulos internos do triângulo
    double ang1 = calcularAngulo(AB, AC);  // Ângulo no ponto A entre AB e AC
    double ang2 = calcularAngulo(BA, BC);  // Ângulo no ponto B entre BA e BC
    double ang3 = calcularAngulo(CA, CB);  // Ângulo no ponto C entre CA e CB

    // Soma dos ângulos - deve ser aproximadamente 180 graus
    double somaAngulos = ang1 + ang2 + ang3;
    if (somaAngulos != 180.0) {
        printf("Os vetores não formam um triângulo válido.\n");
        return 1;
    }

    // Cálculo dos módulos (lados do triângulo)
    double ladoAB = modulo(AB);
    double ladoAC = modulo(AC);
    double ladoBC = modulo(BC);

    // Saída dos ângulos
    printf("\nÂngulo no ponto V1: %.2f graus\n", ang1);
    printf("Ângulo no ponto V2: %.2f graus\n", ang2);
    printf("Ângulo no ponto V3: %.2f graus\n", ang3);

    // Classificação do triângulo
    printf("\nTipo do triângulo por lados: %s\n", tipoTrianguloPorLados(ladoAB, ladoAC, ladoBC));
    printf("Tipo do triângulo por ângulos: %s\n", tipoTrianguloPorAngulos(ang1, ang2, ang3));

    return 0;
}
