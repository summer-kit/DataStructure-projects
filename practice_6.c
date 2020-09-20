#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNIGS
#define MAX_TERMS 80

typedef struct {
    int expon;
    float coeff;
} Term;

typedef struct {
    int nTerms;
    Term term[MAX_TERMS];
} SparsePoly;

void readSPoly(SparsePoly* p);
void printSPoly(SparsePoly* p, char *str);
void addSPoly(SparsePoly* a, SparsePoly* b, SparsePoly* c);

int main()
{
    SparsePoly a, b, c, d, e;
    readSPoly(&a);
    readSPoly(&b);
    addSPoly(&a, &b, &c);

    printSPoly(&a, " A = ");
    printSPoly(&b, " B = ");
    printSPoly(&c, "A + B = ");

    return 0;
}

void readSPoly(SparsePoly* p) {
    p -> nTerms = 0;
    while(1) {
        printf("계수 차수 입력(종료 : -1): ");
        scanf("%f%d", &(p->term[p->nTerms].coeff), &(p->term[p->nTerms].expon));
        if(p->term[p->nTerms].expon<0) {
            printSPoly(p, "입력 다항식 : ");
            return ;
        }
        p->nTerms ++;
    }
}

void addSPoly(SparsePoly* a, SparsePoly* b, SparsePoly* c) {
    int i, j;

    c->nTerms = 0;
    for (i = j = 0; i<a->nTerms || j<b->nTerms;) {
        if (i == a->nTerms|| a->term[i].expon < b->term[j].expon)
            c->term[c->nTerms++] = b->term[j++];
        else if (j == b->nTerms || a->term[i].expon > b->term[j].expon)
            c->term[c->nTerms++] = a->term[i++];
        else {
            c->term[c->nTerms] = a->term[i++];
            c->term[c->nTerms++].coeff += b->term[j++].coeff;
        }
    }
}

void printSPoly(SparsePoly* p, char *str) {
    int i;
    printf("\t%s", str);
    for (i = 0; i < p->nTerms; i++) {
        printf("%5.1f", p->term[i].coeff);
        if (p->term[i].expon>0)
        printf("x^%d + ", p->term[i].expon);
    }
    printf("\n");
    return ;
}
