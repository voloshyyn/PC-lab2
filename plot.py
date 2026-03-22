import matplotlib.pyplot as plt

sizes = [100000, 1000000, 5000000, 10000000]

time_seq = [1.2, 12.5, 65.0, 130.5]    
time_mutex = [45.0, 480.2, 2500.4, 5100.0] 
time_cas = [5.5, 55.0, 280.0, 570.0]     

plt.figure(figsize=(10, 6))

plt.plot(sizes, time_seq, marker='o', linestyle='-', color='green', linewidth=2, label='Послідовний алгоритм')
plt.plot(sizes, time_mutex, marker='s', linestyle='-', color='red', linewidth=2, label='М\'ютекс (Блокуючий)')
plt.plot(sizes, time_cas, marker='^', linestyle='-', color='blue', linewidth=2, label='CAS (Неблокуючий)')

plt.title('Залежність часу виконання від кількості даних', fontsize=14, fontweight='bold')
plt.xlabel('Кількість елементів у масиві', fontsize=12)
plt.ylabel('Час виконання (мс)', fontsize=12) 

plt.grid(True, linestyle='--', alpha=0.7) 
plt.legend(fontsize=11) 

plt.tight_layout()
plt.savefig('performance_graph.png', dpi=300)
print("Графік успішно збережено як 'performance_graph.png'")

plt.show()