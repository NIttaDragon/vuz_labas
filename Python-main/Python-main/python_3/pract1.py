import qiskit
import matplotlib
from matplotlib import *
from qiskit import *
from matplotlib import pyplot as plt
from qiskit.visualization import plot_histogram as hist

BS = QuantumCircuit(2)
BS.h(0)
BS.h(1)
BS.cx(0, 1)
#BS.measure_all()
#BS.draw()
print(BS.measure_all())
print(BS.draw())
backend = BasicAer.get_backend('qasm_simulator')
job = execute(BS, backend, shots=10000)
result = job.result()
counts = result.get_counts(BS)
print(counts)
hist(counts)
plt.show()
