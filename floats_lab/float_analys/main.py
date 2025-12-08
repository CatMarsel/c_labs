import csv
import math
import matplotlib.pyplot as plt

# === 1. Графики f(x), f'(x), F(x) ===

xs = []
fs = []
dfs = []
Fs = []

with open("function.csv", newline="") as f:
    reader = csv.reader(f)
    next(reader)  
    for row in reader:
        x, fx, dfx, Fx = map(float, row)
        xs.append(x)
        fs.append(fx)
        dfs.append(dfx)
        Fs.append(Fx)

plt.figure(figsize=(8, 6))
plt.plot(xs, fs, label="f(x) = x^2")
plt.plot(xs, dfs, label="f'(x) = 2x")
plt.plot(xs, Fs, label="F(x) = x^3/3")
plt.xlabel("x")
plt.ylabel("value")
plt.title("Функция, производная и первообразная")
plt.grid(True)
plt.legend()
plt.tight_layout()

# === 2. Интеграл, float vs double ===

Ns = []
area_float = []
area_double = []

with open("integrals.csv", newline="") as f:
    reader = csv.reader(f)
    next(reader)  
    for row in reader:
        N = int(row[0])
        af = float(row[1])
        ad = float(row[2])
        Ns.append(N)
        area_float.append(af)
        area_double.append(ad)

analytic = 1.0 / 3.0

err_float = [abs(a - analytic) for a in area_float]
err_double = [abs(a - analytic) for a in area_double]

# График значений интеграла
plt.figure(figsize=(8, 6))
plt.plot(Ns, area_float, "o-", label="float")
plt.plot(Ns, area_double, "o-", label="double")
plt.axhline(analytic, color="k", linestyle="--", label="аналитическое 1/3")
plt.xlabel("N (число прямоугольников)")
plt.ylabel("значение интеграла")
plt.title("Интеграл методом прямоугольников (float vs double)")
plt.grid(True)
plt.legend()
plt.tight_layout()

# График ошибок в логарифмических осях
plt.figure(figsize=(8, 6))
plt.loglog(Ns, err_float, "o-", label="ошибка float")
plt.loglog(Ns, err_double, "o-", label="ошибка double")
plt.xlabel("N (число прямоугольников)")
plt.ylabel("|численный - аналитический|")
plt.title("Зависимость ошибки от числа прямоугольников")
plt.grid(True, which="both")
plt.legend()
plt.tight_layout()

# === 3. Поиск наиболее близких значений ===

min_idx_float = min(range(len(Ns)), key=lambda i: err_float[i])
min_idx_double = min(range(len(Ns)), key=lambda i: err_double[i])

print("Аналитическое значение интеграла: ", analytic)
print()
print("FLOAT:")
print(f"  Лучшая аппроксимация при N = {Ns[min_idx_float]}")
print(f"  Значение: {area_float[min_idx_float]}")
print(f"  Ошибка:  {err_float[min_idx_float]}")
print()
print("DOUBLE:")
print(f"  Лучшая аппроксимация при N = {Ns[min_idx_double]}")
print(f"  Значение: {area_double[min_idx_double]}")
print(f"  Ошибка:  {err_double[min_idx_double]}")

plt.show()
