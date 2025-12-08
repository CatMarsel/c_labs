import numpy as np
import matplotlib.pyplot as plt
import glob
import os

# Папка, где лежат CSV-файлы
PATH = "/Users/maksimkuzin/Documents/МФТИ/1_семестр/информатика/analys/01/"   # можно указать полный путь, если нужно

# Ищем все .csv
files = glob.glob(os.path.join(PATH, "*.csv"))
print("Найденные файлы:", files)

if not files:
    print("⚠ Не найдено ни одного .csv в папке", PATH)

plt.figure(figsize=(10, 6))

for f in files:
    print(f"\nЧитаю файл: {f}")
    try:
        # БЕЗ delimiter="..." — по умолчанию разбивает по любым пробелам/табам
        data = np.loadtxt(f)
    except Exception as e:
        print(f"  ⚠ Не удалось прочитать {f}: {e}")
        continue

    if data.ndim == 1:
        # Если в файле всего одна строка
        if data.size < 2:
            print(f"  ⚠ В файле {f} меньше 2 столбцов")
            continue
        n = np.array([data[0]])
        t = np.array([data[1]])
    else:
        if data.shape[1] < 2:
            print(f"  ⚠ В файле {f} меньше 2 столбцов")
            continue
        n = data[:, 0]
        t = data[:, 1]

    print(f"  примеры данных n: {n[:5]}, t: {t[:5]}")

    # фильтрация нулевых/отрицательных значений (иначе log не определён)
    mask = (n > 0) & (t > 0)
    n = n[mask]
    t = t[mask]

    if n.size == 0:
        print(f"  ⚠ В {f} после фильтрации нет положительных n,t -> пропускаю")
        continue

    # сортируем по n, чтобы линия шла по возрастанию
    order = np.argsort(n)
    n = n[order]
    t = t[order]

    ln_n = np.log(n)
    ln_t2 = 2 * np.log(t)

    label = os.path.basename(f)

    # Точки
    plt.scatter(ln_n, ln_t2, s=22)

    # Штриховая линия между точками
    plt.plot(ln_n, ln_t2, linestyle="--", linewidth=1, label=label)

# Оформление
plt.xlabel("ln(n)")
plt.ylabel("2 · ln(t)")
plt.title("Зависимость 2·ln(t) от ln(n)")
plt.grid(True)
plt.legend()
plt.tight_layout()

plt.show()
