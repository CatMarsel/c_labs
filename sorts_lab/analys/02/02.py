import numpy as np
import matplotlib.pyplot as plt
import glob
import os

PATH = "/Users/maksimkuzin/Documents/МФТИ/1_семестр/информатика/analys/02/"   # папка с csv-файлами
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

    # парсим данные
    if data.ndim == 1:
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

    # фильтрация значений: n > 1 (чтобы ln(n) был определён и >0), t > 0
    mask = (n > 1) & (t > 0)
    n = n[mask]
    t = t[mask]

    if n.size == 0:
        print(f"  ⚠ В {f} нет допустимых значений -> пропуск")
        continue

    # сортировка по n
    order = np.argsort(n)
    n = n[order]
    t = t[order]

    # вычисляем нормированное время: t / (n ln n)
    t_norm = t / (n * np.log(n))

    # подпись для легенды
    label = os.path.basename(f)

    # точки
    plt.scatter(n, t_norm, s=22)

    # соединяющая штриховая линия
    plt.plot(n, t_norm, linestyle="--", linewidth=1, label=label)

# оформление графика
plt.xlabel("n")
plt.ylabel("t / (n · ln(n))")
plt.title("График зависимости t/(n·ln(n)) от n")
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.show()
