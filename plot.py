import matplotlib.pyplot as plt

sizes = [100000, 1000000, 5000000, 10000000]

time_seq = [1.1615, 12.01, 57.4763, 114.751]
time_mutex = [5.0215, 31.7342, 168.427, 336.158]
time_cas = [4.1137, 35.7491, 176.189, 368.595]

plt.plot(sizes, time_seq, marker='o', linestyle='-', color='green', linewidth=2, label='Послідовний алгоритм')
plt.plot(sizes, time_mutex, marker='s', linestyle='-', color='red', linewidth=2, label='М\'ютекс (Блокуючий)')
plt.plot(sizes, time_cas, marker='^', linestyle='-', color='blue', linewidth=2, label='CAS (Неблокуючий)')

plt.title('Залежність часу виконання від кількості даних', fontsize=12, fontweight='bold')
plt.xlabel('Кількість елементів у масиві', fontsize=10)
plt.ylabel('Час виконання (мс)', fontsize=10)
plt.grid(True, linestyle='--', alpha=0.7)
plt.legend(fontsize=10)

plt.show()