# Pascal Layer Transformed Triangles

**Preprint (Zenodo):** https://doi.org/10.5281/zenodo.18084442

---

## Description

This repository contains datasets generated from a layer-based finite-difference transform derived from Pascal-type binomial operators acting on integer powers.

For a fixed layer `l` and power `p`, the transform is defined by

\[
T_{l,p}(n) = \sum_{v=0}^{l} (-1)^v \binom{l}{v} (n + l - v)^p
\]

For each fixed `l` and increasing `p`, this operator produces a family of polynomials whose coefficients form a triangular structure.  
The degree of each polynomial is `p - l`; higher-degree terms vanish automatically due to finite-difference cancellation.

---

## Contents

```

data/
l_1.tsv
l_2.tsv
...
l_16.tsv

src/
layer_triangle_tsv.c
auto_run.c

```

- `data/` contains the generated datasets
- `src/` contains the exact C code used to generate them

---

## Data format

All datasets are stored as **TSV (tab-separated values)** files with exactly two columns:

```

power    row

```

Example:

```

2   [2]
3   [6 6]
4   [12 24 14]
5   [20 60 70 30]
6   [30 120 210 180 62]

```

- Column 1: the power `p`
- Column 2: the coefficient row of the transformed polynomial, ordered from highest surviving power to the constant term

This format preserves the intrinsic triangular structure without artificial padding.

---

## Generation method

- Implemented in C
- Exact arithmetic using the GNU Multiple Precision Arithmetic Library (GMP)
- Binomial coefficients computed via `mpz_bin_uiui`
- No factorials are explicitly evaluated
- All results are exact and reproducible

---

## Mathematical context

This construction is related to:

- Finite difference operators
- Pascal triangle and binomial transforms
- Polynomial degree collapse
- Discrete calculus and Stirling-type structures

The purpose of this repository is **data availability and reproducibility**.  
Theoretical derivations and interpretation are provided in the linked preprint.

---

## License

MIT License
