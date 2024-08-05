import pandas as pd
import numpy as np
from scipy import stats

# Read CSV files
files = [f'outputs/output-train{i}.csv' for i in range(9)]
dataframes = [pd.read_csv(file, header=None) for file in files]

# Combine dataframes
data = pd.concat(dataframes, ignore_index=True)
data.columns = ['Time', 'Event']

# Extract times for each event
approach_times = data[data['Event'] == 1]['Time'].values
exit_times = data[data['Event'] == 3]['Time'].values

# Calculate durations from Approach to Exit
durations = exit_times - approach_times[:len(exit_times)]

# Compute average duration
average_duration = np.mean(durations)

# Calculate confidence interval
confidence_level = 0.95
degrees_freedom = len(durations) - 1
sample_mean = np.mean(durations)
sample_standard_error = stats.sem(durations)
confidence_interval = stats.t.interval(confidence_level, degrees_freedom, sample_mean, sample_standard_error)

# Print results
print(f"Duración Promedio: {average_duration:.2f} unidades de tiempo")
print(f"Intervalo de Confianza del 95%: ({confidence_interval[0]:.2f}, {confidence_interval[1]:.2f}) unidades de tiempo")

# Validates model
mu0 = 4.3  # Valor de referencia
epsilon = 1.0  # Margen de error aceptable

best_case = abs(confidence_interval[1] - mu0)
worst_case = abs(confidence_interval[0] - mu0)

#if confidence_interval[0] <= mu0 <= confidence_interval[1]:
   # if best_case > epsilon or worst_case > epsilon:
   #     print("Se necesitan réplicas adicionales.")
  #  else:
 #       print("El modelo es aceptado.")
#else:
    #if best_case <= epsilon:
     #   print("El modelo es aceptado.")
    #else:
        #print("Se necesitan réplicas adicionales.")
