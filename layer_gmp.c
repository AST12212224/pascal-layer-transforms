#include <stdio.h>
#include <gmp.h>

int main() {
    int l, p_max;

    printf("Enter layer l: ");
    scanf("%d", &l);

    printf("Enter max power p: ");
    scanf("%d", &p_max);

    if (p_max < l) p_max = l + 6;

    char fname[32];
    sprintf(fname, "l_%d.tsv", l);
    FILE *fp = fopen(fname, "w");

    /* Header */
    fprintf(fp, "power\trow\n");

    mpz_t coeff, inner, bin_lv, bin_pk, term;
    mpz_inits(coeff, inner, bin_lv, bin_pk, term, NULL);

    for (int p = l; p <= p_max; p++) {

        /* column 1: power */
        fprintf(fp, "%d\t[", p);

        /* column 2: triangle row */
        for (int k = p - l; k >= 0; k--) {

            mpz_set_ui(inner, 0);

            for (int v = 0; v <= l; v++) {
                mpz_bin_uiui(bin_lv, l, v);
                mpz_ui_pow_ui(term, l - v, p - k);
                mpz_mul(term, term, bin_lv);

                if (v % 2)
                    mpz_sub(inner, inner, term);
                else
                    mpz_add(inner, inner, term);
            }

            mpz_bin_uiui(bin_pk, p, k);
            mpz_mul(coeff, inner, bin_pk);

            gmp_fprintf(fp, "%Zd", coeff);
            if (k > 0) fprintf(fp, " ");
        }

        fprintf(fp, "]\n");
    }

    mpz_clears(coeff, inner, bin_lv, bin_pk, term, NULL);
    fclose(fp);

    printf("Generated %s\n", fname);
    return 0;
}

