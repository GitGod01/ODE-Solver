cat > README.md << 'EOF'
# ODE Solver — Numerical Integration in C++

A command-line tool that solves Ordinary Differential Equations (ODEs) using three numerical integration schemes and compares their accuracy against the exact analytical solution.

## Methods Implemented
- **Euler Method** — First-order, simplest discretization scheme
- **RK2 (Midpoint Method)** — Second-order Runge-Kutta
- **RK4 (Classic Runge-Kutta)** — Fourth-order, industry standard integration scheme

## Problem Solved
Solves the exponential decay ODE: `dy/dt = -2y`, `y(0) = 1`  
Exact solution: `y = e^(-2t)`

## Results
| Method | Max Error |
|--------|-----------|
| Euler  | ~0.040    |
| RK2    | ~0.003    |
| RK4    | ~0.000006 |

RK4 is ~6,000x more accurate than Euler for the same step size.

## Build & Run
```bash
