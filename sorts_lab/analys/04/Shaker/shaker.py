import numpy as np
import matplotlib.pyplot as plt
import glob
import os

PATH = "/Users/maksimkuzin/Documents/МФТИ/1_семестр/информатика/analys/04/Shaker/"
files = glob.glob(os.path.join(PATH, "*.csv"))

print("Найденные файлы:", files)

plt.figure(figsize=(10, 6))

for f in files:
    print(f"\nЧитаю файл: {f}")
    try:
        data = np.loadtxt(f)
    except Exception as e:
        print(f"  ⚠ Не удалось прочитать {f}: {e}")
        continue

    # парсим n и t
    if data.ndim == 1:
        if data.size < 2:
            print(f"  ⚠ В файле {f} меньше двух столбцов")
            continue
        n = np.array([data[0]])
        t = np.array([data[1]])
    else:
        if data.shape[1] < 2:
            print(f"  ⚠ В файле {f} меньше двух столбцов")
            continue
        n = data[:, 0]
        t = data[:, 1]

    # фильтрация
    mask = (n > 0) & (t > 0)
    n = n[mask]
    t = t[mask]

    if n.size == 0:
        print(f"  ⚠ Нет валидных данных в {f}")
        continue

    # сортировка по n
    order = np.argsort(n)
    n = n[order]
    t = t[order]

    label = os.path.basename(f)

    # точки
    plt.scatter(n, t, s=22)

    # линия
    plt.plot(n, t, linestyle="--", linewidth=1, label=label)

# оформление
plt.xlabel("n")
plt.ylabel("t (ns)")
plt.title("Shaker")
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.show()
